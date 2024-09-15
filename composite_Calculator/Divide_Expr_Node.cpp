// -*- C++ -*-
// Divide_Expr_Node.cpp

#include "Divide_Expr_Node.h"

// Divide_Expr_Node()
Divide_Expr_Node::Divide_Expr_Node(void)
    : Binary_Expr_Node(), 
    precedence(2),
    id_("/")
{

}

// Divide_Expr_Node(Expr_Node *left,Expr_Node *right)
Divide_Expr_Node::Divide_Expr_Node(Expr_Node *left,Expr_Node *right)
    : Binary_Expr_Node(left,right), 
    precedence(2),
    id_("/")
{

}

// ~Divide_Expr_Node
Divide_Expr_Node::~Divide_Expr_Node(void)
{

}

// Eval
int Divide_Expr_Node::eval(int num1, int num2) const
{
    return num1/num2;
}

// Accept
void Divide_Expr_Node::accept(Expr_Node_Visitor & v) 
{
    v.Visit_Division_Node(*this);
}

// getPrecedence
int Divide_Expr_Node::getPrecedence(){
    return precedence;
}

// getID
std::string Divide_Expr_Node::getID(){
    return id_;
}