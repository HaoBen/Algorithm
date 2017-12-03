#include "makeseuss.h"
#include <fstream>
#include <iostream>
using namespace std;

MakeSeuss::MakeSeuss(string file, string newf, bool h1, bool c1)
{
    ht = new HashMap(h1,c1);
    newfile = newf;
    fn = file;
    readFile();
    writeFile();
}

void MakeSeuss::readFile() {
    ifstream infile(fn.c_str(),ios::in);    //open file
    string key = "";
    string value = "";
    infile>>key;
    ht->first = key;
    while(infile>>value) {
        ht->addKeyValue(key,value);
        key = value;
        value = "";
    }
    ht->addKeyValue(key,value);
    infile.close();
}

void MakeSeuss::writeFile(){
    ofstream outfile(newfile.c_str(),ios::out);
    outfile<<ht->first<<" ";
    string key = ht->first;
    string value="";
    int ct = 0;
    int len = 0;
    srand(time(0));
    while(ct < 500 && key != "") {
        HashNode *tmp = ht->findKey(key);
        value = tmp ? tmp->getRandValue() : "";
        outfile<<value<<" ";
        if(len == 11){
            outfile<<"\n";
            len = 0;
        } else {
            len++;
        }
        key = value;
        ct++;
    }
    outfile.close();
}

void MakeSeuss::printMap()
{
    ht->printMap();
    cout<<ht->keysNum<<"/"<<ht->mapSize<<endl;
}
