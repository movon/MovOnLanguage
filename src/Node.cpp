#include "Node.h"


Node::Node(Node* Parent, NodeType Nodetype, std::vector<Tok> Tokens){
    parent = Parent;
    nodeType = Nodetype;
    tokens = Tokens;
}

    