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


// VARIABILI GLOBALI

#define N 10
int solution_count = 0;
int queens[N];

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


// Due funzioni che ci servono a stampare a schermo le varie soluzioni.
int ft_putnbr(int n)
{
    char buff = '0' + n;
    return write(1, &buff, 1);
}

void print_solution(int queens[])
{
    int i = 0;

    while(i < N)
    {
        ft_putnbr(queens[i]);
        i++;
    }
    
    write(1, "$", 1);
    write(1, "\n", 1);
}



void solve(int row, int queens[])
{
    // CASO BASE
    if(row == N)
    {
        print_solution(queens);
        solution_count++;
        return;
    }
    
    int col = 0;

    // la funzione ricorsiva si occupa di aumentare le linee, il ciclo di aumentare le colonne
    while(col < N)
    {
        if(is_valid(queens, row, col))
        {
            queens[row] = col;
            solve(row + 1, queens);
        }

        col++;
    }

    // QUESTO SECONDO RETURN PUò ANCHE ESSERE IMPLICITO ESSENDO LA FUNZIONE VOID
    return;
}



int ft_ten_queens_puzzle(void)
{
    solve(0, queens);
    return solution_count;
}



int main(void)
{
    printf("%i", ft_ten_queens_puzzle());
}



