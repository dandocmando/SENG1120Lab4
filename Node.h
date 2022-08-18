//
// Created by Dan on 17/08/2022.
//

#include "account.h"
#include <string>
#ifndef CPLUSPLUS_NODE_H
#define CPLUSPLUS_NODE_H


class Node {

public:
    typedef account value_type;

    // setters and getters for next and previous nodes
    void set_next(Node* n);
    void set_prev(Node* p);
    void set_data(const value_type& d);

    Node* get_next() const;
    Node* get_prev() const;
    value_type get_data() const; // returns the data in the node, needs ostream operator to be used

    static void Printout(Node* head); // prints out each Node in the list

    bool delete_node(const std::string& accName); // deletes a node from the list if it has the same name as the parameter

private:
    Node* prev; // pointer to previous Node in list
    Node* next; // pointer to next Node in list
    value_type data; //value_type is a class that is defined in account.h
};

#endif //CPLUSPLUS_NODE_H
