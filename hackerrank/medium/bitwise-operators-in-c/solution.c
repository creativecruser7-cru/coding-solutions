#include <stdio.h>

void calculate_the_maximum(int n, int k)
{
    int max_and = 0;
    int max_or = 0;
    int max_xor = 0;
    int result;

    for (int a = 1; a <= n; a++)
    {
        for (int b = a + 1; b <= n; b++)
        {
            result = a & b;
            if (result < k && result > max_and)
                max_and = result;

            result = a | b;
            if (result < k && result > max_or)
                max_or = result;

            result = a ^ b;
            if (result < k && result > max_xor)
                max_xor = result;
        }
    }

    printf("%d\n", max_and);
    printf("%d\n", max_or);
    printf("%d\n", max_xor);
}

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);

    calculate_the_maximum(n, k);

    return 0;
}
