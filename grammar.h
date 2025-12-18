#pragma once
#include"lexical.h"
class grammar : public lexical
{
private:

 public:
	 void CorrectGrammar(TypeOfToken t);
	 TypeOfToken symbol;
	 void SyntaxError(TypeOfToken t);
	 void StartSymbol();
	 void stmt();
	 void expr();
	 void z();
	 void expr_dash();
	 void lf();
	 void cond();
	 void comp_stmt();
	 grammar(string projectname);
	 ~grammar();
};

