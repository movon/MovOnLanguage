#include "gtest/gtest.h"
#include "../src/Base/Tok.h"
#include "../src/Grammar/Program/Expression/F/F.h"
#include "../src/Base/Node.h"


#include <iostream>
#include <vector>

// Tests that the Foo::Bar() method does Abc.
TEST(TestF, ParsesCorrectly) {
    Tok two("2", tokType::INT);
    Tok power("^", tokType::OPERATOR);
    std::vector<Tok> toks;
    toks.push_back(two);
    toks.push_back(power);
    toks.push_back(two);
    TokStreamer* st = new TokStreamer(toks);

    Node* daddy = F::tryParse(st);


    // Creating the expected nodes
    Node* expectedDaddy = Node::createNode(nullptr, NodeType::E);
    Node* node1 = Node::createNode(expectedDaddy, NodeType::INT, two);
    Node* node2 = Node::createNode(expectedDaddy, NodeType::EXPO, power);
    Node* node3 = Node::createNode(expectedDaddy, NodeType::INT, two);
    



    ASSERT_TRUE(daddy->equals(expectedDaddy));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
