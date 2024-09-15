// -*- C++ -*-
// Node_Command_Factory.h 

#ifndef _Node_Command_Factory_H_
#define _Node_Command_Factory_H_

#include "Number_Expr_Node.h"
#include "Sub_Expr_Node.h"
#include "Add_Expr_Node.h"
#include "Multiply_Expr_Node.h"
#include "Divide_Expr_Node.h"
#include "Mod_Expr_Node.h"
#include "Unary_Expr_Node.h"
#include "Parenthesis_Node.h"


class Node_Command_Factory{ 

public: 
    // Default constructor
    Node_Command_Factory(void);

    virtual ~Node_Command_Factory (void) = 0;

    virtual Number_Expr_Node * create_number_expr_node (int num) = 0;

    // Pure Virtual for creating nodes
    virtual Add_Expr_Node * create_add_expr_node (void) = 0;
    virtual Sub_Expr_Node * create_sub_expr_node (void) = 0;
    virtual Multiply_Expr_Node * create_multiply_expr_node (void) = 0;
    virtual Divide_Expr_Node * create_divide_expr_node (void) = 0;
    virtual Mod_Expr_Node * create_mod_expr_node (void) = 0;
  
    // Pure Virtual for creating nodes with initalizer that setleft and setRight
    virtual Add_Expr_Node * build_add_expr_node (Expr_Node *left, Expr_Node *right) = 0;
    virtual Sub_Expr_Node * build_sub_expr_node (Expr_Node *left, Expr_Node *right) = 0;
    virtual Multiply_Expr_Node * build_multiply_expr_node (Expr_Node *left, Expr_Node *right) = 0;
    virtual Divide_Expr_Node * build_divide_expr_node (Expr_Node *left, Expr_Node *right) = 0;
    virtual Mod_Expr_Node * build_mod_expr_node (Expr_Node *left, Expr_Node *right) = 0;

    virtual Unary_Expr_Node * create_unary_expr_node (int num) = 0;
    virtual Parenthesis_Node * create_paren_node (int num) = 0;

private:
    Node_Command_Factory (const Node_Command_Factory &);
    const Node_Command_Factory & operator = (const Node_Command_Factory &);
};



#endif