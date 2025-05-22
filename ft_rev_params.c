#include<unistd.h>

/* ft_rev_params();
 *
 * allowed functions: write.
 *
 * We're dealing with a program here, you should therefore have a function main in 
 * your .c file.
 *
 * Create a program that displays its given arguments.
 *
 * One per line, in the reverse order of the command line.
 *
 * It should display all arguments, except for argv[0].
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
        ft_putchar(string[i]);
        i++;
    }

    return write(1, "\n", 1);
}

int main(int argc, char *argv[])
{
    int counter = argc - 1;

    while(counter >= 1)
    {
        my_print(argv[counter]);
        counter--;
    }
    return 0;
}
