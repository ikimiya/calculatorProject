// -*- C++ -*-
// Unary_Expr_Node.h 

#ifndef _UNARY_EXPR_NODE_H_
#define _UNARY_EXPR_NODE_H_

#include "Expr_Node.h"

class Unary_Expr_Node : public Expr_Node {

public:

    Unary_Expr_Node (void);
    Unary_Expr_Node (Expr_Node * child);
    virtual ~Unary_Expr_Node (void);

    virtual void accept (Expr_Node_Visitor &v);

    virtual int eval (void);
    virtual Expr_Node * getChild() const;

    int getPrecedence();
    std::string getID();

protected:
    Expr_Node * child_;
    int precedence;
    std::string id_;
}; 

#endif