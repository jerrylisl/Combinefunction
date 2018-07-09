#ifndef MFUNCTOR
#define MFUNCTOR
#include "Funcbase.h"

template<typename X, typename Y, typename F1, typename... Fs> //原型
class MFunc : public MFunc<X, Y, Fs...>
{
public:
    explicit MFunc(F1 f1, Fs... fs)
        : MFunc<X, Y, Fs...>(fs...),
          _f(f1)
           {}

     Y operator() (X x)
     {
         return _f(MFunc<X, Y, Fs...>::operator ()(x));
     }


private:
    F1 _f;
   // MFunc<X, Y, Fs...>  _fs;这里也可以用组合来实现，本质不变


};

template<typename X, typename Y, typename F1, typename F2> //二元偏特化
class MFunc<X, Y, F1, F2> : public Func_base<X, Y>
{
public:
    explicit MFunc(F1 f1, F2 f2)
        : _f1(f1),
          _f2(f2) {}
    Y operator() (X x)
    {
        return _f1(_f2(x));
    }

private:
    F1 _f1;
    F2 _f2;


};


template<typename X, typename Y>
class MFunctor
{
public:
    template<typename F1, typename... Fs>
    explicit MFunctor(F1 f1, Fs... fs)
        : _p(new MFunc<X, Y, F1, Fs...>(f1, fs...)) {}

    Y operator() (X x)
    {
        return (*_p)(x);
    }

    ~MFunctor() {delete _p;}

private:
    Func_base<X, Y>* _p;


};

template<typename X, typename Y, typename F1, typename... Fs>
MFunctor<X, Y> comb(F1 f1, Fs... fs)
{
    return MFunctor<X, Y>(f1, fs...);
}


#endif // MFUNCTOR

