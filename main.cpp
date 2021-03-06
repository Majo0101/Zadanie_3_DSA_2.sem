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

    bool accessRW_File = true;

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
        cout << "The data was loaded correctly" << endl;

        File.close();
    }

    void buyGoods(int type,int pieces,float price){
        if (type == 1){
            for (int i = 0; i < pieces; i++) {
                type1.add(price);
            }
        }else if(type == 2){
            for (int i = 0; i < pieces; i++) {
                type2.add(price);
            }
        }else if(type == 3){
            for (int i = 0; i < pieces; i++) {
                type3.add(price);
            }
        }else{
            cout << endl << "Bad type of goods" << endl << endl;
        }
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
        cout << "Total price: " << type1.totalPrice();
        cout << endl << endl << "Type 2" << endl;
        type2.summary();
        cout << "Total price: " << type2.totalPrice();
        cout << endl << endl << "Type 3" << endl;
        type3.summary();
        cout << "Total price: " << type3.totalPrice();

    }

    void sellGoods(int type, int pieces){

        float tmp;
        float compare = INT16_MIN;
        int counter = 0;
        int i;

        if (type == 1){
            if (type1.sumUp() >= pieces){

                writeSellData(pieces, type);

            }else{
                cout << endl << "Lack of goods" << endl;
            }
        }else if (type == 2){
            if (type2.sumUp() >= pieces){

                writeSellData(pieces,type);

            }else{
                cout << endl << "Lack of goods" << endl;
            }
        }else if (type == 3){
            if (type3.sumUp() >= pieces){

                writeSellData(pieces ,type);

            }else{
                cout << endl << "Lack of goods" << endl;
            }
        }else{
            cout << endl << "Bad type of goods" << endl << endl;
        }
    }

    void writeSellData(int pieces , int type){

        float tmp;
        float compare = INT16_MIN;
        int counter = 0;
        int i;
        string Sell;

        stringstream sell;


        for (i = 0; i < pieces; i++) {

            if (type == 1) {tmp = type1.removeFIFOitem();}
            if (type == 2) {tmp = type2.removeFIFOitem();}
            if (type == 3) {tmp = type3.removeFIFOitem();}

            counter++;

            if (tmp != compare){
                if (i != 0) {
                    cout << "Pcs: " << counter << "  Price: " << compare << endl;
                    sell << type << " P " << counter << " " << compare;
                    Sell = sell.str();
                    backup.writeToFifo(Sell);
                    sell.str("");
                }else{
                    counter = 1;
                }
                compare = tmp;
                counter = 0;
            }
        }
        if (i != 0){
            cout << "Pcs: " << counter + 1 << "  Price: " << compare << endl;
            sell << type << " P " << counter +1 << " " << compare;
            Sell = sell.str();
            backup.writeToFifo(Sell);
            sell.str("");
        }
    }

    ~Read(){
        cout << "Read class was destroyed" << endl;
    }

};

int main(){

    Read obj;

    stringstream backup;

    string backUp;
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
                while(cin.fail()) {
                    cout << "Error" << endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin >> type;
                }
                obj.showDataForType(type);
                i--;
                break;

            case 'k' :
                cout << "Enter type of goods" << endl;
                cin >> type;
                while(cin.fail()) {
                    cout << "Error" << endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin >> type;
                }
                cout << "Enter number of pieces" <<endl;
                cin >> pieces;
                while(cin.fail()) {
                    cout << "Error" << endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin >> pieces;
                }
                cout << "Enter price" << endl;
                cin >> price;
                while(cin.fail()) {
                    cout << "Error" << endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin >> price;
                }
                obj.buyGoods(type,pieces,price);

                backup << type << " K "<< pieces << " " << price;
                backUp = backup.str();
                obj.backup.writeToFifo(backUp);
                backup.str("");

                i--;
                break;

            case 'p':
                cout << "Enter type of goods" << endl;
                cin >> type;
                while(cin.fail()) {
                    cout << "Error" << endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin >> type;
                }
                cout << "Enter number of pieces" <<endl;
                cin >> pieces;
                while(cin.fail()) {
                    cout << "Error" << endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin >> pieces;
                }
                obj.sellGoods(type,pieces);
                i--;
                break;

            case 'n':
                if (obj.accessRW_File){
                    obj.readData();
                    obj.accessRW_File = false;
                }else{
                    cout << "You can't mix DATA before write" << endl;
                }

                i--;
                break;

            case 's':
                obj.showData();
                i--;
                break;

            case 'w':
                if (!obj.accessRW_File){
                    obj.backup.writeToFile();
                    obj.accessRW_File = true;
                }else{
                    cout << "You need read data first with n" << endl;
                }
                i--;
                break;

            case 'e':
                if (!obj.accessRW_File){
                    cout << "Write data before exit" << endl;
                }else{
                    i = 5;
                }
                i--;
                break;

            default:
                cout << endl <<  "Bad input" << endl;
        }

        fflush(stdin);
    }

    return 0;
}


