// -*- C++ -*-
// Mod_Expr_Node.cpp

#include "Mod_Expr_Node.h"

// Mod_Expr_Node
Mod_Expr_Node::Mod_Expr_Node(void)
    : Binary_Expr_Node(), 
    precedence(2),
    id_("%")
{

}

// Mod_Expr_Node(Expr_Node *left,Expr_Node *right)
Mod_Expr_Node::Mod_Expr_Node(Expr_Node *left,Expr_Node *right)
    : Binary_Expr_Node(left,right), 
    precedence(2),
    id_("%")
{

}

// Deconsturctor
Mod_Expr_Node::~Mod_Expr_Node(void)
{

}

// eval
int Mod_Expr_Node::eval(int num1, int num2) const
{
    return num1%num2;
}

// accept
void Mod_Expr_Node::accept(Expr_Node_Visitor & v) 
{
    v.Visit_Modulus_Node(*this);
}

// getPrecedence
int Mod_Expr_Node::getPrecedence(){
    return precedence;
}

// getID
std::string Mod_Expr_Node::getID(){
    return id_;
}