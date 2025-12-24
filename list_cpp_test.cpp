#include<iostream>
#include<list>

int main()
{
        list<int> test;

        test.push_back(10);
        test.push_front(20);
        test.push_back(30);

        test.pop_front();
        test.pop_back();

        test.push_front(30);

        test.sort();
        test.reverse();
}
