

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 1000
#include "funciones.h"



int main()
{
    int proximoId = 1010;
    char seguir = 's';
    char salir;
    eEmpleado lista[TAM];
    int flag =0;

    inicializarEmpleados(lista, TAM);

    harcodearEmpleados(lista, 10); // DEJO EL HARDCODEO PARA TESTEO DEL PROGRAMA, EL MISMO PUEDE SER COMENTADO Y EL PROGRAMA ANDA PERFECTAMENTE IGUAL.


    do
    {

        switch (menu())
        {

        case 1:
            if(altaEmpleado( proximoId, lista, TAM) == 1)
            {
                proximoId++;
                flag =1;
            }
            break;
        case 2:
            if(flag ==1)
            {
                modificarEmpleado (lista, TAM);
            }
            else
            {

                printf("\nNo dio de alta ningun empleado\n");
            }

            break;
        case 3:
            if(flag ==1)
            {
                bajaEmpleado(lista, TAM);
            }
            else
            {
                printf("\nNo dio de alta ningun empleado\n");
            }
            break;
        case 4:
            if(flag ==1)
            {
                informar(lista, TAM);
            }
            else
            {
                printf("\nNo dio de alta ningun empleado\n");
            }

            break;

        case 5:
            printf("\nconfirma salir? : ");
            scanf("%c", &salir);

            if(salir == 's')
            {
                seguir = 'n';
            }

            break;

        default:
            printf("OPCION NO VALIDA\n\n");
        }

    }
    while (seguir =='s');

    return 0;
}


