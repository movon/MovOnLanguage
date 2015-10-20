#include "Parser.h"

static Node* currParent = nullptr;
static Node* prevNode = nullptr;
static std::vector<Tok> currentStatement;
static std::vector<Tok> prevStatement;
static std::vector<Node*> nodes;
static int E_index = 0;
static int INT_index = 0;
static int ADD_index = 0;
static int SUB_index = 0;
static int MUL_index = 0;
static int DIV_index = 0;
static int EXPO_index = 0;

void Parser::error(std::string errormsg) {
    //needs implementing
    //in the error class most likely
	std::cout << errormsg << std::endl;
}
 
bool Parser::accept(Tok& tok, tokType t) {
    return tok.type == t;
}

bool Parser::expect(Tok& tok, tokType t) {
    if (accept(tok, t)) {
        return true;
    }
    error("Unexpected symbol");
    return false;
}

void Parser::run(std::vector<Tok> toks) {
	TokStreamer* st = new TokStreamer(toks, -1);
	//Program(st);
	E(st);
	drawNodes();

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
		error("Can't draw");
	}
	Node* main = createNode(nullptr, NodeType::E);
	for (int i = nodes.size()-1; i >= 0; i--) {
		main->addChild(nodes.at(i));
	}
	//digraph += handle_node(main) + "}";
	std::vector<std::string> result = handle_node(main);
	std::string digraph = "digraph Nodes {\n";
	std::set<std::string> s;
	for (int i = 0; i < result.size();i++) {
		if (s.find(result.at(i)) == s.end()) {
			digraph += result.at(i) + "\n";
			s.insert(result.at(i));
		}
		
	}
	digraph += "}";
	std::cout << digraph;
	file <<digraph;
}

Node* Parser::createNode(Node* parent, NodeType nodeType){
    Node* node = new Node(parent, nodeType);
    if(parent != nullptr){
       parent->addChild(node);
    }

    return node;   
}

Node* Parser::createNode(Node* parent, NodeType nodeType, Tok t) {
    Node* node = new Node(parent, nodeType, t);
    if (parent != nullptr) {
        parent->addChild(node);
    }

    return node;
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

bool Parser::Program(TokStreamer* st) {
	int save = st->getIndex();
	if (Program1(st)) {
		return true;
	}

	return false;
}

bool Parser::Program1(TokStreamer* st) {
	bool atLeastOneFuncDef = false;

	while (FunctionDef(st)) {
		atLeastOneFuncDef = true;
		//maybe createNode
		//maybe add the node in nodes.back() to different endpoints of the tree
	}

	return atLeastOneFuncDef;
}

bool Parser::FunctionDef(TokStreamer* st) {
	return false;
}

bool Parser::termByType(tokType t, TokStreamer* st) {
    if (st->getNextToken().type == t) {
        //maybe createNode
        return true;
    }

    return false;
}

bool Parser::termByValue(std::string s, TokStreamer* st) {
    if (st->getNextToken().content == s) {
        //maybe createNode
        return true;
    }

    return false;
}

bool Parser::LOne(TokStreamer* st) {
    int save = st->getIndex();
    if (LOne1(st)) {
        //maybe createNode
        return true;
    }

    st->setIndex(save);
    if (LOne2(st)) {
        //maybe createNode
        return true;
    }

	st->setIndex(save);
    return false;
}

bool Parser::LOne1(TokStreamer* st) {
    if (termByValue("+", st)) {
		nodes.push_back(createNode(nullptr, NodeType::ADD));
        return true;
    }

    return false;
}

bool Parser::LOne2(TokStreamer* st) {
    if (termByValue("-", st)) {
		nodes.push_back(createNode(nullptr, NodeType::SUB));
        return true;
    }

    return false;
}

bool Parser::LTwo(TokStreamer* st) {
    int save = st->getIndex();
    if (LTwo1(st)) {
        return true;
    }

    st->setIndex(save);
    if (LTwo2(st))  {
        return true;
    }

	st->setIndex(save);
    return false;
}

bool Parser::LTwo1(TokStreamer* st) {
    if (termByValue("*", st)) {
		nodes.push_back(createNode(nullptr, NodeType::MUL));
        return true;
    }

    return false;
}

bool Parser::LTwo2(TokStreamer* st) {
    if (termByValue("/", st)) {
		nodes.push_back(createNode(nullptr, NodeType::DIV));
        return true;
    }

    return false; 
}

bool Parser::E(TokStreamer* st) {
    int save = st->getIndex();
    if (E1(st)) {
        return true;
    }
    
    st->setIndex(save);
    if (E2(st)) {
        return true;
    }

    st->setIndex(save);
    if (E3(st)) {
        return true;
    }

    st->setIndex(save);
    if (E4(st)) {
        return true;
    }

    st->setIndex(save);
    if (E5(st)) {
        return true;
    }

	st->setIndex(save);
    return false;
}

bool Parser::E1(TokStreamer* st) {
    Node* E;
	if (T(st)) {
		//maybe createNode
		Node* result;
		result = nodes.back();
		nodes.pop_back();
		E = createNode(nullptr, NodeType::E);
		E->addChild(result);
		while (LOne(st)) {
			//maybe createNode
			if (E->numChildren() == 1) {
				result = nodes.back();
				nodes.pop_back();
				E->addChild(result);
				if (T(st)) {
					result = nodes.back();
					nodes.pop_back();
					E->addChild(result);
				}
				else {
					error("Expected another term after operator \"+\" or \"-\"");
				}
			}
			else {
				//Unite the children into an E
				Node* newE = createNode(nullptr, NodeType::E);
				E->changeParent(newE);
				Node* temp = newE;
				newE = E;
				E = temp;
				result = nodes.back();//LOne
				nodes.pop_back();
				E->addChild(result);
				if (T(st)) {
					result = nodes.back();
					nodes.pop_back();//T
					E->addChild(result);
				}
				else {
					error("Expected another term after operator \"+\" or \"-\"");
				}
			}
		}
        nodes.push_back(E);
        return true;
    }
    return false;
}

bool Parser::E2(TokStreamer* st) {
    if (termByValue("+", st) && termByValue("+", st)) {
        if (termByType(tokType::IDENTIFIER, st)) {//we need to see how we get this identifiers name
            Tok id = st->getLastToken(1);
            Node* C = createNode(nullptr, NodeType::CREMENTER);
            C->addChild(createNode(C, NodeType::ADD));
            C->addChild(createNode(C, NodeType::ID, id));
            nodes.push_back(C);
            return true;
        }
        else {
            error("Expected an identifier after \"++\" operation");
        }
    }

    return false;
}

bool Parser::E3(TokStreamer* st) {
    if (termByType(tokType::IDENTIFIER, st)) {//we need to see how we get this identifiers name
        if (termByValue("+", st) && termByValue("+",st)) {
			Tok name = st->getLastToken(3);
			Node* C = createNode(nullptr, NodeType::CREMENTER);
			C->addChild(createNode(C, NodeType::ID,name));
			C->addChild(createNode(C, NodeType::ADD));
			nodes.push_back(C);
            return true;
        }
		else{
			error("Expected an identifier before \"++\" operation");
		}
    }

    return false;
}

bool Parser::E4(TokStreamer* st) {
    if (termByValue("-", st) && termByValue("-", st)) {
        if (termByType(tokType::IDENTIFIER, st)) {//we need to see how we get this identifiers name
            Tok id = st->getLastToken(1);
            Node* C = createNode(nullptr, NodeType::CREMENTER);
            C->addChild(createNode(C, NodeType::SUB));
            C->addChild(createNode(C, NodeType::ID, id));
            nodes.push_back(C);
            return true;
        }
        else {
            error("Expected an identifier after \"++\" operation");
        }
    }

    return false;
}

bool Parser::E5(TokStreamer* st) {
    if (termByType(tokType::IDENTIFIER, st)) {//we need to see how we get this identifiers name
        if (termByValue("-", st) && termByValue("-",st)) {
            Tok name = st->getLastToken(3);
            Node* C = createNode(nullptr, NodeType::CREMENTER);
            C->addChild(createNode(C, NodeType::ID,name));
            C->addChild(createNode(C, NodeType::SUB));
            nodes.push_back(C);
            return true;
        }
        else{
            error("Expected an identifier before \"--\" operation");
        }
    }

    return false;
}

bool Parser::T(TokStreamer* st) {
	int save = st->getIndex();
	if (T1(st)) {
        return true;
    }

	st->setIndex(save);
    return false;
}

bool Parser::T1(TokStreamer* st) {
    Node* T;
	Node* result;
	if (F(st)) {
		Node* node;
		node = nodes.back();
		nodes.pop_back();
		T = createNode(nullptr, NodeType::E);
		T->addChild(node);
		while (LTwo(st)) {
			if (T->numChildren() == 1){
				T->addChild(nodes.back());
				nodes.pop_back();
				if (F(st)){
					T->addChild(nodes.back());
					nodes.pop_back();
				}
				else{
					error("expected a term after \"*\" or \"/\" ");
				}
			}
			else{
				Node* newE = createNode(nullptr, NodeType::E);
				T->changeParent(newE);
				Node* temp = newE;
				newE = T;
				T = temp;
				result = nodes.back();//LOne
				nodes.pop_back();
				T->addChild(result);
				if (F(st)) {
					result = nodes.back();
					nodes.pop_back();//T
					T->addChild(result);
				}
				else{
					error("expected a term after \"*\" or \"/\" ");
				}
			}
		}
		nodes.push_back(T);
        return true;
    }
    
    return false;
}

bool Parser::F(TokStreamer* st) {
	int save = st->getIndex();
	if (F1(st)) {
        return true;
    }

	st->setIndex(save);
    return false;
}

bool Parser::F1(TokStreamer* st) {
	Node* f;
    if (P(st)) {
		f = createNode(nullptr, NodeType::E);
		f->addChild(nodes.back());
		nodes.pop_back();
		int save = st->getIndex();
        if (termByValue("^", st)) {
            if (F(st)) {
				f->addChild(createNode(f, NodeType::EXPO));
				f->addChild(nodes.back());
				nodes.pop_back();
            }
            else {
                error("Expected another term after operator \"^\"");
            }
        }
		else {
			st->setIndex(save);
		}
		nodes.push_back(f);
        return true;
    }
    
    return false;
}

bool Parser::P(TokStreamer* st) {
    int save = st->getIndex();
    if (P1(st)) {
        //maybe createNode
        return true;
    }
    
    st->setIndex(save);
    if (P2(st)) {
        //maybe createNode
        return true;
    }

    st->setIndex(save);
    if (P3(st)) {
        //maybe createNode
        return true;
    }

	st->setIndex(save);
    return false;
}


bool Parser::P1(TokStreamer* st)  {//this function is complete, i mean it
	if (V(st)) {
		return true;
	}

	return false;
}


bool Parser::P2(TokStreamer* st) {//this function is complete, i mean it
    if (termByType(tokType::OPENPARAN, st)) {
        if (E(st)) {
            if (termByType(tokType::CLOSINGPARAN, st)) {
                return true;
            }
            else {
                error("Expected closing paran after expression");
            }
        }
        else {
            error("Expected expression after opening paran");
        }
    }
    
    return false;
}

bool Parser::P3(TokStreamer* st) {
	Node* P = createNode(nullptr, NodeType::E);
    if (termByValue("-", st)) {
        if (T(st)) {
			P->addChild(createNode(P, NodeType::SUB));
			P->addChild(nodes.back());
			nodes.pop_back();
			nodes.push_back(P);
            return true;
        }
        else {
            error("Expected a term after unirary minus sign");
        }
    }
    
    return false;
}

bool Parser::P4(TokStreamer* st) {
	Node* P = createNode(nullptr, NodeType::E);
	if (termByValue("+", st)) {
		if (T(st)) {
			P->addChild(createNode(P, NodeType::ADD));
			P->addChild(nodes.back());
			nodes.pop_back();
			nodes.push_back(P);
			return true;
		}
		else {
			error("Expected a term after unirary plus sign");
		}
	}

	return false;
}

bool Parser::V(TokStreamer* st) {
    int save = st->getIndex();
    if (V1(st)) {
        //maybe createNode
        return true;
    }

    st->setIndex(save);
    if (V2(st)) {
        return true;
    }

    st->setIndex(save);
    if (V3(st)) {
        return true;
    }
	
	st->setIndex(save);
    return false;
}

bool Parser::V1(TokStreamer* st) {
    if (termByType(tokType::INT, st)) {
		Node* V = createNode(nullptr, NodeType::INT,st->getLastToken(1));
		nodes.push_back(V);
        return true;
    }

    return false;
}

bool Parser::V2(TokStreamer* st) {
    if (termByType(tokType::FLOAT, st)) {
		Node* V = createNode(nullptr, NodeType::FLOAT,st->getLastToken(1));
		nodes.push_back(V);
        return true;
    }

    return false;
}

bool Parser::V3(TokStreamer* st) {
    if (termByType(tokType::IDENTIFIER, st)) {
		Node* V = createNode(nullptr, NodeType::ID, st->getLastToken(1));
		nodes.push_back(V);
        return true;
    }

    return false;
}
