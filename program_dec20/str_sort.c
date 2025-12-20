#include<stdio.h>
#include<string.h>
int main()
{
        int n;
        scanf("%d",&n);

        char str[n][101];
        for (int i = 0; i < n; i++) {
                fgets(str[i], 101, stdin);
        }

        char tmp[101];
        for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                        if (strlen(str[i]) > strlen(str[j])) {
                                strcpy(tmp, str[i]);
                                strcpy(str[i], str[j]);
                                strcpy(str[j], tmp);
                        }
                }
        }

        for (int k = 0; k < n; k++) {
                printf("%s", str[k]);
        }
        return 0;
}
