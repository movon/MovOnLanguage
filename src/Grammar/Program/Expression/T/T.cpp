#include "T.h"

Node* T::tryParse(TokStreamer* st) {
    Job T1Parser(T1::tryParse, st);
    T1Parser.executeTask();
    if(T1Parser.suceeded()) {
        return T1Parser.getResult();
    }
    return nullptr;
}
