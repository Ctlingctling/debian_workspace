#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[10])
{
        while (argc > 1) {
                ++argv;
                printf("%s\n", *argv);
                --argc;
        }
        return 0;
}
