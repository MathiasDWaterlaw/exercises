#include<stdio.h>

/* ft_recursive_factorial();
 *
 * Allowed functions: none
 *
 * Create a recursive function that returns the factorial of the number given
 * as a parameter.
 *
 * If the argument is not valid the function should return 0.
 *
 * Overfows must not be handled, the function return will be undefined.
 *
 * Here's how it should be prototyped:
 *
 *      int ft_recursive_factorial(int nb);
 * */

int ft_recursive_factorial(int nb)
{   
    if(nb < 0)
    {
        return 0;
    }

    if(nb == 0)
    {
        return 1;
    }

    return nb *= ft_recursive_factorial(nb - 1);
}

int main(void)
{
    int num_1 = ft_recursive_factorial(5);

    printf("%i", num_1);
}
