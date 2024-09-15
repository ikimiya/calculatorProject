// -*- C++ -*-
// Divide_Expr_Node.h 

#ifndef _DIVIDE_EXPR_NODE_H_
#define _DIVIDE_EXPR_NODE_H_

#include "Binary_Expr_Node.h"

class Divide_Expr_Node : public Binary_Expr_Node {

public:

    // Constructor
    Divide_Expr_Node (void);

    // Initalizer
    Divide_Expr_Node (Expr_Node * left, Expr_Node *right);

    // Deconstructor
    virtual ~Divide_Expr_Node (void);

    // Eval based on division
    virtual int eval (int num1, int num2) const;

    // Visitor accept divison node
    virtual void accept (Expr_Node_Visitor & v);

    // return Precendence
    int getPrecedence();

    // return id
    std::string getID();

private:
    int precedence;
    std::string id_;
};


#endif