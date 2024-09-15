// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Basic_Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Basic_Array <T>::Basic_Array (void)
    :cur_size_ (0),max_size_ (0), data_ (new T[0])
{
    // initalize array at 0
}

//
// Array (size_t)
//
template <typename T>
Basic_Array <T>::Basic_Array (size_t length)
    : cur_size_ (length), max_size_ (length), data_(0)
{
    if(length >= 0){
        this->data_ = new T[length];
        this->fill(0); // initalize filling all values to zero
    }// else array size not created less zero
}

//
// Array (size_t, T)
//
template <typename T>
Basic_Array <T>::Basic_Array (size_t length, T fill)
    : cur_size_ (length), max_size_(length), data_ (0)
{
    if(length >= 0){
        this->data_ = new T[length];
        this->fill(fill);
    }// else array size not created less zero
}

//
// Array (const Array &)
//
template <typename T>
Basic_Array <T>::Basic_Array (const Basic_Array & array)
    : cur_size_ (array.cur_size_),
    max_size_ (array.max_size_), 
    data_ (array.data_)
{
    // Copy Array Swap Pointer Value
    T *nArray_ = new T[this->cur_size_];
    for(int i = 0; i < array.cur_size_;i++){
        nArray_[i] = array.data_[i];
    }
    T* temp = this->data_;
    this->data_ = nArray_;
    nArray_ = temp;
    delete [] temp;
}

//
// ~Array
//
template <typename T>
Basic_Array <T>::~Basic_Array (void)
{
    delete[] this->data_;
}

//
// operator =
//
template <typename T>
const Basic_Array <T> & Basic_Array <T>::operator = (const Basic_Array & rhs)
{
    if(this == &rhs){
        return *this;
    }
    // check max array
    if(this->max_size_ < rhs.cur_size_){
        T* nArray_ = new T[rhs.cur_size_];
        for(int i = 0; i < this->max_size_; i++){   // copy values over
            nArray_[i] = rhs.data_[i];
        }
        T* temp = this->data_;
        this->data_ = nArray_;
        nArray_ = temp;
        delete [] temp;
    }
    return *this;
}

//
// operator []
//
template <typename T>
T & Basic_Array <T>::operator [] (size_t index)
{
    if(index < 0 || index > this->cur_size_){
        throw std::out_of_range("exception");
    }
    return this->data_[index];
}

//
// operator [] 
//
template <typename T>
const T & Basic_Array <T>::operator [] (size_t index) const
{
    if(index < 0 || index > this->cur_size_){
        throw std::out_of_range("exception");
    }
    return this->data_[index];
}

//
// get
//
template <typename T>
T Basic_Array <T>::get (size_t index) const
{
    if(index < 0 || index > this->cur_size_){
        throw std::out_of_range("Out of range ::Get");
    }else{
        return this->data_[index];
    }
}

//
// set
//
template <typename T>
void Basic_Array <T>::set (size_t index, T value)
{
    if(index < 0 || index > this->cur_size_){
        throw std::out_of_range("Out of range ::Set");
    }else{
       this->data_[index] = value;  // zero based index start 0
    }
}

//
// find (T)
//
template  <typename T>
int Basic_Array <T>::find (T value) const
{
    int i = 0;
    // loop each T array if equals to ch input
    do{
        if(this->data_[i] == value){
            return i; // return index character found
        } else if(i == this->cur_size_ && this->data_[i] != value){
            return -1;  // character not found
        }i++;
    }
    while(i < this->cur_size_);
    return -1;
}

//
// find (T, size_t) 
//
template <typename T>
int Basic_Array <T>::find (T val, size_t start) const
{
    if(start < 0 || start > this->cur_size_){
        throw std::out_of_range("exception");
    }
    // while loop to check index values
    do{
        if(this->data_[start] == val){
            return start; 
        } start++;
    }
    while(start < this->cur_size_);
    if(start == this->cur_size_){
        return -1;  // character not found
    }
    return 0;  
}

//
// operator ==
//
template <typename T>
bool Basic_Array <T>::operator == (const Basic_Array & rhs) const
{
    // self compare
    if(this == &rhs){
        return true;
    }
    // arraysize same
    if(this.cur_size_ != rhs.cur_size_){
        return false;
    }
    // check each element and value
    for(int i = 0; i < rhs.cur_size_;i++){
        if(this->data_[i] != rhs.data_[i]){
            return false;
        }
    }
    return true;
}

//
// operator !=
//
template <typename T>
bool Basic_Array <T>::operator != (const Basic_Array & rhs) const
{
    return !(*this == &rhs);
}

//
// fill
//
template <typename T>
void Basic_Array <T>::fill (T value)
{   
    // + 1 to loop all array
    for(int i =0; i < this->cur_size_; i++){
        this->data_[i] = value;
    }
}
