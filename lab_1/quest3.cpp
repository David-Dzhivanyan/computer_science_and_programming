#include <cstdarg>
#include <iostream>

using namespace std;

template <typename Type>
concept Comparable = requires(Type a, Type b) {
    { a < b } -> std::convertible_to<bool>;
};

template <typename Type>
bool is_sort(Type first) {
    return true;
}

template <typename Type, typename... Args>
requires(Comparable<Args>&&...) bool is_sort(Type first, Type second, Args... args) {
    return (first < second && is_sort(second, args...));
}

int main() {
    bool answ = is_sort(1, 2, 3, 4, 1);

    cout << answ << endl;

    return 0;
}