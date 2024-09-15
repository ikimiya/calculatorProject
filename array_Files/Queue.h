// -*- C++ -*-

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "Array.h"
#include <exception>

template <typename T>
class Queue: public Array<T>
{
public:
    // typedef 
    typedef T type;

    class empty_exception : public std::exception
    {
    public:
        /// Default constructor.
        empty_exception (void)
        : std::exception () { }

        /**
         * Initializing constructor.
         *
         * @param[in]      msg         Error message.
         */
        empty_exception (const char * msg)
        : std::exception (msg) { }
    };

    // Default constructor
    Queue (void);

    // Copy Constructor
    Queue (const Queue & q);

    // destructor
    ~Queue (void);

    // Assingment Operator
    const Queue & operator = (const Queue &rhs);

    // add element to end of the elist
    void enqueue(T element);

    // remove element at fornt of list, if no elements in queue throw empty
    // simialrt to stack
    void dequeue (void);

    // chekc empty if empty true otherwise false
    bool is_empty (void) const;

    // top of queue
    T top (void) const;

    // back of queue
    T bot (void) const;

    // return numer of elemnt in queue; and
    size_t size(void) const;

    /// Remove all elements from the stack.
    void clear (void);

private:
    //member variabels

    //front 
    size_t queue_top_;
    // back
    size_t queue_bot_;

    Array<T> quArray_;   //use data and max size

};

// infile include
#include "Queue.inl"

// include source since template
#include "Queue.cpp"

#endif // define QUEUE_H_

