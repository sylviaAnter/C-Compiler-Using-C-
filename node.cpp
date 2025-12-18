#include "node.h"
node::node(string projectname):grammar(projectname)
{
   
    for (int i = 0; i < 4; i++) 
    {
        child[i] = NULL;
    }
}
node::~node()
{
   
    for (int i = 0; i < 4; i++)
    {
        delete child[i];
    }
}