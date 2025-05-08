#include<stdio.h>
#include<unistd.h>

/*
 * ft_atoi_base
 * 
 * allowed functions: none
 *
 * Write a function that converts the initial portion of the string pointed by the str to
 * int rappresentation.
 *
 * str is in a specific base given as a second parameter.
 * 
 * excepted the base rule the function should work exactly like ft_atoi.
 *
 * If there's an invalid argument, the funtion should return 0. Examples of invalid
 * arguments:
 * 
 *  - base is empty or size 1;
 *  - base contains the same character twice;
 *  - base contains + or - or whitespaces;
 *
 * here's how it should be prototyped:
 *
 * int ft_atoi_base(char *str, char *base);
 */

int ft_strlen(char *str) //ritorna la lunghezza della stringa inserita
{
    int counter = 0;
    while(*str++)
    {
        counter++;
    }
    return counter;
}

int invalid_base(char *str) //controlla se la base inserita è corretta
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
            {
                return 1;
            }

            if(str[i] == str[j])
            {
                counter++;
            }

            j++;
        }

        if(counter > 1)
        {
            return 1;
        }

        i++;
    }

    return 0;
}

int powerof(int nbr, int exp)
{
    int accumulator = nbr;

    if(exp == 0)
    {
        return 1;
    }

    while(exp > 1)
    {
        accumulator *= nbr;
        exp--;
    }

    return accumulator;
}

// AGGIUNGERE UNA FUNZIONE STR_CLEANER CHE RESTITUISCA UNICAMENTE LA STRINGA DA UTILIZZARE
// PER LA CONVERSIONE

int c_in_base(char c, char *base)
{
	while(*base++)
	{
		if(c == *base)
		{
			return 1;
		}
	}
	
	return 0;
}

char is_negative(char *str)
{
	int i = 0;
	int counter = 0;
	
	while(str[i] == ' ' || str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
		{
			counter++;
		}
		
		i++;
	}
	
	return(counter % 2);
}

int ft_atoi_base(char *str, char *base)
{
    int base_length = ft_strlen(base);
    int str_length = ft_strlen(str);

    if(invalid_base(base) || base_length < 2)
    {
        printf("error: invalid base\n");
        return(0);
    }


    /* Questa parte della funzione si occupa di tradurre un segno in qualsiasi base 
     * nel suo equivalente decimale, utilizzando la base fornita come parametro nella funzione.
     */

    int counter = 0;
    int i = 0;
    int array_int[str_length];
    
    while(str[i] != '\0')
    {
        counter = 0;
        
        while(str[i] != base[counter])
        {
            counter++;
        }

        array_int[i] = counter; //assegna il counter al suo posto corrispondente nell'array.
        i++;
    }

    /* Da ora la funzione moltiplica ogni numero nell'array per la sua base, per poi
     * sommare tutto nella variabile accumulator.
     */

    int back_counter = str_length - 1;
    int accumulator = 0;
    int j = 0;
    
    while(back_counter >= 0)
    {
        accumulator += array_int[back_counter--] * powerof(base_length, j++);
    }
    
    printf("str: %s, result: %i", str, accumulator);
    printf("\n");

    return accumulator;
}

// ====================================================================
//                                TESTING
// ====================================================================

int main(void)
{
    char *BIN, *DEC, *HEX, *OCT; 
    char *WRONG_1, *WRONG_2, *WRONG_3;
    char *WRONG_4, *WRONG_5, *WRONG_6, *WRONG_7;

    //BASI
    BIN = "01";
    OCT = "01234567";
    DEC = "0123456789";
    HEX = "0123456789ABCDEF";
    
    //BASI SBAGLIATE PER CONTROLLO
    WRONG_1 = "";
    WRONG_2 = " ";
    WRONG_3 = "2";
    WRONG_4 = "ABGG43";
    WRONG_5 = "123-567";
    WRONG_6 = "43+45";
    WRONG_7 = "FG ASDERT";

    //TEST
    ft_atoi_base("11111001010", BIN);
    ft_atoi_base("3712", OCT);
    ft_atoi_base("1994", DEC);
    ft_atoi_base("07CA", HEX);

    ft_atoi_base("42", WRONG_1);
    ft_atoi_base("42", WRONG_2);
    ft_atoi_base("42", WRONG_3);
    ft_atoi_base("42", WRONG_4);
    ft_atoi_base("42", WRONG_5);
    ft_atoi_base("42", WRONG_6);
    ft_atoi_base("42", WRONG_7);
}
  






