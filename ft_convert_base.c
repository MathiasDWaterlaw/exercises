#include<stdlib.h>
#include<stdio.h>

/* ft_convert_base(); ft_convert_base2();
 *
 * allowed function: malloc, free.
 * 
 * Create a function that returns the result of the conversion of the string nbr from
 * a base base_from to a base base_to.
 *
 * nbr, base_from, base_to may be not writable.
 *
 * nbr will follow the same rules as ft_atoi_base. Beware of '+', '-' and whitespaces.
 *
 * The number represented by nbr must fit inside an int.
 *
 * If a base is wrong, NULL should be returned.
 *
 * The returned number must be prefixed only by a single and uniq '-' if necessary,
 * no whitespaces, no '+'.
 *
 * Here's how it should be prototyped:
 *
 *      char *ft_convert_base(char *nbr, char *base_from, char *base_to);
 * */

// CONTROLLA LA LUNGHEZZA DI UNA STRINGA
int str_len(char *str)
{
    int counter = 0;
    while(str[counter] != '\0')
        counter++;
    return counter;
}

//CONTROLLA SE LA BASE PASSATA è VALIDA
int base_valid(char *str)
{
    int i, j, counter;

    i = 0;
    while(str[i] != '\0')
    {
        j = 0;
        counter = 0;

        while(str[j] != '\0')
        {
            if(str[j] == '-' || str[j] == '+' || str[j] == ' ')
                return 0;
            if(str[i] == str[j])
                counter++;
            j++;
        }

        if(counter > 1)
            return 0;
        i++;
    }

    return 1;
}

// CONTROLLA SE IL NUMERO PASSATO DALLA STRINGA è NEGATIVO
int is_negative(char *str)
{
    int i, counter;

    i = 0;
    while(str[i] == ' ' || str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
            counter++;
        i++;
    }

    return(counter % 2);
}

// CONTROLLA SE UN CARATTERE FA PARTE DELLA BASE, SE SI RITORNA 1
int char_in_base(char c, char *base)
{
    int i = 0;
    while(base[i] != '\0')
    {
        if(c == base[i])
            return 1;
        i++;
    }

    return 0;
}

// RIPULISCE LA STRINGA DA TUTTI I CARATTERI SUPERFLUI E RITORNA LA STRINGA RIPULITA
char *str_cleaner(char *str, char *base_from)
{
    int i, j, str_length;
    char *cleaned_str;

    str_length = str_len(str);
    cleaned_str = (char *)malloc(str_length + 1);
    i = 1;
    j = 0;

    while(i - 1 < str_length)
    {
        if(str[i - 1] == '-' || str[i - 1] == '+' || str[i - 1] == ' ')
            i++;

        else if(char_in_base(str[i - 1], base_from) && char_in_base(str[i], base_from))
        {
            cleaned_str[j] = str[i - 1];
            j++;
        }
        else
        {    
            cleaned_str[j] = str[i - 1];
            cleaned_str[j + 1] = '\0';
            return cleaned_str;
        }
        i++;
    }

    cleaned_str[str_length + 1] = '\0';
    return cleaned_str;
}

// TESTING
int main(void)
{
    char *base_from = "0123456789";
    char *cleaned_str = str_cleaner("-- ++ 1994,456", base_from);

    printf(cleaned_str);
}






