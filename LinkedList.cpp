//
// Created by Dan on 22/08/2022.
//

#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList(){
    head_ptr = NULL;
    tail_ptr = NULL;
    lst_len = 0;

};
LinkedList::LinkedList(value_type& dataIn){
    head_ptr = new Node(dataIn);
    tail_ptr = head_ptr;
    lst_len = 1;


}
LinkedList::~LinkedList(){
    while(head_ptr !=NULL){ // loops while head_ptr isn't NULL
        remove_head(); // calls remove_head for each head that isn't NULL
    }
    tail_ptr=NULL; // after loop is complete assign tail_ptr to NULL
}


void LinkedList::add_to_head(value_type& d){
    if(lst_len==0){
        head_ptr = new Node(d);
        tail_ptr = head_ptr;
        lst_len=1;
    }
    else{
        Node* head_insert = new Node(d); //create a new node to insert into the list

        head_ptr->set_prev(head_insert); //sets the previous pointer of the head node to the new node
        head_insert->set_next(head_ptr); //sets the next pointer of the new node to the head node

        head_ptr = head_insert; //sets the head node to the new node
        lst_len++; //increments the length of the list

        head_insert = NULL; //deletes the new node
    }
}

void LinkedList::add_to_tail(value_type& d){
    if(lst_len==0){
        head_ptr = new Node(d); //create a new node to insert into the list
        tail_ptr=head_ptr; //sets the tail node to the new node
        lst_len=1; //increments the length of the list
    }
    else{
        Node* tail_insert = new Node(d); //create a new node to insert into the list

        tail_ptr->set_next(tail_insert); //sets the next pointer of the tail node to the new node
        tail_insert->set_prev(tail_ptr); //sets the previous pointer of the new node to the tail node

        tail_ptr = tail_insert; //sets the tail node to the new node

        lst_len++; //increments the length of the list
        tail_insert = NULL; //deletes the new node
    }
    current_ptr = tail_ptr; //sets the current node to the tail node
}

void LinkedList::add_current(value_type& d){}

LinkedList::value_type LinkedList::remove_head(){
    if(lst_len==0){ //if the list is empty
        //return NULL; //returns NULL
        std::cout<<"LinkedList has no Nodes"<<std::endl;
    }

    else if(lst_len==1){ //if the list has only one node
        value_type delData = head_ptr->get_data(); //gets the delData from the head node, this delData will be returned
        delete head_ptr; //deletes the head node (mem mgmnt)
        head_ptr=NULL; //sets the head node to null
        tail_ptr=NULL; //sets the tail node to null
        lst_len--; //decrements the length of the list
        return delData; //returns the delData
    }

    else{ //if the list has more than one node
        value_type delData = head_ptr->get_data();

        Node* tmp_head_ptr = head_ptr; //create a temporary node to hold the head node

        head_ptr = tmp_head_ptr->get_next(); //sets the head node to the next node
        head_ptr->set_prev(NULL); //sets the previous pointer of the new head node to NULL

        delete tmp_head_ptr;
        lst_len--;

        tmp_head_ptr=NULL; //sets the temporary node to null

        return delData;
    }
    current_ptr = head_ptr; //sets the current node to the head node
    return LinkedList::value_type();
}
LinkedList::value_type LinkedList::remove_tail(){
    if(lst_len==0){ //if the list is empty
        //return current_ptr->get_data();;
        std::cout<<"LinkedList has no Nodes"<<std::endl;
    }

    else if(lst_len==1){ //if the list has only one node
        value_type delData = tail_ptr->get_data(); //gets the delData from the tail node, this will be returned
        delete tail_ptr; //deletes the head node (mem mgmnt)
        head_ptr=NULL; //sets the head node to null
        tail_ptr=NULL; //sets the tail node to null
        lst_len--; //decrements the length of the list
        return delData; //returns the data
    }

    else{ //if the list has more than one node
        value_type delData = tail_ptr->get_data();

        Node* tmp_tail_ptr = tail_ptr; //create a temporary node to hold the tail node

        tail_ptr = tmp_tail_ptr->get_prev(); //sets the tail node to the next node
        tail_ptr->set_next(NULL); //sets the next pointer of the new tail node to null

        delete tmp_tail_ptr; //deletes the temporary node (mem mgmnt)

        lst_len--; //decrements the length of the list
        tmp_tail_ptr=NULL; //sets the temporary node to null


        return delData; //returns the data
    }
    current_ptr = head_ptr; //sets the current node to the tail node
    return LinkedList::value_type(); //returns empty account
}

LinkedList::value_type& LinkedList::remove_current(){
    if(lst_len==0){ //if the list is empty
        //return current_ptr->get_data();;
        std::cout<<"LinkedList has no Nodes"<<std::endl;
    }

    else if(lst_len==1){ //if the list has only one node
        value_type delData = current_ptr->get_data();
        delete head_ptr; //deletes the head node (mem mgmnt)
        head_ptr=NULL; //sets the head node to null
        tail_ptr=NULL; //sets the tail node to null
        lst_len--; //decrements the length of the list
        return delData;; //returns the data
    }

    else{ //if the list has more than one node
        std::cout << "current_ptr: " << current_ptr->get_data() << std::endl;

        value_type delData = current_ptr->get_data();
        std::cout << "test";

        Node* tmp_current_ptr = current_ptr; //create a temporary node to hold the current node
        std::cout << "test";

        //current_ptr = tmp_current_ptr->get_next(); //sets the current node to the next node
        std::cout << "test";
        if(current_ptr->get_prev() != NULL){
            //current_ptr->get_prev()->set_next(current_ptr->get_next()); //
            //current_ptr->get
            std::cout << "test";
        }
        else{
            //current_ptr->set_prev(NULL);
        }


        //delete tmp_current_ptr; //deletes the temporary node (mem mgmnt)
        std::cout << "test";


        lst_len--; //decrements the length of the list

        //tmp_current_ptr=NULL; //sets the temporary node to null
        std::cout << "test";
        return delData; //returns the data
    }
    //return LinkedList::value_type&; //returns empty account
}

void LinkedList::move_to_head(){
    current_ptr = head_ptr;
}

void LinkedList::move_to_tail(){
    current_ptr = tail_ptr;
}

void LinkedList::forward(){
    if(current_ptr->get_next() != NULL){
        current_ptr = current_ptr->get_next();
    }
    else{
        std::cout << "Next Node is null.";
    }
}

void LinkedList::backward(){
    if(current_ptr->get_prev() !=NULL){
        current_ptr = current_ptr->get_prev();
    }
    else{
        std::cout << "Previous Node is null.";
    }

}

LinkedList::value_type LinkedList::get_current(){
    return current_ptr->get_data();
}

int LinkedList::size() const{
    return lst_len;
}

void LinkedList::printout(){
    Node* tmp_ptr = head_ptr; //create a temporary node to hold the head node
    std::cout << "LinkList Current Data:"<<std::endl;
    while(tmp_ptr!=NULL){ //while the temporary node is not null
        std::cout<<tmp_ptr->get_data();//<<std::endl; //print the data of the temporary node
        tmp_ptr = tmp_ptr->get_next(); //sets the temporary node to the next node
    }
    std::cout<<"Linklist End"<<std::endl<<std::endl;
}

void LinkedList::printoutV2() { //prints the list using the len of the list
    Node* tmp_ptr = head_ptr; //create a temporary node to hold the head node
    std::cout << "LinkList Current Data:"<<std::endl;
    for(int i=0; i<lst_len; i++){ //while the temporary node is not null
        std::cout<<tmp_ptr->get_data(); //print the data of the temporary node
        tmp_ptr = tmp_ptr->get_next(); //sets the temporary node to the next node
    }
    std::cout<<"Linklist End"<<std::endl<<std::endl;

}

void LinkedList::printReverse() {
    Node* tmp_ptr = tail_ptr; //create a temporary node to hold the tail node
    std::cout << "LinkList Current Data in Reverse:"<<std::endl;
    while(tmp_ptr!=NULL){ //while the temporary node is not null
        std::cout<<tmp_ptr->get_data();//<<std::endl; //print the data of the temporary node
        tmp_ptr = tmp_ptr->get_prev(); //sets the temporary node to the next node
    }
    std::cout<<"Linklist End"<<std::endl<<std::endl;

}

void LinkedList::printCurrent() {
    std::cout << "LinkList Single Node data:"<<std::endl;
    std::cout<<current_ptr->get_data();//<<std::endl; //print the data of the temporary node
    std::cout<<"Linklist End"<<std::endl<<std::endl;

}




