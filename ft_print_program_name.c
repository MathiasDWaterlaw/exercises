#include<unistd.h>
#include<stdio.h>

/* ft_print_program_name();
 *
 * allowed functions: write
 *
 * We're dealing with a program here, you should therefore have a function "main" in your .c
 * file.
 *
 * Create a program that displays its own name.
 *
 * Example:
 *
 *      >./a.out
 *      ./a.out
 *      $>
 * */

int ft_putchar(char c)
{
    return write(1, &c, 1);
}

void my_print(char *string)
{
    int i = 0;

    while(string[i] != '\0')
    {
        ft_putchar(string[i++]);
    }
}

int main(void)
{
    my_print(__FILE__);
    return 0;
}
