// -*- C++ -*-
// Expr_Tree.h

#ifndef _EXPR_TREE_H_

#define _EXPR_TREE_H_

// Create Expression Tree for builder
#include "Expr_Node.h"
#include "Expr_Node_Visitor.h"

class Expr_Tree {

public:
    // constructor    
    Expr_Tree(void);

    // Initalizer
    Expr_Tree(Expr_Node * root);

    // Deconstructor
    ~Expr_Tree(void);

    // Visitor to accept function
    virtual void accept(Expr_Node_Visitor &v);

    // Check if the root is null or not
    bool treeExist (void);

private:
    Expr_Node * root_;

};


#endif