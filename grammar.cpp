#include "grammar.h"
grammar::grammar(string projectname):lexical(projectname)
{
	
}
///////////////////////////////////////
grammar::~grammar()
{
	//file.close();
}
////////////////////////////////////////
void grammar::SyntaxError(TypeOfToken t)
{
	cout << "token not found   "<< t <<endl;
	//grammar::~grammar();
}

///  grammar  ::: bat5od token :::: batkrno bal symbol 
// symbol== type of token from the file 



// x = 0 ;
void grammar::CorrectGrammar(TypeOfToken t)
{
	if (symbol == t)
	{
		cout << nameOfToken(t);
		cout << "  the grammar of this token is correct\n";
	}
	else if (symbol != t)
	{
		SyntaxError(t);
	}
	if (t != EOFF)
	  symbol = token();
}
//startsymbol-->stmt eof
void grammar::StartSymbol()
{
	symbol= token();// semicolon || plus || miuns || iden || equal     symbol=X
	stmt();
	CorrectGrammar(EOFF);
}
//stmt-- > expr | comp_stmt
void grammar::stmt()//symbol =X
{
	if (symbol == DO)
	{
		comp_stmt();
	}
	else if (symbol==X||symbol==Y)
	{
		expr();
	}
}
//expr--> z expr_dash
void grammar::expr()
{
	z();
	expr_dash();
}
//expr_dash--> epsilon| z expr_dash
void grammar::expr_dash()
{
		z();
		expr_dash();
}
// z--> x = lf
void grammar::z()
{
	if(symbol == X)
	{
		CorrectGrammar(X);
	  //cout << "/////////////////////////////\n";
	}
	else if (symbol == Y)
	{
		CorrectGrammar(Y);
      //cout << "/////////////////////////////\n";
	}
	CorrectGrammar(EQUALS);//x= 0;
	lf();
}
//lf--> x + num ;| y - num ; | num ;  
void grammar::lf()
{
	if (symbol == X)
	{
		    CorrectGrammar(X);
			CorrectGrammar(PLUS);
			CorrectGrammar(CONST);
			CorrectGrammar(SEMICOLON);
//	cout << "/////////////////////////////\n";
	}
	else if(symbol==Y)
	{
		CorrectGrammar(Y);
		CorrectGrammar(MINUS);
		CorrectGrammar(CONST);
		CorrectGrammar(SEMICOLON);
//		cout << "/////////////////////////////\n";
	}
	else if(symbol==CONST)
	{
		CorrectGrammar(CONST);
		CorrectGrammar(SEMICOLON);
      //cout << "/////////////////////////////\n";
	}//x=0;
	////////////////////////////////////////////////////////////////////
	if (symbol == RIGHT_CURLY)
	{
		//cout << "/////////////////////////////\n";
		CorrectGrammar(RIGHT_CURLY);
		//cout << "/////////////////////////////\n";
		CorrectGrammar(WHILE);
		//cout << "/////////////////////////////\n";
		CorrectGrammar(LEFT_PARN);
		//cout << "/////////////////////////////\n";
		cond();
		//cout << "/////////////////////////////\n";
		CorrectGrammar(RIGHT_PARN);
		//cout << "/////////////////////////////\n";
		CorrectGrammar(SEMICOLON);
	//	cout << "/////////////////////////////\n";
	}
}
//comp_stmt-->do{stmt}while(cond);
void grammar::comp_stmt()
{   
    	CorrectGrammar(DO);
		//cout << "/////////////////////////////\n";
		CorrectGrammar(LEFT_CURLY);
		
		stmt();
}
//cond-- > id < id
void grammar::cond()
{
		CorrectGrammar(X);
		CorrectGrammar(LESS);
		CorrectGrammar(Y);
}
