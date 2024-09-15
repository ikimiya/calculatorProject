// -*- C++ -*-
// Binary_Expr_Node.cpp

#include "Binary_Expr_Node.h"

// Binary_Expr_Node
Binary_Expr_Node::Binary_Expr_Node(void)
    :left_(NULL), right_(NULL)
{

}

// Binary_Expr_Node(Expr_Node *left,Expr_Node *right)
Binary_Expr_Node::Binary_Expr_Node(Expr_Node *left,Expr_Node *right)
    :left_(left),
    right_(right)
{

}

// ~Binary_Expr_Node
Binary_Expr_Node::~Binary_Expr_Node(void)
{
    if(this->left_ != NULL){
        delete this->left_;
    }

    if(this->right_ != NULL)
    {
       delete this->right_; 
    }
}

// eval
int Binary_Expr_Node::eval()
{
    int n1 = this->eval();
    int n2 = this->eval();
    return this->eval(n1,n2);
}

// getLeft
Expr_Node* Binary_Expr_Node::getLeft() const
{
    return this->left_;
}

// getRight
Expr_Node* Binary_Expr_Node::getRight() const
{
    return this->right_;
}

// setLeft
void Binary_Expr_Node::setLeft(Expr_Node *left)
{
    this->left_ = left;
}

// setRight
void Binary_Expr_Node::setRight(Expr_Node *right)
{
    this->right_ = right;
}