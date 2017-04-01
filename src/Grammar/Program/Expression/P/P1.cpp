#include "P1.h"

Node* P1::tryParse(TokStreamer* st) {
	Job VParser(&V::tryParse, st);
    VParser.executeTask();
	if(VParser.suceeded()) {
		return VParser.getResult();
	}
	return nullptr;
}