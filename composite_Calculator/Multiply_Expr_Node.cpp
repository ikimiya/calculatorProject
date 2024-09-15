// -*- C++ -*-
// Multiply_Expr_Node.cpp

#include "Multiply_Expr_Node.h"

// Multiply_Expr_Node
Multiply_Expr_Node::Multiply_Expr_Node(void)
    : Binary_Expr_Node(), 
    precedence(2),
    id_("*")
{

}

// Multiply_expr_Node(Expr_Node *left,Expr_Node *right)
Multiply_Expr_Node::Multiply_Expr_Node(Expr_Node *left,Expr_Node *right)
    : Binary_Expr_Node(left,right), 
    precedence(2),
    id_("*")
{

}

// ~Multiply_Expr_Node
Multiply_Expr_Node::~Multiply_Expr_Node(void)
{

}

// eval
int Multiply_Expr_Node::eval(int num1, int num2)const
{
    return num1*num2;
}

// accept
void Multiply_Expr_Node::accept(Expr_Node_Visitor & v) 
{
    v.Visit_Multiplication_Node(*this);
}

// getPrecedece
int Multiply_Expr_Node::getPrecedence(){
    return precedence;
}

// getID
std::string Multiply_Expr_Node::getID(){
    return id_;
}