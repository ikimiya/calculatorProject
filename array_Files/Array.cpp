// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array <T>::Array (void)
    :Basic_Array<T>()
{
    // initalize Basic_Array<T>()
}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
    : Basic_Array<T>(length)
{
    // Initalizie Basic_Array<T>() with parameters
}

//
// Array (size_t, T)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
    : Basic_Array<T> (length,fill)
{
    // Use Basic_Array<T> lengthfill method
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array)
    : Basic_Array<T>(&array)
{
    // Copy Array Swap Pointers
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
Array <T>::~Array (void)
{

}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
    if(this == &rhs){
        return *this;
    }

    // check max array
    if(this->max_size_ < rhs.cur_size_){
        // Copy array switch pointers
        T* nArray_ = new T[rhs.cur_size_];
        for(int i = 0; i < this->max_size_; i++){   
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
T & Array <T>::operator [] (size_t index)
{
    if(index < 0 || index > this->cur_size_){
        throw std::out_of_range("exception");
    }
    return this->data_[index];  //return data_ at index
}

//
// operator [] 
//
template <typename T>
const T & Array <T>::operator [] (size_t index) const
{
    if(index < 0 || index > this->cur_size_){
        throw std::out_of_range("exception");
    }
    return this->data_[index];  //return data_ at index
}

//
// get
//
template <typename T>
T Array <T>::get (size_t index) const
{
    // Range [bigger than zero, less than current size]
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
void Array <T>::set (size_t index, T value)
{
    if(index < 0 || index > this->cur_size_){
        throw std::out_of_range("Out of range ::Set");
    }else{
       this->data_[index] = value;
    }   
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
    if(new_size > 0 && new_size < this->cur_size_){   // nSize between [0-curent]
        this->cur_size_ = new_size;
    }else if(new_size > this->cur_size_ && new_size < this->max_size_){ // for newsize between [cur-max] 
        this->cur_size_ = new_size;
    }else if(new_size > this->max_size_){  // array enlarged nSize [mSize-nSize]
        T* nArray_ = new T[new_size];
        for(int i = 0; i < new_size; i++){   // copy values over
            nArray_[i] = this->data_[i];
        }
        T* temp = this->data_;
        this->data_ = nArray_;
        nArray_ = temp;
        delete[] nArray_;
        this->max_size_ = new_size;
    }else if(new_size == this->cur_size_){ 
        return; // nothing happens
    }   // end if else 

}

//
// find (T)
//
template  <typename T>
int Array <T>::find (T value) const
{
    int i = 0;
    // loop each T array if equals to ch input
    do{
        if(this->data_[i] == value){
            return i; // character found return index 
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
int Array <T>::find (T val, size_t start) const
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
bool Array <T>::operator == (const Array & rhs) const
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
bool Array <T>::operator != (const Array & rhs) const
{
    return !(*this == &rhs);
}

//
// fill
//
template <typename T>
void Array <T>::fill (T value)
{   
    for(int i =0; i < this->cur_size_; i++){
        this->data_[i] = value;
    }
}

//
// shrink
//
template <typename T>
void Array<T>::shrink (void)
{
    if(this->cur_size_ < this->max_size_){
        // Create new array, copy data, and swap pointers
        T *nArray_ = new char[this->cur_size_];
        for(int i = 0; i < this->max_size_; i++){  
            nArray_[i] = this->data_[i];
        }
        T* temp = this->data_;
        this->data_ = nArray_;
        nArray_ = temp;
        delete[] nArray_;
    }
}
