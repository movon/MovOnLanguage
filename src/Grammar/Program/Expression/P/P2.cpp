#include "P2.h"

Node* P2::tryParse(TokStreamer* ts) {
    if (termByType(tokType::OPENPARAN, ts)) {
        Node* E_Node;
        if (E_Node = E::getInstance().tryParse(ts)) {
            if (termByType(tokType::CLOSINGPARAN, ts)) {
                return E_Node;
            }
            else {
                error("Expected closing paran after expression");
            }
        }
        else {
            error("Expected expression after opening paran");
        }
    }
    
    return nullptr;
}