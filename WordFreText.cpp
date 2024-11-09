#include <iostream>
#include <sstream>
#include <map>
#include <cctype>
#include <algorithm>
using namespace std;

string normalizeWord(const string &word) {
    string result = word;
    for (char &ch : result) {
        if (isalpha(ch)) {
            ch = tolower(ch);
        }
    }
    return result;
}

int main() {
    string input;
    map<string, int> wordCount;

    while (getline(cin, input)) {
        stringstream ss(input);
        string word;

        while (ss >> word) {
            string cleanWord;
            for (char ch : word) {
                if (isalnum(ch)) {
                    cleanWord += ch;
                }
            }
            if (!cleanWord.empty()) {
                cleanWord = normalizeWord(cleanWord);
                wordCount[cleanWord]++;
            }
        }
    }

    for (const auto &entry : wordCount) {
        cout << entry.first << " " << entry.second << endl;
    }

    return 0;
}
