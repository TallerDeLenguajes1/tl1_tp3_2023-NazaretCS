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
void CargaProductos(Producto * Productos, int cantProductos);
void MostrarCliente(Cliente *cliente, int cantClientes);

int main(){

    int cantClientes;
    Cliente *cliente;

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

    cliente = (Cliente *)malloc(cantClientes * sizeof(Cliente));

    CargarClientes(cliente, cantClientes);

    MostrarCliente(cliente, cantClientes);

    return 0;
}


void CargarClientes(Cliente *cliente, int cantClientes){

    char * buff = (char *)malloc(sizeof(char)*100);;

    for (int i = 0; i < cantClientes; i++)
    {
        cliente[i].ClienteID = i+1;
        cliente[i].NombreCliente = (char *)malloc(sizeof(char)*100);
        //printf("Ingrese el nombre Del Cliente: ");  //Provar mejorar esta parte
        printf("Ingrese el nombre Del Cliente: ");  //Provar mejorar esta parte
        fflush(stdin);
        //gets(cliente[i].NombreCliente);
        gets(buff);
        cliente[i].NombreCliente = (char *)malloc((strlen(buff) +1) * sizeof(char));
        strcpy(cliente[i].NombreCliente, buff);
        cliente[i].CantidadProductosAPedir = rand() % 5 +1;
        int cantProductos = cliente[i].CantidadProductosAPedir;
        cliente[i].Productos = (Producto *)malloc(cliente->CantidadProductosAPedir * sizeof(Producto));
        CargaProductos(cliente[i].Productos, cantProductos);
    }
    free(buff);
}


void CargaProductos(Producto * productos, int cantProductos){

    for (int j = 0; j < cantProductos; j++)
    {
        productos[j].ProductoID = j +1;
        productos[j].Cantidad = rand() %10 +1;
        productos[j].PrecioUnitario = rand() % 100 + 10;
        productos[j].TipoProducto = (char *)malloc(20*sizeof(char));
        productos[j].TipoProducto = *(TiposProductos + rand()%5);
    }
}




void MostrarCliente(Cliente *Cliente, int canti){
    
    for(int k = 0; k < canti; k++){
        printf("\n------Cliente[%d]------\n", k+1);
        printf("Id del Cliente: %d\n", Cliente[k].ClienteID);
        printf("Nombre : %s\n", Cliente[k].NombreCliente);
        printf("Cantidad de productos: %d\n\n",Cliente[k].CantidadProductosAPedir);
        printf("    PRODUCTOS\n");

        for(int m = 0; m < Cliente[k].CantidadProductosAPedir; m++){
            printf("    ID del producto: %d\n", Cliente[k].Productos[m].ProductoID);
            printf("    Cantidad: %d\n", Cliente[k].Productos[m].Cantidad);
            printf("    Precio unitario: %2.f\n", Cliente[k].Productos[m].PrecioUnitario);
            printf("    Productos que lleva: %s\n\n", Cliente[k].Productos[m].TipoProducto);
        }
    }
    free(Cliente);
}


