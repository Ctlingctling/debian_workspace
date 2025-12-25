#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main() {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string word;
        int count = 0;
        string longest_word = "";

        while (ss >> word) {
                count++;
                if (word.length() > longest_word.length()) {
                        longest_word = word;
                }
        }

        cout << "word count: " << count << endl;
        cout << "longest wd: " << longest_word << endl;
        cout << "longest wd: " << longest_word.length() << endl;
        return 0;
}
