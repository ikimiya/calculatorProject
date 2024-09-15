// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Stack.h"

#define mSize 30

//
// Stack
//
template <typename T>
Stack <T>::Stack (void)
    : stArray_(mSize),
    stack_top_ (-1)
{

}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
    : stack_top_(stack.stack_top_)
{
 
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
    
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    // push stack is on top of stack
    if(is_empty()){
        stack_top_ = 0;
        stArray_[stack_top_] = element;
    }else{
        stack_top_++;
        stArray_[stack_top_] = element;
    }
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    if(is_empty()){
        throw empty_exception();
    } else{
        stack_top_--;
        if(is_empty()){  //check if all empty
            return;
        }
    }
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    //check referenec to self
    if(this == &rhs){
        return *this;
    }else{  // copy
        for(int i = 0; i < this->stack_top_;i++){
            stArray_.data[i] = rhs.data_[i];
        }
    }
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    if(is_empty()){
        return;
    }
    while(!is_empty()){
        this->pop();
    }
    // remove all element from stack / reset
}
