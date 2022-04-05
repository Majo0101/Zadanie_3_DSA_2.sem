#include "GoodsQueue.h"
#include <string>
#include <iostream>
#include <queue>

using namespace std;

void GoodsQueue::add(float n) {

    node *tmp = new node;
    tmp->data = n;
    tmp->next = NULL;

    if(head == NULL)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tail->next;
    }
}

void GoodsQueue::print() {

    node *tmp;

    tmp = head;

    if (head != NULL) {
        while (tmp != NULL) {
            cout << tmp->data << endl;
            tmp = tmp->next;
        }
    }else{
        cout << endl << endl << "No goods" << endl;
    }
}

void GoodsQueue::removeLastItem() {

    node *tmp;
    node *lastNode;

    if(head != NULL){
        if(head->next == NULL) {
            head = NULL;
        }else {
            tmp = head;
            while (tmp->next->next != NULL) {
                tmp = tmp->next;
            }

            lastNode = tmp->next;

            tmp->next = NULL;

            free(lastNode);
        }
    }else{
        cout << endl << "No goods" << endl;
    }
}

int GoodsQueue::sumUp() {

    node*tmp;
    int counter = 0;

    tmp = head;

    while (tmp != NULL){
        counter++;
        tmp = tmp->next;

    }
    return counter;
}

void GoodsQueue::removeFirstItem() {

    node*tmp;

    if(head != NULL){

        tmp = head;
        head = head->next;
        free(tmp);
    }else{
        cout << endl << "No goods" << endl;
    }
}

void GoodsQueue::summary() {

    node *tmp;
    float max = 0;
    float min = INT16_MAX;
    float maxSecond = 0;
    int counter = 0;
    string result;

    tmp = head;

    if (head != NULL){
        while (tmp != NULL) {
            if (max < tmp->data) {
                max = tmp->data;
            }
            if (min > tmp->data) {
                min = tmp->data;
            }
            tmp = tmp->next;
        }
    }

    if (head != NULL) {
        while (max != min) {

            tmp = head;

            while (tmp != NULL) {
                if (max <= tmp->data) {
                    tmp = tmp->next = tmp->next;
                } else {
                    if (maxSecond < tmp->data) {
                        maxSecond = tmp->data;
                    }

                    tmp = tmp->next;
                }
            }

            tmp = head;

            while (tmp != NULL) {
                if (max == tmp->data) {
                    counter++;
                }
                tmp = tmp->next;
            }

            cout << endl << endl << "cislo " << max << " counter " << counter;

            max = maxSecond;
            maxSecond = 0;
            counter = 0;
        }
    }

    tmp = head;

    if (head != NULL){
        while (tmp != NULL){
            if (min == tmp->data){
                counter++;
            }
            tmp = tmp->next;
        }
        cout << endl << endl << "cislo "<< min << " counter " << counter;
        counter = 0;
    }
}