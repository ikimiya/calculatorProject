// -*- C++ -*-
// Eval_Expr_Tree.cpp

#include "Eval_Expr_Tree.h"

// Eval_Expr_Tree
Eval_Expr_Tree::Eval_Expr_Tree(void)
    :result_(-1)
{
    
}

// ~Eval_Expr_Tree
Eval_Expr_Tree::~Eval_Expr_Tree(void)
{
    
}

// Visit Number Node
void Eval_Expr_Tree::Visit_Number_Node(Number_Expr_Node &node)
{
    this->result_ = node.eval();
}

// Visit Addition Node
void Eval_Expr_Tree::Visit_Addition_Node(const Add_Expr_Node & node)
{
    // Accept left node, Accept right node, perform eval to result
    Expr_Node *left;
    Expr_Node *right;

    Eval_Expr_Tree leftEval;
    Eval_Expr_Tree rightEval;

    // visit left node
    left = node.getLeft();
    left->accept(leftEval);
    int result1 = leftEval.result();

    // visit right node
    right = node.getRight();
    right->accept(rightEval);
    int result2 = rightEval.result();

    // perform eval to result
    this->result_ = node.eval(result1,result2);
}

// Visit Subtraction Node
void Eval_Expr_Tree::Visit_Subtraction_Node(const Sub_Expr_Node & node)
{
    Expr_Node *left;
    Expr_Node *right;

    Eval_Expr_Tree leftEval;
    Eval_Expr_Tree rightEval;

    // visit left node
    left = node.getLeft();
    left->accept(leftEval);
    int result1 = leftEval.result();

    // visit right node
    right = node.getRight();
    right->accept(rightEval);
    int result2 = rightEval.result();

    this->result_ = node.eval(result1,result2);

}

// Visit Multiplication Node
void Eval_Expr_Tree::Visit_Multiplication_Node(const Multiply_Expr_Node & node)
{
    Expr_Node *left;
    Expr_Node *right;

    Eval_Expr_Tree leftEval;
    Eval_Expr_Tree rightEval;

    // visit left node
    left = node.getLeft();
    left->accept(leftEval);
    int result1 = leftEval.result();

    // visit right node
    right = node.getRight();
    right->accept(rightEval);
    int result2 = rightEval.result();

    this->result_ = node.eval(result1,result2);

}

// Visit Division Node
void Eval_Expr_Tree::Visit_Division_Node(const Divide_Expr_Node & node)
{
    Expr_Node *left;
    Expr_Node *right;

    Eval_Expr_Tree leftEval;
    Eval_Expr_Tree rightEval;

    // visit left node
    left = node.getLeft();
    left->accept(leftEval);
    int result1 = leftEval.result();

    // visit right node
    right = node.getRight();
    right->accept(rightEval);
    int result2 = rightEval.result();

    this->result_ = node.eval(result1,result2);
}

// Visit Modulus Node
void Eval_Expr_Tree::Visit_Modulus_Node(const Mod_Expr_Node & node)
{
    Expr_Node *left;
    Expr_Node *right;

    Eval_Expr_Tree leftEval;
    Eval_Expr_Tree rightEval;

    // visit left node
    left = node.getLeft();
    left->accept(leftEval);
    int result1 = leftEval.result();

    // visit right node
    right = node.getRight();
    right->accept(rightEval);
    int result2 = rightEval.result();

    this->result_ = node.eval(result1,result2);
}

// Result, returns result
int Eval_Expr_Tree::result(void) const {
    return this->result_;
}