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
}

void LinkedList::add_current(value_type& d){}

LinkedList::value_type LinkedList::remove_head(){
    if(lst_len==0){ //if the list is empty
        return current_ptr->get_data(); //returns the data
    }

    else if(lst_len==1){ //if the list has only one node
        current_ptr=head_ptr; //sets the current node to the head node
        delete head_ptr; //deletes the head node (mem mgmnt)
        head_ptr=NULL; //sets the head node to null
        tail_ptr=NULL; //sets the tail node to null
        lst_len--; //decrements the length of the list
        return current_ptr->get_data(); //returns the data
    }

    else{ //if the list has more than one node
        Node* tmp_head_ptr = head_ptr; //create a temporary node to hold the head node
        head_ptr = tmp_head_ptr->get_next(); //sets the head node to the next node

        delete tmp_head_ptr; //deletes the temporary node (mem mgmnt)

        lst_len--; //decrements the length of the list

        tmp_head_ptr=NULL; //sets the temporary node to null

        //return tmp_head_ptr->get_data();; //returns the data
    }
}
LinkedList::value_type LinkedList::remove_tail(){
    if(lst_len==0){ //if the list is empty
        return current_ptr->get_data();;
    }

    else if(lst_len==1){ //if the list has only one node
        delete head_ptr; //deletes the head node (mem mgmnt)
        head_ptr=NULL; //sets the head node to null
        tail_ptr=NULL; //sets the tail node to null
        lst_len--; //decrements the length of the list
        return current_ptr->get_data();; //returns the data
    }

    else{ //if the list has more than one node
        Node* tmp_tail_ptr = tail_ptr; //create a temporary node to hold the tail node
        tail_ptr = tmp_tail_ptr->get_next(); //sets the tail node to the next node
        delete tmp_tail_ptr; //deletes the temporary node (mem mgmnt)

        lst_len--; //decrements the length of the list

        tmp_tail_ptr=NULL; //sets the temporary node to null

        return current_ptr->get_data();; //returns the data
    }
}

LinkedList::value_type LinkedList::remove_current(){
    if(lst_len==0){ //if the list is empty
        return current_ptr->get_data();;
    }

    else if(lst_len==1){ //if the list has only one node
        delete head_ptr; //deletes the head node (mem mgmnt)
        head_ptr=NULL; //sets the head node to null
        tail_ptr=NULL; //sets the tail node to null
        lst_len--; //decrements the length of the list
        return current_ptr->get_data();; //returns the data
    }

    else{ //if the list has more than one node
        Node* tmp_current_ptr = current_ptr; //create a temporary node to hold the current node
        current_ptr = tmp_current_ptr->get_next(); //sets the current node to the next node
        delete tmp_current_ptr; //deletes the temporary node (mem mgmnt)

        lst_len--; //decrements the length of the list

        tmp_current_ptr=NULL; //sets the temporary node to null

        return current_ptr->get_data();; //returns the data
    }
}

void LinkedList::move_to_head(){
    current_ptr = head_ptr;
}

void LinkedList::move_to_tail(){
    current_ptr = tail_ptr;
}

void LinkedList::forward(){
    current_ptr = current_ptr->get_next();
}

void LinkedList::backward(){
    current_ptr = current_ptr->get_next();
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
