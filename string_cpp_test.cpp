#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
        string s;
        getline(cin, s);
        int left = 0;
        int right = s.length() - 1;

        //reverse(s.begin(), s.end());
        while (left < right) {
                char temp = s[left];
                s[left] = s[right];
                s[right]= temp;
                left++;
                right--;
        }
        cout << s << endl;
        return 0;
}
