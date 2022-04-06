#include <iostream>
#include <sstream>
#include "Backup.h"
#include "GoodsQueue.h"
#include <string>
#include <fstream>

#define file "Data.txt"

using namespace std;

class Read{

public:
    GoodsQueue type1;
    GoodsQueue type2;
    GoodsQueue type3;

    Backup backup;


    void readData(){

        stringstream strStream;

        string data;

        ifstream File(file);

        if (!File.is_open()){
            cout << endl << "Data file doesn't exist" << endl;
            exit(1);
        }

        int typeGoods;
        char transaction;
        int numPieces;
        float price;

        while( File >> typeGoods >> transaction >> numPieces >> price ){

            strStream << typeGoods << " " << transaction << " " << numPieces << " " << price;

            data = strStream.str();

            backup.writeToFifo(data);

            strStream.str("");

            if (typeGoods == 1){
                if (transaction == 'K'){
                    for (int i = 0; i < numPieces; i++) {
                        type1.add(price);
                    }

                }else{
                    for (int i = 0; i < numPieces; i++) {
                        if(type1.removeSelected(price)){
                            cout << endl << endl << "Bad input data" << endl;
                            exit(2);
                        }
                    }
                }
            }

            if (typeGoods == 2){
                if (transaction == 'K'){
                    for (int i = 0; i < numPieces; i++) {
                        type2.add(price);
                    }

                }else{
                    for (int i = 0; i < numPieces; i++) {
                        if (type2.removeSelected(price)) {
                            cout << endl << endl << "Bad input data" << endl;
                            exit(3);

                        }
                    }
                }
            }

            if (typeGoods == 3){
                if (transaction == 'K'){
                    for (int i = 0; i < numPieces; i++) {
                        type3.add(price);
                    }

                }else{
                    for (int i = 0; i < numPieces; i++) {
                        if(type3.removeSelected(price)) {
                            cout << endl << endl << "Bad input data" << endl;
                            exit(4);
                        }
                    }
                }
            }
        }
    }

    void writeData(int type, float n){


    }



};


int main(){

    Read obj;

    obj.readData();

    obj.backup.writeToFile();



    return 0;
}


