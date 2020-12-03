//This file is the result of tangling recursion.org. For a breakdown of how this works, refer to it.
#include <iostream>
#include <vector>

long double
factorial(int n)
{
    return
        (n <= 0)
         ? 1
         : n * factorial(n - 1)
    ;
}
long double
fibonacci_rec(int n)
{
    return
        (n<=2)
        ? 1
        : fibonacci_rec(n-1) + fibonacci_rec(n-2)
    ;
}
long double
fibonacci_mem(int n)
{
    static std::vector<double> cache(100,0);

    if(cache[n] == 0)
        cache[n] =
            (n<=2)
            ? 1
            : fibonacci_mem(n-1) + fibonacci_mem(n-2)
        ;

    return cache[n];
}
long double
fibonacci_dyn(int n)
{
    double prev = 1, prev2 = 1;

    for(int i = 3; i <= n; i++)
    {
        double buf = prev2;
        prev2 = prev;
        prev = buf + prev2;
    }

    return prev;
}
// I'm using macros here to define which function to benchmark without any overhead.
#define fn(n) factorial(n)
//#define fn(n) fibonacci_rec(n)
//#define fn(n) fibonacci_mem(n)
//#define fn(n) fibonacci_dyn(n)

int
main ()
{
    for(int i = 1; i <= 1000; i++)
        std::cout << "Function(" << i << ") = " << fn(i) << std::endl;
}
