//
// Created by PC on 4. 4. 2022.
//

#include "GoodsQueue.h"
#include <string>
#include <iostream>
#include <queue>

using namespace std;

void GoodsQueue ::pushToFront(int a){

    Goods.push(a);

}

bool GoodsQueue ::sellFromFront(int a){

    if (Goods.size() > a){
        for (int i = 0; i < a; i++) {
            Goods.pop();
        }
        return false;
    }else{
        cout << endl << "Lack of goods !!" << endl;
        return true;
    }
}

void GoodsQueue ::sumGoods(){



}