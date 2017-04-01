#include "Program.h"

Node* Program::tryParse(TokStreamer* st) {
    Job EParser(E::tryParse, st);
    EParser.executeTask();
    return EParser.getResult();
}