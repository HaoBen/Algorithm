#include <iterator>

namespace my {

template <typename T, typename Iter>
Iter _violent_search_impl(Iter from, Iter to, const T &val, const std::input_iterator_tag&) {
    while (from < to) {
        if (*from == val) return from;
        else ++from;
    }
    return to;
}

template <typename T, typename Iter>
Iter violent_search(Iter from, Iter to, const T &val) {
    using _IterCategory = typename std::iterator_traits<Iter>::iterator_category;
    return _violent_search_impl(from, to, val,  _IterCategory{});
}

}