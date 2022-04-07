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

    struct node {
        float data;
        node* next;
    };

    void add(float n);
    void print();
    void removeLIFOitem();
    float removeFIFOitem();
    int sumUp();
    void summary();
    bool removeSelected(float n);
    int differentNumber(int n);
    float totalPrice();

private:
    node *head,*tail;
};



#endif //ZADANIE_3_GOODSQUEUE_H
