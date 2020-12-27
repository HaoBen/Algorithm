#include <vector>
#include <iostream>
#include <string>

using namespace std;

void func(string &str, int m) {
    if (m >= str.length()) return;

    int sep = str.length()-m;
    for (int i = 0, j = sep-1; i <= j; ++i,--j) swap(str[i], str[j]);
    for (int i = sep, j = str.length()-1; i <=j ; ++i,--j) swap(str[i], str[j]);
    for (int i = 0, j = str.length()-1; i <= j; ++i, --j) swap(str[i], str[j]);
    return;
}
// [from, to]
void helper(string &str, int from, int to) {
    while (from < to) {
        swap(str[from], str[to]);
        ++from; --to;
    }
}
void func1(string &str) {
    for (int i = 0; i < str.length();) {
        while (i < str.length() && str[i] == ' ') ++i;
        if (i < str.length()) {
            int j = i;
            while (i < str.length() && str[i] != ' ') ++i;
            helper(str, j, i-1);
        }
    }
    helper(str, 0, str.length()-1);
}
int main() {
    string test = "I love bao feng";
    func1(test);
    cout << test << endl;
}