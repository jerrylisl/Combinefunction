#ifndef FUNCTOR
#define FUNCTOR

#include "Funcbase.h"



template<typename X, typename Y, typename F, typename G>
class Func : public Func_base<X, Y>
{
public:
    explicit Func(F f, G g)
        : _f(f),
          _g(g) {}


    Y operator() (X x)
    {
        return _f(_g(x));
    }

private:
    F _f;
    G _g;

};

template<typename X, typename Y>
class Functor
{
public:
    template<typename F, typename G>
    explicit Functor(F f, G g)
        : _p(new Func<X, Y, F, G>(f, g)) {}

    Y operator() (X x)
    {
        return (*_p)(x);
    }

    ~Functor() {delete _p;}

private:
    Func_base<X, Y>* _p;


};

template<typename X, typename Y, typename F, typename G>
Functor<X, Y> comb(F f, G g)
{
    return Functor<X, Y>(f, g);
}


#endif // FUNCTOR

