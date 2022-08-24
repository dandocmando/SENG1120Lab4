//
// Created by Dan on 23/08/2022.
//

#include "LinkedList.h"
#include "account.h"
#include <string>
#include <iostream>

int main(){
    LinkedList* test = new LinkedList(); //create a new linked list

    for(int i=0;i<10;i++){ //add 10 nodes to the list
        account newaccount = account("John",i*10);
        test->add_to_head(newaccount); //adds the new account to the head of the list
    }

    // function tests for linked list class

    // add to head
    std::cout << "add to head" << std::endl;
    test->printout();
    account testacc = account("testacc",100); //create a new account
    test->add_to_head(testacc); //add the new account to the head of the list

    account testacc2 = account("testacc2",200); //create a new account

    //add to tail
    std::cout << "add to tail" << std::endl;
    test->add_to_tail(testacc2); //add the new account to the tail of the list
    test->printout();

    //remove head
    std::cout << "remove head" << std::endl;
    test->remove_head(); //removes the head of the list
    test->printout();

    //remove tail
    std::cout << "remove tail" << std::endl;
    test->remove_tail(); //removes the tail of the list
    test->printout();




    //std::cout << test->get_current();
    //test->move_to_head(); //moves the current pointer to the head of the list
    test->printout(); //prints the list
    return  0;
}