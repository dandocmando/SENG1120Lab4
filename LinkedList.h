//
// Created by Dan on 22/08/2022.
//

#ifndef CPLUSPLUS_LINKEDLIST_H
#define CPLUSPLUS_LINKEDLIST_H


#include "Node.h"
#include "account.h"
#include <string>

class LinkedList {

public:
    typedef account value_type;

    LinkedList();
    LinkedList(value_type& dataIn);
    ~LinkedList();


    void add_to_head(value_type& d);
    void add_to_tail(value_type& d);
    void add_current(value_type& d);
    value_type remove_head();
    value_type remove_tail();
    value_type& remove_current();

    void move_to_head();
    void move_to_tail();
    void forward();
    void backward();
    value_type get_current();
    int size() const;

    void printout();
    void printoutV2();
    void printReverse();
    void printCurrent();

private:
    Node* head_ptr;
    Node* tail_ptr;
    Node* current_ptr;
    int lst_len;
    //value_type data; //value_type is a class that is defined in account.h
};





#endif //CPLUSPLUS_LINKEDLIST_H
