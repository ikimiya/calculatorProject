// -*- C++ -*-
// Print_Inorder_Expression.h

#ifndef _PRINT_INORDER_EXPRESSION_H_
#define _PRINT_INORDER_EXPRESSION_H_

#include "Expr_Node_Visitor.h"
#include <iostream>

class Print_Inorder_Expression : public Expr_Node_Visitor {

public:
    Print_Inorder_Expression (std::ostream & out);
    virtual ~Print_Inorder_Expression (void);

    virtual void Visit_Number_Node (const Number_Expr_Node & node);
    
    // Methods for visiting concrete nodes
    virtual void Visit_Addition_Node (const Add_Expr_Node & node);
    virtual void Visit_Subtraction_Node (const Sub_Expr_Node & node);

    virtual void Visit_Multiplication_Node (const Multiply_Expr_Node & node);
    virtual void Visit_Division_Node (const Divide_Expr_Node & node);
    virtual void Visit_Modulus_Node (const Mod_Expr_Node & node);

private:

    // output stream
    std::ostream &out_;

    // Same for other concrete visitor patterns

};


#endif

