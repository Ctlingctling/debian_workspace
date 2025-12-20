#include<stdio.h>
#include<string.h>
int main()
{
        int n;
        scanf("%d", &n);
        getchar();

        char str[n][101];
        for (int i = 0; i < n; i++) {
                fgets(str[i], 101, stdin);
                int len = strlen(str[i]);
                if (len > 0 && str[i][len - 1] == '\n') {
                        str[i][len - 1] = '\0';
                }
        }

        char tmp [101];
        
        for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                        if (strlen(str[i]) > strlen(str[j])) {
                                strcpy(tmp, str[i]);
                                strcpy(str[i], str[j]);
                                strcpy(str[j], tmp);
                        } else if (strlen(str[i]) == strlen(str[j])) {
                                if (strcmp(str[i], str[j]) > 0) {
                                        strcpy(tmp, str[i]);
                                        strcpy(str[i], str[j]);
                                        strcpy(str[j], tmp);
                                }
                        }
                }
        }

        for (int k = 0; k < n; k++) {
                if (k == n) printf("%s", str[k]);
                printf("%s\n", str[k]);
                
        }
        return 0;
}
