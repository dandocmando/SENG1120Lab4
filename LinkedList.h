//
// Created by Dan on 22/08/2022.
//

#ifndef CPLUSPLUS_LINKEDLIST_H
#define CPLUSPLUS_LINKEDLIST_H


#include "Node.h"
#include <string>

class LinkedList {

public:
    typedef account value_type;

    LinkedList();
    ~LinkedList();


    void add_to_head(value_type& d);
    void add_to_tail(value_type& d);
    void add_current(value_type& d);
    value_type remove_head();
    value_type remove_tail();
    value_type remove_current();

    void start();
    void end();
    void forward();
    void backward();
    value_type& get_current();
    int size();

private:
    Node* head;
    Node* tail;
    Node* current;
    //int count;
    value_type data; //value_type is a class that is defined in account.h
};


};


#endif //CPLUSPLUS_LINKEDLIST_H
