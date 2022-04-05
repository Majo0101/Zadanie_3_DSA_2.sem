#include <string>
#include <iostream>
#include <queue>

using namespace std;

#ifndef ZADANIE_3_BACKUP_H
#define ZADANIE_3_BACKUP_H


class Backup {

public:
    void writeToFifo(string in);
    void writeToFile();

private:
    queue<string> front;
};


#endif //ZADANIE_3_BACKUP_H
