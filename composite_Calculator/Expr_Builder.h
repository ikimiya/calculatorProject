// -*- c++ -*-
// Expr_Builder.h

#ifndef _EXPR_BUILDER_H_
#define _EXPR_BUILDER_H_

#include <iostream>
#include "Expr_Node.h"
#include "Expr_Tree.h"

#include "Number_Expr_Node.h"

// include Operators
#include "Add_Expr_Node.h"
#include "Sub_Expr_Node.h"
#include "Multiply_Expr_Node.h"
#include "Divide_Expr_Node.h"
#include "Mod_Expr_Node.h"
#include "Parenthesis_Node.h"

#include "Stack_Node_Factory.h"

class Expr_Builder{

public:

    // Constructor
    Expr_Builder(void);

    // Deconstructor
    virtual ~Expr_Builder(void);

    // pure virutal for start expression 
    virtual void start_expression (void) = 0;

    // pure virtual for builders
    virtual void build_number (int n) = 0;
    virtual void build_add_operator (void) = 0;
    virtual void build_subtract_operator (void) = 0;
    virtual void build_multiply_operator (void) = 0;
    virtual void build_divide_operator(void) = 0;
    virtual void build_mod_operator(void) = 0;

    // pure virtual for open and close parenthesis
    virtual void build_open_parenthesis (void) = 0;
    virtual void build_close_parenthesis (void) = 0;

    virtual Expr_Tree * get_expression (void) = 0;

};

#endif 