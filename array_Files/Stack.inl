// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
    // number of elements in stack
    return stArray_.size();
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
    // check empty if no elements
    if(is_empty()){
        throw empty_exception();
    }
    return stArray_[stack_top_];   
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
    if(stack_top_ == -1){
        return true;
    }else{
        return false;
    }
    // check if empty  true / false
}
