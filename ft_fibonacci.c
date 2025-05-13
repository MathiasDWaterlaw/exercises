#include<stdio.h>

/* ft_fibonacci();
 *
 * allowed functions: none
 *
 * Create a function ft: fibonacci that returns th n-th element if the Fibonacci sequence,
 * the first element being at the 0 index. We'll condider that the Fibonacci sequence
 * starts like this: 0, 1, 1, 2.
 *
 * Overflows must not be handled, the function return will be undefined.
 *
 * Here's how it should be prototyped:
 *
 *      int ft_fibonacci(int index);
 *
 * Obviusly, ft_fibonacci has to be recursive.
 *
 * if the index is less than 0, the function should return -1.
 * */

int ft_fibonacci(int index)
{

    if(index <= 1)
    {
        if(index < 0)
        {
            return -1;
        }
        else
        {
            return index;
        }
    } 
    return ft_fibonacci(index - 2) + ft_fibonacci(index - 1);
}

int main(void)
{
    int index1 = 3;
    int index2 = 5;
    int index3 = 10;

    printf("%i\n", ft_fibonacci(index1));
    printf("%i\n", ft_fibonacci(index2));
    printf("%i\n", ft_fibonacci(index3));
}
