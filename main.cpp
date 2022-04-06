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

    bool accesWtoFile = false;

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

    void buyGoods(int type,int pieces,float price){


    }

    void showDataForType(int type){

        if (type == 1){
            type1.summary();
        }else if (type == 2){
            type2.summary();
        }else if (type == 3){
            type3.summary();
        }else{
            cout << endl << "Bad type of goods" << endl << endl;
        }
    }

    void showData(){

        cout << "Type 1"<< endl;
        type1.summary();
        cout << endl << endl << "Type 2" << endl;
        type2.summary();
        cout << endl << endl << "Type 3" << endl;
        type3.summary();

    }

    void sellGoods(int type, int pieces){
        if (type == 1){
            if (type1.sumUp() > pieces){
                for (int i = 0; i < pieces; i++) {
                    type1.removeFIFOitem();
                }
            }else{
                cout << endl << "Lack of goods" << endl;
            }
        }else if (type == 2){
            if (type2.sumUp() > pieces){
                for (int i = 0; i < pieces; i++) {
                    type2.removeFIFOitem();
                }
            }else{
                cout << endl << "Lack of goods" << endl;
            }
        }else if (type == 3){
            if (type3.sumUp() > pieces){
                for (int i = 0; i < pieces; i++) {
                    type3.removeFIFOitem();
                }
            }else{
                cout << endl << "Lack of goods" << endl;
            }
        }else{
            cout << endl << "Bad type of goods" << endl << endl;
        }
    }

};

int main(){

    Read obj;

    char choice;
    int type;
    int pieces;
    float price;

    for (int i = 0; i < 3; ++i) {

        cout << endl << endl
        << "Enter your choice:" << endl
        << "i -  Show inventory for type of goods " << endl
        << "k -  Buy goods by type" << endl
        << "p -  Sell goods by type" << endl
        << "n -  Load inventory from file" << endl
        << "s -  Show goods inventory" << endl
        << "w -  Write inventory to file" << endl
        << "e -  EXIT" << endl << endl;

        cin >> choice;

        switch (choice) {

            case 'i' :
                cout << "Enter type of goods" << endl;
                cin >> type;
                obj.showDataForType(type);
                i--;
                break;

            case 'k' :
                cout << "Enter type of goods" << endl;
                cin >> type;
                cout << "Enter number of pieces" <<endl;
                cin >> pieces;
                cout << "Enter price" << endl;
                cin >> price;
                obj.buyGoods(type,pieces,price);
                i--;
                break;

            case 'p':
                cout << "Enter type of goods" << endl;
                cin >> type;
                cout << "Enter number of pieces" <<endl;
                cin >> pieces;
                obj.sellGoods(type,pieces);
                i--;
                break;

            case 'n':
                obj.readData();
                obj.accesWtoFile = true;
                i--;
                break;

            case 's':
                obj.showData();
                i--;
                break;

            case 'w':
                if (obj.accesWtoFile){
                    obj.backup.writeToFile();
                }else{
                    cout << "You need read data first with n" << endl;
                }
                i--;
                break;

            case 'e':
                i = 5;
                break;

            default:
                cout << endl <<  "Bad input" << endl;
        }

        fflush(stdin);
    }



    return 0;
}


