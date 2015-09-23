#ifndef PARENTNODE_H
#define PARENTNODE_H

#include <string>
#include "Node.h"
class ParentNode {
public:
    std::string name;
    std::vector<Node*> children;
    ParentNode();
};


#endif