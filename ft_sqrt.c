#include<stdio.h>

/* ft_sqrt.c
 *
 * allowed functions: none
 *
 * Create a function that returns the square root of a number(if it exists), or 0 if the
 * square root is an irrational number.
 *
 * Here's how it should be prototyped:
 *      
 *      int ft_sqrt(int nb);
 * */

int ft_sqrt(int nb)
{
    int i = 0;
    int accumulator = 0;

    while(accumulator < nb)
    {
        accumulator = i * i;
        i++;
    }

    if(accumulator == nb)
    {
        return i - 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    // TESTS
    int num1 = 4;
    int num2 = 16;
    int num3 = 8;
    int num4 = 9;
    
    printf("%i\n", ft_sqrt(num1));
    printf("%i\n", ft_sqrt(num2));
    printf("%i\n", ft_sqrt(num3));
    printf("%i\n", ft_sqrt(num4));
}
