//
// Created by daniel on 4/1/17.
//

#ifndef MOVONLANGUAGE_PIPELINE_H
#define MOVONLANGUAGE_PIPELINE_H


#include <vector>
#include "Job.h"
#include "successJob.h"

class Pipeline : public Job{
private:
    static Node* mergeResults(Node* firstJobResult, Node* secondJobResult);
    OnSuccessJob* onSuccessJob;
    std::vector<Job> jobs;
public:
    Pipeline(std::vector<Job> jobs);
    ~Pipeline();
    virtual void executeTask();
    virtual void fail();
};


#endif //MOVONLANGUAGE_PIPELINE_H
