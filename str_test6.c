#include<stdio.h>
#include<string.h>

int main()
{
        char weekday[7][10] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
        printf ("%p %p", weekday, weekday + 1);
        printf ("%s %s", weekday, weekday + 1);
}
