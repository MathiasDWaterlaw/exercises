#include<stdio.h>

/* ft_is_prime();
 *
 * allowed functions: none
 *
 * Create a function that returns 1 if the number given as a parameter is a prime number,
 * and 0 if it isn't
 *
 * Here's how it should be prototyped:
 *      
 *      int ft_is_prime(int nb);
 * */

int ft_is_prime(int nb)
{
    int i = 2;
    
    if(nb < 2)
    {
        return 0;
    }

    while(i < nb)
    {
        if(nb % i == 0)
            return 0;

        i++;
    }

    return 1;
}

int main(void)
{
    int iter = 0;
    int counter = 1;

    while(iter <= 100)
    {    
        if(ft_is_prime(iter))
        {
            printf(" -%i: %i is prime\n",counter, iter);
            counter++;
        }
        iter++;
    }
}
