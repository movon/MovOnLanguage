#include "Program.h"

Node* Program::tryParse(TokStreamer* st) {
    Node* statement = nullptr;
    statement = Statement::tryParse(st);
    if (statement) {
        return statement;
    }
    
    return nullptr;
}