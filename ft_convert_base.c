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

const int int_max = 2147483647;
const int int_min = (-2147483648);

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
    int i = 1;
    int j = 0;
    int str_length = str_len(str);
    char *cleaned_str = (char *)malloc(str_length + 1);

    while(i - 1 < str_length)
    {
        if(str[i - 1] == '-' || str[i - 1] == '+' || str[i - 1] == ' ')
            i++;

        else
        {
            if(char_in_base(str[i - 1], base_from) && char_in_base(str[i], base_from))
                cleaned_str[j++] = str[i - 1];
            
            else
            {
                cleaned_str[j] = str[i - 1];
                cleaned_str[j + 1] = '\0';
                return cleaned_str;
            }

            i++;
        }
    }
    cleaned_str[str_length + 1] = '\0';
    return cleaned_str;
}

int powerof(int nbr, int exp)
{
    int accumulator = nbr;

    if(exp == 0)
        return 1;

    while(exp > 1)
    {
        if(accumulator > int_max / nbr)
            return -1;

        accumulator *= nbr;
        exp--;
    }

    return accumulator;
}


int to_decimal(char *str, char *base)
{
    int i = 0;
    int counter_back = str_len(str) - 1;
    int base_length = str_len(base);
    int accumulator = 0;

    while(counter_back >= 0)
    {
        int counter = 0;
        
        while(str[counter_back] != base[counter] && counter < base_length)
            counter++;
        
        if(counter == base_length)
            return -1;
        
        int power = powerof(base_length, i);

        if(power < 0 || counter > (int_max - accumulator) / power)
            return -1;

        accumulator += counter * power;
        counter_back--;
        i++;
    }
    
    return accumulator;
}


int calc_memo(int nbr, int base_len)
{
    int length = 0;

    if(nbr == 0)
        return 1;

    while(nbr > 0)
    {
        nbr /= base_len;
        length++;
    }

    return length;
}


char *to_base(int nbr, int negative, char *base_to)
{
    int base_length = str_len(base_to);
    int size = calc_memo(nbr, base_length);
    int module;
    char *final_str;

    if(negative)
        final_str = (char *)malloc(size + 2);
    else
        final_str = (char *)malloc(size + 1);

    final_str[size] = '\0';

    while(--size >= 0)
    {
        module = nbr % base_length;
        nbr /= base_length;
        final_str[size] = base_to[module];

        if(size == 0 && negative)
            final_str[size] = '-';
    }
    
    if(!final_str)
        return NULL;

    return final_str;
}


char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    char *return_str, *cleaned_str;
    int nbr_negative, decimal_nbr;

    if(base_valid(base_from) == 0 && base_valid(base_to) == 0)
        return(return_str = NULL);
    
    nbr_negative = is_negative(nbr);
    cleaned_str = str_cleaner(nbr, base_from);
    decimal_nbr = to_decimal(cleaned_str, base_from);
    
    free(cleaned_str);
    cleaned_str = NULL;
    
    if(decimal_nbr == -1)
        return(nbr_negative ? "-2147483648" : "2147483647");
    
    return_str = to_base(decimal_nbr, nbr_negative, base_to);

    printf("\n string injected: \"%s\"\n", nbr);
    printf(" Base from: %s\n", base_from);
    printf(" Base to: %s\n", base_to);
    printf(" Decimal conversion: %i\n", decimal_nbr);
    printf(" Returned string: %s", return_str);

    return return_str;
}



// TESTING
int main(void)
{

    ft_convert_base("  ---7CA/-2984", "0123456789ABCDEF", "01");
}






