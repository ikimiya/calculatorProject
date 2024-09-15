// -*- c++ -*-
// Expr_Tree_Builder.cpp

#include "Expr_Tree_Builder.h"

// Expr_Tree_Builder()
Expr_Tree_Builder::Expr_Tree_Builder(void)
    :cmd (0),
    factory(this->store_)
{

}

// ~Expr_Tree_Builder
Expr_Tree_Builder::~Expr_Tree_Builder()
{
    delete this->tree_;
}

// Create a new Expr_Tree
void Expr_Tree_Builder::start_expression(void)
{
    // chechk if there is a tree
    if(!tree_->treeExist()){
        this->tree_ = new Expr_Tree();
    } else{
        std::runtime_error("Tree Already Exist");
    }
}

// build Number
void Expr_Tree_Builder::build_number(int num)
{
    cmd = factory.create_number_expr_node(num);
    build_tree(cmd); 
}

// build add operator
void Expr_Tree_Builder::build_add_operator()
{
    cmd = factory.create_add_expr_node();
    build_tree(cmd);
}

// build subtract operator
void Expr_Tree_Builder::build_subtract_operator()
{
    cmd = factory.create_sub_expr_node();
    build_tree(cmd);
}

// build multiply operator
void Expr_Tree_Builder::build_multiply_operator()
{
    cmd = factory.create_multiply_expr_node();
    build_tree(cmd);
}

// build divide operator
void Expr_Tree_Builder::build_divide_operator()
{
    cmd = factory.create_divide_expr_node();
    build_tree(cmd);
}

// build mod operator
void Expr_Tree_Builder::build_mod_operator()
{
    cmd = factory.create_mod_expr_node();
    build_tree(cmd);
}

// build open parenthesis
void Expr_Tree_Builder::build_open_parenthesis()
{
    cmd = factory.create_paren_node(1);
    build_tree(cmd);
}

// build close parenthesis
void Expr_Tree_Builder::build_close_parenthesis()
{
    cmd = factory.create_paren_node(2);
    build_tree(cmd);
}

// get Expression
Expr_Tree *Expr_Tree_Builder::get_expression()
{
    return this->tree_;
}

// build_tree
void Expr_Tree_Builder::build_tree(Expr_Node * cmd)
{
    if(cmd->getID() == "Numb"){
        nodeS_.push(cmd);
    }else if(cmd->getID() == "("){
        opS_.push(cmd);
    }
    else if(cmd->getID() == ")" && !opS_.is_empty() && !nodeS_.is_empty()){
        tree_builder(opS_.top()->getID());
    }
    else if (isOperator(cmd)){
        if((opS_.is_empty())){
            opS_.push(cmd);
        }else if (opS_.top()->getID() == "(" || opS_.top()->getPrecedence() <= cmd->getPrecedence()){
            opS_.push(cmd);
        } 
        else if (opS_.top()->getPrecedence() > cmd->getPrecedence()){
            tree_builder(opS_.top()->getID());
        }
    }
}

// constructRoot
void Expr_Tree_Builder::constructRoot(){
    
    // while stack not empty complete construct tree
    while(!opS_.is_empty()){
        tree_builder(opS_.top()->getID());

        // make remain the root of the tree
        if(opS_.is_empty()){
            Expr_Node * treeRoot = nodeS_.top();
            nodeS_.pop();
            this->tree_ = new Expr_Tree(treeRoot);
        }
    }

    // for if op stack is already empty
    if(!nodeS_.is_empty()){
        Expr_Node * treeRoot = nodeS_.top();
        nodeS_.pop();
        this->tree_ = new Expr_Tree(treeRoot);
    }
    
}

// isOperator
bool Expr_Tree_Builder::isOperator(Expr_Node * cmd)
{
    std::string opValue = cmd->getID();
    if(opValue == "+" || opValue == "-" || opValue == "*" || opValue == "/" || opValue == "%"){
        return true;
    }
    return false;
}

// isNumber
bool Expr_Tree_Builder::isNumber(Expr_Node * cmd)
{
    std::string isNum = cmd->getID();
    if(isNum == "Numb"){
        return true;
    }
    return false;
}

// tree_builder
void Expr_Tree_Builder::tree_builder(std::string op)
{
    // if loop to check and build the root
    if(op == "+"){
        // pop operator from stack
        opS_.pop();  
        Expr_Node * rightChild = nodeS_.top();
        nodeS_.pop();
        Expr_Node * leftChild = nodeS_.top();
        nodeS_.pop();
        Expr_Node * root = factory.build_add_expr_node(leftChild,rightChild);
        
        nodeS_.push(root);
        
        if(!opS_.is_empty()){
            if(opS_.top()->getID() == "("){
                opS_.pop();
            }
        }
    }
    else if (op == "-"){
        opS_.pop();  
        Expr_Node * rightChild = nodeS_.top();
        nodeS_.pop();
        Expr_Node * leftChild = nodeS_.top();
        nodeS_.pop();
        cmd = factory.build_sub_expr_node(leftChild,rightChild);

        nodeS_.push(cmd);

        if(!opS_.is_empty()){
            if(opS_.top()->getID() == "("){
                opS_.pop();
            }
        }

    }
    else if (op == "*"){
        opS_.pop();  
        Expr_Node * rightChild = nodeS_.top();
        nodeS_.pop();
        Expr_Node * leftChild = nodeS_.top();
        nodeS_.pop();
        cmd = factory.build_multiply_expr_node(leftChild,rightChild);

        nodeS_.push(cmd);

        if(!opS_.is_empty()){
            if(opS_.top()->getID() == "("){
                opS_.pop();
            }
        }

    }
    else if (op == "/"){
        opS_.pop();  
        Expr_Node * rightChild = nodeS_.top();
        nodeS_.pop();
        Expr_Node * leftChild = nodeS_.top();
        nodeS_.pop();
        cmd = factory.build_divide_expr_node(leftChild,rightChild);

        nodeS_.push(cmd);

        if(!opS_.is_empty()){
            if(opS_.top()->getID() == "("){
                opS_.pop();
            }
        }

    }
    else if (op == "%"){
        opS_.pop();  
        Expr_Node * rightChild = nodeS_.top();
        nodeS_.pop();
        Expr_Node * leftChild = nodeS_.top();
        nodeS_.pop();
        cmd = factory.build_mod_expr_node(leftChild,rightChild);

        nodeS_.push(cmd);

        if(!opS_.is_empty()){
            if(opS_.top()->getID() == "("){
                opS_.pop();
            }
        }
    }
    // if ( 5 ) 
    else if (op == "("){
        opS_.pop();

    }else{
        return;
    }

}