#include<stdio.h>

//an unsafe realizing.
void mystrcpy(char *t, char *s)
{
        while ((*s) != 0) {
                *t = *s;
                t++;
                s++;
        }
}

//linux version
void strcpy(char *t, char *s)
{
        while ((*t++ = *s++));
}

int main()
{
        printf("foobar");
}
