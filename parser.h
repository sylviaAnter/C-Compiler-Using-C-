#define parser_H
#define parser_H
class parser 
{
private :
	int i = 0, top = 0;
	char stack[50];
	int n;

public :
	char givenstring[50];
	void error();
	void push(char c);
	void pop();
	void DisplayParser();
	void DisplayGrammar();
	//void begin();
	void matched();
	//void printStack(char stack[50]);
	parser();
	~parser();
};