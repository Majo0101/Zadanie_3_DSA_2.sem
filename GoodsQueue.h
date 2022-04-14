#ifndef ZADANIE_3_GOODSQUEUE_H
#define ZADANIE_3_GOODSQUEUE_H

#include <string>
#include <iostream>
#include <queue>

using namespace std;

class GoodsQueue {

public:

    GoodsQueue(){
        head = NULL;
        tail = NULL;
    }

    ~GoodsQueue(){
        cout << "Goods class was destroyed" << endl;
    }

    struct node {
        float data;
        node* next;
    };

    void add(float n); //add item to fifo
    void print();      //print fifo - used during development
    void removeLIFOitem(); //remove LIFO style - used during development
    float removeFIFOitem(); //remove FIFO style
    int sumUp();    //sumup goods in linked list
    void summary(); //sumary in linked lis
    bool removeSelected(float n); //remove selected item
    int differentNumber(int n); //used during development
    float totalPrice();         //total price in linked list


private:
    node *head,*tail;
};



#endif //ZADANIE_3_GOODSQUEUE_H
