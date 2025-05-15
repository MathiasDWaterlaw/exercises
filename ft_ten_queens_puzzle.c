#include<stdio.h>
#include<unistd.h>

/* The Ten Queens
 *
 * allowed functions: write();
 *
 * Create a function that displays all possible placements of the ten queens on a chessboard
 * which would contain ten columns and ten lines, without them being able to reach each other
 * in a single move, and returns the number of possibilities.
 *
 * Recursivity is required to solve this problem.
 *
 * Here's how it should be prototyped:
 * 
 *      int ft_ten_queens_puzzle(void);
 *
 * Here's how it'll be displayed:
 *
 *      >./a.out | cat -e
 *      0257948136$
 *      0258693147$
 *      ...
 *      4605713829$
 *      4609582731$
 *      ...
 *      9742051863$
 *      >
 * 
 * The sequence goes from left to right. The first digit represents the first Queen's position
 * in the first column (the index starting from 0). The Nth digit represents the Nth Queen's
 * position in the Nth column.
 *
 * The return value must be the total number of displayed solutions.
 * */

void display_matrix(int matrix[4][4], int length)
{
    int i = 0;
    int j = 0;

    while(i < length)
    {
        j = 0;
        printf(" ");

        while(j < length)
        {
            printf("%i ", matrix[i][j]);
            j++;
        }

        printf("\n");
        i++;
    }
}

int ft_ten_queens_puzzle(void)
{
    int length = 4;
    int matrix[length][length];
    
    int i = 0;
    int j = 0;
    
    //FILLING THE ARRAY;
    while(i < length)
    {
        j = 0;
        while(j < length)
        {
            matrix[i][j] = 1;
            j++;
        }
        i++;
    }
    
    i = 0;
    while(i < length)
    {   
        printf("\n -%i: \n", i);
        display_matrix(matrix, length);
        i++;
    }

    return 0;
}

int main(void)
{
    ft_ten_queens_puzzle();
}



