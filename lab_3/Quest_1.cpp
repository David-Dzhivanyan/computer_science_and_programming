#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
using namespace std;

struct Fraction {
    int numerator;
    int denominator;
};
bool operator<(const Fraction& f1, const Fraction& f2) {
    return (f1.numerator * f2.denominator) < (f2.numerator * f1.denominator);
}
bool operator>(const Fraction& f1, const Fraction& f2) {
    return (f1.numerator * f2.denominator) > (f2.numerator * f1.denominator);
}
bool compareFractions(const Fraction& f1, const Fraction& f2) {
    return (f1.numerator * f2.denominator) == (f2.numerator * f1.denominator);
}
bool isFractionGreaterThan10(const Fraction& f) {
    return ((f.numerator/f.denominator) > 10);
}

int get_random_num(int max, int min){
    return (rand() % (min - max + 1)) + max;
}
Fraction get_random_fraction(int min, int max) {
    Fraction fraction;
    fraction.numerator = get_random_num(min, max);
    fraction.denominator = get_random_num(min, max);
    return fraction;
}

void ptintFraction(vector<Fraction>& vec){
    for (const Fraction& fraction : vec) {
        cout << fraction.numerator << "/" << fraction.denominator << " ";
    }
    cout << endl << "Size: " << vec.size() << endl;

    if(vec.size() == 0){
        cout << "is empty." << endl;
    }
}

int main() {
    srand(time(nullptr));

    int n; // количество элементов в векторах
    int min, max; // диапазон для генерации значений

    cout << "Enter the number of elements in the vectors: ";
    cin >> n;

    cout << "Enter the minimum value to generate: ";
    cin >> min;

    cout << "Enter the maximum value to generate: ";
    cin >> max;
    
    vector<Fraction> vector1, vector2;

    // Заполняем первый вектор случайными дробями
    for (int i = 0; i < n; i++) {
        vector1.push_back(get_random_fraction(min, max));
    }

    // Заполняем второй вектор случайными дробями
    for (int i = 0; i < n; i++) {
        vector2.push_back(get_random_fraction(min, max));
    }

    // Выводим элементы первого вектора
    cout << "Первый вектор: ";
    ptintFraction(vector1);

    // Выводим элементы второго вектора
    cout << "Второй вектор: ";
    ptintFraction(vector2);

//    vector1.reserve(10);
//
//    cout << "After reserve(10):" << endl;
//    ptintFraction(vector1);
//    cout << "Capacity: " << vector1.capacity() << endl;
//
//    vector1.resize(5);
//
//    cout << "After resize(5):" << endl;
//    cout << "Capacity: " << vector1.capacity() << endl;
//    ptintFraction(vector1);

    stable_sort(vector1.begin(), vector1.end());
    stable_sort(vector2.begin(), vector2.end());
    ptintFraction(vector1);
    ptintFraction(vector2);

    vector<Fraction> vector3;
    set_intersection(vector1.begin(), vector1.end(), vector2.begin(), vector2.end(),
                          back_inserter(vector3));

    ptintFraction(vector3);

    vector<Fraction> vector4;
    unique_copy(vector3.begin(), vector3.end(), back_inserter(vector4), compareFractions);

    ptintFraction(vector4);


    Fraction f1 = {0, 0};
    replace_if(vector3.begin(), vector3.end(), isFractionGreaterThan10, f1);

    ptintFraction(vector3);

//    - size() возвращает текущий фактический размер вектора (количество элементов в нём).
//    - capacity() возвращает текущую емкость вектора (сколько элементов вектор может хранить до того, как ему потребуется снова расшириться).
//    - resize(size_type) изменяет фактический размер вектора на заданное значение. Изменив размер, он может как увеличиваться, так и уменьшаться.
//    - reserve(size_type) резервирует память вектора для будущего использования, чтобы предотвратить неэффективные повторные выделения памяти,
//    когда элементы добавляются в вектор. Размер фактических элементов вектора после вызова reserve() остается неизменным.
    return 0;
    
}