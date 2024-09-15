// -*- C++ -*-
// Expr_Tree_Builder.h

#ifndef _EXPR_TREE_BUILDER_H_
#define _EXPR_TREE_BUILDER_H_

#include <iostream>
#include "Expr_Builder.h"
#include "../array_Files/Stack.h"

class Expr_Tree_Builder : Expr_Builder{

public:

    // Constructor
    Expr_Tree_Builder (void);

    // Deconstructor
    ~Expr_Tree_Builder (void);

    // Start Expression create new tree
    virtual void start_expression (void);

    // build operators to build commands
    virtual void build_number (int n);
    virtual void build_add_operator (void);
    virtual void build_subtract_operator (void);
    virtual void build_multiply_operator(void);
    virtual void build_divide_operator(void);
    virtual void build_mod_operator (void);

    // build open or closed parenthesis 
    virtual void build_open_parenthesis (void);
    virtual void build_close_parenthesis (void);

    // send command to build tree for nodes
    virtual void build_tree(Expr_Node * cmd);

    // construct the root with the leftover nodes
    void constructRoot();

    // return the tree
    virtual Expr_Tree * get_expression (void); 

    // check if is Operator
    bool isOperator(Expr_Node *cmd);

    // check if it is Number
    bool isNumber(Expr_Node *cmd);

    // build the trees based on string
    void tree_builder(std::string op);

private:
    // current state of expression tree
    Expr_Tree * tree_;

    // store factory
    Stack<int> store_;
    Stack_Node_Factory factory;

    // command
    Expr_Node * cmd;
    
    // OperatorStack
    Stack<Expr_Node*> opS_;

    // Nodes stack
    Stack<Expr_Node*> nodeS_;

};


#endif