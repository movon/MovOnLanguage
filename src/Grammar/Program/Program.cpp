#include "Program.h"

Node* Program::tryParse(TokStreamer* st) {
    Node* statement = nullptr;
    if (statement = FunctionDef::tryParse(st)) {
        return statement;
    }
    
    return nullptr;
}