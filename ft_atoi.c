#include<stdio.h>
// Write a function that converts the initial portion of the string pointend by str
// to its int representation
//
// The string can start with an arbitrary amount of white space (as determined by
// isspace(3))
//
// The string can be followed by an arbitrary amount of + and - signs, - sign will change
// the sign of the int returned based on the number of - is odd or even
//
// Finally the string can be followed by any numbers of the base 10.
//
// Your funciotn should read the string until the string stop following the rules and
// return the number found until now.
//
// You should not take care of overflow or underflow. result can be undefined in
// that case.
//
// Prototype: int ft_atoi(char *str);

int str_nb(char *str, int length)
{
    int base = 1;
    int number = 0;

    while(length > 0)
    {
        int current = (int)str[length - 1] - 48;
        number += current * base;
        
        base *= 10;
        length--;
    }
    return number;
}

int ft_atoi(char *str)
{
    int even_counter = 0;
    int s_counter = 0;
    int number = 0;
    char int_string[11];

    while(*str++)
    {
        if(*str == '-')
        {
            even_counter++;
        }
        if(*str >= '0' && *str <= '9')
        {
            int_string[s_counter] = *str;
            s_counter++;
        }
        if((*str >= '0' && *str <= '9')
          &&(str[+1] < '0' || str[+1] > '9'))
        {    
            number = str_nb(int_string, s_counter);
            return (even_counter % 2 == 0 ? number : number * -1);
        }
    }
    number = str_nb(int_string, s_counter);
    return(even_counter % 2 == 0 ? number : number * -1);
}

int main(void)
{
    char stringa_1[] = "  ---+--+1234ab567";
    char stringa_2[] = "               234";
    char stringa_3[] = "      ----3498ghie";
    char stringa_4[] = "+++++++-4587sod984";
    char stringa_5[] = "+-+32442234fbgr253";
    char stringa_6[] = "            ----42";



    printf("stringa 1 - expected: -1234, output: %d\n", ft_atoi(stringa_1));
    printf("stringa 2 - expected: 234, output: %d\n", ft_atoi(stringa_2));
    printf("stringa 3 - expected: 3498, output: %d\n", ft_atoi(stringa_3));
    printf("stringa 4 - expected: -4587, output: %d\n", ft_atoi(stringa_4));
    printf("stringa 5 - expected: -32442234, output: %d\n", ft_atoi(stringa_5));
    printf("stringa 6 - expected: 42, output: %d\n", ft_atoi(stringa_6));



    return 0;
}
