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

    void set_next(Node* n);
    void set_prev(Node* p);
    void set_data(const value_type& d);

    Node* get_next() const;
    Node* get_prev() const;
    value_type get_data() const;

    static void Printout(Node* head);

private:
    Node* prev;
    Node* next;
    value_type data;
};

#endif //CPLUSPLUS_NODE_H
