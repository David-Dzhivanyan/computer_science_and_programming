#include <math.h>

#include <iostream>

using namespace std;

class Coordinates {
   private:
    double latitude;
    double longitude;

   public:
    Coordinates() : latitude(), longitude() {}
    Coordinates(double x, double y) : latitude(x), longitude(y) {}

    double get_latitude_r() { return latitude * 0.017453; }
    double get_longitude_r() { return longitude * 0.017453; }

    void output() {
        cout << "degree: " << latitude << " " << longitude << endl;
        cout << "radian: " << (latitude * 0.017453) << " " << (longitude * 0.017453) << endl;
    }
};

template <typename Type>
concept is_pointer_check = !is_pointer<Type>::value;

template <typename Type>
concept StringLike = !is_convertible_v<Type, string>;

template <typename Type>
concept final_concept = is_pointer_check<Type> && StringLike<Type>;

template <typename Type>
requires final_concept<Type>
class Vector {
   private:
    Type *elements = nullptr;
    size_t size_count;

   public:
    Vector() : elements(new Type[0]), size_count() {}
    Vector(Type *arr, size_t val) : elements(new Type[val]), size_count(val) {
        for (int i = 0; i < size_count; i++) {
            elements[i] = arr[i];
        }
    }

    size_t size() const { return size_count; }

    void resize(int new_size) {
        Type *tempElem = new Type[new_size];
        if (new_size < size_count) {
            for (int i = 0; i < new_size; i++) tempElem[i] = elements[i];
        } else if (new_size > size_count) {
            for (int i = 0; i < size_count; i++) tempElem[i] = elements[i];
        }
        delete[] elements;
        elements = tempElem;
        size_count = new_size;
    }

    void push_back(const Type &val) {
        resize(size_count + 1);
        elements[size_count - 1] = val;
    }

    void erase(int pos) {
        for (int i = pos; i < size_count; i++) {
            elements[i] = elements[i + 1];
        }
        resize(size_count - 1);
    }

    int distance(Vector<Type> &vector) {
        if (size_count != vector.size_count) {
            return -1;
        } else {
            int d = 0;
            for (int i = 0; i < size_count; i++) {
                d += pow(vector.elements[i] - elements[i], 2);
            }

            return sqrt(d);
        }
    }

    friend ostream &operator<<(ostream &out, const Vector<Type> &vector) {
        for (int i = 0; i < vector.size_count; ++i) {
            out << vector.elements[i] << " ";
        }

        return out;
    }
    friend void operator+(double num, const Vector<Type> &vector) {
        for (int i = 0; i < vector.size_count; ++i) {
            vector.elements[i] = vector.elements[i] + num;
        }
    }
    friend void operator+(const Vector<Type> &vector, double num) {
        for (int i = 0; i < vector.size_count; ++i) {
            vector.elements[i] = vector.elements[i] + num;
        }
    }
    friend void operator*(double num, const Vector<Type> &vector) {
        for (int i = 0; i < vector.size_count; ++i) {
            vector.elements[i] = vector.elements[i] * num;
        }
    }
    friend void operator*(const Vector<Type> &vector, double num) {
        for (int i = 0; i < vector.size_count; ++i) {
            vector.elements[i] = vector.elements[i] * num;
        }
    }
    ~Vector() { delete[] elements; }
};

template <>
class Vector<Coordinates> {
   private:
    Coordinates *elements = nullptr;
    size_t size_count = 2;

   public:
    Vector(Coordinates A, Coordinates B) {
        elements = new Coordinates[2];
        elements[0] = A;
        elements[1] = B;
    }

    double distance() {
        double first = pow(cos(elements[1].get_latitude_r()) *
                               sin(elements[0].get_longitude_r() - elements[1].get_longitude_r()),
                           2);
        double second = pow(cos(elements[0].get_latitude_r()) * sin(elements[1].get_latitude_r()) -
                                sin(elements[0].get_latitude_r()) * cos(elements[1].get_latitude_r()) *
                                    cos(elements[0].get_longitude_r() - elements[1].get_longitude_r()),
                            2);
        double third = sin(elements[0].get_latitude_r()) * sin(elements[1].get_latitude_r());
        double fourth = cos(elements[0].get_latitude_r()) * cos(elements[1].get_latitude_r()) *
                        cos(elements[0].get_longitude_r() - elements[1].get_longitude_r());

        double b = atan((sqrt(first + second)) / (third + fourth));
        b *= 6372795;
        return b / 1000.;
    }

    ~Vector() { delete[] elements; }
};

int main() {
    //    int arr1[] = {1, 3, 3};
    //    int arr2[] = {1, 2, 4};
    //    //    int* arr1[] = {};
    //    //    string arr1[] = {"1", "2","3"};
    //    Vector<int> V1(arr1, 3);
    //    Vector<int> V2(arr2, 3);
    //
    //    int d = V1.distance(V2);
    //    cout << d << endl;

    Coordinates a(48.707067, 44.516975);  // Vlg
    Coordinates b(55.755864, 37.617698);  // Msk

    Vector<Coordinates> V1(a, b);

    cout << V1.distance() << "km" << endl;
}