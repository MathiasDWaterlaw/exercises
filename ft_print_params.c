#include<unistd.h>
#include<stdio.h>

/* ft_print_params.c
 *
 * allowed functions: write
 *
 * We're dealing with a program here, you should therefore have a funcion main in
 * your .c file.
 *
 * Create a program that displays its given arguments.
 *
 * One per line, in the same order as in the command line.
 *
 * It should display all arguments, except for *argv[0].
 *
 * Example: 
 *
 *      >./a.out test1 test2 test3
 *      test1
 *      test2
 *      test3
 *      $>
 * */

int ft_putchar(char c)
{
    return write(1, &c, 1);
}

int my_print(char *string)
{
    int i = 0;
    while(string[i] != '\0')
    {
        ft_putchar(string[i++]);
    }
    return write(1, "\n", 1);
}

int main(int argc, char *argv[])
{
    if(argc > 1)
    {
        int i = 1;

        while(i < argc)
        { 
            my_print(argv[i]);
            i++;
        }
    }

    return 0;
}
