#include <vector>
#include <cstdlib>
#include <ctime>

template <typename T>
void RandomOrder(std::vector<T> &v)
{
    std::srand(std::time(nullptr));
    for (int i = 0; i < v.size(); ++i)
    {
        int j = rand() % v.size();
        std::swap(v[i], v[j]);
    }
}
