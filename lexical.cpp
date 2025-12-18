#include"lexical.h"
lexical::lexical(string projectname) //Open file and initialize file counter.
{
	file.open(projectname);
	ctrLine = 1;
}
lexical::~lexical()  //To close file once phase is over.
{
	file.close();
}
TypeOfToken lexical::token()
{
	file.get(c); //To get the characters.
	if (file.eof() == true)  //In case the file is empty or if it reaches the end of file.
	{
		return EOFF;
	}
	while (c == '\n') //In case of new line, get the next character.
	{
		file.get(c);
		ctrLine++;
	}
	while (c == '\t' || c == ' ')  //In case of space, get the next character.
	{
		file.get(c);
	}
	switch (c)  //Switch case for every token type.
	{
	case '=':
	{
		return EQUALS;
		break;
	}
	case '+':
	{
		return PLUS;
		break;
	}
	case '-':
	{
		return MINUS;
		break;
	}
	case '(':
	{
		return LEFT_PARN;
		break;
	}
	case ')':
	{
		return RIGHT_PARN;
		break;
	}
	case '{':
	{
		return LEFT_CURLY;
		break;
	}
	case '}':
	{
		return RIGHT_CURLY;
		break;
	}
	case ';':
	{
		return SEMICOLON;
		break;
	}
	case '<':
	{
		return LESS;
		break;
	}
	default:
	{
		if (isalpha(c)) //If token is character.
		{
			word = c;
			file.get(c);
			while (isalpha(c))  //Loop while 'c' is alphabet.
			{
				word += c;
				file.get(c);
			}
			file.putback(c); //To keep the value of C in case it's not a character, so it's not skipped during the while loop.
			if (word == "while")
			{
				return WHILE;
				break;
			}
			else if (word == "do")
			{
				return DO;
				break;
			}
			else if (word == "x")
			{
				return X;
			}
			else if (word == "y")
			{
				return Y;
			}
			else
			{
				return IDENTIFER;
				break;
			}

		}
		else if (isdigit(c)) //If token is digit.
		{
			word = c;
			file.get(c);  //To obtain the first digit in the file.
			while (isdigit(c))
			{
				word += c;
				file.get(c);
			}
			file.putback(c); //To keep the value of C in case it's not a digit, so it's not skipped.
			return CONST;
			break;
		}
		else  //Else statement if it's not any of the above. (Error)
		{
			x = c;
			return ERROR;
			break;

		}

	}
	}
}
////////////////////////////////////////////////////////
void lexical::display()  //To display on the screen.
{
	TypeOfToken token;
	if (file.eof() == true)
	{
		cout << "End of file.\n";
	}

	while (!file.eof())
	{
		token = lexical::token();
		switch (token)
		{
		case CONST:
		{
			cout << "Constant : Integer Number.\n" << endl;
			break;
		}
		case DO:
		{
			cout << "DO : Keyword.\n" << endl;
			break;
		}
		case WHILE:
		{
			cout << "WHILE : Keyword.\n" << endl;
			break;
		}
		case PLUS:
		{
			cout << "+ : Addition Operator.\n" << endl;
			break;
		}
		case MINUS:
		{
			cout << "- : Subtraction Operator.\n" << endl;
			break;
		}
		case LEFT_PARN:
		{
			cout << "( :  Left Parenthesis.\n" << endl;
			break;
		}
		case RIGHT_PARN:
		{
			cout << ") : Right Parenthesis.\n" << endl;
			break;
		}
		case LEFT_CURLY:
		{
			cout << "{ :  Left Curly Bracket.\n" << endl;
			break;
		}
		case RIGHT_CURLY:
		{
			cout << "} : Right Curly Bracket.\n" << endl;
			break;
		}
		case EQUALS:
		{
			cout << "= : Equals assignment.\n" << endl;
			break;
		}
		case LESS:
		{
			cout << "<  : Less than.\n" << endl;
			break;
		}
		case SEMICOLON:
		{
			cout << ";  : Semicolon.\n" << endl;
			break;
		}
		case IDENTIFER:
		{
			cout << "ID : Identifier.\n" << endl;
			break;
		}
		case X:
		{
			cout << "X : Identifier X.\n" << endl;
			break;
		}
		case Y:
		{
			cout << "Y : Identifier Y.\n" << endl;
			break;
		}

		case ERROR:  //In case of error.
		{
			cout << "Error in token: (" << x << ") || Error in line: " << ctrLine; //Prints the token that caused an error and which line it was on.
		}
		default:
		{
			cout << "  " << endl << endl << endl;
		}
		}
	}
}
string lexical::nameOfToken(TypeOfToken t)   //Same as above, only done to pass the output to the next phase.
{

	switch (t)
	{

	case CONST:
	{
		return "Name of token: Number || Type: Integer.\n";
		break;
	}
	case DO:
	{
		return "Name of token: DO || Type: Keyword.\n";
		break;
	}
	case WHILE:
	{
		return "Name of token: WHILE || Type: Keyword.\n";
		break;
	}case PLUS:
	{
		return "Name of token: + || Type: Addition Operator.\n";
		break;
	}
	case MINUS:
	{
		return "Name of token: - || Type: Subtraction Operator.\n";
		break;
	}
	case LEFT_PARN:
	{
		return "Name of token: ( || Type: Left Parenthesis Punchator.\n";
		break;
	}
	case RIGHT_PARN:
	{
		return "Name of token: ) || Type: Right Parenthesis Punchator.\n";
		break;
	}
	case LEFT_CURLY:
	{
		return "Name of token: { || Type: Left Curly Bracket Punchator.\n";
		break;
	}
	case RIGHT_CURLY:
	{
		return "Name of token: } || Type: Right Curly Bracket Punchator.\n";
		break;
	}
	case EQUALS:
	{
		return "Name of token: = || Type: Equals Assignment Pperator.\n";
		break;
	}
	case LESS:
	{
		return "Name of token: < || Type: Less Than Operator.\n";
		break;
	}
	case SEMICOLON:
	{
		return "Name of token: ; || Type: Semicolon Punchator.\n";
		break;
	}
	case IDENTIFER:
	{
		return "Name of token: ID || Type: Identifier.\n";
		break;
	}
	case X:
	{
		return " Name of token: X || Type: Identifier X.\n";
		break;
	}
	case Y:
	{
		return " Name of token: Y || Type: Identifier Y.\n";
		break;
	}

	case EOFF:
	{
		return "Name of token: EOFF || Type: EndOfFile.\n";
		break;
	}
	case ROOT:
	{
		return "Name of token: Root.\n";
		break;
	}
	default:
	{
		cout << "nameoftoken\n";
	}

	}
	//return "error token";
}





