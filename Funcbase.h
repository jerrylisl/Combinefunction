#ifndef FUNCBASE
#define FUNCBASE

template<typename X, typename Y>
class Func_base
{
public:
    virtual Y operator()(X) = 0;
};

#endif // FUNCBASE

