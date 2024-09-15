// -*- C++ -*-
// Stack_Node_Factory.cpp

#include "Stack_Node_Factory.h"

// Stack_Node_Factory (stack)
Stack_Node_Factory::Stack_Node_Factory(Stack<int> &s)
    :s_(s)
{

}

// ~Stack_Node_Factory
Stack_Node_Factory::~Stack_Node_Factory()
{

}

// Create Number Expr Node
Number_Expr_Node * Stack_Node_Factory::create_number_expr_node(int num)
{
    return new Number_Expr_Node(num);
}

// Create Add Expr Node
Add_Expr_Node * Stack_Node_Factory::create_add_expr_node()
{
    return new Add_Expr_Node();
}

// Create Sub Expr Node
Sub_Expr_Node * Stack_Node_Factory::create_sub_expr_node()
{
   return new Sub_Expr_Node();
}

// Create Divide Expr Node
Divide_Expr_Node * Stack_Node_Factory::create_divide_expr_node()
{
   return new Divide_Expr_Node();
}

// Create Multiply Expr Node
Multiply_Expr_Node * Stack_Node_Factory::create_multiply_expr_node()
{
    return new Multiply_Expr_Node();
}

// Create Mod Expr Node
Mod_Expr_Node * Stack_Node_Factory::create_mod_expr_node()
{
    return new Mod_Expr_Node();
}

// Build Add_Expr_Node
Add_Expr_Node * Stack_Node_Factory::build_add_expr_node(Expr_Node *left, Expr_Node *right)
{
    return new Add_Expr_Node(left,right);
}

// Build Sub_Expr_Node
Sub_Expr_Node * Stack_Node_Factory::build_sub_expr_node(Expr_Node *left, Expr_Node *right)
{
   return new Sub_Expr_Node(left,right);
}

// Build divide_expr_node
Divide_Expr_Node * Stack_Node_Factory::build_divide_expr_node(Expr_Node *left, Expr_Node *right)
{
   return new Divide_Expr_Node(left,right);
}

// Build multiply_expr_node
Multiply_Expr_Node * Stack_Node_Factory::build_multiply_expr_node(Expr_Node *left, Expr_Node *right)
{
    return new Multiply_Expr_Node(left,right);
}

// build mode_expr_node
Mod_Expr_Node * Stack_Node_Factory::build_mod_expr_node(Expr_Node *left, Expr_Node *right)
{
    return new Mod_Expr_Node(left,right);
}

// create unary_Expr_node
Unary_Expr_Node * Stack_Node_Factory::create_unary_expr_node(int num)
{
    return new Unary_Expr_Node();
}

// create Parentehsis Node
Parenthesis_Node * Stack_Node_Factory::create_paren_node(int num)
{
    return new Parenthesis_Node(num);
}
