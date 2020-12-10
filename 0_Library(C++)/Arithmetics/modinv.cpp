#include "../INCLUDES.h"

int gcd_ext(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {
        int d = gcd_ext(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }
}

int modinv(int a, int M)
{ // aの逆元を求める
    int x, y;
    gcd_ext(a, M, x, y);
    return (M + x % M) % M;
}