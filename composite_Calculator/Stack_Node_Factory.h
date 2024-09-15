// -*- C++ -*-
// Stack_Node_Factory.h 

#ifndef _Stack_Node_Factory_H_
#define _Stack_Node_Factory_H_

#include "../array_Files/Stack.h"
#include "Node_Command_Factory.h"



class Stack_Node_Factory :public Node_Command_Factory{ 

public: 
    // Default constructor with initializer
    Stack_Node_Factory(Stack<int> &s);

    // Deconstructor
    virtual ~Stack_Node_Factory (void);

    // Create number node
    virtual Number_Expr_Node * create_number_expr_node (int num);

    // Create Operator Nodes
    virtual Add_Expr_Node * create_add_expr_node (void);
    virtual Sub_Expr_Node * create_sub_expr_node (void);
    virtual Multiply_Expr_Node * create_multiply_expr_node (void);
    virtual Divide_Expr_Node * create_divide_expr_node (void);
    virtual Mod_Expr_Node * create_mod_expr_node (void);

    // Build Operator Nodes with initalizers
    virtual Add_Expr_Node * build_add_expr_node (Expr_Node *left, Expr_Node *right);
    virtual Sub_Expr_Node * build_sub_expr_node (Expr_Node *left, Expr_Node *right);
    virtual Multiply_Expr_Node * build_multiply_expr_node (Expr_Node *left, Expr_Node *right);
    virtual Divide_Expr_Node * build_divide_expr_node (Expr_Node *left, Expr_Node *right);
    virtual Mod_Expr_Node * build_mod_expr_node (Expr_Node *left, Expr_Node *right);

    // create Parenthesis Node
    virtual Parenthesis_Node * create_paren_node (int num);

    virtual Unary_Expr_Node * create_unary_expr_node (int num);

private:
    Stack<int> & s_;


};



#endif