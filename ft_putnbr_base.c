#include<stdio.h>
#include<unistd.h>

// ft_putnbr_base
// Allowed functions: write
//
// Create a function that displays a number in a base system in the terminal.
//
// This number is given in the shape of an int, and the radix in the shape of a string
// of characters.
// 
// The base-system contains all useable symbols to display that number:
// - 0123456789 is the commonly used base system to represent decimal numbers
// - 01 is a binary base system ;
// - 0123456789ABCDEF an hexadecimal base system ;
// - poneyvif is an octal base system.
//
// The function must handle negative numbers.
//
// If there's an invalide argument, nothing should be displayed. Exemple of invalid
// arguments:
// - base is empty or size of 1 ;
// - base contains the same character twice ;
// - base contains + or - ;
//
// Prototype: void ft_putnbr_base(int nbr, char *base);



int ft_putchar(char c) //scrive sullo schermo il carattere indicato nel parametro
{
    write(1, &c, 1);
    return 0;
}

int ft_strlen(char *str) // ritorna la lunghezza di una stringa di caratteri
{
    int counter = 0;
    while(*str++)
    {
        counter++;
    }

    return counter;
}

int base_controller(char *str)
{
   int i, j, counter;

   i = 0;
   while(str[i] != '\0')
   {
       j = 0;
       counter = 0;

       while(str[j] != '\0')
       {

           if(str[j] == '-' || str[j] == '+')
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

void ft_putnbr_base(int nbr, char *base)
{
    int divider = ft_strlen(base);
    int counter = 0;
    int module;

    char array[100];
    
    if(base_controller(base))
    {
        return;
    }
  
    if(nbr < 0)
    {
        nbr *= -1;
        ft_putchar('-');
    }
    
    while(nbr > 0)
    {
        module = nbr % divider;
        array[counter] = base[module];

        nbr /= divider;
        counter++;
    }

    while(counter >= 0)
    {
        ft_putchar(array[counter - 1]); 
        counter--;
    }

    ft_putchar('\n');
}

int main(void)
{
    char *HEX = "0123456789ABCDEF";
    char *DEC = "0123456789";
    char *BIN = "01";
    char *OCT = "poneyvif";
    char *Wrong_1 = "123456+adfg";
    char *Wrong_2 = "ABCDDFGH";

    ft_putnbr_base(45, BIN);
    
    ft_putnbr_base(45, HEX);

    ft_putnbr_base(45, DEC);

    ft_putnbr_base(45, OCT);

    ft_putnbr_base(67, Wrong_1);
    ft_putnbr_base(983, Wrong_2);
}
