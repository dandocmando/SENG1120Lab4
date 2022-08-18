#include <iostream>
#include <string>
#include "Node.h"
#include "account.h"

int main() {
    Node* head;
    Node* tail;
    Node* n;

    account* acc = new account("james",100.0);

    n = new Node;
    n->set_data(*acc);
    n->set_prev(NULL);
    head = n;
    tail = n;

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
    tail->set_next(NULL);

    Node::Printout(head);


    return 0;
}
