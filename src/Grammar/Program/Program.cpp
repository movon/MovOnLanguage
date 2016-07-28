#include "Program.h"

Node* Program::tryParse(TokStreamer* ts) {
    Node* statement = nullptr;
    if (statement = E::getInstance().tryParse(ts)) {
        return statement;
    }
    
    return nullptr;
}