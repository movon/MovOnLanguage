#include "Program.h"

Node* Program::tryParse(TokStreamer* st) {
    Node* statement = nullptr;
    if (statement = E::tryParse(st)) {
        return statement;
    }
    
    return nullptr;
}