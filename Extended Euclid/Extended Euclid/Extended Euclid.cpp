// Extended Euclid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//input:a,b from Z;different from 0.
//output:(a,b) V=(c,d) with (a,b)=ac+bd;
//d= (a,b);


//Ideea e sa scrie ca o combinatie liniara : ac+bd=k unde k=(a,b);
#include <iostream>
using namespace std;
int main()
{
    int a,b,c, d,k;
    int e, f;
    int g, h;
    cin >> a >> b;
    e = 1, f = 0;//V0;
    g = 0; h = 1;//V1;

    while (b != 0)
    {
        int q = a / b;
        int r = a % b;
        a = b, b = r;
        c = e, d = f;//V=V0;
        e = g; f = h ;//V0=V1;
        g = (c-(q*g)); h =d-(q*h); //V1=V-q*V1;
    }
    k = a;
    c = e;d = f; //V=V0;

    cout << k << '\n';
    cout << c << ' ' << d;
}
