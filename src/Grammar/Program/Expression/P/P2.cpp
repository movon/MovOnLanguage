Node* P2::tryParse(TokStreamer* st) {
    if (termByType(tokType::OPENPARAN)) {
        Node* E_Node;
        if (E_Node = E.tryParse(st)) {
            if (termByType(tokType::CLOSINGPARAN)) {
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