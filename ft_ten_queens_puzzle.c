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


/*void display_matrix(int matrix[length][length], int length)
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
}*/

#define N 10

// Controlla se alle coordinate row, col, si può inserire una regina. se si può ritorna 1;
int is_valid(int queens[], int row, int col)
{
    int i = 0;

    while(i < row)
    {
        int diag_key1 = i - queens[i];
        int diag_key2 = i + queens[i];

        if(queens[i] == col)
        { return 0; }

        if(row - col == diag_key1 || row + col == diag_key2)
        { return 0; }

        i++;
    }

    return 1;
}




int ft_ten_queens_puzzle(void)
{
    int queens[N] = {0, 5};

    //==================

    

    //TESTING:
    
    int test = is_valid(queens, 2, 3);
    printf("%i", test);

    return 0;
}



int main(void)
{
    ft_ten_queens_puzzle();
}



