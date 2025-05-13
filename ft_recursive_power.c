#include<stdio.h>

/* ft_recursive_power();
 *
 * Create a recursive function that returns the value of a power applied to a number.
 *
 * Overflows must not be handled, the function return will be undefined.
 *
 * We've decided that 0 power 0 will returns 1
 *
 * Here's how it should be prototyped:
 *
 *      int ft_recursive_power(int nb, int power);
 * */

int ft_recursive_power(int nb, int power)
{
    if(power < 0)
    {
        return 0;
    }

    if(power == 0 && nb == 0)
    {
        return 1;
    }

    if(power == 0)
    {
        return 1;
    }

    return nb *= ft_recursive_power(nb, power - 1);
}

int main(void)
{
    int num = ft_recursive_power(5, 2);

    printf("%i", num);
}
