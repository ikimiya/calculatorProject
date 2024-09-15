// -*- C++ -*-
// Add_Expr_Node.h 

#ifndef _ADD_EXPR_NODE_H_
#define _ADD_EXPR_NODE_H_

#include "Binary_Expr_Node.h"

class Add_Expr_Node : public Binary_Expr_Node {

public:
    // Default Constructor 
    Add_Expr_Node (void);
    
    // Initalizer constructor
    Add_Expr_Node (Expr_Node * left, Expr_Node *right);

    // Deconstructor
    virtual ~Add_Expr_Node (void);

    //eval based on add
    virtual int eval (int num1, int num2) const;

    // visitor accept add
    virtual void accept (Expr_Node_Visitor & v);

    // get precedence 
    int getPrecedence();

    // get the operator id
    std::string getID();

private:
    int precedence;
    std::string id_;

};


#endif