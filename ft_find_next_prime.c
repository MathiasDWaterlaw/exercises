#include<stdio.h>

/* ft_find_next_prime();
 *
 * allowed functions: none;
 *
 * Create a function that returns the next prime number greater or equal to the number
 * given as argument.
 *
 * Here's how it should be prototyped:
 *
 *      int ft_find_next_prime(int nb);
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
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int ft_find_next_prime(int nb)
{
    while(ft_is_prime(nb) != 1)
    {nb++;}

    return nb;
}

int main(void)
{
    //TESTS
    
    int num1 = 25;
    int num2 = 2;
    int num3 = 13;
    int num4 = 60;
    int num5 = 87;

    printf("next prime of: %i, is %i \n", num1, ft_find_next_prime(num1)); 
    printf("next prime of: %i, is %i \n", num2, ft_find_next_prime(num2));
    printf("next prime of: %i, is %i \n", num3, ft_find_next_prime(num3));
    printf("next prime of: %i, is %i \n", num4, ft_find_next_prime(num4));
    printf("next prime of: %i, is %i \n", num5, ft_find_next_prime(num5));  
}
