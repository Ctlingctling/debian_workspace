#include <bits/stdc++.h>

using namespace std;

void word_reverse();

int main() {
        word_reverse();
        return 0;
}

void word_reverse() {
        string line = "I am learning how to use cpp 12345";
        stringstream ss(line);

        vector<string> words;
        string token;

        while (ss >> token) {
                words.push_back(token);
        }
        for (string& w : words) {
                cout << w << ' ';
        }

        cout << endl;

        for (string& w : words) {
                reverse(w.begin(), w.end());
                cout << w << ' ';
        }
        cout << endl;
}
