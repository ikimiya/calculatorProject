// -*- C++ -*-
// $Id: Array.inl 828 2011-02-07 14:21:52Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// size
//
template <typename T>
inline
size_t Basic_Array <T>::size (void) const
{
    return this->cur_size_; // the current size
}

//
// max_size
//
template <typename T>
inline
size_t Basic_Array <T>::max_size (void) const
{
    return this->max_size_; // the max size
}
