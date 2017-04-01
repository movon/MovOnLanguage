#include "V.h"


Node* V::tryParse(TokStreamer* st) {
    std::vector<Job> jobs = {
            Job(&V1::tryParse, st),
            Job(&V2::tryParse, st),
            Job(&V3::tryParse, st),
    };
    Pipeline pipeline(jobs);
    pipeline.executeTask();
    if(pipeline.suceeded()) {
        return pipeline.getResult();
    }
    return nullptr;
}