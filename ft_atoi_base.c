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

//ELEVA IL NBR AL SUO EXP
//funzione matematica di potenza
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

// Controlla che il carattere inserito come primo parametro faccia parte della base
int c_in_base(char c, char *base)
{
    int i = 0;

	while(base[i] != '\0')
	{
		if(c == base[i])
		{
			return 1;
		}

        i++;
	}
	
	return 0;
}

// controlla la prima parte della stringa e restituisce 1 (TRUE) se il numero finale è negativo
// e 0 (FALSE) se il numero finale è positivo.
int is_negative(char *str)
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


// LA FUNZIONE PRINCIPALE CHE UTILIZZA TUTTE LE ALTRE
int ft_atoi_base(char *str, char *base)
{
    int base_length = ft_strlen(base);
    int str_length = ft_strlen(str);
    int negative = is_negative(str);

    if(invalid_base(base) || base_length < 2)
    {
        printf("error: invalid base\n");
        return(0);
    }
    
    /* Nella prima parte si occupa di ripulire la stringa principale di tutti
     * i caratteri che non devono essere considerati nella fase finale della funzione
     * */

    int j = 0;
    int cleaned_i = 0;
    char cleaned_str[100];
    
    while(j <= str_length)
    {
        if(c_in_base(str[j], base))
        {
            cleaned_str[cleaned_i] = str[j];
            cleaned_i++;        
        }

        if(c_in_base(str[j - 1], base) && c_in_base(str[j], base) == 0)
        {
            j += str_length;
        }
         
        else
        {
            cleaned_str[j + 1] = '\0';
        }

        j++;
    }
    printf(" original str: \"%s\" \n", str);
    printf(" cleaned: \"%s\" \n",cleaned_str);

    /* Nella seconda fase si occupa di tradurre un segno in qualsiasi base 
     * nel suo equivalente decimale, utilizzando la base fornita come parametro nella funzione.
     * Successivamente, nell'accumulatore, questo equivalente decimale viene sommato ai 
     * precedenti/successivi, ma moliplicato per la base elevata al numero di posizione 
     * (unità, decine, centinaia ecc)
     */

    int counter = 0;
    int i = 0;
    int back_counter = ft_strlen(cleaned_str) - 1;
    int accumulator = 0;
    
    while(back_counter >= 0)
    {
        counter = 0;
        
        while(cleaned_str[back_counter] != base[counter])
        {
            counter++;
        }

        accumulator += counter * powerof(base_length, i++);
        back_counter--;
    }
   
    accumulator = negative ? accumulator * -1 : accumulator;
    printf(" result: %i", accumulator);
    printf("\n\n");

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
    char *PV = ".,";
    
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
    ft_atoi_base(" - --3712", OCT);
    ft_atoi_base("1994", DEC);
    ft_atoi_base("07CA", HEX);
    ft_atoi_base(",,,,,..,.,.", PV);

    ft_atoi_base("+ +-11111001010AT1010", BIN);
    ft_atoi_base(" 3712,9", OCT);
    ft_atoi_base(" --1994d1994", DEC);
    ft_atoi_base("      --+07CA-CA", HEX);

    ft_atoi_base("42", WRONG_1);
    ft_atoi_base("42", WRONG_2);
    ft_atoi_base("42", WRONG_3);
    ft_atoi_base("42", WRONG_4);
    ft_atoi_base("42", WRONG_5);
    ft_atoi_base("42", WRONG_6);
    ft_atoi_base("42", WRONG_7);
}
  






