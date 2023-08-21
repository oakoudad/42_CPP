#include <stdio.h>

int main()
{
    int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i = 0;
    int odd = 9;

    while (i < 10)
    {
        if (num[i] % 2 == 1)
        {
            i++;
            continue;
        }
        if (num[odd] % 2 == 0)
        {
            odd--;
            continue;
        }
        num[i] = num[i] + num[odd];
        num[odd] = num[i] - num[odd];
        num[i] = num[i] - num[odd];
        i++;
        odd--;
    }
    i = 0;
    while (i < 10)
        printf("%d ", num[i++]);
}