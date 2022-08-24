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
    test->printoutV2();

    //remove head
    std::cout << "remove head" << std::endl;
    test->remove_head(); //removes the head of the list
    test->printoutV2();

    //remove tail
    std::cout << "remove tail" << std::endl;
    //linked list values are not deleted when removed from the list, below allows data to be saved
    std::cout << test->size();
    LinkedList::value_type newtt = test->remove_tail(); //removes the tail of the list
    std::cout <<"size: "<< test->size()<<std::endl;
    //test->remove_tail();
    std::cout << newtt.get_name() << std::endl; // prints the name of the account of the node removed from the list
    std::cout<<newtt.balance()<<std::endl; // prints the balance of the account of the node removed from the list

    test->printoutV2();
    //std::cout << "remove current" << std::endl;
    //test->move_to_head(); //move to the head of the list
    //std::cout<<test->get_current();
    //test->remove_current(); //removes the current node of the list

    //test->printout();





    //std::cout << test->get_current();
    //test->move_to_head(); //moves the current pointer to the head of the list
    //test->printout(); //prints the list
    return  0;
}