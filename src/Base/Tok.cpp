#include "Tok.h"


Tok::Tok(std::string con, tokType ty) {
    content = con;
    type = ty;
}

Tok::Tok() {
    type = tokType::NONE;
    content = "";
}


bool Tok::equals(Tok t) {
    // bool equ = this->content.compare(t.content) == 0 && this->type == t.type;
    // if ( equ ) {
        // std::cout << "this content: " << this->content << " is equal to: " << t.content << " and this type: " << this->type << " is equal to : " << t.type << std::endl;
    // }
    return this->content.compare(t.content) == 0 && this->type == t.type;
}
