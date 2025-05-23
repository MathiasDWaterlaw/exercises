#include<stdlib.h>
#include<stdio.h>

/* ft_range()
 *
 * allowed functions: malloc.
 *
 * Create a function ft_range which returns an array of ints. This int array should
 * contain all values between min and max.
 *
 * Min included - max excluded.
 *
 * Here's how it should be prototyped:
 *
 *      int *ft_range(int min, int max);
 * 
 * If min value is greater or equal to max's value, a null pointer should be returned.
 *
 * */

int *ft_range(int min, int max)
{
    if(min >= max)
        return NULL;

    int space = max - min;
    int *num_array = (int *) malloc(space * 4);
    int i = 0;

    while(min < max)
    {
        num_array[i] = min;
        printf("%i", num_array[i]);
        i++;
        min++;
    }


    return num_array;
}

int main(void)
{
    ft_range(1, 4);
    return 0;
}
