#include <iostream>
#include <sstream>
#include "Backup.h"
#include "GoodsQueue.h"
#include <string>

using namespace std;

int main(){

    Backup backup;

    GoodsQueue type1;
    GoodsQueue type2;
    GoodsQueue type3;



    stringstream ss;










    string a = "sdgsgsggfdgfd";

    backup.writeToFifo(a);


    cout << a << endl;


    backup.writeToFile();


    return 0;
}