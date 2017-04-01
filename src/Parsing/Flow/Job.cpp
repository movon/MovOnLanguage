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
    if(!tree) {
        this->fail();
    } else {
        this->succeed(tree);
    }
}

void Job::fail() {
    this->status = statusTypes::failure;
    for(unsigned int i = 0; i < failJob.size() && i < failMerge.size(); i++) {
        failJob.at(i)->executeTask();
        this->result = (*this->failMerge.at(i))(this->result, failJob.at(i)->getResult());
    }
    //    Return the state to the starting state
    this->st->setIndex(this->preState);
}

bool Job::failed() {
    return this->status == statusTypes::failure;
}

void Job::succeed(Node *result) {
    this->result = result;
    this->status = statusTypes::success;
    for(unsigned int i = 0; i < successMerge.size() && i < successJob.size(); i++) {

        successJob.at(i)->executeTask();
        if(successJob.at(i)->succeeded()) {
            this->result = (*this->successMerge.at(i))(this->result, this->successJob.at(i)->getResult());
        }
//        TODO: decide if to fail the entire job if it's on success jobs fail
    }
}

bool Job::succeeded() {
    return this->status == statusTypes::success;
}

Job* Job::onFail(Job* nextJob, Node* (*mergeResultsFunc)(Node* firstJobResult, Node* secondJobResult)) {
    this->failJob.push_back(nextJob);
    this->failMerge.push_back(mergeResultsFunc);
    return this;
}

Job* Job::onSuccess(Job* nextJob, Node* (*mergeResultsFunc)(Node* firstJobResult, Node* secondJobResult)) {
    this->successJob.push_back(nextJob);
    this->successMerge.push_back(mergeResultsFunc);
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
    if(otherJob->succeeded()) {
        result = (*mergeResultsFunc)(result, otherJob->getResult());
    }
}

void Job::reset() {
    this->status = statusTypes::unExecuted;
    this->successJob.clear();
    this->failJob.clear();
}

Node *Job::mergeNothing(Node* firstJobResult, Node* secondJobResult) {
    return firstJobResult;
}

Job::~Job() {

}
