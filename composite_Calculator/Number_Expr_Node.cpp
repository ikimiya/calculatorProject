// -*- C++ -*-
// Number_Expr_Node.cpp

#include "Number_Expr_Node.h"

// Number_Expr_Node
Number_Expr_Node::Number_Expr_Node(void)
    : precedence(0),
    id_("Numb")
{

}

// Number_Expr_Node (Expr_Node *left,Expr_Node *right)
Number_Expr_Node::Number_Expr_Node(int num)
    : num_(num), 
    precedence(0),
    id_("Numb")
{

}

// ~Number_Expr_Node
Number_Expr_Node::~Number_Expr_Node(void)
{

}

// accept
void Number_Expr_Node::accept(Expr_Node_Visitor & v)
{
    v.Visit_Number_Node(*this);
}

// eval
int Number_Expr_Node::eval()
{
    return this->num_;
}

// getPrecedence
int Number_Expr_Node::getPrecedence(){
    return precedence;
}

// getID
std::string Number_Expr_Node::getID(){
    return id_;
}