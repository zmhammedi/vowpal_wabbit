/*
Copyright (c) by respective owners including Yahoo!, Microsoft, and
individual contributors. All rights reserved.  Released under a BSD (revised)
license as described in the file LICENSE.
*/
//#include <limits>
#include <CNTKLibrary.h>

#include "cntk.h"
#include "reductions.h"
#include "vw.h"
#include "crossplat_compat.h"

#include <iostream>

namespace VW_CNTK {
	using namespace VW;
	using namespace LEARNER;
	using namespace CNTK;

	struct cntk
	{

		vw* all;
	};

	void predict(cntk& dat, base_learner&, example& ex)
	{

	}

	void learn(cntk& dat, base_learner&, example& ex)
	{

	}

	void  update(cntk& dat, base_learner&, example& ex)
	{
		// TODO: what should this do?
	}

	float sensitivity(cntk& dat, base_learner&, example& ex)
	{
		// TODO: what should this do?
		return 0.;
	}

	void save_load(cntk& dat, io_buf& model_file, bool read, bool text)
	{
		vw& all = *dat.all;

		try
		{
			// TODO: DeviceDescriptor::GPUDevice(0));
			auto model = Function::LoadModel(L"c:\\temp\\cntk\\model.1", DeviceDescriptor::CPUDevice());
			auto inputs = model->Inputs();
			auto& input = inputs.front();
			auto& inputUid = input.Uid();

			auto& input2 = inputs[1];
			auto& inputUid2 = input2.Uid();

			auto& input3 = inputs[2];
			auto& inputUid3 = input3.Uid();

			for (auto inputVar : inputs)
			{
				auto uid = inputVar.Uid();
				auto name = inputVar.Name();

				int y = 9;

				// look for features...
				// TODO: what is parameters*
			}

			//for (auto inputVarInfo : inputVarUids)
			//{
			//	auto newInputVar = *(std::find_if(inputs.begin(), inputs.end(), [inputVarInfo](const CNTK::Variable& var) {
			//		return (var.Uid() == inputVarInfo.first);
			//	}));
			//	*(inputVarInfo.second) = newInputVar;
			//}

			auto outputs = model->Outputs();

			if (outputs.size() == 0)
				THROW("Need at least 1 output");

			auto& prediction = outputs.front();

			// Variable& 
			//for (auto outputVarInfo : outputVarNames)
			//{
			//	auto newOutputVar = *(std::find_if(outputs.begin(), outputs.end(), [outputVarInfo](const CNTK::Variable& var) {
			//		return (var.Owner()->Name() == outputVarInfo.first);
			//	}));
			//	*(outputVarInfo.second) = newOutputVar;
			//}

			// auto classifierOutput = LSTMSequenceClassiferNet(features, numOutputClasses, embeddingDim, hiddenDim, cellDim, device, L"classifierOutput");

			// TODO: is numOutputClasses == outputs.size()
			// isSparse?
			auto labels = InputVariable({ outputs.size() }, DataType::Float, L"Label"); // , { Axis::DefaultDynamicAxis() });

			// TODO: support different losses
			auto trainingLoss = SquaredError(prediction, labels, L"squaredError");

			// TODO: -1,1 vs 0,1
			// logistic -> CNTK::BinaryCrossEntropy()


			// multi-class  ->  CrossEntropyWithSoftmax
			// ranking  ->  CNTK::LambdaRank
			// cosine distance -> CNTK::CosineDistance

			//CNTK::SquaredError(predictionVar, labels, L"squaredError");

			//auto trainingLoss = CNTK::CrossEntropyWithSoftmax(classifierOutput, labels, L"lossFunction");
			//auto prediction = CNTK::ClassificationError(classifierOutput, labels, L"classificationError");

			// TODO: support more learners
			AdditionalLearningOptions opts;
			opts.l1RegularizationWeight = dat.all->l1_lambda;
			opts.l2RegularizationWeight = dat.all->l2_lambda;

			auto trainer = CreateTrainer(model, trainingLoss, prediction,
				{ SGDLearner(model->Parameters(), LearningRateSchedule(dat.all->eta, LearningRateSchedule::UnitType::Minibatch), opts) });

			int x = 0;
		}
		catch (const std::logic_error& ex)
		{
			std::cerr << "cntk error: " << ex.what() << std::endl;
			throw ex;
		}
		catch (const std::runtime_error& ex)
		{
			std::cerr << "cntk error: " << ex.what() << std::endl;
			throw ex;
		}

	}

	base_learner* setup(vw& all)
	{
		if (missing_option(all, true, "cntk", "Use CNTK as base learner."))
			return nullptr;

		new_options(all, "CNTK options")
			("foo", "use foo update.");
		//("sparse_l2", po::value<float>()->default_value(0.f), "use per feature normalized updates");
		add_options(all);
		po::variables_map& vm = all.vm;
		cntk& g = calloc_or_throw<cntk>();
		g.all = &all;

		learner<cntk>& ret = init_learner(&g, learn, 1 /* TODO: can I do 0*/);
		ret.set_predict(predict);
		ret.set_sensitivity(sensitivity);
		ret.set_update(update);
		ret.set_save_load(save_load);

		//ret.set_multipredict(multipredict);
		//ret.set_end_pass(end_pass);

		return make_base(ret);
	}
}