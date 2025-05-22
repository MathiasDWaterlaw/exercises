#include<unistd.h>

/* ft_sort_params();
 *
 * allowed functions: write
 *
 * We're dealing with a program here, you should therefore have a function main
 * in your .c file
 *
 * Create a program that displays its given argument sorted by ascii order.
 *
 * It should display all arguments, except for argv[0].
 *
 * One argument per line.
 * */

int ft_putchar(char c)
{
    return write(1, &c, 1);
}

int my_print(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        ft_putchar(str[i++]);
    }

    return write(1, "\n", 1);
}

int ft_strcmp(char *str1, char *str2)
{
    int i = 0;
    while( (str1[i] == str2[i]) && (str1[i] != '\0' && str2[i] != '\0') )
    {
        i++;
    }

    return (str1[i] - str2[i]);
}

void array_sorter(int counter, char *array[])
{
    int i = 2;
    char *tmp;

    while(i < counter)
    {
        if(ft_strcmp(array[i - 1], array[i]) > 0)
        {
            tmp = array[i - 1];
            array[i - 1] = array[i];
            array[i] = tmp;
        }

        i++;
    }
}

int main(int argc, char *argv[])
{
    int _counter = argc;
    int i = 0;

    array_sorter(_counter, argv);

    while(i < argc)
    {
        my_print(argv[i++]);
    }

    return 0;
}






