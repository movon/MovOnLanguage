#ifndef PARENTNODE_H
#define PARENTNODE_H

#include <string>
#include "Node.h"
class ParentNode : public Node {
public:
    std::string name;
    ParentNode(std::string name);
};


#endif