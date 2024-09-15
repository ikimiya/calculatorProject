// -*- C++ -*-

//size get
template <typename T>
size_t Queue <T>::size (void) const
{
    // elements in Queue
    return quArray_.size(); 
}

// top of stack
template <typename T>
inline
T Queue <T>::top (void) const
{
    // Is the top of the array, the front
    if(is_empty()){
        throw empty_exception();
    }
    return quArray_[queue_top_];
}

template <typename T>
inline
T Queue <T>::bot (void) const
{
    // Is the bottom of array, the back
    if(is_empty()){
        throw empty_exception();
    }
    return quArray_[queue_bot_];
}


//ISempty
template <typename T>
bool Queue<T>::is_empty (void) const
{
    if(this->queue_top_ == -1 && this->queue_bot_ == -1){   // check if both empty
        return true;
    }else{
        return false;
    }
}