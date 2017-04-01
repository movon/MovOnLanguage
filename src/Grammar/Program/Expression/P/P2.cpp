#include "P2.h"

Node* P2::tryParse(TokStreamer* st) {
    if (termByType(tokType::OPENPARAN, st)) {
        Job EParser(&E::tryParse, st);
        EParser.executeTask();
        if(EParser.succeeded()) {
            if (termByType(tokType::CLOSINGPARAN, st)) {
                return EParser.getResult();
            }
            else {
                error("Expected closing paran after expression");
            }
        } else {
            error("Expected expression after opening paran");
        }
    }
    return nullptr;
}