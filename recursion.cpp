#include <iostream>
#include <vector>

/* Calculate the factorial of n (recursive)
 * factorial of n do
 *   if n is <= 0 do
 *     return 1
 *   else do
 *     return n * factorial(n - 1)
*/
unsigned long
factorial(int n)
{
    return
        (n <= 0)
         ? 1
         : n * factorial(n - 1)
    ;
}

/* Calculate fibonacci number n (recursive)
 * fib(n) := (n<=2) ? 1 : fib(n-1) + fib(n-2)
*/
double
fibonacci_rec(int n)
{
    return
        (n<=2)
        ? 1
        : fibonacci_rec(n-1) + fibonacci_rec(n-2)
    ;
}

/* Calculate fibonacci number n (memoized)
 * fib(n) := (n<=2) ? 1 : fib(n-1) + fib(n-2)
*/
double
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

/* Calculate fibonacci number n (dynamic)
 * fib(n) := (n<=2) ? 1 : fib(n-1) + fib(n-2)
*/
double
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

// I'm using macros here to define fibonacci so we get accurate timing info
//#define fibonacci(n) fibonacci_rec(n)
//#define fibonacci(n) fibonacci_mem(n)
#define fibonacci(n) fibonacci_dyn(n)

int
main ()
{
    //std::cout << factorial(6) << std::endl;
    for(int i = 1; i <= 100; i++)
        std::cout << "Fib(" << i << ") = " << fibonacci(i) << std::endl;
}
