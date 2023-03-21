  Game of Life (Conway's version)
      by Linguini, Ximena, Ricardo and Esteban
      
...........................................................................................................................................................................................................................................................................
  Recomendaciones de descarga:

Código funcional únicamente en  C99 o C11, debido a que se produce el siguiente error:
error: 'for' loop initial declarations are only allowed in C99 or C11 mode.


  Por esto mismo se recomienda hacer uso del ambiente virtual de Visual Studio Code.
De la misma manera, se recomienda descargar la librería creada por nosotros mismos, la cual cuenta con una terminación de .h;
esto dependiendo del tamaño de matriz que el usuario desea utilizar. 


  Asimismo, se recomienda mantener las librerias .h y los archivos .c dentro de un mismo ambiente, 
eventualmente si se decide mover la libreria, es necesario indicarle al compilador la carpeta y nombre del archivo de la libreria,
para que el compilador pueda encontrarlo a la hore de compilar el archivo.c.
...........................................................................................................................................................................................................................................................................
  Descripciones generales de los archivos:

  El archivo testing(1).c y GofL(1).h utilizan las matrices de 100 x 100, 
por otra parte, el archivo testing(2).c y GofL(2).h hacen uso la matriz de 50 x 50, 
esto con el propósito de que a la hora de compilar, se imprima en pantalla la matriz de manera ordenada;
aspecto, el cual no sucede con la matriz de 100x100, debido a las capacidades de la pantalla.
Por último, el archivo 10x10.c, como su nombre lo indica, es una matriz de 10 x 10, la cual, fue la matriz inicial del proyecto.
...........................................................................................................................................................................................................................................................................
    Reglas del funcionamiento del juego:

  1. Por cada espacio de la matriz que este poblada:
        - Cada celula con ningun vecino o con un solo vecino, mueren por soledad.
        - Cada celula con 4 o más vecinos, muere por sobrepoblación.
        - Cada celula con 2 0 3 vecinos, sobrevive.
      
  2. Para espacios vacios:
        - Cada celula vacia con 3 vecinos, se pobla.
      
...........................................................................................................................................................................................................................................................................
  Consideraciones generales de la implementación:

  -	El universo puede representar hasta 10,000 células en una matriz cuadrada de 100x100.
  -	Al iniciar el programa, el universo estará vacío - i.e ninguna célula está viva.
  -	El usuario puede escribir pares de números enteros para determinar qué células inician con vida.
  -	Cuando el usuario ingresa -1 -1 la simulación inicia
  -	Cada generación el programa imprimirá el estado actual del universo a consola.
  -	El usuario ingresara el carácter ‘n’ (next) para avanzar una generación
  -	El usuario puede ingresar el carácter ‘e’ (exit) para terminar la simulación.
...................................................................................................................................................................
