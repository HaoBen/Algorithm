#ifndef HASHNODE_H
#define HASHNODE_H
#include <string>

using  std::string;

class HashNode {
    friend class HashMap;

    // chain address method needs it
    HashNode *next;

    // The keyword for words prediction
    string keyword;

    //the dynamically allocated array of word that follow the key;
    string *values;

    //the size of the values array
    int valuesSize;

    //the number words in the array so far;
    int currSize;
public:
    //constructor-initializes keywords to "",values to 0,and array to NULL
    HashNode();  
     //initializes keywords,the arraySize to 2;
    HashNode(string key);
      //in addition,puts a value in the values array and initializes currSize to 1
    HashNode(string key,string value);
    //deconstructor
    ~HashNode();

     //adds a new value in the end of the value array.And I choose to check before adding.
    void addValue(string value);

    //create a new array,double the length,and copies over the values.(e.x:newly allocated)
    void dblArray();

    //returns a random string from the values array.
    //if there's no values in the array then it returns an empty string
    string getRandValue();

    //to calculate the hashCode
    //I use weighted multiplication to calculate
    //and the based number is 31
    static int hashCode(string key);
};

#endif // HASHNODE_H
