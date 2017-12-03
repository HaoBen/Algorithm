#ifndef MAKESEUSS_H
#define MAKESEUSS_H
#include "hashmap.h"

class MakeSeuss
{
    HashMap* ht;
    string fn;
    string newfile;
public:
    MakeSeuss(string file,string newf,bool h1,bool c1);
    void readFile();
    void writeFile();

    void printMap();
};

#endif // MAKESEUSS_H
