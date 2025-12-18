#include"tree.h"
tree::tree(string projectFile):node(projectFile)
{
	
}
tree::~tree()
{

}
void tree::starttree1()
{
    node* Node = new node("zzz.txt");
	root = Node;
	s = token();
	Node->nodename = " START";
	Node->child[0] = stmt1();
}
node* tree::stmt1()
{
	node* Node = new node("zzz.txt");
	Node->child[0] = semicolon1();
	return Node;
}
node* tree::semicolon1()
{
	node* Node = new node("zzz.txt");
	Node->nodename = " ;";
	if (s==X||s==Y)
	{
		Node->child[0] = equalxeq();
	}
	else if(s==DO)
	{
			Node->child[0] = new node("zzz.txt");
			Node->child[0]->nodename = " do";
			s = token(); s = token();
		    Node->child[1]=rec();
			Node->child[2] = new node("zzz.txt");
			Node->child[2]->nodename = " while";
		    //Node->child[3] = new node("zzz.txt");
		    Node->child[3] = cond();
	}
	return Node;
}
node* tree::equalxeq()
{
	node* Node = new node("zzz.txt");
	if (s == X)
	{s = token();
		if (s == EQUALS)
		{
			Node->nodename = " =";
			Node->child[0] = new node("zzz.txt");
			Node->child[0]->nodename = " X";
			s = token();
			if (s == CONST)
			Node->child[1] = new node("zzz.txt");
			Node->child[1]->nodename = " 0";
		}
	}
	else if (s == Y)
	{
		s = token();
		if (s == EQUALS)
		{
			Node->nodename = " =";
			Node->child[0] = new node("zzz.txt");
			Node->child[0]->nodename = " Y";
			s = token();
			if (s == CONST)
			Node->child[1] = new node("zzz.txt");
			Node->child[1]->nodename = " 10";
		}
	}
	return Node;
}
node* tree::rec()
{
	node* Node = new node("zzz.txt");
	Node->child[0]= e();
	Node->child[1]= r();
	return Node;
}
node* tree::e()
{
	node* Node = new node("zzz.txt");
	Node->nodename = " ;";
	Node->child[0] = equalxplus();
	//Node->nodename = " ;";
	return Node;
}
node* tree::equalxplus()
{
	node* Node = new node("zzz.txt");
	if (s == X)
	{
		s = token();
		if (s == EQUALS)
		{
			Node->nodename = " =";
			Node->child[0] = new node("zzz.txt");
			Node->child[0]->nodename = " X";
			s = token();
			Node->child[1] = plus();
		}
	}
	return Node;
}
node* tree::plus()
{
	node* Node = new node("zzz.txt");
	if (s == X)
	{
		s = token();
		if (s == PLUS)
		{
			Node->nodename = " +";
			Node->child[0] = new node("zzz.txt");
			Node->child[0]->nodename = " X";
			s = token();
			if (s == CONST)
			{
				Node->child[1] = new node("zzz.txt");
				Node->child[1]->nodename = " 1";
				s = token();
			}
		}
	}
	return Node;
}
node* tree::r()
{
	node* Node = new node("zzz.txt");
	Node->child[0] = equalyminus();
	Node->nodename = " ;";
	return Node;
}
node* tree::equalyminus()
{
	node* Node = new node("zzz.txt");
	s = token();
	if (s == Y)
	{
		s = token();
		if (s == EQUALS)
		{
			Node->nodename = " =";
			Node->child[0] = new node("zzz.txt");
			Node->child[0]->nodename = " Y";
			s = token();
			Node->child[1] = minus();
		}
	}
	return Node;
}
node* tree::minus()
{
	node* Node = new node("zzz.txt");
	if (s == Y)
	{
		s = token();
		if (s == MINUS)
		{
			Node->nodename = " -";
			Node->child[0] = new node("zzz.txt");
			Node->child[0]->nodename = " Y";
			s = token();
			if (s == CONST)
			{
				Node->child[1] = new node("zzz.txt");
				Node->child[1]->nodename = " 1";
				s = token();
			}
		}
	}
	return Node;
}
node* tree::cond()
{
	node* Node = new node("zzz.txt");
	Node->nodename = " <";
	Node->child[0] = new node("zzz.txt");
	Node->child[0]->nodename = " X";
	Node->child[1] = new node("zzz.txt");
	Node->child[1]->nodename = " Y";
	return Node;
}
void tree::displayTree(node* root)
{
	if (root)
	{
		cout <<"| " << root->nodename << endl;
		displayTree(root->child[0]);
		displayTree(root->child[1]);
		displayTree(root->child[2]);
		displayTree(root->child[3]);
	}
}
