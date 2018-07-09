#ifndef WRONGFUNC
#define WRONGFUNC

//这一页的代码全是理想的设计方案以及无法通过的代码

//目标：一个函数，输入为函数，输出为输入函数的组合函数，即：
/*
 *   fg = comb(f, g);
 *
 *   则fg（x）等价于f(g(x))
 *
 */

//函数指针的一个空想,行不通
using p = int(*)(int);

p comb(p f, p ,g)
{
    return int result(int x) {f(g(x));};
}

//排除嵌套定义，因为域的原因，行不通
int result(int x)
{
    f(g(x));
}

p comb(p f, p, g)
{
    return &result;
}

//C++11后可以使用lambda表达式，但下列方案依旧行不通,lambda不是一个函数指针
p comb (p f, p g)
{
    return [f, g](int x)->int {return f(g(x));};
}

//试图用模板改良上述方案，但参数无法推导，行不通
template<typename X, typename Y, typename T, typename F, typename G>
T comb(F f, G g)
{
    return [f, g](X x) -> Y {return f(g(x));};
}


#endif // WRONGFUNC

