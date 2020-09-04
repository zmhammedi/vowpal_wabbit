// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.
#pragma once

#include "vw/experimental/vwvis.h"
#include "types.h"

#ifdef __cplusplus
extern "C"
{
#endif
  static const uint32_t AUTO_CONDITION_FEATURES = 1;
  static const uint32_t AUTO_HAMMING_LOSS = 2;
  static const uint32_t EXAMPLES_DONT_CHANGE = 4;
  static const uint32_t IS_LDF = 8;

  VW_DLL_PUBLIC VWStatus vw_search_set_options(
      VWSearch* search_handle, uint32_t options, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_search_get_history_length(
      VWSearch* search_handle, uint32_t* history_length, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_search_set_loss(VWSearch* search_handle, float loss, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_search_get_should_output(
      VWSearch* search_handle, bool* shouldOutput, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_search_get_predict_needs_example(
      VWSearch* search_handle, bool* shouldOutput, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_search_output(VWSearch* search_handle, const char* output, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_search_get_num_actions(
      VWSearch* search_handle, uint32_t* num_actions, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_search_set_force_oracle(
      VWSearch* search_handle, bool forceOracle, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_search_get_is_ldf(VWSearch* search_handle, bool* isLDF, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_search_get_predictor(
      VWSearch* search_handle, VWSearchPredictor** predictor, uint32_t ptag, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;

  // This is a rough guess as to what is needed here. We will need to test and update as appropriate.
  typedef VWStatus(VWSearchRunFunc)(void*);
  typedef VWStatus(VWSearchSetupFunc)(void*);
  typedef VWStatus(VWSearchTeardownFunc)(void*);
  VW_DLL_PUBLIC VWStatus vw_search_predictor_set_predict_hooks(VWSearch* search_handle, VWSearchRunFunc* runFunc,
      void* runContext, VWSearchSetupFunc* setupFunc, void* setupContext, VWSearchTeardownFunc* teardownFunc,
      void* teardownContext, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_search_predictor_set_input(
      VWSearchPredictor* predictor_handle, VWExample* input, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_search_predictor_set_input_length(
      VWSearchPredictor* predictor_handle, size_t inputLength, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_search_predictor_set_input_at(
      VWSearchPredictor* predictor_handle, size_t position, VWExample* input, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_search_predictor_push_oracle(
      VWSearchPredictor* predictor_handle, uint32_t oracle, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_search_predictor_clear_oracle(
      VWSearchPredictor* predictor_handle, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_search_predictor_push_allowed(
      VWSearchPredictor* predictor_handle, uint32_t allowed, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_search_predictor_clear_allowed(
      VWSearchPredictor* predictor_handle, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_search_predictor_push_condition(
      VWSearchPredictor* predictor_handle, uint32_t tag, char name, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_search_predictor_push_condition_range(
      VWSearchPredictor* predictor_handle, uint32_t hi, uint32_t cout, char name0, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_search_predictor_clear_condition(
      VWSearchPredictor* predictor_handle, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_search_predictor_set_learner_id(
      VWSearchPredictor* predictor_handle, size_t id, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_search_predictor_set_tag(
      VWSearchPredictor* predictor_handle, uint32_t tag, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_search_predictor_predict(
      VWSearchPredictor* predictor_handle, uint32_t* action, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;

#ifdef __cplusplus
}
#endif
