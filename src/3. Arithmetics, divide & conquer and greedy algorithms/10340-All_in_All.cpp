/*
https://onlinejudge.org/external/103/10340.pdf
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string input, const string &delimiter) {
    vector<string> words{};
    size_t pos = 0;
    while ((pos = input.find(delimiter)) != string::npos) {
        words.push_back(input.substr(0, pos));
        input.erase(0, pos + delimiter.length());
    }
    words.push_back(input);
    return words;
}

int main() {
    string input;
    string space_delimiter = " ";
    while (getline(cin, input)) {
        auto splitstring = split(input, space_delimiter);
        int counter = 0;
        bool last_check = false;
        for (auto const &letter : splitstring[0]) {
            while (counter < splitstring[1].length()) {
                if (letter == splitstring[1][counter]) {
                    counter++;
                    last_check = true;
                    break;
                }
                counter++;
                last_check = false;
            }
        }
        if (counter >= splitstring[1].length() && !last_check) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
}