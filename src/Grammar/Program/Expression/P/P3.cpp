Node* P3::tryParse(TokStreamer* st) {
    Node* P = Node::createNode(nullptr, NodeType::E);
    if (termByValue("-")) {
        if (Node* T_Node = T.tryParse(st)) {
			P->addChild(Node::createNode(P, NodeType::SUB));
			P->addChild(T_Node);
            return P;
        }
        else {
            error("Expected a term after unirary minus sign");
        }
    }
    
    return nullptr;
}