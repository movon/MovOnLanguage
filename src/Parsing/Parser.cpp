#include "Parser.h"


void Parser::run(std::vector<Tok> toks) {
	ts = new TokStreamer(toks, -1);
	AST = E::getInstance().tryParse(ts);
	drawNodes();
	delete ts;
}

void Parser::error(std::string errormsg) {
    //needs implementing
    //in the error class most likely
	std::cout << errormsg << std::endl;
}

std::string Parser::nodeToRealString(Node* n) {
	switch (n->nodeType)
	{
		case NodeType::E:
			if (n->drawName == ""){
				++E_index;
				n->drawName = "E" + std::to_string(E_index);
			}

			return n->drawName;
			
		case NodeType::INT:
			if (n->drawName == ""){
				n->drawName = "INT" + std::to_string(INT_index++) + std::string("_") + n->t.content + std::string("_");
			}
			return n->drawName;
		case NodeType::ADD:
			if (n->drawName == ""){
				n->drawName = "ADD" + std::to_string(ADD_index++);
			}
			return n->drawName;
		case NodeType::SUB:
			if (n->drawName == ""){
				n->drawName = "SUB" + std::to_string(SUB_index++);
			}
			return n->drawName;
		case NodeType::DIV:
			if (n->drawName == "") {
				n->drawName = "DIV" + std::to_string(DIV_index++);
			}
			return n->drawName;
		case NodeType::MUL:
			if (n->drawName == ""){
				n->drawName = "MUL" + std::to_string(MUL_index++);
			}
			return n->drawName;
		case NodeType::EXPO:
			if (n->drawName == ""){
				n->drawName = "EXPO" + std::to_string(EXPO_index++);
			}
			return n->drawName;
		default:
			return "";
		}
}

std::vector<std::string> Parser::handle_node(Node* node) {
	
	std::vector<std::string> results;
	std::vector<std::string> v1;
	std::vector<Node*> children = node->getChildren();
	for (int i = 0; i < children.size(); i++) {
		v1 = handle_node(children.at(i));
		v1.push_back(nodeToRealString(node) + " -> " + nodeToRealString(children.at(i)));
		results.insert(results.end(), v1.begin(), v1.end());
	}
	return results;
	
}

void Parser::drawNodes() {
	std::ofstream file;
	file.open("graph.gv");
	if (file.fail()) {
		error("Can't open file graph.gv");
	} else {
		std::cout << "Succeed opening file" << std::endl;
	}
	//digraph += handle_node(main) + "}";
	std::vector<std::string> result = handle_node(AST);
	
	std::string digraph = "digraph Nodes {\n";
	std::set<std::string> s;
	for (int i = 0; i < result.size();i++) {
		if (s.find(result.at(i)) == s.end()) {
			digraph += result.at(i) + "\n";
			s.insert(result.at(i));
		}
		
	}
	digraph += "}";
	std::cout << digraph << std::endl;
	std::cout << "Before writing to file" << std::endl;
	file << digraph;
	std::cout << "Finished drawing nodes" << std::endl;
}

//Grammar for Program:
// Program --> {FunctionDef}
// FunctionDef --> "function" ID "(" [TYPE ID {"," TYPE ID}] ")" "{" BODY "}"
// BODY --> {STMT}
// STMT --> FLOW | ASSIGNMENT | FUNCALL | KEYWORDS // int i = ?; string s = (string) ?.size(k|?);
// FUNCALL --> FUNCNAME "(" [V {"," V} ] ")" ";"
// ASSIGNMENT --> CREATION | TYPE ID ";"
// CREATION --> TYPE ID "=" V ";" | ID "=" V ";"
// FLOW --> LOOP | "if" "(" BEXP ")" "{" BODY "}" { "elsif" "(" BEXP ")" "{" BODY "}" } [ "else" "{" BODY "}" ]
// LOOP --> FOR | WHILE
// FOR --> "foreach" TYPE ID "@" ID "{" BODY "}" | "for" "(" [CREATION] ";" [BEXP] ";" [E] ")" "{" BODY "}"
// WHILE --> "while" "(" BEXP ")" "{" BODY "}"


//Grammar for Expressions:
// E --> T {LOne T} | "+" "+" ID | ID "+" "+" | "-" "-" ID | ID "-" "-"
// T --> F {LTwo F}
// F --> P ["^" F]
// P --> "(" E ")" | V | "-" T | "+" T //V is constants and identifiers
// LOne -> "+" | "-"
// LTwo -> "*" | "/"
// V --> INT | FLOAT | STRING ... | ID | FUNCNAME "(" [ ID { "," ID } ] ")" // TODO: IMPLEMENT LAST ONE!!!!

//Grammar for BEXP:
// BEXP -> lvl1bexp {OR lvl1bexp}
// lvl1bexp -> lvl2bexp {(AND|XOR) lvl2bexp}
// lvl2bexp -> NOT lvl3bexp | lvl3bexp
// lvl3bexp -> TRUE | FALSE | E COMPARISON_OPERATOR E