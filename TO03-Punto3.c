/* 3) Escriba un programa que solicite 5 nombres, los cargue en un vector de punteros char y una vez cargados los liste por pantalla (Todo implementando reserva dinámica de memoria) (Lea las notas 1 y 2) */


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(){

    char *Vector[5], *buff, *vec;
    /* vec = Vector; */


    // PARA RESIVIR 1 NOMBRE
   /*  buff = (char *) malloc( 200 * sizeof(char));
    printf("\nPor favor ingrese su nombre: \n");
    gets(buff);
    Vector[1] = (char *) malloc ( (strlen(buff) + 1) * sizeof(char));
    strcpy(Vector[1], buff);
    puts(Vector[1]); */



    buff = (char *) malloc( 200 * sizeof(char));

    for (int i = 0; i < 5; i++)
    {
        printf("\nPor favor, ingrese El nombre q desea Cargar: \n");
        gets(buff);
        Vector[i] = (char *) malloc ( (strlen(buff) + 1) * sizeof(char));
        strcpy(Vector[i], buff);
        
    }
    
    /* vec = Vector; */
    printf("\nContenido del Vector: \n");
    for (int j = 0; j < 5; j++)
    {
        puts(Vector[j]);
        printf("\n");
    }
    

    // SEIMPRE ACORDARSE DE LIBERAR LA MEMORIA
    free(buff);
    for (int i = 0; i < 5; i++)
    {
        free(Vector[i]);
    }
    

    return 0;
}