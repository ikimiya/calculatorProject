// -*- C++ -*-
// Sub_Expr_Node.h 

#ifndef _SUB_EXPR_NODE_H_
#define _SUB_EXPR_NODE_H_

#include "Binary_Expr_Node.h"

class Sub_Expr_Node : public Binary_Expr_Node {
public:

    // Constructor
    Sub_Expr_Node (void);

    // Initalizer
    Sub_Expr_Node (Expr_Node * left, Expr_Node *right);

    // Deconstructor
    virtual ~Sub_Expr_Node (void);

    // Eval for Sub 
    virtual int eval (int num1, int num2) const;

    // Accept Visitor for sub
    virtual void accept (Expr_Node_Visitor & v);

    // get Precedence
    int getPrecedence();

    // get ID
    std::string getID();

private:
    int precedence;
    std::string id_;
};


#endif