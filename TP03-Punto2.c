/* 

    2) Una empresa necesita simular la producción de los próximos 5 años para tal fin necesita generar una matriz (estática) de 5x12 donde cada fila corresponde a un año y cada columna es un mes. Ud. debe realizar las siguientes tareas:
        a. Cargue dicha matriz con valores aleatorios entre 10000 y 50000.
        b. Muestre por pantalla los valores cargados
        c. Saque el promedio de ganancia por año y muestrelos por pantalla
        d. Obtenga el valor máximo y el valor mínimo obtenido informando el “año” y el “mes” de
        cuándo ocurrió.

 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define M 5  // filas
#define N 12 // columnas

int main(){

    int Matriz[M][N], pMatriz, GananciaAnual[M], SumaAnual=0, i = 0, j = 0, Maximo, Minimo, PosMaxi, PosMin;

    pMatriz = Matriz;

    srand(time(NULL));
    
    // CARGADO DE LA MATRIZ

    for ( i = 0; i < M ; i++)   // el primer for recorre las filas, el segundo las columnas.
    {
        for ( j = 0; j < N; j++)
        {
            Matriz[i][j] = rand() % 4000 + 1000;       //Valores aleatoreos Formula: [MAX-MIN]+MIN
        }
    }
    


    // IMPRESION POR PANTALLA DE LA MATRIZ

    printf("\n\n\n_________     IMPRESION DE MATRIZ[%d][%d]     _________\n\n", M, N);

    for ( i = 0; i < M ; i++)   
    {
        for ( j = 0; j < N; j++)
        {
            printf("%d  ",Matriz[i][j] );      
        }
        printf("\n");
    }
    


    //CALCULO DE PROMEDIOS ANUALES

    for ( i = 0; i < M ; i++)   
    {
        for ( j = 0; j < N; j++)
        {
            SumaAnual = SumaAnual + Matriz[i][j];
        }
        GananciaAnual[i] = SumaAnual / N;
    }
    
    printf("\n\n_____    GANANCIAS ANUALES    _____\n\n");

    for ( i = 0; i < M; i++)
    {
        printf("Anio %d: %d \n",i+1,GananciaAnual[i]);
    }
    

    /*printf("%d",(1041 + 3467 + 3334 + 3500 + 4169 + 4724 + 4478 + 2358 + 3962 + 1464 + 2705 + 1145)/N);

    printf("%d",3028); */


    printf("\n\n_____    CALCULO DEL MAXIMO Y EL MINIMO POR ANIO    _____\n");
    for ( i = 0; i < M ; i++)   
    {
        Maximo = 999;
        Minimo =5001;
        for ( j = 0; j < N; j++)
        {   
            
            if ( Matriz[i][j] > Maximo)
            {
                Maximo = Matriz[i][j];
                PosMaxi = j;
            }

            if (Matriz[i][j] < Minimo)
            {
                Minimo = Matriz[i][j];
                PosMin = j;
            }
                  
        }
        printf("\nANIO %d\n    Maximo: %d  en el mes de: %d\n    Minimo: %d en el mes de: %d\n", i+1, Maximo, PosMaxi+1, Minimo, PosMin+1);      
    }

    return 0;
}


