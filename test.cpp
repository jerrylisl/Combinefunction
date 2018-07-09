#include <iostream>
#include "Functor.h"
#include "SimpFunc.h"
#include "PtrFunc.h"
#include "MFunctor.h"
#include "VecFunctor.h"

using namespace std;

int f(int a)
{
    return a + 1;
}

int g(int a)
{
    return a * a;
}

class M
{
public:
    int operator() (int a)
    {
        return a - 3;
    }

};

class N
{
public:
    int operator() (int a)
    {
        return a / 2;
    }

};


using p = int(*)(int);

M m;
N n;


int main()
{
    PtrFunc fg = ptrcomb(f, g);
    cout << "PtrFunc fg(2) = " << fg(2) << endl;

    SimpFunc<int, int, p, p> gf = simpcomb<int, int, p, p>(g, f);
    cout << "SimpFunc gf(2) = " << gf(2) << endl;

    Functor<int, int> mn = comb<int, int>(m, n);
    cout << "Functor mn(2) = " << mn(2) << endl;

    VecFunctor<int, int> fff(f, f, f, 0);
    cout << "VecFunctor fff(2) = " << fff(2) << endl;

    MFunctor<int, int> mnfg = comb<int, int>(m, n, f, g);
    cout << "MFunctor mnfg(2) = " << mnfg(2) << endl;

    auto mg = [](int x)->int {return m(g(x));};
    cout << "lambdaStyle mg(2) = " << mg(2) << endl;


    return 0;
}

