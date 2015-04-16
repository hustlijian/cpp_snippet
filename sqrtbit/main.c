#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef unsigned int U32;

#define LEN_QUEST 100 /* precision */
#define A 2  /* A^0.5 */

U32 InvMpy(U32 *a, U32 m, U32 n)/* res = a(m)a(n) + a(m+1)a(n-1) + ... + a(n)a(m) */
{
    U32 i;
    U32 res;
    if (n < m)
        return 0;
    if (n == m)
        return(a[m] * a[m]);

    res = 0;
    for (i = 0; i <= n; i++)
    {
        res += a[m+i] * a[n-i];
    }
    return res;
}

U32 Calc(U32 *res, U32 rest, U32 precision, U32 len)
{
    U32 tmp;
    U32 max;
    U32 isRight = 0;

    rest = 10 * rest;
    tmp = InvMpy(res, 1, precision-1);
    // printf("precision:%u, rest:%u, tmp: %u, res[p]:%u\n", precision, rest, tmp, res[precision]);
    if (tmp > rest) {
        return 0;
    }
    if ((precision > len) && (tmp != rest)) {
        return 1;
    }
    max = (rest - tmp)>> 1;
    if (max > 9)
        max = 9;
    for (int i = max; i >= 0; i--)
    {
        res[precision] = i;
        tmp = InvMpy(res, 0, precision);
        if (tmp > rest)
            continue;
        tmp = rest - tmp;
        tmp = Calc(res, tmp, precision+1, len);
        if (tmp != 0)
        {
            isRight = 1;
            break;
        }
    }
    return isRight;
}

int main(int argc, char *argv[])
{
    U32 *res;
    U32 rest;
    U32 x = A;
    U32 len = LEN_QUEST;

    if (argc > 1) {
        x = atoi(argv[1]);
    }
    if (argc > 2) {
        len = atoi(argv[2]);
    }

    res = (U32*) malloc(sizeof(U32) * (len+2));
    memset(res, 0, sizeof(U32) * (len+2));

    res[0] = (U32)sqrt(1.0L*x);

    rest = x - res[0] * res[0];

    Calc(res, rest, 1, len);

    printf( "%d.",(int)res[0]);
    for (U32 i = 1; i <= len; i++)
    {
        printf("%d",(int)res[i]);
    }
    printf("\n");
    printf("The %uth sqrt(%u) digit is: %u\n", len, x, res[len]);

    free(res);
    return 0;
}
