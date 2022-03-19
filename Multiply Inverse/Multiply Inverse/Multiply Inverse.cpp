// Multiply Inverse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void ExtendedEuclid(int a, int b, int& c, int& d, int& k)
{

    int e, f;
    int g, h;
    e = 1, f = 0;//V0;
    g = 0; h = 1;//V1;

    while (b != 0)
    {
        int q = a / b;
        int r = a % b;
        a = b, b = r;
        c = e, d = f;//V=V0;
        e = g; f = h;//V0=V1;
        g = (c - (q * g)); h = d - (q * h); //V1=V-q*V1;
    }
    k = a;
    c = e; d = f; //V=V0;
}
int MultiplyInverse(int a, int m)
{
    int k, c, d, x, y;
    int n;
    ExtendedEuclid(a, m, c, d, n);
    if (n != 1)
    {
        return 0;
    }
    else
        return c % m;
}
int main()
{
    int a, m;
    cin >> a >> m;
    cout<<MultiplyInverse(a, m);
}
