// -*- C++ -*-
// Binary_Expr_Node.h 

#ifndef _BINARY_EXPR_NODE_H_
#define _BINARY_EXPR_NODE_H_

#include "Expr_Node.h"

class Binary_Expr_Node : public Expr_Node {
    public:

    // Constructor
    Binary_Expr_Node (void);

    // Initalizer
    Binary_Expr_Node (Expr_Node *left,Expr_Node *right);

    // Deconstructor
    virtual ~Binary_Expr_Node (void);

    // eval left and right child for result
    virtual int eval (void);

    // pure virtual for eval
    virtual int eval (int num1, int num2)const = 0;

    // pure virutal for accept
    virtual void accept (Expr_Node_Visitor & v) = 0;

    // return left child
    virtual Expr_Node *getLeft() const;

    // return right child
    virtual Expr_Node *getRight() const;

    // set left child
    virtual void setLeft(Expr_Node * left);

    // set right child
    virtual void setRight(Expr_Node *right);

    // pure virtual for get Precedence
    virtual int getPrecedence() = 0;

    // pure virtual for get ID
    virtual std::string getID() = 0;

    private:
    Expr_Node * right_;
    Expr_Node * left_;
    
}; 


#endif