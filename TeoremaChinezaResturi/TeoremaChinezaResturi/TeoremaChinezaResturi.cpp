// TeoremaChinezaResturi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//in: b1,...bn-prime intre ele
//a1x=b1modc1
//a2x=b2modc2
//a3x=b3modc3
//a4x=b4modc4




//anx=bn mod cn
//out:x=? 
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
void EcuatieG1(int a, int b, int m,int &x) //Modificam putin functia
{
    int c, d, k;
    ExtendedEuclid(a, m, c, d, k);
    if (b % k == 0)
    {
        int bb = b / k;
        int xx = c * bb;
        for (int i = 0; i <= k - 1; i++)
            x= ((xx + i * m) / k) % m;
    }
}

void CRT(int v1[],int v2[],int v3[],int vsol[],int n)
{
    int m = 1;
    for (int i = 1; i <= n; i++)
        m = m * v3[i];
    for (int j = 1; j <= n; j++)
    {
        int x;
        int k = m / v3[j];
        EcuatieG1(v1[j], v2[j], k, x);
        vsol[j] = x;
    }
    int Sol=0;
    for (int i = 1; i <= n; i++)
        Sol = (Sol + (m / v3[i]) * vsol[i]) % m;
    cout << Sol;
}

int main()
{
    int n, v1[101], v2[101], v3[101], vsol[101];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v1[i] >> v2[i] >> v3[i];
    }
    CRT(v1, v2, v3, vsol, n);
}

