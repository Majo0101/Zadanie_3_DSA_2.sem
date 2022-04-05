#include "GoodsQueue.h"
#include <string>
#include <iostream>
#include <queue>

using namespace std;

void GoodsQueue ::add(float n) {

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

    node*tmp;

    tmp = head;

    while (tmp != NULL){
        cout << tmp -> data << endl;
        tmp = tmp->next;
    }


}