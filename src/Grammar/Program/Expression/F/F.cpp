#include "F.h"

Node* F::tryParse(TokStreamer* st) {
    Job F1Parser(F1::tryParse, st);
    F1Parser.executeTask();
    if(F1Parser.suceeded()) {
        return F1Parser.getResult();
    }
    return nullptr;
}