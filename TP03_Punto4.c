#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Producto;


struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable // “CantidadProductosAPedir”
} typedef Cliente;



void CargarClientes(Cliente *cliente, int cantClientes);
void CargarProductos(Producto *Productos, int CantProductos);
void MostrarClientes(Cliente *cliente, int cantClientes);

int main(){

    int cantClientes;
    Cliente *cliente, *pAuxClientes;

    srand(time(NULL));

    do
    {
        printf("\nPor favor, ingrese la cantidad de Clientes que atendera: (Como maximo puede atender 5 Clientes) \n");
        scanf("%d", &cantClientes);
        if (cantClientes > 5 || cantClientes < 1)
        {
            printf("El dato ingresado no corresponde con lo solicitado. Por favor, intente nuevamente...\n");
        }
    } while (cantClientes > 5 || cantClientes < 1);
    
    //printf("%d",cantClientes);

    cliente = (Cliente *) malloc(cantClientes * sizeof(cliente));    // reservo la memoria dinamica para esa cantidad de clientes.



    pAuxClientes = cliente;
    CargarClientes(pAuxClientes, cantClientes);


    pAuxClientes = cliente;
    MostrarClientes(pAuxClientes, cantClientes);

    return 0;
}


void CargarClientes(Cliente *cliente, int cantClientes){

    char *buff, *Nombre;
    
    buff = (char *) malloc( 100 * sizeof(char));

    for (int i = 0; i < cantClientes; i++)
    {
        cliente->ClienteID = i+1;
        fflush(stdin);
        printf("\n\nIngrese el Nombre del Cliente, por favor:\n");
        gets(buff);
        cliente->NombreCliente = (char *)malloc( (strlen(buff)+1) * sizeof(char) );
        strcpy(cliente->NombreCliente, buff);
        cliente->CantidadProductosAPedir = rand() % 4 + 1;

        //printf("%d \n", cliente->CantidadProductosAPedir);
        cliente->Productos = (Producto *) malloc(cliente->CantidadProductosAPedir * sizeof(Producto));

        CargarProductos(cliente->Productos, cliente->CantidadProductosAPedir);
        cliente++;
    }
    free(buff);
}


void CargarProductos(Producto *Productos, int CantProductos){

    char *buff;
    buff = (char *) malloc(100 * sizeof(char));

    //printf("asdasd %d\n",CantProductos);

    for (int i = 0; i < CantProductos; i++)
    {
        Productos->ProductoID = i+1;
        Productos->Cantidad = rand() % 9 + 1;
        Productos->PrecioUnitario = rand() % 900 + 100;
        buff = TiposProductos[(rand()%4)];
        Productos->TipoProducto = (char *) malloc( (strlen(buff) +1) * sizeof(char) );
        strcpy(Productos->TipoProducto, buff);
        Productos++;
    }
    //free(buff);
}


void MostrarClientes(Cliente *cliente, int cantClientes){

    printf("\n\n\nLISTADOS DE LOS CLIENTES\n");
    for (int i = 0; i < cantClientes; i++)
    {
        printf("\n\nCliente ID: %d\nNombre del Cliente: ",cliente->ClienteID);
        puts(cliente->NombreCliente);
        printf("Cantidad de Productos: %d\n", cliente->CantidadProductosAPedir);
        printf("\n   Detalle de los productos del cliente:");
        for (int j = 0; j < cliente->CantidadProductosAPedir; j++)
        {
            printf("\n      Tipo de Producto: ");
            puts(cliente->Productos->TipoProducto);
            printf("      Id del Producto: %d\n      Precio Unitario: %d\n      Cantidad: %d\n\n", cliente->Productos->ProductoID, cliente->Productos->PrecioUnitario, cliente->Productos->Cantidad);
            cliente->Productos++;
        }
        
        cliente++;
    }
    
}

/*  

    ***************************
    **                       **
    **        ######         **     1) Porque si descomento el free(buff) de la función CargarProductos se me produce un error.?
    **      ####   ####      **     
    **      ##     ###       **     2) Porque solo cuando estoy debugeando se me imprimen los detalles de los clientes.?
    **          ###          **     
    **         ###           **     3) Porque a veces me toma el primer nombre, y a veces no.?
    **         ##            **
    **                       **
    **         ##            **
    **                       **
    ***************************

*/