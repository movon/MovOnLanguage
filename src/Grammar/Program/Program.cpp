#include "Program.h"

Node* Program::tryParse(TokStreamer* st) {
    Node* statement = nullptr;
    if (statement = Statement::tryParse(st)) {
        return statement;
    }
    
    return nullptr;
}