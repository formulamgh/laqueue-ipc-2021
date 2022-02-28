/*
 * LaQueue
 * 
 * 
 * This is part of a series of labs for the Liberal Arts and Science Academy.
 * The series of labs provides a mockup of an POSIX Operating System
 * referred to as LA(SA)nix or LAnix.
 *  
 * (c) copyright 2018, James Shockey - all rights reserved
 * 
 * */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "PQueue.h"



/*
 * Class Priority Queue
 */

/*
 * Constructor
 */
PQueue::PQueue(){
  std::cout << "Test Constructor\n";
  
  front = NULL;
}
		
/*
 * Insert into Priority Queue
 */
void PQueue::push(void *item, int priority){
  node* newNode = new node();
  newNode->priority = priority;
  newNode->data = item;
  
  node* searchNode = front;
  
  if(front == NULL){
    newNode->link = NULL;
    front = newNode;
    return;
  } else if(front->priority > priority){
    newNode->link = front;
    front = newNode;
    return;
  } else{
    while(searchNode->link != NULL){
      if(searchNode->link->priority <= priority){
        searchNode = searchNode->link;
      } else{
        newNode->link = searchNode->link;
        searchNode->link = newNode;
        return;
      }
    }
    
    newNode->link = NULL;
    searchNode->link = newNode;
    return;
  }
}

/*
 * Delete from Priority Queue
 */
void* PQueue::top(){
  if(front != NULL){
    return front->data;
  } else{
    return NULL;
  }
}
/*
 * Delete from Priority Queue
 */
void PQueue::pop(){
  if(front != NULL){
    node* temp = front;
    front = front->link;
    free(temp);
  } else{
    std::cout << "Error: Queue Empty\n";
    exit(1);
    return;
  }  
}

/*
 * Print Priority Queue
 */
void PQueue::display(){
  if(front != NULL){
    node* ptr = front;
    
    while(ptr->link != NULL){
  	  /* Use the following out command for the data */
  	  std::cout<<ptr->priority<<" "<<(char*)ptr->data<<std::endl;
  
      //
      ptr = ptr->link;
    }
  
    /* Use the following out command for the data */
    std::cout<<ptr->priority<<" "<<(char*)ptr->data<<std::endl;
  } else{
    std::cout << "Error: Queue Empty\n";
    exit(1);
    return;
  }
}
	