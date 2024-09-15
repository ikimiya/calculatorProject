// -*- C++ -*-
// Unary_Expr_Node.cpp

#include "Unary_Expr_Node.h"

Unary_Expr_Node::Unary_Expr_Node(void)
    :id_("unary")
{

}

Unary_Expr_Node::Unary_Expr_Node(Expr_Node * child)
    : child_(child), 
    precedence(0),
    id_("unary")
{

}

Unary_Expr_Node::~Unary_Expr_Node(void)
{

}

void Unary_Expr_Node::accept(Expr_Node_Visitor &v)
{
    //v.Visit_Unary_Node(*this);
}

int Unary_Expr_Node::eval(void)
{
    if (this->child_){
        return this->child_->eval ();
    }
    return 0;
}

Expr_Node* Unary_Expr_Node::getChild(void) const
{
    return this->child_;
}

int Unary_Expr_Node::getPrecedence(){
    return precedence;
}

std::string Unary_Expr_Node::getID(){
    return id_;
}