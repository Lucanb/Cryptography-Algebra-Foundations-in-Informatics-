// EcuatieCongruentiala.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//input : a,b,m in Z with m>=1;
//output: all solutions modulo m of ax=b mod m;


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
void EcuatieG1(int a,int b,int m)
{
    int c, d, k;
    ExtendedEuclid(a, m, c, d, k);
    if (b % k == 0)
    {
        int bb = b / k;
        int xx = c * bb;
        for (int i = 0; i <= k - 1; i++)
            cout << ((xx + i * m) / k) % m;
    }
    else
        cout << "Ecuatia nu are solutii";
}
int main()
{
    int a, m, b, x;
    cin >> a >> b >> m; // va fi ax congruent b modulo m
    //Care sunt solutiile x?
    EcuatieG1(a, b, m);
}
