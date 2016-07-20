Node* P1::tryParse(TokStreamer* st) {
    Node* V_Node;
    if (V_Node = V.tryParse(st)) {
		return V_Node;
	}

	return nullptr;
}