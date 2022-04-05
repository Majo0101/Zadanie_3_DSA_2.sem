#include <iostream>
#include <sstream>
#include "Backup.h"
#include "GoodsQueue.h"
#include <string>
#include <fstream>

#define file "Data.txt"

using namespace std;

int main(){

    Backup backup;

    GoodsQueue type1;
    GoodsQueue type2;
    GoodsQueue type3;

    stringstream strStream;

    ifstream File(file);

    if (!File.is_open()){
        cout << endl << "Somethings went wrong" << endl;
        exit(1);
    }

    int typeGoods;
    char transaction;
    int numPieces;
    float price;

    while( File >> typeGoods >> transaction >> numPieces >> price ){

        strStream << typeGoods << " " << transaction << " " << numPieces << " " << price;



        if (typeGoods == 1){
            if (transaction == 'K'){


            }else{


            }
        }

        if (typeGoods == 2){
            if (transaction == 'K'){


            }else{


            }

        }

        if (typeGoods == 3){
            if (transaction == 'K'){


            }else{


            }
        }

    }









    return 0;
}