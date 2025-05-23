#include<stdio.h>
#include<stdlib.h>

/* ft_strdup();
 *
 * allowed functions: malloc
 *
 * Reproduce the behavior of the function strdup
 * 
 *      - the strdup function returns a pointer
 *        to a null-terminated byte string, which
 *        is a duplicate of the string pointed by
 *        the paramater passed to the function. -
 *
 * Here's how it should prototyped:
 *
 *      char *ft_strdup(char *src);
 * */

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        i++;
    }

    return i;
}

char *ft_strdup(char *src)
{
    int length, i; 
    length = ft_strlen(src);
    char *_str = (char *)malloc(length + 1);
    i = 0;

    while(i <= length)
    {
        _str[i] = src[i]; 
        i++;
    }

    _str[length + 1] = '\0';
    return _str;
}

int main(void)
{
    char *str = "Mi chiamo Mathias";
    char *str2 = ft_strdup(str);

    printf(" Original: ");
    printf(str);
    printf("\n");
    printf(" Duplicated: ");
    printf(str2);

    return 0;
}
