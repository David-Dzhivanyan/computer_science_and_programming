#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <locale>
#include <cctype>
#include <set>
using namespace std;

// Функция для приведения строки к нижнему регистру
//string toLowercase(string& str) {
//    char32_t table[256] = { U'а', U'б', U'в', U'г', U'д', U'е', U'ж', U'з', U'и', U'й', U'к', U'л', U'м', U'н', U'о', U'п', U'р', U'с', U'т', U'у', U'ф', U'х', U'ц', U'ч', U'ш', U'щ', U'ъ', U'ы', U'ь', U'э', U'ю', U'я' };
//    for(int i=0; i<sizeof(str)-1; i++)
//        str[i] = table[str[i]];
//}

void printSet(const set<string>& s) {
    for (const string & element : s) {
        cout << element << " ";
    }
    cout << endl;
}

bool startsWithPrefix(const std::string& word, const std::string& prefix) {
    return word.find(prefix) == 0;
}

bool endsWithConsonant(const std::string& word, const std::set<char>& consonants) {
    char lastChar = word.back();
    return (consonants.find(lastChar) != consonants.end());
}

int main() {
    setlocale(LC_ALL,"ru");

    ifstream file("text2.txt");
    ifstream stop_file("text.txt");
    if (!file || !stop_file) {
        cout << "File opening error!" << endl;
        return 1;
    }

    map<string, int> word_frequency;
    set<string> stop_word;
    multimap<int, string, greater<int>> sorted_words; //используется третий аргумент greater<int> для мультикарты sortedWords, чтобы пары были упорядочены по убыванию.
    string word;

    while (stop_file >> word) {
        stop_word.insert(word);
    }
    //printSet(stop_word);

    while (file >> word) {
        if(isalpha(word.front())){
            continue;
        }

        // Исключаем знаки препинания
        word.erase(remove_if(word.begin(), word.end(), [](unsigned char c) { return ispunct(c); }), word.end());

        // Если слово не пустое, увеличиваем его счетчик в map
        if (!word.empty() && stop_word.find(word) == stop_word.end()) {
            word_frequency[word]++;
        }
    }

    int count = 0;
    // Заполняем multimap
    for (const auto& pair : word_frequency) {
        sorted_words.insert(::pair<int, string>(pair.second, pair.first));
        count++;
    }
    cout << "Number of words: " << count << endl;

    // Выводим результаты
    count = 0;
    for (const auto& pair : sorted_words) {
        if (count == 50) {
            break;
        }
        cout << pair.first << ": " << pair.second << endl;
        count++;
    }

    string user_input_occurrence;
    cout << "Enter the key occurrence: ";
    cin >> user_input_occurrence;

    auto it = word_frequency.find(user_input_occurrence);
    if (it != word_frequency.end()) {
        cout << "Word: " << it->first << ", Frequency of occurrence: " << it->second << endl;
    } else {
        cout << "There's no such word." << endl;
    }

    string user_input_erase;
    cout << "Enter the key delete: ";
    cin >> user_input_erase;

    auto it1 = word_frequency.find(user_input_erase);
    if (it1 != word_frequency.end()) {
        word_frequency.erase(it);
        cout << "The word has been deleted." << endl;
    } else {
        cout << "There's no such word." << endl;
    }

    count = 0;
    // Пересчитываем, чтобы посмотреть количество слов
    for (const auto& pair : word_frequency) {
        sorted_words.insert(::pair<int, string>(pair.second, pair.first));
        count++;
    }
    cout << "Number of words: " << count << endl;

    string new_key;
    cout << "Enter the key: ";
    cin >> new_key;

    string new_value;
    cout << "Enter the new value: ";
    cin >> new_value;

    auto it3 = word_frequency.find(new_key);
    if (it3 != word_frequency.end()) {
        it3->second = stoi(new_value); // Заменяем старое значение на новое
    } else {
        word_frequency[new_key] = stoi(new_value); // Добавляем новое слово и его значение
    }

    count = 0;
    // Пересчитываем, чтобы посмотреть количество слов
    for (const auto& pair : word_frequency) {
        sorted_words.insert(::pair<int, string>(pair.second, pair.first));
        count++;
    }
    cout << "Number of words: " << count << endl;

    //set<char> vowels = {'а', 'е', 'ё', 'и', 'о', 'у', 'ы', 'э', 'ю', 'я'};
    //set<char> consonants = {'б', 'в', 'г', 'д', 'ж', 'з', 'й', 'к', 'л', 'м', 'н', 'п', 'р', 'с', 'т', 'ф', 'х', 'ц', 'ч', 'ш', 'щ'};

//    string word1;
//
//    std::map<std::string, int> filteredWords;
//    filter(word_frequency.begin(), word_frequency.end(), std::inserter(filteredWords, filteredWords.begin()),
//           [&](const std::pair<std::string, int>& pair) {
//               return !startsWithPrefix(pair.first, "при"); //&& !endsWithConsonant(pair.first, consonants);
//           });
//
//    for (const auto& pair : filteredWords) {
//        std::cout << pair.first << ": " << pair.second << std::endl;
//

    stop_file.close();
    file.close();
    return 0;
}


