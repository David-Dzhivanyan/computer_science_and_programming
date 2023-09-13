#include <iostream>

using namespace std;

template <class Type>
class Vector {
   private:
    Type *elements = nullptr;
    int size_count;

   public:
    Vector() : elements(new Type[0]), size_count() {}

    int size() const { return size_count; }

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

int main() {
    Vector<int> V1;

    V1.push_back(0);
    V1.push_back(1);
    V1.push_back(2);
    V1.push_back(3);
    cout << V1 << endl;
    cout << V1.size() << endl;
    V1.erase(3);
    cout << V1 << endl;
    cout << V1.size() << endl;

    1 + V1;
    V1 + 1;
    2 * V1;
    V1 * 2;
    cout << V1 << endl;
}