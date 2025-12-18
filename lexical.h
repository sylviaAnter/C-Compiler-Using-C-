#include <fstream>
#include <iostream>
#include <string.h>
#include<list>
using namespace std;

enum TypeOfToken {
	CONST, WHILE, DO, LEFT_PARN, RIGHT_PARN, MINUS, ROOT, LESS, EQUALS, PLUS, SEMICOLON, ERROR, IDENTIFER, STARTTREE, $,
	LEFT_CURLY, RIGHT_CURLY, EOFF, STMT, ONE, COMP_STMT, COND, Z, EXPR_DASH, EXPR, LF, EPSILON, REC, START, X, Y
};  //Introducing all token types.
class lexical
{
private:

public:
	char x;
	char c;
	string word;  //String to fit a list of tokens in.
	int ctrLine = 1;  //Line counter.
	ifstream file;  //Introducing file.
	TypeOfToken token();  //Token identifying.
	void display();  //Displaying.
	lexical(string projectname);  //Calling lexical function.
	string nameOfToken(TypeOfToken t);  //Calling Name of Token function.
	~lexical();  //Ending lexical.
};