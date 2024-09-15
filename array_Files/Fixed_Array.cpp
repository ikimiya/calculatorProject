// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Fixed_Array
//

#define mSize 30

template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void)
    :Basic_Array<T> (mSize)
{
    // default constructor
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr)
    : Basic_Array<T> (&arr)
{
    for(int i = 0; i< this->max_size_;i++){
        this.data_[i] = arr.data_;
    }
	// copy constructor
}

//
// Fixed_Array
//
template <typename T, size_t N>
template <size_t M>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, M> & arr)
    : Basic_Array<T> (&arr)
{
    // initialize constructor ,any size as long same type
}

//
// Fixed_Array
//

template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill) 
{
    // uses Basic_Array fill method
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
    
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
    //Check Self Assingment
    if(this = *rhs){
        return *this;
    }else{
        for(int i = 0; i < rhs.cur_size_;i++){
            this->data_[i] = rhs.data_[i];
        }
    }
    return *this;
}

//
// operator =
//
template <typename T, size_t N>
template <size_t M>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, M> & rhs)
{
    //Check Self Assignment
    if(this = *rhs){
        return *this;
    }else{
        for(int i = 0; i < rhs.cur_size_;i++){
            this->data_[i] = rhs.data_[i];
        }
    }
    return *this;
}
