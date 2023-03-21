void crear_tabla(char lista[50][50]);
void crear_copia(char lista[50][50]);
void mostrar_tabla(char lista[50][50]);
void copiar_tabla(char lista[50][50], char copia[50][50]);
void poner_vida(char lista[50][50], int stop[1]);
int revisar_tabla(char lista[50][50], int x, int y);
void reglas(char lista[50][50]);


//llena la tabla de # antes de empezar
void crear_tabla(char lista[50][50])
{
    for (int i = 0; i < 50;i++)
    {
        for (int j = 0; j < 50; j++)
        {
            lista[i][j] = '#';
        }
    }
}

void crear_copia(char lista[50][50])
{
    for (int i = 0; i < 50;i++)
    {
        for (int j = 0; j < 50; j++)
        {
            lista[i][j] = '=';
        }
    }
}

void mostrar_tabla(char lista[50][50])
{
    for (int i = 0; i < 50;i++)
    {
        for (int j = 0; j < 50; j++)
        {
            printf("%c ",lista[i][j]);
        }
        printf("\n");
    }
}

void copiar_tabla(char lista[50][50], char copia[50][50])
{
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if (lista[i][j] == 'X' || lista[i][j] == '#')
            {
                copia[i][j] = lista[i][j];
            }
        }
    }
}

void poner_vida(char lista[50][50], int stop[1])
{
    printf("Para salir del modo Poner Vida seleccione -1 en la seleccion de columnas y filas\n");
    int x = get_int("Selecciona la fila: ");
    while (x > 50 || x < -1)
    {
        mostrar_tabla(lista);
        printf("Por favor seleccione un numero entre 1 y 50\n");
        x = get_int("Selecciona la columna: ");
    }
    int y = get_int("Selecciona la columna: ");
    while (y > 50 || y < -1)
    {
        mostrar_tabla(lista);
        printf("Por favor seleccione un numero entre 1 y 50\n");
        y = get_int("Selecciona la fila: ");
    }
    while (lista[x-1][y-1] != '#')
    {
        //este if evita que si se pone -1 -1 se vuelva a iniciar la funcion
        if (x == -1 && y == -1)
        {
            break;
        }
        mostrar_tabla(lista);
        printf("Esa posicion ya esta ocupada o esta fuera del rango, seleccione otra\n");
        x = get_int("Selecciona la columna: ");
        y = get_int("Selecciona la fila: ");
    }
    //si se introdujo -1 -1 el arreglo stop cambia de 0 a 1 terminando el modo poner vida
    if (x == -1 && y == -1)
    {
        stop[0] = 1;
    }
    //si no se introduce -1 -1 y la posicion esta dentro del rango y no esta ocupada entonces se cambiara a viva y se repetira el proceso
    if (x > 0 && y > 0 )
    {
        lista[x-1][y-1] = 'X';
    }
    mostrar_tabla(lista);
}

int revisar_tabla(char lista[50][50], int x, int y)
{
    int cont = 0;
    //revisa los espacios que no sean las esquinas ni los limites de los lados
    if (x > 0 && x < 49 && y > 0 && y < 49)
    {
        if (lista[x - 1][y - 1] == 'X')
        {
            cont++;
        }
            if (lista[x][y - 1] == 'X')
        {
            cont++;
        }
            if (lista[x + 1][y - 1] == 'X')
        {
            cont++;
        }
            if (lista[x - 1][y] == 'X')
        {
             cont++;
        }
            if (lista[x + 1][y] == 'X')
        {
             cont++;
        }
            if (lista[x - 1][y + 1] == 'X')
        {
              cont++;
        }
            if (lista[x][y + 1] == 'X')
        {
            cont++;
        }
            if (lista[x + 1][y + 1] == 'X')
        {
            cont++;
        }
    }
    //revisa la esquina superior izquierda
    if (x == 0 && y == 0)
    {
        if (lista[x + 1][y] == 'X')
        {
            cont++;
        }
        if (lista[x][y + 1] == 'X')
        {
            cont++;
        }
        if (lista[x + 1][y + 1] == 'X')
        {
            cont++;
        }
    }
    //revisa la esquina superior derecha
    if (x == 49 && y == 0)
    {
        if (lista[x - 1][y] == 'X')
        {
            cont++;
        }
        if (lista[x][y + 1] == 'X')
        {
            cont++;
        }
        if (lista[x - 1][y + 1] == 'X')
        {
            cont++;
        }
    }
    //revisa la esquina inferior izquierda
    if (x == 0 && y == 49)
    {
        if (lista[x][y - 1] == 'X')
        {
            cont++;
        }
        if (lista[x + 1][y + 1] == 'X')
        {
            cont++;
        }
        if (lista[x + 1][y] == 'X')
        {
            cont++;
        }
    }
    //revisa la esquina inferior derecha
    if (x == 49 && y == 0)
    {
        if (lista[x - 1][y - 1] == 'X')
        {
            cont++;
        }
        if (lista[x][y - 1] == 'X')
        {
            cont++;
        }
        if (lista[x - 1][y] == 'X')
        {
            cont++;
        }
    }
    //revisa el limite superior
    if (y == 0 && x != 0 && x != 49)
    {
        if (lista[x - 1][y] == 'X')
        {
            cont++;
        }
        if (lista[x - 1][y + 1] == 'X')
        {
            cont++;
        }
        if (lista[x][y + 1] == 'X')
        {
            cont++;
        }
        if (lista[x + 1][y + 1] == 'X')
        {
            cont++;
        }
        if (lista[x + 1][y] == 'X')
        {
            cont++;
        }
    }
    //revisa el limite derecho
    if (x == 49 && y != 0 && y != 49)
    {
        if (lista[x][y - 1] == 'X')
        {
            cont++;
        }
        if (lista[x - 1][y - 1] == 'X')
        {
            cont++;
        }
        if (lista[x - 1][y] == 'X')
        {
            cont++;
        }
        if (lista[x - 1][y + 1] == 'X')
        {
            cont++;
        }
        if (lista[x][y + 1] == 'X')
        {
            cont++;
        }
    }
    //revisa el limite inferior
    if (y == 49 && x != 0 && x!= 49)
    {
        if (lista[x - 1][y] == 'X')
        {
            cont++;
        }
        if (lista[x - 1][y - 1] == 'X')
        {
            cont++;
        }
        if (lista[x][y - 1] == 'X')
        {
            cont++;
        }
        if (lista[x + 1][y - 1] == 'X')
        {
            cont++;
        }
        if (lista[x + 1][y] == 'X')
        {
            cont++;
        }
    }
    //revisa el limite izquierdo
    if (x == 0 && y != 0 && y != 49)
    {
        if (lista[x][y - 1] == 'X')
        {
            cont++;
        }
        if (lista[x + 1][y - 1] == 'X')
        {
            cont++;
        }
        if (lista[x + 1][y] == 'X')
        {
            cont++;
        }
        if (lista[x + 1][y + 1] == 'X')
        {
            cont++;
        }
        if (lista[x][y + 1] == 'X')
        {
            cont++;
        }
    }
    return cont;
}

void reglas(char lista[50][50])
{
    //se realiza una copia de la lista para que los cambios ocurran simultaneamente y que unas reglas no afectan a otras
    char copia_1[50][50];
    crear_copia(copia_1);
    char copia_2[50][50];
    crear_copia(copia_2);
    char copia_3[50][50];
    crear_copia(copia_3);
    //recorre cada celda y realiza la funcion revisar para realizar las distintas reglas dependiendo del resultado
    for (int y = 0; y < 50; y++)
    {
        for (int x = 0; x < 50; x++)
        {
            //revisa con la funcion revisar si tiene 1 o ningun vecino y si es asi, morira
            if (lista[x][y] == 'X' && revisar_tabla(lista,x,y) < 2)
            {
                copia_1[x][y] = '#';
            }
            //revisa con la funcion revisar si tiene 4 o mÃ¡s vecinos y si es asÃ­, morira
            if (lista[x][y] == 'X' && revisar_tabla(lista,x,y) > 3)
            {
                copia_2[x][y] = '#';
            }
            //revisa una celda vacia y si tiene 3 vecinos entonces esta vivira
            if (lista[x][y] == '#' && revisar_tabla(lista,x,y) == 3)
            {
                copia_3[x][y] = 'X';
            }
        }
    }
    //una vez se hayan hecho los cambio a las copias estos cambios pasaran a formar parte de la tabla original
    copiar_tabla(copia_1, lista);
    copiar_tabla(copia_2, lista);
    copiar_tabla(copia_3, lista);
}
