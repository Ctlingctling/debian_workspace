#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int main()
{
        string a1 = "Pro";
        string a2 = "gram";
        a1 += a2;
        cout << a1 << endl;

        string a3 = a2;
        cout << a3 << endl;

        return 0;
}
