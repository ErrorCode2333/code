#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _Max 1000
int num[_Max];
int ans[_Max]; // 商
int res[_Max]; // 余数

int main () {

    int M, N;
       
    while (scanf("%d%d", &M, &N) != EOF);
    {

        char cnum[1000];
        scanf("%s", cnum);

        int len = strlen(cnum);

        for (int i = 0; i < len; i++)
        {
            char c = cnum[i];
            num[i] = (c <= '9') ? c - '0' : (c - 'A' + 10);
        }

        int index = 0;

        while (len)
        {
            int s = 0;
            for (int i = 0; i < len; i++)
            {
                s = s * M + num[i];
                ans[i] = s / N;
                s = s % N;
            }
            
            res[index++] = s;

            int p = 0;
            // 复制商
            while (ans[p] == 0 && p < len)
                p++;

            memset(num, 0, sizeof(num));

            int k = 0;
            // memcpy(num, ans + p, sizeof(int) * (len - p));
            for (int j = p; j < len; j++)
            {
                num[k++] = ans[j];
            }

            memset(ans, 0, sizeof(ans));

            len = k;
        }


        for (int i = index - 1; i >= 0; i--)
        {
            int n = res[i];
            if (n < 10)
            {
                printf("%d", n);
            }

            else
            {
                char c = n - 10 + 'a';
                printf("%c", c);
            }
        }

        printf("\n");
    }
    return 0;
}
