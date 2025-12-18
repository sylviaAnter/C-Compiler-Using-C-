#pragma once
#include"grammar.h"
class node:public grammar
{
  public:
    string nodename;
    node* child[4];	
    node(string projectname);
    ~node();

};

