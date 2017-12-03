#include "hashmap.h"
#include <stdlib.h>
#include <iostream>

HashMap::HashMap(bool h1, bool c1)
{
    this->h1 = h1;
    this->c1 = c1;
    keysNum = 0;
    mapSize = 32;
    map = (HashNode**)malloc(sizeof(HashNode*) * mapSize);

    //if collHash2 is selected,then create a fake random array
    if(!c1) {
        srand(mapSize);
        randomArray = new int[mapSize];
        for(int i = 0;i < mapSize;++i) {
            randomArray[i] = (rand()%mapSize-1)+1;
        }
    }
}

HashMap::~HashMap()
{
    if(!c1)
        delete[] randomArray;
    for(int i = 0;i < mapSize;++i) {
        HashNode *tmp = map[i];
        while(tmp != NULL) {
            HashNode *next = tmp->next;
            delete tmp;
            tmp = next;
        }
    }
    delete[] map;
}

void HashMap::addKeyValue(string key,string value) {
    int index = getIndex(key);
    std::cout<<key<<"("<<index<<")"<<std::endl;
    if(c1) {
        if(map[index] == NULL) {
            map[index] = new HashNode(key,value);
            keysNum++;
            return;
        } else {
            HashNode* tmp = map[index];
            while(tmp != NULL) {
                if(tmp->keyword == key) {
                    tmp->addValue(value);
                    return ;
                }
                tmp = tmp->next;
            }
            HashNode* head = new HashNode(key,value);
            head->next = map[index];
            map[index] = head;
        }
    }  else {                           //end if(c1)
        if(map[index] == NULL) {
            map[index] = new HashNode(key,value);
            keysNum++;
        }
        else
            map[index]->addValue(value);
    }

    if(keysNum >= mapSize * 0.7)
        reHash();
}

int HashMap::getIndex(string key) {
    int index;
    //use the selected hash function to get the original index
    if(h1)
        index = calHash1(key);
    else
        index = calHash2(key);

    //use the selected collsion function to handle the collsions
    if(c1)
        index = collHash1(key,index);
    else
        index = collHash2(key,index);

    return index;
}

int HashMap::calHash1(string key)
{
    int hashCode = HashNode::hashCode(key);
    int hash = (hashCode>>16)^hashCode;
    return hash & mapSize-1;
}

int HashMap::calHash2(string key){
    int hashCode = HashNode::hashCode(key);
    int index;
    if(hashCode >= 0)
        index = hashCode % mapSize;
    else
        index = (-1 * hashCode) % mapSize;
    return  index;
}

int HashMap::collHash1(string key,int index) {

    //The method is chain address,so it just returns origin index
    return index;
}

int HashMap::collHash2(string key,int index) {
    //to check if the position is already used
    // if not,return index
    if(map[index] == NULL || map[index]->keyword == key)
        return index;

    //to get new index to insert
    do {
        for(int i = 0;i < mapSize;++i) {
            index = (index + randomArray[i]) % mapSize;
            if(map[index] == NULL || map[index]->keyword == key)
                return index;
        }
        reHash();
    } while(1);
}

HashNode* HashMap::findKey(string key) {
    int index;
    if(h1) {
        index = calHash1(key);
    } else {
        index = calHash2(key);
    }

    //first check
    if(map[index] == NULL)
        return NULL;
    if(map[index]->keyword == key)
        return map[index];

    //check by selected collision function
    if(c1) {
        HashNode* tmp = map[index];
        while(tmp != NULL) {
            if(tmp->keyword == key)
                return tmp;
            tmp = tmp->next;
        }
        return NULL;
    } else {
        for(int i = 0; i < mapSize;++i) {
            index = (index+randomArray[i]) % mapSize;
            if(map[index]->keyword == key)
                return map[index];
        }
        return NULL;
    }
}

void HashMap::reHash() {
    int oldMapSize = mapSize;
    HashNode** oldMap = map;    // to save the old map
    mapSize *= 2;
    map = (HashNode**)malloc(sizeof(HashNode*)*mapSize);    //get a new map
    //if collHash2 is selected,then create a new fake random array
    if(!c1) {
        int *old = randomArray;
        srand(mapSize);
        randomArray = new int[mapSize];
        for(int i = 0;i < mapSize;++i) {
            randomArray[i] = (rand()%mapSize-1)+1;
        }
        delete[] old;
    }

    //rehash from old map to new map
    for(int i = 0;i < oldMapSize;++i) {
        if(oldMap[i] != NULL) {
            if(c1) {    //if collHash1 is selected
                 HashNode* tmp = oldMap[i];
                 while(tmp!=NULL) {
                     int index = getIndex(tmp->keyword);
                     HashNode* nextone = tmp->next;
                     tmp->next = map[index];
                     map[index] = tmp;
                     tmp = nextone;
                 }
            } else {
                int index = getIndex(oldMap[i]->keyword);
                map[index] = oldMap[i];
            }
        }
    }

    //release old map
    delete[] oldMap;
}

void HashMap::printMap() {
    if(c1) {
        for(int i = 0;i < mapSize; ++i) {
            HashNode* tmp = map[i];
            while(tmp != NULL) {
                std::cout<<i<<"->";
                std::cout<<tmp->keyword<<" : ";
                for(int j = 0; j < tmp->currSize;++j){
                    std::cout<<tmp->values[j]<<",";
                }
                std::cout<<std::endl;
                tmp = tmp->next;
            } // end while
        } // end for loop
    } else {
        for(int i = 0;i < mapSize;++i) {
            if(map[i] != NULL) {
                std::cout<<map[i]->keyword<<" : ";
                for(int j = 0;j < map[i]->currSize;++j) {
                    std::cout<<map[i]->values[j]<<",";
                }
                std::cout<<std::endl;
            }
        }   //end for i
    }   //end if else
}


