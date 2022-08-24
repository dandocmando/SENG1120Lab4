//
// Created by Dan on 17/08/2022.
//

#include "account.h"
#include <string>
#ifndef CPLUSPLUS_NODE_H
#define CPLUSPLUS_NODE_H


class Node {

public:
    typedef account value_type; //value_type is a class that is defined in account.h

    explicit Node(const value_type& dataIn, Node* nextIn = NULL, Node* prevIn = NULL);
    Node();

    // setters and getters for next and previous nodes
    void set_next(Node* n);
    void set_prev(Node* p);

    Node* get_next() const;
    Node* get_prev() const;
    value_type get_data() const; // returns the data in the node, needs ostream operator to be used

private:
    Node* prev; // pointer to previous Node in list
    Node* next; // pointer to next Node in list
    value_type data; //value_type is a class that is defined in account.h
};

std::ostream& operator <<(std::ostream& out, const Node::value_type& d); //overloads the ostream operator to print the data in the node

#endif //CPLUSPLUS_NODE_H
