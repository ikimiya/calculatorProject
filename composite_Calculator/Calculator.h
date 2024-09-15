// -*- C++ -*-
// Caculator.h 

#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <string>
#include <sstream>
#include <iostream>

#include <exception>
#include <stdexcept>

#include "Expr_Builder.h"
#include "Expr_Tree_Builder.h"
#include "Eval_Expr_Tree.h"
class Calculator {

public:

    // Default Constructor
    Calculator(void);

    // Deconstructor
    ~Calculator(void);

    // check if isNumber
    bool isNumber(const std::string& str);

    // check if isOperator
    bool isOperator(const std::string & str);

    // check if the input is valid
    bool validator (const std::string & str);

    // find the size of input without " "
    int findSize(const std::string& str);

    // evaluate the expression
    int evaluate (const std::string &infix,Expr_Tree_Builder &build);

    // parse the expression and build the tree
    bool parse_expr(const std::string &infix,Expr_Tree_Builder &build);

    // Start program
    void Start(void);
    
};

#endif 