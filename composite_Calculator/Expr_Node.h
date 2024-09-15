// -*- C++ -*-
// Expr_Node.h 

#ifndef _EXPR_NODE_H_
#define _EXPR_NODE_H_

#include <iostream>

#include "Expr_Node_Visitor.h"

class Expr_Node {

    public:

        // Constructor
        Expr_Node (void);

        // Deconstructor
        virtual ~Expr_Node (void);

        // pure virutal eval
        virtual int eval (void) = 0;

        // pure virutal to support visitor
        virtual void accept (Expr_Node_Visitor & v) = 0;

        // pure virtual get Precendence
        virtual int getPrecedence() = 0;

        // pure virutal get ID
        virtual std::string getID() = 0;


}; 



#endif 