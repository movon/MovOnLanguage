#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "../../Base/BaseGrammar.h"
#include "../../../Parsing/TokStreamer.h" 

namespace Assignment{
	Node* tryParse(TokStreamer* st);
}

#endif
