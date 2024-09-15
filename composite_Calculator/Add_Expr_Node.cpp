// -*- C++ -*-
// Add_Expr_Node.cpp

#include "Add_Expr_Node.h"

// Add_Expr_Node ()
Add_Expr_Node::Add_Expr_Node(void)
    : Binary_Expr_Node(), 
    precedence(1),
    id_("+")
{

}

// Add_Expr_Node (Expr_Node *left,Expr_Node *right)
Add_Expr_Node::Add_Expr_Node(Expr_Node *left,Expr_Node *right)
    : Binary_Expr_Node(left,right), 
    precedence(1),
    id_("+")
{

}

// ~Add_Expr_Node
Add_Expr_Node::~Add_Expr_Node(void)
{
    
}

// eval
int Add_Expr_Node::eval(int num1, int num2) const
{
    return num1+num2;
}

// accept
void Add_Expr_Node::accept(Expr_Node_Visitor & v) 
{
    v.Visit_Addition_Node(*this);
}

// getPrecedence
int Add_Expr_Node::getPrecedence(){
    return precedence;
}

// getID
std::string Add_Expr_Node::getID(){
    return id_;
}
