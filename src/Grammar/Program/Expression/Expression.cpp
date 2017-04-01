#include "Expression.h"


Node* E::tryParse(TokStreamer* ts) {

    std::vector<Job> EPipeline = {Job(E1::tryParse, ts), Job(E2::tryParse, ts), Job(E3::tryParse, ts), Job(E4::tryParse, ts), Job(E5::tryParse, ts)};
    Pipeline pipeline = Pipeline(EPipeline);

    pipeline.executeTask();
    if(pipeline.suceeded()) {
        return pipeline.getResult();
    }
    return nullptr;
}