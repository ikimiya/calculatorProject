// -*- C++ -*-
// Parenthesis_Node.cpp

#include "Parenthesis_Node.h"

// Parethesis Node
Parenthesis_Node::Parenthesis_Node(void)
{

}

// Parenthesis Node (num)
Parenthesis_Node::Parenthesis_Node(int num)
    :precedence(1)
{
    // create node type based on num
    if(num == 1){
        id_ = "(";
    }else if (num == 2){
        id_ = ")";
    }else{
        id_ = "NULL";
    }
}

// ~Parentheisis Node
Parenthesis_Node::~Parenthesis_Node(void)
{

}

// accept
void Parenthesis_Node::accept(Expr_Node_Visitor &v)
{
    // does not take visitor
}

// eval
int Parenthesis_Node::eval(void)
{
    return 0;
}

// getPrecedence
int Parenthesis_Node::getPrecedence(){
    return precedence;
}

// getID
std::string Parenthesis_Node::getID(){
    return id_;
}