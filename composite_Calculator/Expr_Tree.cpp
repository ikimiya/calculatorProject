// -*- Expr_Tree.cpp -*-
// Expr_Tree.cpp

#include "Expr_Tree.h"

// Expr_Tree
Expr_Tree::Expr_Tree(void)
    :root_(NULL)
{

}

// Expr_Tree(Expr_Node * root)
Expr_Tree::Expr_Tree(Expr_Node *root)
    :root_(root)
{

}

// ~Expr_Tree
Expr_Tree::~Expr_Tree(void)
{
    // delete nodes
    while(this->root_ != NULL){
        delete this->root_;
    }
}

// accept
void Expr_Tree::accept(Expr_Node_Visitor &v)
{
    // send root to accept 
    root_->accept(v);
}

// treeExist
bool Expr_Tree::treeExist(void)
{   
    // check if root does not equal null/nothing
    if(this->root_ != NULL){
        return true;
    }else{
        return false;
    }
    
}
