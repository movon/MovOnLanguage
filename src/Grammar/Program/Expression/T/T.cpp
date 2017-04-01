#include "T.h"

Node* T::tryParse(TokStreamer* st) {
    Job T1Parser(T1::tryParse, st);
    T1Parser.executeTask();
    return T1Parser.getResult();
}
