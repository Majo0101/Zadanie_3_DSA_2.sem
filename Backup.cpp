#include "Backup.h"
#include <iostream>
#include <fstream>
#include <string>

#define file "Data.txt"

using namespace std;

void Backup ::writeToFile() {

    ofstream File(file);

    if(File.is_open()){
        while(!front.empty()){

            File << front.front() << endl;

            front.pop();
        }

        cout << endl << "Backup was successfully writen" << endl;

    }else{
        cout << endl << "Unable write to file !!" << endl;
    }

    File.close();
}

void Backup ::writeToFifo(string in) {

    front.push(in);

}