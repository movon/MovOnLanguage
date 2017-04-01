//
// Created by daniel on 4/1/17.
//

#ifndef MOVONLANGUAGE_JOB_H
#define MOVONLANGUAGE_JOB_H


#include "../../Base/Node.h"
#include "../../Base/TokStreamer.h"
#include <exception>

class Job {
private:
    enum class statusTypes {failure, success, unExecuted};
    Node* (*execute)(TokStreamer*);
    statusTypes status = statusTypes::unExecuted;
    Node* result;
    TokStreamer *st;
    int preState;
    Job* failJob;
    Job* successJob;
    Node* (*successMerge)(Node *, Node *);

protected:
    void fail();
    void succeed(Node* result = nullptr);
public:
    Job(Node * (*executeFunc)(TokStreamer*), TokStreamer* st);
    Job();

    virtual void executeTask();
    bool failed();
    bool suceeded();
    Job *onFail(Job *nextJob);
    Job *onSuccess(Job *nextJob, Node* (*mergeResultsFunc)(Node* firstJobResult, Node* secondJobResult));
    Node *getResult();
    void mergeResults(Job* otherJob, Node* (*mergeResultsFunc)(Node* firstJobResult, Node* secondJobResult));
    void reset();

    static Node *doNothing(TokStreamer *);
};


#endif //MOVONLANGUAGE_JOB_H
