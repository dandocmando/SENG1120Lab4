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
    Node* temp = head; //create a temporary node to traverse the list

    while(temp != NULL){ //while the temporary node is not null
        std::cout << temp->get_data() << " "; //print out the data in the node
        temp = temp->get_next(); //point temp node to the next node


    }
    std::cout << std::endl;
}

void Node::set_data(const Node::value_type& d) { //set the data in the node
    data = d;

}

bool Node::delete_node(const std::string& accName) { //deletes a node from the list if it has the same name as the parameter
    if (get_data().get_name() == accName) {
        return true;


    }
    return false;
}
