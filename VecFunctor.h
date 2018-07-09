#ifndef VECFUNCTOR
#define VECFUNCTOR

#include"Funcbase.h"
#include<vector>
#include<stdarg.h>

template<typename X, typename Y, typename F>
class VecFunc : public Func_base<X, Y>
{
public:
    using p = int(*)(int);
    explicit VecFunc(std::vector<F> fs)
        :_Fs(fs)    {    }


    Y operator() (X x)
    {
        for (int i = 0; i < _Fs.size(); ++ i)
        {
            x = _Fs[i](x);
        }
        return x;
    }

private:
    std::vector<F> _Fs;
};

template<typename X, typename Y>
class VecFunctor
{
public:
    template<typename F>
    explicit VecFunctor(F f, ...)
    {
        va_list ap;
        va_start(ap, f);
        std::vector<F> fs;
        fs.push_back(f);
        F temp = va_arg(ap, F);
        while (temp != 0)
        {
            fs.push_back(temp);
            temp = va_arg(ap, F);
        }
        va_end(ap);
        _p = new VecFunc<X,Y,F>(fs);
    }


    Y operator() (X x)
    {
        return (*_p)(x);
    }

    ~VecFunctor() {delete _p;}

private:
    Func_base<X, Y>* _p;


};


#endif // VECFUNCTOR

