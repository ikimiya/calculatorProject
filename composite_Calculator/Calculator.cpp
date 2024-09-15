// -*- C++ -*-
// Caculator.cpp

#include "Calculator.h"
#include <exception>
#include <stdexcept>

// Calculator
Calculator::Calculator(void)
{

}

// ~Calculator
Calculator::~Calculator(void)
{

}

// isNumber
bool Calculator::isNumber(const std::string& str)
{
    for(int i = 0; i < str.length();i++){
        if(str[i] == '(' || str[i] == ')'){
            return false;
        }else{
            if (std::isdigit(str[i])){
                return true;
            }
        }
    }
    return false;
}

// isOperator
bool Calculator::isOperator(const std::string & str)
{
    if(str == "+" || str == "-" || str == "*" || str == "/" || str == "%"){
        return true;
    }
    return false;
}

// validator
bool Calculator::validator(const std::string &str)
{
    std::string infix = str;
    std::string token;

    std::istringstream input(str); 

    int tokenSize = findSize(str);
    int startSize = 0;

    while (!input.eof ()) {
        input >> token;
        if(!(token == " ")){
            startSize++;
        }
    }

    if(tokenSize != startSize){
        return false;
    }
    else if (str[0] == ' '){
        return false;
    }
    else if (isOperator(&infix[0])){    
        return false;
    }
    else if (!isNumber(str) && (str[0] != '(')){ 
        return false;
    }
    else if(str[str.size() - 1] == ' '){  
        return false;
    }
    else if(str.length() == 1){
        return false;
    }
    else{  
        return true;
    }

}

// findSize
int Calculator::findSize(const std::string& str)
{
    std::istringstream input(str); 
    std::string token;

    int size = 0;
    int maxSize = str.size() - 1;

    // check if there is leading zero
    if(str[maxSize] == ' '){
        size = -1;
    }

    while (!input.eof ()) {
            input >> token;
            size++;
    }
    return size;

}

// evaluate
int Calculator::evaluate(const std::string &infix,Expr_Tree_Builder &build)
{
    // call evaluator tree
    Eval_Expr_Tree evaluate;

    // parse expression to create tree 
    this->parse_expr(infix,build);

    Expr_Tree * exprTree = build.get_expression();

    // Use visitor pattern to accept root
    exprTree->accept(evaluate);

    int result = evaluate.result();

    return result;
}

// Parse Expression
bool Calculator::parse_expr(const std::string & infix,Expr_Tree_Builder &builder)
{
    int size = findSize(infix);

    std::istringstream input (infix);
    std::string token;

    builder.start_expression();
    int count = 0;

    while(!input.eof() && count < size){
        input >> token;
        // Build Operators
        if (token == "+"){
            builder.build_add_operator();
        }else if (token == "-"){
            builder.build_subtract_operator();
        }else if (token == "*"){
            builder.build_multiply_operator();
        }else if (token == "/"){
           builder.build_divide_operator();
        }else if (token == "%"){
            builder.build_mod_operator();
        // Build Parenthesis
        }else if (token == "("){
            builder.build_open_parenthesis();
        }else if (token == ")"){
            builder.build_close_parenthesis();
        // Build Number
        }else if(isNumber(token)){
            int numToken = std::stoi(token);
            builder.build_number(numToken);      
        }else{
            std::runtime_error("Broken Operator False"); // error message
        }
        
    }   
    // build remaining roots
    builder.constructRoot();

    return true;

}

// Start
void Calculator::Start(){

    std::string infix_;
    bool keepGoing = true;
    std::string calcInputMenu_ = "Please Enter Calculator Input: ";

    Expr_Tree_Builder builder;

    while(keepGoing){

        std::cout << calcInputMenu_;
        std::getline(std::cin,infix_);

        if(infix_ == "QUIT")  
        {
            keepGoing = false;
        }else{
            if(validator(infix_)){
                int RESULT = evaluate(infix_,builder);
                std::cout << "RESULT: " << RESULT << std::endl;
            }else{
                std::cout << "Bad Input" << std::endl;
            }
    
        } // end if == quit if/else
    }

}