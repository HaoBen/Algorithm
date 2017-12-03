#include "hashnode.h"
#include <stdlib.h>
#include <iostream>
HashNode::HashNode(){
    string keyword;
    values = NULL;
    valuesSize=currSize = 0;
    next = NULL;
}
HashNode::HashNode(string key){
    keyword = key;
    valuesSize = 2;
    currSize = 0;
    values = new string[valuesSize];
    next = NULL;
}
HashNode::HashNode(string key, string value) {
    new  (this)HashNode(key);
    values[0] = value;
    currSize = 1;
}

HashNode::~HashNode()
{
    delete[] values;
}

void HashNode::addValue(string value) {
    //check whether the value is already existed
    for(int i = 0;i < currSize;++i) {
        if(value == values[i])
            return;
    }

    //check whether the arrays is full
    //if so,call the dblArray();
    if(valuesSize == currSize){
        dblArray();
    }
    values[currSize] = value;
    currSize++;
}

void HashNode::dblArray() {
    string *tmp = values;
    valuesSize *= 2;
    values = new string[valuesSize]();

    for(int i = 0;i < currSize;++i){
        values[i] = tmp[i];
    }
}

string HashNode::getRandValue() {
    if(currSize == 0)
        return "";
    int index = rand()%currSize;
    return values[index];
}

int HashNode::hashCode(string key) {
    int hash = 0;
    for(string::size_type i = 0;i < key.length();++i){
        if(i == key.length()-1){
            hash += key[i];
        } else {
            hash += (hash + key[i])*31;
        }
    }
    return hash;
}

