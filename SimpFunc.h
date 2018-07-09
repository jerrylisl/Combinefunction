#ifndef SIMPFUNC
#define SIMPFUNC

template<typename X, typename Y, typename F, typename G>
class SimpFunc
{
public:
    explicit SimpFunc(F f, G g)
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

template<typename X, typename Y, typename F, typename G>
SimpFunc<X, Y, F, G> simpcomb(F f, G g)
{
    return SimpFunc<X, Y, F, G>(f, g);
}



#endif // SIMPFUNC

