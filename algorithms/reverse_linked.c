/**
 * \file reverse_linked.c
 * \author eduardo
 * Create on Tue 2021-01-12 18:43 UTC
 * 
 */

#include "reverse_linked.h"

struct node {
    int value;
    struct node* nextNode;
};

void reverse() {
    struct node *head, *prevnode, *currentnode, *nextnode;
    prevnode = 0;
    currentnode = nextnode = head;
    while(nextnode != 0) {
        nextnode = nextnode->nextNode;
        currentnode->nextNode = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    };
    head = prevnode;
}
