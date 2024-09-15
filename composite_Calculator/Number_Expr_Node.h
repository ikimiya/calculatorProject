// -*- C++ -*-
// Number_Expr_Node.h 

#ifndef _NUMBER_EXPR_NODE_H_
#define _NUMBER_EXPR_NODE_H_

#include "Expr_Node.h"

class Number_Expr_Node : public Expr_Node {

public:

    // Constructor
    Number_Expr_Node (void);

    // Initalizer
    Number_Expr_Node (int num);

    // Deconstructor
    virtual ~Number_Expr_Node (void);
    
    // Accept visitor based on num
    virtual void accept(Expr_Node_Visitor & v);

    // eval to return number
    virtual int eval (void);

    // get ID
    std::string getID();

    // get Precendence
    int getPrecedence();

private:
    int precedence;
    std::string id_;

protected: 
    int num_;
    
}; 


#endif