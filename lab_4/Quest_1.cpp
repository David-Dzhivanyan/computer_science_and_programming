#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

// Функция для разделения текста на предложения
vector<string> splitSentences(const string& text) {
    vector<string> sentences;
    string sentence;
    size_t pos = 0;
    size_t found;

    while ((found = text.find('.', pos)) != string::npos) {
        sentence = text.substr(pos, found - pos + 1);
        sentences.push_back(sentence);
        pos = found + 1;
    }

    return sentences;
}

// Функция для формирования множества букв из предложения
set<char> getLettersSet(const string& sentence) {
    set<char> lettersSet;
    for (char c : sentence) {
        if (isalpha(c)) { // Проверка, является ли символ буквой
            lettersSet.insert(c); // Приведение символа к нижнему регистру и добавление в множество
        }
    }
    return lettersSet;
}

// Функция для печати множества
void printSet(const set<char>& s) {
    for (const char & element : s) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    ifstream file("text1.txt");
    if (!file) {
        cout << "File opening error!" << endl;
        return 1;
    }

    string text((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    cout << text;

    vector<string> sentences = splitSentences(text);

    set<char> set1 = getLettersSet(sentences[0]);
    set<char> set2 = getLettersSet(sentences[1]);

    printSet(set1);
    printSet(set2);


    set<char> union_set;
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(union_set, union_set.begin()));
    cout << "Association: ";
    printSet(union_set);

    set<char> intersection_set;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(intersection_set, intersection_set.begin()));
    cout << "Intersection: ";
    printSet(intersection_set);

    set<char> difference_set;
    set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(difference_set, difference_set.begin()));
    cout << "Difference: ";
    printSet(difference_set);

    return 0;
}