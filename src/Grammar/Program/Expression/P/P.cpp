#include "P.h"

Node* P::tryParse(TokStreamer* st) {
    std::vector<Job> jobs = {
                                Job(P1::tryParse, st),
                                Job(P2::tryParse, st),
                                Job(P3::tryParse, st)
    };
    Pipeline pipeline(jobs);
    pipeline.executeTask();
    if(pipeline.succeeded()) {
        return pipeline.getResult();
    }

    return nullptr;
};