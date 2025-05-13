#include<stdio.h>

/* ft_iterative_power();
 *
 * Create an iterated function that returns the value of a power applied to a number.
 * An power lower than 0 returns 0. Overflow must not be handled.
 *
 * We've decided that 0 power 0 will return 1
 *
 * Here's how it should be prototyped:
 *      
 *      int ft_iterative_power(int nb, int power);
 * */

int ft_iterative_power(int nb, int power)
{
    int accumulator = 1;
    
    if(power < 0)
    {
        return 0;
    }
    
    if(nb == 0 && power == 0)
    {
        return 1;
    }

    while(power > 0)
    {
        accumulator *= nb;
        power--;
    }

    return accumulator;
}

int main(void)
{
    int num_1 = ft_iterative_power(5, 3);

    printf("%i", num_1);
}
