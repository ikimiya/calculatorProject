// -*- C++ -*-

#include "Queue.h"
#include <stdexcept>

#define mSize 30

// Queue
template <typename T>
Queue <T>::Queue (void)
    : queue_bot_ (-1), queue_top_(-1),
    quArray_(mSize)
{

}

//Queue
template <typename T>
Queue <T>::Queue (const Queue & queue)
    : queue_bot_ (queue.queue_bot_), 
    queue_top_ (queue.queue_top_)
{
    quArray_.max_size_ = queue.max_size_;
    quArray_.data_ = queue.data_;
}

// ~Queue
template <typename T>
Queue <T>::~Queue (void)
{
    
}

// enqueue
template <typename T>
void Queue <T>::enqueue (T element)
{
    if(is_empty()){   // if empty initalize values at zero and insert queue
        queue_bot_ = 0;
        queue_top_ = 0;
        quArray_[queue_top_] = element;
    }else{
        queue_top_++;   // else increase top and insert to queue
        quArray_[queue_top_] = element;
    }
}

// dequeue
template <typename T>
void Queue<T>::dequeue (void)
{
    if(is_empty()){ 
        throw empty_exception();
    }else{
        queue_bot_++;
        if(queue_bot_-1 == queue_top_){  // if equals queue reset
            queue_bot_ = -1;
            queue_top_ = -1;
        }
    }
}

// operator =
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
    //check referenec to self
    if(this == &rhs){
        return *this;
    }else{
        // copy 
        for(int i = 0; i < queue_top_; i++){
            quArray_.data_[i] = rhs.data_[i];
        }
    }
}

// clear
template <typename T>
void Queue <T>::clear (void)
{
    if(is_empty()){
        return;
    }
    while(!is_empty()){ // uses dequeue until its empty
        this->dequeue();
    }
}