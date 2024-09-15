// -*- C++ -*-
// Expr_Node_Visitor.h 

#ifndef _EXPR_NODE_VISITOR_H_
#define _EXPR_NODE_VISITOR_H_

#include <iostream> 

class Add_Expr_Node;
class Sub_Expr_Node;
class Multiply_Expr_Node;
class Divide_Expr_Node;
class Mod_Expr_Node;
class Number_Expr_Node;
class Expr_Tree;
class Expr_Node_Visitor {

public:

    // Constructor
    Expr_Node_Visitor(void);

    // Deconstructor
    virtual ~Expr_Node_Visitor (void);

    // Methods for visiting concrete nodes
    virtual void Visit_Addition_Node (const Add_Expr_Node & node) = 0;
    virtual void Visit_Subtraction_Node (const Sub_Expr_Node & node) = 0;
    virtual void Visit_Multiplication_Node (const Multiply_Expr_Node & node) = 0;
    virtual void Visit_Division_Node (const Divide_Expr_Node & node) = 0;
    virtual void Visit_Modulus_Node (const Mod_Expr_Node & node) = 0;
    
    virtual void Visit_Number_Node (Number_Expr_Node & node) = 0;    

};


#endif