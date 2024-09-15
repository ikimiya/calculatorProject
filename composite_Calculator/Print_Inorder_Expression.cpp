// -*- C++ -*-
// Print_Inorder_Expression.cpp

#include "Print_Inorder_Expression.h"

#include <iostream>
#include <ostream>

Print_Inorder_Expression::Print_Inorder_Expression(std::ostream & out)
   :out_ (out)
{

}

Print_Inorder_Expression::~Print_Inorder_Expression (void){

}

void Print_Inorder_Expression::Visit_Addition_Node(const Add_Expr_Node & node){

}

void Print_Inorder_Expression::Visit_Subtraction_Node(const Sub_Expr_Node & node){

}

void Print_Inorder_Expression::Visit_Multiplication_Node(const Multiply_Expr_Node & node){

}

void Print_Inorder_Expression::Visit_Division_Node(const Divide_Expr_Node & node){

}

void Print_Inorder_Expression::Visit_Modulus_Node(const Mod_Expr_Node & node){

}

void Print_Inorder_Expression::Visit_Number_Node(const Number_Expr_Node & node)
{

}