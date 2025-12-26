#include <bits/stdc++.h>
using namespace std;
int main() {
        word_reverse();
}

void word_reverse() {
        string line = "I am learning how to use cpp 12345";
        stringstream ss(line);

        vector<string> word;
        string token;

        while (ss >> token) {
                word.push_back(token);
        }
        for (string& w : word) {
                reverse(w.begin(), w.end());
                cout << w << ' ';
        }
        return 0;
}