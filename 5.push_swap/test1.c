

#include <stdio.h>

int main(void)
{
    int dp[10] = {1};
    int i = 0;
    while(i < 10)
    {
        printf("%d\n", dp[i]);
        i++;
    }
    return(0);
}