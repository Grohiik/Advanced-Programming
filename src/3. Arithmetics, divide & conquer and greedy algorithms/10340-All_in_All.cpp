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
    return words;
}

int main() {
    string input;
    string space_delimiter = " ";
    while (getline(cin, input)) {
        auto splitstring = split(input, space_delimiter);
        int counter = 0;
        bool sequence = true;
        for (auto const &letter : splitstring[0]) {
            for (; counter < splitstring[1].length(); counter) {
                if (letter == splitstring[1][counter]) {
                    break;
                }
            }
        }
        if (counter >= splitstring[1].length()) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}