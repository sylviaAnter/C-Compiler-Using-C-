#include <fstream>
#include <iostream>
#include <string.h>
#include"lexical.h"
#include"grammer.h"
using namespace std;

enum TypeOfToken
{
	CONST, WHILE, DO, LEFT_PARN, RIGHT_PARN, MINUS, LESS, EQUALS, PLUS, SEMICOLON, IDENTIFER, LEFT_CURLY, RIGHT_CURLY, EOFF
};
grammer::grammer()
{

}
grammer::~grammer()
{

}
void grammer::CorrectGrammar(TypeOfToken t)
{
	if (symbol == t)
	{
		lexical::NameOfToken(symbol);
		cout << " is matched so correct grammar\n";
	}
	else
	{
		SyntaxError(symbol);
	}
	if (t != EOFF)
	{
		symbol = lexical::token();
	}
}

void grammer::SyntaxError(TypeOfToken t) 
{
	cout << "syntax error || not avaiable symbol\n";
}
//////////////////////////////////
//startsymbol-- > program eof
void grammer::StartSymbol()
{
	symbol = lexical::token();
	stmt();
	CorrectGrammar(EOFF);
}
////////////////////////////////////
//stmt--> expr | comp_stmt

void grammer:: stmt()
{
	if (isalpha(symbol))
	{
		expr();
	}
	else if (symbol == 'do')
	{
		comp_stmt();
	}
}
//////////////////////////////////////
//expr-->{id=num;}
void grammer::expr()
{
	while (symbol == IDENTIFER || symbol == EQUALS || symbol == PLUS || symbol == SEMICOLON || symbol == CONST)
	{
		if (symbol == IDENTIFER)
		{
			CorrectGrammar(IDENTIFER);
			CorrectGrammar(EQUALS);
			if (symbol == CONST)
			{
				CorrectGrammar(CONST);
				CorrectGrammar(SEMICOLON);
			}
			else if (symbol == IDENTIFER)
			{
				CorrectGrammar(IDENTIFER);
				if (symbol == PLUS)
				{
					CorrectGrammar(PLUS);
				}
				else if (symbol == MINUS)
				{
					CorrectGrammar(MINUS);
				}
				CorrectGrammar(CONST);
				CorrectGrammar(SEMICOLON);
			}

		}
	}

}
///////////////////////////////////////
//comp_stmt-->do{stmt}while(cond);
void grammer::comp_stmt()
{
	if (symbol == DO)
	{
		    CorrectGrammar(DO);
			CorrectGrammar(LEFT_CURLY);
			stmt();
			CorrectGrammar(LEFT_CURLY);
			CorrectGrammar(WHILE);
			CorrectGrammar(LEFT_PARN);
			cond();
			CorrectGrammar(RIGHT_CURLY);
			CorrectGrammar(SEMICOLON);
    }
}
/////////////////////////////////////////////
//cond-->id log_op id
void grammer::cond()
{
	CorrectGrammar(IDENTIFER);
	CorrectGrammar(LESS);
	CorrectGrammar(IDENTIFER);
}
