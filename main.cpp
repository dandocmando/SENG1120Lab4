#include <iostream>
#include <string>
#include "Node.h"
#include "account.h"

int main() {
    Node* head; //pointer to the head of the list
    Node* tail; //pointer to the tail of the list
    Node* n; //pointer to a node

    account* acc = new account("james",100.0); // create an account on the heap

    n = new Node; // create a new Node
    n->set_data(*acc); // set the data in the node
    n->set_prev(NULL); // set the previous node to null
    head = n; // set the head to the new node
    tail = n; // set the tail to the new node

    account* acc2 = new account("dan",250.0);
    n = new Node;
    n->set_data(*acc2);
    n->set_prev(tail);
    tail->set_next(n);
    tail = n;


    account* acc3 = new account("neek",499.0);
    n = new Node;
    n->set_data(*acc3);
    n->set_prev(tail);
    tail->set_next(n);
    tail = n;


    account* acc4 = new account("pinky",25.0);
    n = new Node;
    n->set_data(*acc4);
    n->set_prev(tail);
    tail->set_next(n);
    tail = n;
    tail->set_next(NULL); // set the next node to null, this is the end of the list

    Node::Printout(head); //prints out the list of nodes
    Node::delete_node("Dan");
    Node::Printout(head);


    return 0;
}
