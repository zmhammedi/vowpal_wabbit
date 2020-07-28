#include "cb.h"
#include "example.h"
#include "array_parameters.h"
#include "reductions_fwd.h"
#include "vw.h"
#include "hash.h"

#include "example_predict_builder.h"

#include <emscripten/bind.h>
#include <iostream>

int main()
{
  return 0;
}

using namespace emscripten;


struct vw_predict
{
  vw_predict()
  {
    try{
      all = VW::initialize("--quiet --cb_explore_adf --cb_sample --coin --epsilon 0.1 -b 12");
    }
    catch(std::exception& e)
    {
      std::cout << e.what() << std::endl;

    }
  }

  vw_predict(const std::vector<char>& bytes)
  {
    io_buf io;
    io.add_file(VW::io::create_buffer_view(bytes.data(), bytes.size()));
    all = VW::initialize("", &io);
  }
  vw* all;
};


example* new_example()
{
  return new example();
}

void destroy_example(example* ex)
{
  delete ex;
}

example_predict* get_inner_example_predict(example* ex)
{
  return static_cast<example_predict*>(ex);
}

void push_feature_string(vw_slim::example_predict_builder& arr, const std::string& feature_idx, float value) {
    arr.push_feature_string((char*)feature_idx.c_str(), value);
}

// void load_model(vw_slim::vw_predict<dense_parameters>& vw, const std::vector<char>& bytes) {
//   vw.load(bytes.data(), bytes.size());
// }

struct predict_results
{
  static predict_results from_action_scores(const ACTION_SCORE::action_scores& a_s)
  {
    predict_results results;
    for(const auto& s : a_s)
    {
      results.pdf.push_back(s.score);
      results.ranking.push_back(s.action);
    }
    return results;
  }


  std::vector<float> pdf;
  std::vector<int> ranking;

  std::vector<float> get_pdf()
  {
    return pdf;
  }

  std::vector<int> get_ranking()
  {
    return ranking;
  }
};

struct action_list
{
  std::vector<example*> actions;
  void add_action(example* a)
  {
    actions.push_back(a);
  }
};

multi_ex setup_examples(vw* all, example* shared, const action_list& actions)
{
  multi_ex examples;
  examples.push_back(shared);

  VW::setup_example(*all, shared);
  all->p->lp.default_label(&shared->l);
  CB::label* ld = &shared->l.cb;
  CB::cb_class f;

  f.partial_prediction = 0.;
  f.action = (uint32_t)uniform_hash("shared", 6, 0);
  f.cost = FLT_MAX;
  f.probability = -1.f;
  ld->costs.push_back(f);

  for (auto* action : actions.actions)
  {
    VW::setup_example(*all, action);
    all->p->lp.default_label(&action->l);
    examples.push_back(action);
  }
  return examples;
}

predict_results predict(vw_predict& vw_obj, const std::string& event_id, example* shared, const action_list& actions)
{
  auto examples = setup_examples(vw_obj.all, shared, actions);
  vw_obj.all->predict(examples);
  auto results = predict_results::from_action_scores(examples[0]->pred.a_s);
  vw_obj.all->finish_example(examples);
  return results;
}

// chosen action is 1 based.
void learn(vw_predict& vw_obj, const std::string& event_id, example* shared, const action_list& actions, int chosen_action, float cost, float prob)
{
  multi_ex examples;
  examples.push_back(shared);

  vw_obj.all->p->lp.default_label(&shared->l);
  CB::label* ld = &shared->l.cb;
  CB::cb_class f;

  f.partial_prediction = 0.;
  f.action = (uint32_t)uniform_hash("shared", 6, 0);
  f.cost = FLT_MAX;
  f.probability = -1.f;
  ld->costs.push_back(f);
  VW::setup_example(*vw_obj.all, shared);

  for (auto* action : actions.actions)
  {
    vw_obj.all->p->lp.default_label(&action->l);
    examples.push_back(action);
  }

  // 1 based works here because it skips the shared example.
  CB::cb_class c;
  c.action = chosen_action;
  c.cost = cost;
  c.probability = prob;
  examples[chosen_action]->l.cb.costs.push_back(c);


  for (auto* action : actions.actions)
  {
   VW::setup_example(*vw_obj.all, action);
  }

  vw_obj.all->learn(examples);
  vw_obj.all->finish_example(examples);
}

EMSCRIPTEN_BINDINGS(vw) {

  class_<example>("example");
  class_<example_predict>("example_predict");

  function("new_example", &new_example, allow_raw_pointers());
  function("destroy_example", &destroy_example, allow_raw_pointers());
  function("get_inner_example_predict", &get_inner_example_predict, allow_raw_pointers());

  class_<vw_slim::example_predict_builder>("example_predict_builder")
    .constructor<example_predict*, const std::string&>()
    .function("push_feature_string", &push_feature_string, allow_raw_pointers())
    .function("push_feature", &vw_slim::example_predict_builder::push_feature, allow_raw_pointers());

  class_<vw_predict>("vw_predict")
    .constructor<>()
    .constructor<const std::vector<char>&>()
    .function("predict", &predict, allow_raw_pointers())
    .function("learn", &learn, allow_raw_pointers());

  class_<predict_results>("predict_results")
    .function("get_pdf", &predict_results::get_pdf)
    .function("get_ranking", &predict_results::get_ranking);

  class_<action_list>("action_list")
    .constructor<>()
    .function("add_action", &action_list::add_action, allow_raw_pointers());

  register_vector<int>("VectorInt");
  register_vector<float>("VectorFloat");
};
