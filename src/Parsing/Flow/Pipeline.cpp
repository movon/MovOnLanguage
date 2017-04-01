//
// Created by daniel on 4/1/17.
//

#include "Pipeline.h"

Pipeline::Pipeline(std::vector<Job> jobs) {
    onSuccessJob = new Job();
    if(jobs.size() == 0) {
        throw new std::runtime_error("Pipeline Accepts at least 1 job. Accepted 0.");
    }

    this->jobs = jobs;
    for(unsigned int i = 0; i < jobs.size() - 1; i++) {
        Job currentJob = jobs.at(i);
        Job nextJob = jobs.at(i + 1);

        currentJob.onFail(&nextJob)->onSuccess(onSuccessJob, &mergeResults);
    }

    Job lastJob = jobs.at(jobs.size() - 1);
    lastJob.onSuccess(onSuccessJob, &mergeResults);
}

void Pipeline::executeTask() {
    jobs.at(0).executeTask();
    if(onSuccessJob->succeeded()) {
        this->succeed(onSuccessJob->getResult());
    } else {
        fail();
    }
}

Node* Pipeline::mergeResults(Node *firstJobResult, Node *secondJobResult) {
    if(firstJobResult->nodeType == NodeType::PIPELINE) {
        return secondJobResult;
    }
//        TODO: some kind of error management
    return secondJobResult;
}

Pipeline::~Pipeline() {
    delete onSuccessJob;
}
