// -*- C++ -*-
// Sub_Expr_Node.cpp

#include "Sub_Expr_Node.h"

// Sub_Expr_Node
Sub_Expr_Node::Sub_Expr_Node(void)
    : Binary_Expr_Node(), 
    precedence(1),
    id_("-")
{

}

// Sub_Expr_Node(Expr_Node left, Expr_Node right)
Sub_Expr_Node::Sub_Expr_Node(Expr_Node *left,Expr_Node *right)
    : Binary_Expr_Node(left,right), 
    precedence(1),
    id_("-")
{

}

// ~Sub_Expr_node
Sub_Expr_Node::~Sub_Expr_Node(void)
{

}

// eval
int Sub_Expr_Node::eval(int num1, int num2)const
{
    return num1 - num2;
}

// accept
void Sub_Expr_Node::accept(Expr_Node_Visitor & v) 
{
    v.Visit_Subtraction_Node(*this);
}

// getPrecedence
int Sub_Expr_Node::getPrecedence(){
    return precedence;
}

// getID
std::string Sub_Expr_Node::getID(){
    return id_;
}