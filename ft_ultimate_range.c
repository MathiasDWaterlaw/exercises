#include<stdlib.h>
#include<stdio.h>

/* ft_ultimate_range();
 *
 * allowed functions: malloc
 *
 * Create a function ft_ultimate_range which allocates and assigns an array of ints.
 * This int array should contain all values between min and max
 *
 * Min included - max excluded.
 *
 * Here's how it should be prototyped:
 *
 *      int ft_ultimate_range(int **range, int min, int max);
 *
 * The size of range should be returned (or -1 on error).
 *
 * If the value of min is greater or equal to max's value, range will point on NULL
 * and it should return 0;
 */

int ft_ultimate_range(int **range, int min, int max)
{
    if(min >= max)
    {
        *range = NULL;
        return 0;
    }
    
    int i = 0;
    int size = max - min;
    *range = (int *) malloc(size * 4);
    
    if(*range == NULL)
        return -1;

    while(min < max)
    {
        *range[i] = min;
        printf("%i", *range[i]);
        i++;
        min++;
    }

    return size;
}

int main(void)
{
    int *array;
    int size = ft_ultimate_range(&array, 1, 4);

    printf("\n array size: %i", size);
    return 0;
}
