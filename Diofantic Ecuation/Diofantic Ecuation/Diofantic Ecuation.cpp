// Diofantic Ecuation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//input:a,b,c from Z with ax+by=m;
//output "fail if it doesnt have integrer solution " or V=[x,y] a possible solution.

#include <iostream>
using namespace std;
void ExtendedEuclid(int a,int b,int &c,int &d ,int &k)
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
void Dyofantic(int a, int b,int  m)
{
    int  c, d, k, cprim, x, y;
   
    ExtendedEuclid(a, b, c, d, k);
    if (m%k != 0)
        cout << "FAIL!";
    else
    {
        cprim = m / k;
        x = cprim * c;
        y = cprim * d;
    }
    cout << x << ' ' << y;
}
int main()
{
    int a, b, m;
    cin >> a >> b >> m;
    Dyofantic(a, b, m);
}
