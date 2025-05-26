#include<stdlib.h>
#include<stdio.h>

/* ft_strjoin();
 *
 * allowed functions: malloc
 *
 * Write a function that will contatenate all strings pointed by strs separated by
 * sep
 *
 * size is the number of strings in strs
 *
 * if size is 0, it should a freeble empty string.
 *
 * Here's how it should be prototyped:
 *
 *      char *ft_strjoin(int size, char **strs, char *sep);
 */

int ft_strlen(char *str)
{
    int counter;
    counter = 0;

    while(str[counter] != '\0')
    {
        counter++;
    }

    return counter;
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    int i, j, y, k, total_length;
    char *final_str;

    if(size == 0)
    {
        final_str = (char *)malloc(1);
        return final_str = "\0";
    }

    i = 0;
    total_length = ft_strlen(sep) * (size - 1);
    while(i < size)
    {
        total_length += ft_strlen(strs[i]);
        i++;
    }

    i = 0;
    y = 0;
    final_str = (char *)malloc(total_length + 1);

    while(i < size)
    {
        j = 0;

        while(strs[i][j] != '\0')
       {
            final_str[y] = strs[i][j];
            j++;
            y++;
        }
        
        if(i == size - 1)
        {
            final_str[++y] = '\0';
        } 
        else
        {
            k = 0;
            while(sep[k] != '\0')
            {
                final_str[y++] = sep[k];
                k++;
            }
        }

        i++;
    }

    return final_str;
}

int main(void)
{
    char *arr[3] = {"Greta", "Van", "Fleetwood"};
    char *string = ft_strjoin(3, arr, " - ");


    printf(string);
    return 0;
}
