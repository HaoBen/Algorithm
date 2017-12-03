#ifndef HASHMAP_H
#define HASHMAP_H
#include "hashnode.h"

class HashMap {
    friend class MakeSeuss;
    int *randomArray;   //open address method need it

    HashNode **map;
    string first;       //for first keyword for printing to a file
    int keysNum;
    int mapSize;        //I use 2^n as the size,and initialize it with 2^5;
    bool h1;        //if true,first hash function used;
    bool c1;        //if true,first collision method used;

public:
    HashMap(bool h1,bool c1);
    ~HashMap();

    //adds a node to the map at the correct index
    //      based on key,and inserts value into the value field of the HashNode
    void addKeyValue(string key,string value);

    //return the index of where the keyword should be inserted into the map array
    int getIndex(string key);

    //hash function 1
    //Refer to the method of HashMap in JDK
    //Perturbation function : h = (hashCode>>16)^hashCode
    //then index = h & (mapSize -1)
    int calHash1(string key);

    //hash function 2
    //Using a simple method just likes this
    // int index = hashCode mod mapSize
    int calHash2(string key);

    //getting index with collision method 1
    //Use the chain address method,
    //e.x : so I need add a 'next' pointer in HashNode
    int collHash1(string key,int index);

    //getting index with collision method 2
    //An open address method is used,
    //rehashing by a series of fake random numbers is used to deal with collisions
    //e.x :I need to add a pointer to a random array in the HashMap
    int collHash2(string key,int index);

    //finds the key in the array and returns its node pointer.
    //If it's not in the array,return NULL
    HashNode* findKey(string key);

    //when size of array is at 70% or can't find a index for current key
    //,double array size and rehash keys.
    void reHash();

    //to check if everything was working
    void printMap();
};

#endif // HASHMAP_H
