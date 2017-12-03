#include <iostream>
#include "makeseuss.h"
using namespace std;

void test1() {
   MakeSeuss make1 = MakeSeuss("DrSeuss.txt","outfile1.txt",true,true);   //calHash1 and collHash1
   make1.printMap();
}
void test2() {
    MakeSeuss make2 = MakeSeuss("DrSeuss.txt","outfile2.txt",true,false);   //calHash1 and collHash2
    make2.printMap();
}
void test3() {
    MakeSeuss make3 = MakeSeuss("DrSeuss.txt","outfile3.txt",false,true);   //calHash2 and collHash1
    make3.printMap();
}
void test4() {
     MakeSeuss make4 = MakeSeuss("DrSeuss.txt","outfile4.txt",false,false);   //calHash2 and collHash2
     make4.printMap();
}

int main(int argc, char *argv[])
{
    //test1();
    //test2();
    //test3();
    //test4();
}

