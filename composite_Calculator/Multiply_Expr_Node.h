// -*- C++ -*-
// Multiply_Expr_Node.h 

#ifndef _MULTIPLY_EXPR_NODE_H_
#define _MULTIPLY_EXPR_NODE_H_

#include "Binary_Expr_Node.h"

class Multiply_Expr_Node : public Binary_Expr_Node {

public:

    // Constructor
    Multiply_Expr_Node (void);
    
    // Initializer
    Multiply_Expr_Node (Expr_Node * left, Expr_Node *right);

    // Deconstructor
    virtual ~Multiply_Expr_Node (void);

    // eval based on multiply
    virtual int eval (int num1, int num2) const;

    // accept visitor for multiply nodes
    virtual void accept (Expr_Node_Visitor & v);

    // getPrecedence
    int getPrecedence();
    
    // getID
    std::string getID();

private:
    int precedence;
    std::string id_;

};


#endif