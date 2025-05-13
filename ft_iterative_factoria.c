#include<stdio.h>

/* ft_iterative_factorial();
 *
 * allowed functions: none
 *
 * Create an iterated function that returns a number. This number is the result of a factorial
 * operation based on the number given as a parameter.
 *
 * If the argument is not valid the function should return 0.
 *
 * Overflows must not be handled, the function return will be undefined.
 *
 * Here's how it should be prototyped:
 *
 *      int ft_iterative_factorial(int nb);
 * */

int ft_iterative_factorial(int nb)
{
    int accumulator = 1;
    int i = 1;
    

    if(nb < 0)
    {
        return 0;
    }

    while(i <= nb)
    {
        accumulator *= i;
        i++;
    }

    return accumulator;
}

int main(void)
{
    int num_1 = ft_iterative_factorial(-1);

    printf("%i", num_1);
}
