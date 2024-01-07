#include"node.h"
#include"list.h"
#include<iostream>
using namespace std;
#pragma once

//--------------------- print list function ---------------------------------------------------
void Linkedlist::printList()
{
    //comments! put these where they belong.
    // walk through the list
    // set up an iterator (something to keep track of where we are on the list)
    // check for empty list

    Node* temp = head;

    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

//---------------------- insert node function --------------------------------------------------
void Linkedlist::insertNode(int data)
{
    //comments! put these where they belong.
    //update the iterator
    //create the new node
    //insert at the end of the list
    //assign the iterator to the start of the list
    //walk through the list until the end

    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

//------------------------------------------------------------------------

//----------------- delete node function -------------------------------------------------------
void Linkedlist::deleteNode(int nodeOffset)
{
    //add comments to each line or section that does something important!

    Node* temp1 = head;
    Node* temp2 = NULL;
    int ListLen = 0;

    if (head == NULL) {
        cout << "List empty." << endl;
        return;
    }

    while (temp1 != NULL) {
        temp1 = temp1->next;
        ListLen++;
    }

    if (ListLen < nodeOffset) {
        cout << "Index out of range"
            << endl;
        return;
    }

    temp1 = head;

    if (nodeOffset == 1) {
        head = head->next;
        delete temp1;
        return;
    }

    while (nodeOffset-- > 1) {

        temp2 = temp1;
        temp1 = temp1->next;
    }

    temp2-> next = temp1->next;
    delete temp1;
}

