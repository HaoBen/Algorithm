#ifndef _COMMON_HPP
#define _COMMON_HPP

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <chrono>
#include <thread>

template <typename T>
void RandomOrder(std::vector<T> &v)
{
    std::srand(std::time(nullptr));
    for (int i = 0; i < v.size(); ++i)
    {
        int j = rand() % v.size();
        std::swap(v[i], v[j]);
    }

    //for (int i = 0; i < v.size(); ++i)
    //{
        //std::cout << v[i] << " ";
    //}
    //std::cout << std::endl;
}

template <class T>
void PrintVector(std::vector<T> &v)
{
    for (auto &item : v)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

template <class Iter>
void PrintRange(Iter from, Iter to)
{
    auto iter = from;
    while (iter != to)
    {
        std::cout << *iter << " ";
        ++iter;
    }
    std::cout << *iter << std::endl;
}

void Delay()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
#endif
