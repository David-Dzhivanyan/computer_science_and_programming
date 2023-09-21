#include <chrono>
#include <fstream>
#include <iostream>
using namespace std;

class Exception_handling {
   private:
    string error_message;
    chrono::system_clock::time_point error_time;

   public:
    Exception_handling(const string& message) : error_message(message), error_time(chrono::system_clock::now()) { }

    void output_error() {
        time_t current_time = chrono::system_clock::to_time_t(error_time);
        cout << "Error: " << error_message << ". " << ctime(&current_time);

        ofstream log_file("log.txt", ios::app);
        if (log_file) {
            log_file << "Error: " << error_message << ". " << ctime(&current_time);
            log_file.close();
        } else {
            cerr << "n/a" << endl;
        }
    };
};

int main() {
    string filename;
    cout << "Enter a file name: ";
    cin >> filename;

    try {
        ifstream file(filename, ios::in);
        if (!file) {
            throw runtime_error("file not found");
        } else {
            string str1, str2;
            while (file >> str1 >> str2) {
                int num1 = stoi(str1), num2 = stoi(str2);

                if (num2 != 0) {
                    double result = num1 * 1. / num2 * 1.;
                    cout << result << endl;
                } else {
                    throw runtime_error("division by zero");
                }
            }
            file.close();
        }
    } catch (exception& e) {
        Exception_handling error(e.what());
        error.output_error();
    }

    return 0;
}