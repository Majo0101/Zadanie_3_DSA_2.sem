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

void GoodsQueue::removeLIFOitem() {

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

float GoodsQueue::removeFIFOitem() {

    node*tmp;

    float giveMeNumber;

    if(head != NULL){

        tmp = head;
        giveMeNumber = tmp ->data;
        head = head->next;
        free(tmp);

        return giveMeNumber;
    }else{
        cout << endl << "No goods" << endl;
        return -0;
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

    if(head == NULL){
        cout << "No goods" << endl << endl;
    }

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

            cout << "Price: " << max << " Pieces: " << counter << endl;

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
        cout << "Price: "<< min << " Pieces: " << counter << endl;
        counter = 0;
    }
}

bool GoodsQueue::removeSelected(float n){
    node*tmp;
    node*prev;

    tmp = head;

    if (tmp != NULL && tmp->data == n){
        head = tmp->next;
        free(tmp);
        return false;
    }else{
        while (tmp != NULL && tmp->data != n){
            prev = tmp;
            tmp = tmp->next;
        }

        if (tmp == NULL){
            return true;
        }else{
            prev->next = tmp->next;
            free(tmp);
            return false;
        }
    }
}

int GoodsQueue::differentNumber(int n){

    node*tmp;

    tmp = head;

    float max = tmp->data;
    int counter = 1;

    while(n != 0){
        if(max != tmp->data){
            max = tmp->data;
            counter++;
        }
        tmp = tmp->next;
        n--;
    }

    return counter;

}

float GoodsQueue::totalPrice() {

    node *tmp;

    tmp = head;

    float totalPrice = 0;

    while (tmp != NULL) {
        totalPrice += tmp->data;
        tmp = tmp->next;
    }

    return totalPrice;
}
