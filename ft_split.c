#include<stdio.h>
#include<stdlib.h>

/* ft_split()
 *
 * allowed functions: malloc
 *
 * Create a function that splits a string of character depending on another string of 
 * character.
 *
 * You'll have to use each character from the string charset as a separator.
 *
 * The function returns an array where each element of the array contains the address
 * of a string wrapped between two separator. The last elemente of that array should 
 * equal to 0 to indicate the end of the array.
 *
 * There cannot be any empty strings in your array. Get your own conclusion accordingly.
 *
 * The string given as argument won't be modifiable.
 *
 * Here's how it should be prototyped:
 *
 *      char **ft_split(char *str, char *charset);
 * */

int is_separator(char c, char *charset) {

    while(*charset) {
        
        if(c == *charset)
            return 1;

        charset++;
    }

    return 0;
}

int word_count(char *str, char *charset) {

    int word_count = 0;
    int in_word = 0;

    while(*str) {

        if(is_separator(*str, charset))
            in_word = 0;

        else if(in_word == 0) {
            in_word = 1;
            word_count++;
        }

        *str++;
    }

    return word_count;
}


