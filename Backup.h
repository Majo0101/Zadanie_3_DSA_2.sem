#include <string>
#include <iostream>
#include <queue>

using namespace std;

#ifndef ZADANIE_3_BACKUP_H
#define ZADANIE_3_BACKUP_H


class Backup {

public:
    Backup(){}
    ~Backup(){
        cout << "Backup class was destroyed" << endl;
    }

    void writeToFifo(string in);   //store data before writing
    void writeToFile();     //write data to file

private:
    queue<string> front;
};


#endif //ZADANIE_3_BACKUP_H
