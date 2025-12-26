#include <bits/stdc++.h>
using namespace std;
int main() {
        string line = "I am learning how to use cpp 12345";
        stringstream ss(line);

        vector<string> word;
        string token;

        while (ss >> token) {
                word.push_back(token);
        }
        for (const string& w : word) {
                cout << w << endl;
        }
        return 0;
}

