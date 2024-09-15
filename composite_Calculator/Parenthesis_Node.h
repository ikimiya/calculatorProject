// -*- C++ -*-
// Parenthesis_Node.h 

#ifndef _PARENTHESIS_NODE_H_
#define _PARENTHESIS_NODE_H_

#include "Expr_Node.h"

// not calculate but insert to stack
class Parenthesis_Node : public Expr_Node {

public:

    // Constructor
    Parenthesis_Node (void);

    // Initalizer
    Parenthesis_Node (int num);

    // Deconstructor
    virtual ~Parenthesis_Node (void);

    // accept
    virtual void accept (Expr_Node_Visitor &v);

    // eval
    virtual int eval (void);

    // getPrecedence
    int getPrecedence();

    // getID
    std::string getID();

private:
    std::string id_;

    int precedence;
}; 

#endif