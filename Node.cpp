//
// Created by Dan on 17/08/2022.
//

#include <iostream>
#include "Node.h"

void Node::set_next(Node* n){next = n;}
void Node::set_prev(Node* p){prev = p;}


Node* Node::get_next() const{return next;}
Node* Node::get_prev() const{return prev;}


Node::value_type Node::get_data() const{return data;}

std::ostream& operator <<(std::ostream& out, const Node::value_type& d){
    out <<"Name: "<< d.get_name() << ", balance: " << d.balance()<<std::endl;
    return out;
}

void Node::Printout(Node* head){
    Node* temp = head;

    while(temp != NULL){
        std::cout << temp->get_data() << " ";
        temp = temp->get_next();


    }
    std::cout << std::endl;
}

void Node::set_data(const Node::value_type& d) {
    data = d;

}
