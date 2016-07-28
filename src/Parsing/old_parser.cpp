#include "Parser.h"



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
	st = new TokStreamer(toks, -1);
	//Program();
	E();
	drawNodes();
	delete st;
}

std::string Parser::nodeToRealString(Node* n) {
	switch (n->nodeType)
	{
		case NodeType::E:
			if (n->drawName == ""){
				++E_index;
<<<<<<< HEAD
				n->drawName = "Expression" + std::to_string(E_index);
=======
				n->drawName = "E" + std::to_string(E_index);
>>>>>>> af25e5201f487a98dd50ca74b3091d9d21b2ffe9
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
	Node* main = Node::createNode(nullptr, NodeType::E);
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
	std::cout << digraph << std::endl;
	file << digraph;
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
<<<<<<< HEAD
// FOR --> "foreach" TYPE ID "@" ID "{" BODY "}" | "for" "(" [CREATION] ";" [BEXP] ";" [Expression] ")" "{" BODY "}"
=======
// FOR --> "foreach" TYPE ID "@" ID "{" BODY "}" | "for" "(" [CREATION] ";" [BEXP] ";" [E] ")" "{" BODY "}"
>>>>>>> af25e5201f487a98dd50ca74b3091d9d21b2ffe9
// WHILE --> "while" "(" BEXP ")" "{" BODY "}"


//Grammar for Expressions:
<<<<<<< HEAD
// Expression --> T {LOne T} | "+" "+" ID | ID "+" "+" | "-" "-" ID | ID "-" "-"
// T --> F {LTwo F}
// F --> P ["^" F]
// P --> "(" Expression ")" | V | "-" T | "+" T //V is constants and identifiers
=======
// E --> T {LOne T} | "+" "+" ID | ID "+" "+" | "-" "-" ID | ID "-" "-"
// T --> F {LTwo F}
// F --> P ["^" F]
// P --> "(" E ")" | V | "-" T | "+" T //V is constants and identifiers
>>>>>>> af25e5201f487a98dd50ca74b3091d9d21b2ffe9
// LOne -> "+" | "-"
// LTwo -> "*" | "/"
// V --> INT | FLOAT | STRING ... | ID | FUNCNAME "(" [ ID { "," ID } ] ")" // TODO: IMPLEMENT LAST ONE!!!!

//Grammar for BEXP:
// BEXP -> lvl1bexp {OR lvl1bexp}
// lvl1bexp -> lvl2bexp {(AND|XOR) lvl2bexp}
// lvl2bexp -> NOT lvl3bexp | lvl3bexp
<<<<<<< HEAD
// lvl3bexp -> TRUE | FALSE | Expression COMPARISON_OPERATOR Expression
=======
// lvl3bexp -> TRUE | FALSE | E COMPARISON_OPERATOR E
>>>>>>> af25e5201f487a98dd50ca74b3091d9d21b2ffe9

bool Parser::Program() {
	int save = st->getIndex();
	if (Program1()) {
		return true;
	}

	return false;
}

bool Parser::Program1() {
	bool atLeastOneFuncDef = false;

	while (FunctionDef()) {
		atLeastOneFuncDef = true;
		//maybe Node::createNode
		//maybe add the node in nodes.back() to different endpoints of the tree
	}

	return atLeastOneFuncDef;
}

bool Parser::FunctionDef() {
	return false;
}

bool Parser::termByType(tokType t) {
	int save = st->getIndex();
	if (st->getNextToken().type == t) {
        //maybe Node::createNode
        return true;
    }

	st->setIndex(save);
    return false;
}

bool Parser::termByValue(std::string s) {
	int save = st->getIndex();
	if (st->getNextToken().content == s) {
        //maybe Node::createNode
        return true;
    }

	st->setIndex(save);
    return false;
}

bool Parser::LOne() {
    int save = st->getIndex();
    if (LOne1()) {
        //maybe Node::createNode
        return true;
    }

    st->setIndex(save);
    if (LOne2()) {
        //maybe Node::createNode
        return true;
    }

	st->setIndex(save);
    return false;
}

bool Parser::LOne1() {
    if (termByValue("+")) {
		nodes.push_back(Node::createNode(nullptr, NodeType::ADD));
        return true;
    }

    return false;
}

bool Parser::LOne2() {
    if (termByValue("-")) {
		nodes.push_back(Node::createNode(nullptr, NodeType::SUB));
        return true;
    }

    return false;
}

bool Parser::LTwo() {
    int save = st->getIndex();
    if (LTwo1()) {
        return true;
    }

    st->setIndex(save);
    if (LTwo2())  {
        return true;
    }

	st->setIndex(save);
    return false;
}

bool Parser::LTwo1() {
    if (termByValue("*")) {
		nodes.push_back(Node::createNode(nullptr, NodeType::MUL));
        return true;
    }

    return false;
}

bool Parser::LTwo2() {
    if (termByValue("/")) {
		nodes.push_back(Node::createNode(nullptr, NodeType::DIV));
        return true;
    }

    return false; 
}

bool Parser::E() {
    int save = st->getIndex();
    if (E1()) {
        return true;
    }
    
    st->setIndex(save);
    if (E2()) {
        return true;
    }

    st->setIndex(save);
    if (E3()) {
        return true;
    }

    st->setIndex(save);
    if (E4()) {
        return true;
    }

    st->setIndex(save);
    if (E5()) {
        return true;
    }

	st->setIndex(save);
    return false;
}

bool Parser::E1() {
    Node* E;
	if (T()) {
		//maybe Node::createNode
		Node* result;
		result = nodes.back();
		nodes.pop_back();
		E = Node::createNode(nullptr, NodeType::E);
		E->addChild(result);
		while (LOne()) {
			//maybe Node::createNode
			if (E->numChildren() == 1) {
				result = nodes.back();
				nodes.pop_back();
				E->addChild(result);
				if (T()) {
					result = nodes.back();
					nodes.pop_back();
					E->addChild(result);
				}
				else {
					error("Expected another term after operator \"+\" or \"-\"");
				}
			}
			else {
<<<<<<< HEAD
				//Unite the children into an Expression
=======
				//Unite the children into an E
>>>>>>> af25e5201f487a98dd50ca74b3091d9d21b2ffe9
				Node* newE = Node::createNode(nullptr, NodeType::E);
				newE->addChild(E);
				Node* temp = newE;
				newE = E;
				E = temp;
				result = nodes.back();//LOne
				nodes.pop_back();
				E->addChild(result);
				if (T()) {
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

bool Parser::E2() {
    if (termByValue("+") && termByValue("+")) {
        if (termByType(tokType::IDENTIFIER)) {//we need to see how we get this identifiers name
            Tok id = st->getLastToken(1);
            Node* C = Node::createNode(nullptr, NodeType::CREMENTER);
            C->addChild(Node::createNode(C, NodeType::ADD));
            C->addChild(Node::createNode(C, NodeType::ID, id));
            nodes.push_back(C);
            return true;
        }
        else {
            error("Expected an identifier after \"++\" operation");
        }
    }

    return false;
}

bool Parser::E3() {
    if (termByType(tokType::IDENTIFIER)) {//we need to see how we get this identifiers name
        if (termByValue("+") && termByValue("+")) {
			Tok name = st->getLastToken(3);
			Node* C = Node::createNode(nullptr, NodeType::CREMENTER);
			C->addChild(Node::createNode(C, NodeType::ID,name));
			C->addChild(Node::createNode(C, NodeType::ADD));
			nodes.push_back(C);
            return true;
        }
		else{
			error("Expected an identifier before \"++\" operation");
		}
    }

    return false;
}

bool Parser::E4() {
    if (termByValue("-") && termByValue("-")) {
        if (termByType(tokType::IDENTIFIER)) {//we need to see how we get this identifiers name
            Tok id = st->getLastToken(1);
            Node* C = Node::createNode(nullptr, NodeType::CREMENTER);
            C->addChild(Node::createNode(C, NodeType::SUB));
            C->addChild(Node::createNode(C, NodeType::ID, id));
            nodes.push_back(C);
            return true;
        }
        else {
            error("Expected an identifier after \"++\" operation");
        }
    }

    return false;
}

bool Parser::E5() {
    if (termByType(tokType::IDENTIFIER)) {//we need to see how we get this identifiers name
        if (termByValue("-") && termByValue("-")) {
            Tok name = st->getLastToken(3);
            Node* C = Node::createNode(nullptr, NodeType::CREMENTER);
            C->addChild(Node::createNode(C, NodeType::ID,name));
            C->addChild(Node::createNode(C, NodeType::SUB));
            nodes.push_back(C);
            return true;
        }
        else{
            error("Expected an identifier before \"--\" operation");
        }
    }

    return false;
}

bool Parser::T() {
	int save = st->getIndex();
	if (T1()) {
        return true;
    }

	st->setIndex(save);
    return false;
}

bool Parser::T1() {
    Node* T;
	Node* result;
	if (F()) {
		Node* node;
		node = nodes.back();
		nodes.pop_back();
		T = Node::createNode(nullptr, NodeType::E);
		T->addChild(node);
		while (LTwo()) {
			if (T->numChildren() == 1){
				T->addChild(nodes.back());
				nodes.pop_back();
				if (F()){
					T->addChild(nodes.back());
					nodes.pop_back();
				}
				else{
					error("expected a term after \"*\" or \"/\" ");
				}
			}
			else{
				Node* newE = Node::createNode(nullptr, NodeType::E);
				newE->addChild(T);
				Node* temp = newE;
				newE = T;
				T = temp;
				result = nodes.back();//LOne
				nodes.pop_back();
				T->addChild(result);
				if (F()) {
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

bool Parser::F() {
	int save = st->getIndex();
	if (F1()) {
        return true;
    }

	st->setIndex(save);
    return false;
}

bool Parser::F1() {
	Node* f;
    if (P()) {
		f = Node::createNode(nullptr, NodeType::E);
		f->addChild(nodes.back());
		nodes.pop_back();
		int save = st->getIndex();
        if (termByValue("^")) {
            if (F()) {
				f->addChild(Node::createNode(f, NodeType::EXPO));
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

bool Parser::P() {
    int save = st->getIndex();
    if (P1()) {
        //maybe Node::createNode
        return true;
    }
    
    st->setIndex(save);
    if (P2()) {
        //maybe Node::createNode
        return true;
    }

    st->setIndex(save);
    if (P3()) {
        //maybe Node::createNode
        return true;
    }

	st->setIndex(save);
    return false;
}


bool Parser::P1()  {//this function is complete, i mean it
	if (V()) {
		return true;
	}

	return false;
}


bool Parser::P2() {//this function is complete, i mean it
    if (termByType(tokType::OPENPARAN)) {
        if (E()) {
            if (termByType(tokType::CLOSINGPARAN)) {
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

bool Parser::P3() {
	Node* P = Node::createNode(nullptr, NodeType::E);
    if (termByValue("-")) {
        if (T()) {
			P->addChild(Node::createNode(P, NodeType::SUB));
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

bool Parser::P4() {
	Node* P = Node::createNode(nullptr, NodeType::E);
	if (termByValue("+")) {
		if (T()) {
			P->addChild(Node::createNode(P, NodeType::ADD));
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

bool Parser::V() {
    int save = st->getIndex();
    if (V1()) {
        //maybe Node::createNode
        return true;
    }

    st->setIndex(save);
    if (V2()) {
        return true;
    }

    st->setIndex(save);
    if (V3()) {
        return true;
    }
	
	st->setIndex(save);
    return false;
}

bool Parser::V1() {
    if (termByType(tokType::INT)) {
		Node* V = Node::createNode(nullptr, NodeType::INT, st->getLastToken(1));
		nodes.push_back(V);
        return true;
    }

    return false;
}

bool Parser::V2() {
    if (termByType(tokType::FLOAT)) {
		Node* V = Node::createNode(nullptr, NodeType::FLOAT, st->getLastToken(1));
		nodes.push_back(V);
        return true;
    }

    return false;
}

bool Parser::V3() {
    if (termByType(tokType::IDENTIFIER)) {
		Node* V = Node::createNode(nullptr, NodeType::ID, st->getLastToken(1));
		nodes.push_back(V);
        return true;
    }

    return false;
}