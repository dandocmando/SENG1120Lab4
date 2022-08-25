//
// Created by Daniel Ferguson on 25/8/2022.
//

#include "LinkedList.h"
#include "account.h"
#include <string>
#include <iostream>

int main() {
    LinkedList *test = new LinkedList(); //create a new linked list

    for (int i = 0; i < 10; i++) { //add 10 nodes to the list
        account newaccount = account("John", i * 10);
        test->add_to_head(newaccount); //adds the new account to the head of the list
    }


    account testacc = account("testacc", 100); //create a new account
    test->printout();
    test->add_to_tail(testacc); //create a new account
    test->printout();
    account testacc2 = account("testacc2", 200); //create a new account
    test->add_to_tail(testacc2); //add the new account to the tail of the list
    test->printout();

    //test->remove_head();
    //test->remove_head();
    test->printout();
    test->remove_tail();
    test->remove_tail();
    test->remove_tail();
    test->remove_tail();
    test->printout();

    test->printReverse();
    test->printCurrent();

}