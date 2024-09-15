// -*- C++ -*-
// Eval_Expr_Tree.h

#ifndef _EVAL_EXPR_TREE_H_
#define _EVAL_EXPR_TREE_H_

#include "Expr_Node_Visitor.h"

#include "Add_Expr_Node.h"
#include "Sub_Expr_Node.h"
#include "Multiply_Expr_Node.h"
#include "Divide_Expr_Node.h"
#include "Mod_Expr_Node.h"
#include "Number_Expr_Node.h"

#include "Expr_Tree.h"

class Eval_Expr_Tree : public Expr_Node_Visitor{

public:

    // Constructor
    Eval_Expr_Tree (void);

    // Deconstructor
    virtual ~Eval_Expr_Tree (void);

    // Methods for visiting concrete nodes
    virtual void Visit_Addition_Node (const Add_Expr_Node & node);

    virtual void Visit_Subtraction_Node (const Sub_Expr_Node & node);

    virtual void Visit_Multiplication_Node (const Multiply_Expr_Node & node);

    virtual void Visit_Modulus_Node (const Mod_Expr_Node & node);

    virtual void Visit_Division_Node (const Divide_Expr_Node & node);

    virtual void Visit_Number_Node (Number_Expr_Node & node);

    // result 
    int result (void) const;


private:
    int result_;
    // other for calcualting result

};

#endif
