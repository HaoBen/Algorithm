#include <iterator>

namespace my
{

template<typename T, typename Iter>
Iter _binary_search_impl(Iter from, Iter to, const T &val, const std::random_access_iterator_tag&) {
    auto noAns = to--;
    while (from <= to) {
        auto mid = from+(to-from)/2;
        if (*mid < val) from = mid+1;
        else if (*mid > val) to = mid-1;
        else return mid;
    }
    return noAns;
}

// [from, to)
template<typename T, typename Iter>
Iter binary_search(Iter from, Iter to, const T &val) {
    using _IterCategory = typename std::iterator_traits<Iter>::iterator_category;
    return _binary_search_impl(from, to, val, _IterCategory {});
}

}