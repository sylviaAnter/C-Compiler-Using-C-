#include "parser.h"
#include<iostream>
#include<string.h>
using namespace std;
parser::parser() 
{
	i = 0, top = 0;
	for (int i = 0; i < 50; i++)
	{
	    givenstring[i]=0;
		stack[i] = 0;
    }
	n=0;
}
parser::~parser()
{

}
void parser:: error()
{
	cout << "syntax error\n";
	exit(0);
}
void parser:: push(char c)
{
	if (top >= 50)//stack overflow
	{
		cout << "stack is full\n";
	}
	else
	{
		stack[top++] = c;//stack[1]=y;
	}
}
void parser::pop()
{
	if (top < 0)
	{
		cout << "stack is empty\n";
	}
	else
	{
		top--;
	}
}
void parser::DisplayGrammar()
{
	cout << "t-->expr|comp_stmt\n";//x=0; , y=0; , do{}while();
	cout << "a-->do{stmt}while(cond);\n";
	cout << "e-->z expr_dash\n";
	cout << "r-->epsilon|z expr_dash\n";
	cout << "z-->id=lf\n";
	cout << "l-->id+num;|id-num;|num;\n";
	cout << "c-->id<id\n";
}
// ///////////////////////////////////////////////////////////
/// /////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////
void parser::DisplayParser()
{
	n = strlen(givenstring);
	int b = strlen(stack);
	givenstring[n] = '$';
	givenstring[n + 1] = '\0';
	push('$');
	push('t');
	while (givenstring[i] != '\0')
	{
		if (givenstring[i] == '$' && stack[top - 1] == '$')
		{
			cout << "parsing is done\n";
			exit(0);
		}
		else if (givenstring[i] == stack[top - 1])//input = do
		{
			if (givenstring[i] == 'd' /* && givenstring[i + 1] == 'o' */ )
			{
				cout << "current input-- " << givenstring[i] << " :::action -- matched " << " do " << "\n";
				i++;
				pop();
				i++;
			}
			else if (givenstring[i] == 'w')//while  
			{
				cout << "current input-- " << givenstring[i] << " :::action -- matched " << " while" << "\n";
				i++;
				pop();
				i += 4;
			}
			else if (givenstring[i] == '1' && givenstring[i + 1] == '0')
			{
				i++;
				cout << "current input-- " << givenstring[i] << " :::action -- matched " << " 10 " << "\n";
				
					pop();
					i++;				
			}
			else
			{
				cout << "current input-- " << givenstring[i] << " :::action -- matched " << givenstring[i] << "  " << stack[top - 1] << "\n";
				i++;
				pop();
			}
		}
		else
		{
			if (stack[top - 1] == 't' && (givenstring[i] == 'x' || givenstring[i] == 'y'))
			{
				cout << "current input-- " << givenstring[i] << " :::action -- predict stmt-->expr\n";
				pop();
				push('e');
			}
			else if (stack[top - 1] == 't' && givenstring[i] == 'd')
			{

				cout << "current input-- " << givenstring[i] << " :::action -- predict stmt-->comp_stmt\n";
				pop();
				push('a');
			}
			else if (stack[top - 1] == 'a' && givenstring[i] == 'd')
			{
				cout << "current input-- " << givenstring[i] << " :::action -- predict comp_stmt-->do{stmt}while(cond);\n";
				pop();
				push(';');
				push(')');
				push('c');
				push('(');
				push('w');
				push('}');
				push('t');
				push('{');
				push('d');
			}
			else if (stack[top - 1] == 'e' && (givenstring[i] == 'x' || givenstring[i] == 'y'))
			{

				cout << "current input-- " << givenstring[i] << " :::action -- predict expr-->z expr_dash\n";
				pop();
				push('r');
				push('z');
			}
			else if (stack[top - 1] == 'r' && (givenstring[i] == 'x' || givenstring[i] == 'y'))
			{

				cout << "current input-- " << givenstring[i] << " :::action -- predict expr-->z expr_dash\n";
				pop();
				push('r');
				push('z');
			}
			else if (stack[top - 1] == 'r' && (givenstring[i] == ';' || givenstring[i] == '$' || givenstring[i] == '}'))
			{

				cout << "current input-- " << givenstring[i] << " :::action -- predict expr_dash-->epsilon \n";
				pop();
			}
			else if (stack[top - 1] == 'z' && (givenstring[i] == 'x' || givenstring[i] == 'y'))
			{
				cout << "current input-- " << givenstring[i] << " :::action -- predict z-->id=lf \n";
				pop();
				push('l');
				push('=');
				push('i');
			}
			else if (stack[top - 1] == 'l' && (givenstring[i] == 'x'))
			{
				cout << "current input-- " << givenstring[i] << " :::action -- predict lf-->id+num; \n";
				pop();
				push(';');
				push('n');
				push('+');
				push('i');
			}
			else if (stack[top - 1] == 'l' && givenstring[i] == 'y')
			{
				cout << "current input-- " << givenstring[i] << " :::action -- predict lf-->id-num; \n";
				pop();
				push(';');
				push('n');
				push('-');
				push('i');
			}
			else if (stack[top - 1] == 'l' && (givenstring[i] == '1' || givenstring[i] == '0'||givenstring[i]=='10'))
			{
				cout << "current input-- " << givenstring[i] << " :::action -- predict lf-->num; \n";
				pop();
				push(';');
				push('n');
			}
			else if (stack[top - 1] == 'i' && givenstring[i] == 'x')
			{
				cout << "current input-- " << givenstring[i] << " :::action -- predict id-->x \n";
				pop();
				push('x');
			}
			else if (stack[top - 1] == 'i' && givenstring[i] == 'y')
			{
				cout << "current input-- " << givenstring[i] << " :::action -- predict id-->y \n";
				pop();
				push('y');
			}
			else if (stack[top - 1] == 'n' && givenstring[i] == '1')
			{
				cout << "current input-- " << givenstring[i] << " :::action -- predict num-->1 \n";
				pop();
				push('1');
			}
			else if (stack[top - 1] == 'n' && givenstring[i] == '0')
			{
				cout << "current input-- " << givenstring[i] << " :::action -- predict num-->0 \n";
				pop();
				push('0');
			}
			else if (stack[top - 1] == 'n' && givenstring[i] == '10')
			{
			cout << "current input-- " << givenstring[i] << " :::action -- predict num-->10 \n";
			pop();
			push('0');
			push('1');
			}
			else if (stack[top - 1] == 'c' && (givenstring[i] == 'x'))
			{
				cout << "current input-- " << givenstring[i] << " :::action -- predict cond--> x<y \n";
				pop();
				push('y');
				push('<');
				push('x');
			}
			else
			{
				cout << stack[top - 1] << "   " << givenstring[i] << endl;
				error();
			}
		}
	}

}

