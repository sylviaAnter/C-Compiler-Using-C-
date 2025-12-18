#pragma once
#include"node.h"
class tree : public node
{
public :
	char ch;
	TypeOfToken s;
	node* root;
	void starttree1();
	node* stmt1();
	node* cond();
	node* rec();
	node* e();
	node* r();
	node* semicolon1();
	node* equalxplus();
	node* equalyminus();
	node* equalxeq();
	node* plus();
	node* minus();
	void displayTree(node* t);
	tree(string projectname);
	~tree();
};

