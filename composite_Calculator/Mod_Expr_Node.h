// -*- C++ -*-
// Mod_Expr_Node.h 

#ifndef _MOD_EXPR_NODE_H_
#define _MOD_EXPR_NODE_H_

#include "Binary_Expr_Node.h"

class Mod_Expr_Node : public Binary_Expr_Node {

public:
    // Constructor
    Mod_Expr_Node (void);

    // Initializer
    Mod_Expr_Node (Expr_Node * left, Expr_Node *right);

    // Deconsturctor
    virtual ~Mod_Expr_Node (void);

    // eval based on Mod 
    virtual int eval (int num1, int num2) const;

    // accept Visitor for Mod Node
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