//
// Created by daniel on 4/1/17.
//

#include "Job.h"

Job::Job(Node * (*executeFunc)(TokStreamer*), TokStreamer* st){
    this->execute = executeFunc;
    this->st = st;
}

void Job::executeTask() {
    this->preState = this->st->getIndex();
    Node* tree = (*this->execute)(this->st);
    if(tree) {
        this->fail();
    } else {
        this->succeed(tree);
    }
}

void Job::fail() {
    this->status = statusTypes::failure;
//    Return the state to the starting state
    this->st->setIndex(this->preState);
    if(failJob) {
        this->failJob->executeTask();
    }
}

bool Job::failed() {
    return this->status == statusTypes::failure;
}

void Job::succeed(Node *result) {
    this->result = result;
    this->status = statusTypes::success;
    if(successJob) {
        this->successJob->executeTask();
        if(this->successJob->suceeded()) {
            this->result = this->successMerge(this->result, this->successJob->getResult());
        }
    }
}

bool Job::suceeded() {
    return this->status == statusTypes::success;
}

Job* Job::onFail(Job* nextJob) {
    this->failJob = nextJob;
    return this;
}

Job* Job::onSuccess(Job* nextJob, Node* (*mergeResultsFunc)(Node* firstJobResult, Node* secondJobResult)) {
    this->successJob = nextJob;
    this->successMerge = mergeResultsFunc;
    return this;
}

Node* Job::getResult() {
    return this->result;
}

Node* Job::doNothing(TokStreamer*) {
    return new Node(nullptr, NodeType::PIPELINE);
}


// Refers to a pipeline onSuccess / onFail jobs
Job::Job() {
    this->execute = &doNothing;
}

void Job::mergeResults(Job *otherJob, Node *(*mergeResultsFunc)(Node *, Node *)) {
    if(otherJob->suceeded()) {
        result = mergeResultsFunc(result, otherJob->getResult());
    }
}

void Job::reset() {
    this->status = statusTypes::unExecuted;
    this->successJob = nullptr;
    this->failJob = nullptr;
}
