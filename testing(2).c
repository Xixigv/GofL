#include <stdio.h>
#include <cs50.h>
#include "gofl.h"

int main()
{
    int game = 0;
    char next;
    char tabla[50][50];
    //este arreglo sirve para detener el modo poner vida
    int stop[1];
    crear_tabla(tabla);
    mostrar_tabla(tabla);
    //dentro de la funcion poner_vida si se introduce columna: -1 y fila: -1 se detendra el modo poner vida
    //este while es el modo poner vida;
    while (stop[0] == 0)
    {
    poner_vida(tabla, stop);
    }
    printf("Presiona n para ir a la siguiente generacion\nPresiona e para terminar la simulacion\n");
    while (game == 0)
    {
        next = get_char(">");
        if (next == 'n')
        {
        reglas(tabla);
        mostrar_tabla(tabla);
        }
        if (next == 'e')
        {
            game = 1;
        }
    }
}
