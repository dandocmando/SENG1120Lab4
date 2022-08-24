//
// Created by Dan on 17/08/2022.
//

#include <iostream>
#include "Node.h"

//setters and getter implementation for next and previous nodes
void Node::set_next(Node* n){next = n;}
void Node::set_prev(Node* p){prev = p;}

Node* Node::get_next() const{return next;}
Node* Node::get_prev() const{return prev;}

Node::value_type Node::get_data() const{return data;} // returns the data in the node, needs ostream operator to be used

std::ostream& operator <<(std::ostream& out, const Node::value_type& d){ //overloads the ostream operator to print the data in the node
    out <<"Name: "<< d.get_name() << ", balance: " << d.balance()<<std::endl;
    return out; //returns the ostream object
}


Node::Node(const Node::value_type &dataIn, Node *nextIn, Node *prevIn) { //constructor for the node class, takes in the data and next and previous nodes
    data = dataIn;
    next = nextIn;
    prev = prevIn;
}

Node::Node() { //constructor for the node class
    next = NULL;
    prev = NULL;
}
