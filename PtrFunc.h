#ifndef PTRFUNC
#define PTRFUNC


class PtrFunc
{
public:
    using p = int(*)(int);
    explicit PtrFunc(p f, p g)
        : _f(f),
          _g(g) {}


    int operator() (int x)
    {
        return _f(_g(x));
    }

private:
    p _f;
    p _g;

};

PtrFunc ptrcomb(PtrFunc::p f, PtrFunc::p g)
{
    return PtrFunc(f, g);
}

#endif // PTRFUNC

