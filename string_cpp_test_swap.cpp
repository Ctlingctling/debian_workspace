#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
        string s;
        getline(cin, s);

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
        }

        cout << s << endl;
        return 0;
}
