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

const int length = 9;

void display_matrix(int matrix[length][length], int length)
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

void put_a_queen(int matrix[length][length], int row, int col)
{
    int _row = row;
    int _col = col;
    
    if(matrix[row][col] != 1)
    {
        printf("\nerror: there's a queen here! -row: %i, -col: %i\n\n", row, col);
        return;
    }

    matrix[row][col] = 8;

    while(_row - 1 >= 0)
    {
        matrix[_row - 1][col] = 0;
        _row--;
    }
    while(_col - 1 >= 0)
    {
        matrix[row][_col - 1] = 0;
        _col--;
    }
    
    _row = row;
    _col = col;

    while(_row + 1 < length)
    {
        matrix[_row + 1][col] = 0;
        _row++;
    }
    while(_col + 1 < length)
    {
        matrix[row][_col + 1] = 0;
        _col++;
    }

    //DIAGONALS
    // L to R

    _row = row;
    _col = col;
    while(_row - 1 >= 0 && _col - 1 >= 0)
    {
        matrix[_row - 1][_col - 1] = 0;
        _row--;
        _col--;
    }

    _row = row;
    _col = col;
    while(_row + 1 < length && _col + 1 < length)
    {
        matrix[_row + 1][_col + 1] = 0;
        _row++;
        _col++;
    }

    //R to L
    _row = row;
    _col = col;
    while(_row - 1>= 0 && _col + 1 < length)
    {
        matrix[_row - 1][_col + 1] = 0;
        _row--;
        _col++;
    }

    _row = row;
    _col = col;
    while(_row + 1< length && _col - 1 >= 0)
    {
        matrix[_row + 1][_col - 1] = 0;
        _row++;
        _col--;
    }
}

int ft_ten_queens_puzzle(void)
{
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
    //==================

    

    //TESTING:
    
    i = 0;
    while(i < 1)
    {   
        printf("\n -%i: \n", i);
        put_a_queen(matrix, 0 ,1);
        put_a_queen(matrix, 1, 3);
        display_matrix(matrix, length);
        i++;
    }

    return 0;
}

int main(void)
{
    ft_ten_queens_puzzle();
}



