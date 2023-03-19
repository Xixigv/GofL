#include <stdio.h>
#include <cs50.h>

char foo [3][4]=
{
       {32,32,32, 0},
       {32,32,32, 0},
       {32,32,32, 0}
};

int main()
{
 for ( i = 0; i <3;i++)
    {
        for ( j = 0; j <3;i++)
        {
            int fila = -1;
            int columna = -1;
            printf("[%s]\n", foo[0]);
            printf("[%s]\n", foo[1]);
            printf("[%s]", foo[2]);
            
            
            j++;
        }
        return 0;
    }
 }
