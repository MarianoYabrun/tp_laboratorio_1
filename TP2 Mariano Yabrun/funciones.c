
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "datawarehouse.h"


/** \brief Muestra en pantalla cada una de las variables de una estructura eEmpleado.
 *
 * \param eEmpleado.
 * \param
 * \return void.
 *
 */

void mostrarEmpleado(eEmpleado x)
{
    printf("\n%4d  ", x.id);
    printf("  %d",x.sector);
    printf("   %4s", x.apellido);
    printf("   %4s", x.nombre);
    printf("   %.2f\n", x.sueldo);

}

/** \brief Utiliza la funcion mostrarEmpleado anidada dentro de un for para mostrar en pantalla un vector de eEmpleado.
 *
 * \param eEmpleado vector[].
 * \param tamanio del vector.
 * \return void
 *
 */

void mostrarEmpleados(eEmpleado vec[], int tam)
{

    printf("\n\n**** LISTADO DE EMPLEADOS****\n\n");
    printf("ID  SECTOR  APELLIDOS  NOMBRE   SUELDO  \n\n");


    ordenarEmpleados(vec, tam);


    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarEmpleado(vec[i]);
        }

    }
    system("pause");


}


/** \brief ordena el vector de eEmpleados por sectores y se ser iguales por apellido.
 *
 * \param eEmpleado vec[].
 * \param taminio del vector.
 * \return  void.
 *
 */

void ordenarEmpleados(eEmpleado vec[], int tam)
{
    eEmpleado auxEmpleado;

    for(int i=0; i<tam-1; i++)
    {

        for(int j=i+1; j<tam; j++)
        {

            if(vec[i].sector > vec[j].sector)
            {

                auxEmpleado = vec[i];
                vec[i] = vec[j];
                vec[j] = auxEmpleado;


            }
            else if(vec[i].sector == vec[j].sector && strcmp(vec[i].apellido, vec[j].apellido) > 0)
            {

                auxEmpleado = vec[i];
                vec[i] = vec[j];
                vec[j] = auxEmpleado;

            }
        }
    }
}

/** \brief Inicializar el vector de eEmpleados igualando a 1 la variable "isEmpty".
 *
 * \param eEmpleado vec[].
 * \param taminio del vector,
 * \return void.
 *
 */

void inicializarEmpleados(eEmpleado vec[], int tam)
{

    for(int i=0; i<tam; i++)
    {

        vec[i].isEmpty = 1;

    }

}

/** \brief  Mostrar en pantalla un menu de 5 opciones.
 *
 * \param void
 * \param void
 * \return opcion seleccionada por el usuario.
 *
 */

int menu()
{
    int opcion;


    printf("\n\n***Gestion de lista empleados***\n\n");
    printf("1) ALTA\n");
    printf("2) MODIFICAR \n");
    printf("3) BAJA \n");
    printf("4) INFORME\n");
    printf("5) SALIR\n");

    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);


    return opcion;
}

/** \brief Busca el indice del vector vacio mas cercano.
 *
 * \param eEmpleado vec[].
 * \param tamanio del vector.
 * \return el indice del vector.
 *
 */

int buscarLibre( eEmpleado vec[], int tam)
{

    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty ==1)
        {
            indice =i;
            break;
        }

    }
    return indice;
}


/** \brief busqueda de un empleado por id.
 *
 * \param int id .
 * \param eEmpleado vec[].
 * \param tamanio del vector.
 * \return indice del empleado cuyo id es pasado por parametro o -1 en caso de no ser encontrado.
 *
 */

int buscarEmpleado(int id,eEmpleado vec[], int tam)
{
    int indice = -1;

    for(int i=0; i<tam; i++)

    {
        if(vec[i].id == id && vec[i].isEmpty == 0)
        {
            indice =i;
            break;
        }

    }
    return indice;
}

/** \brief dar de alta un empleado en el programa, pidiendole al usario todos los datos menos el id que es generado automaticamente.
 *
 * \param int id.
 * \param eEmpleado vec[].
 * \return 0 de estar completo el sistema o 1 si el alta se pudo realizar.
 *
 */

int altaEmpleado( int id, eEmpleado vec[], int tam)
{

    int indice = buscarLibre(vec, tam);
    eEmpleado auxEmpleado;
    int todoOk;

    if(indice == -1)
    {
        printf("Sistema completo \n\n");
        todoOk =0;

    }
    else
    {
        auxEmpleado.id = id;

        printf("\n Ingrese Nombre: ");
        fflush(stdin);
        gets(auxEmpleado.nombre);

        printf("\n Ingrese Apellido: ");
        fflush(stdin);
        gets(auxEmpleado.apellido);

        printf("\n Ingrese Sueldo: ");
        fflush(stdin);
        scanf("%f", &auxEmpleado.sueldo );

        printf("\n Ingrese sector: ");
        fflush(stdin);
        scanf("%d", &auxEmpleado.sector);

        auxEmpleado.isEmpty =0;

        vec[indice] = auxEmpleado;
        todoOk =1;
    }
    return todoOk;
}

/** \brief baja logica del un empleado en el vector igualando la variable "isEmpty" a 1.
 * \param eEmpleado vec[].
 * \param  tamanio del vector.
 * \return void
 *
 */

void bajaEmpleado(eEmpleado vec[], int tam)
{
    int id;
    int indice;
    char confirmar;
    system("cls");
    printf("***BAJA EMPLEADO***");
    printf("Ingrese id del empleado que quiera eliminar del sistema: ");
    scanf("%d", &id);

    indice = buscarEmpleado(id, vec, tam);

    if(indice ==-1)
    {
        printf("\nNo hay un empleado cuyo id sea %d", id);
    }
    else
    {
        mostrarEmpleado(vec[indice]);

        printf("\n\nConfirma la baja de ese empleado? presione 's' para confirmar ");
        fflush(stdin);
        scanf("%c", &confirmar);

        if(confirmar == 's')
        {
            vec[indice].isEmpty = 1;
            printf("BAJA EXITOSA");
        }
        else
        {
            printf("\nSe ha cancelado la operacion\n");
        }
    }
}

/** \brief Modificar un empleado del vector, se le pide al usuario el id para identificar al empleado y luego el debe decidir que variable quiere modificar.
 *
 * \param eEmpleado vec[].
 * \param tamanio del vector.
 * \return void.
 *
 */

void modificarEmpleado (eEmpleado vec[], int tam)
{

    int id;
    int opcion;
    int indice;
    system("cls");

    printf("***** Modificar Empleado *****\n\n");
    printf("Ingrese id del empleado que quiera modificar: ");
    scanf("%d", &id);

    indice = buscarEmpleado(id, vec, tam);

    if(indice == -1)
    {
        printf("No existe un empleado con ese ID");
    }
    else
    {

        mostrarEmpleado(vec[indice]);

        printf("Que dato desea modificar? \n\n");
        printf("1- Modificar nombre\n");
        printf("2- Modificar apellido\n");
        printf("3- Modificar sueldo\n");
        printf("4- Modificar sector\n");
        printf("5- Salir\n");

        scanf("%d", &opcion);



        switch(opcion)
        {
        case 1:
            printf("Ingrese nuevo nombre: ");
            fflush(stdin);
            gets(vec[indice].nombre);
            break;

        case 2:
            printf("Ingrese nuevo apellido: ");
            fflush(stdin);
            gets(vec[indice].apellido);
            break;

        case 3:
            printf("ingrese nuevo sueldo: ");
            fflush(stdin);
            scanf("%f", &vec[indice].sueldo);
            break;

        case 4:
            printf("ingrese nuevo sector:  ");
            fflush(stdin);
            scanf("%d", &vec[indice].sector);
            break;

        case 5:
            break;

        default:
            printf("OPCION NO VALIDA\n\n");
            break;
        }
    }
}

/** \brief utiliza un switch y 3 funciones, dandole al usario la opcion de que elija que informe desea realizar.
 *
 * \param eEmpleado vec[].
 * \param tamanio del vector
 * \return void
 *
 */

void informar(eEmpleado vec[], int tam)
{

    char seguir ='s';


    do
    {

        switch (menuInformes())
        {

        case 1:
            mostrarEmpleados(vec, tam);

            break;
        case 2:
            informarSueldos(vec, tam);
            break;

        case 3:
            seguir = 'n';
            break;

        }

    }
    while (seguir =='s');

}

/** \brief muestra en pantalla un menu de informes al usuario.
 *
 * \param void
 * \param void
 * \return opcion elegida por el usuario.
 *
 */

int menuInformes()
{
    int opcion;

    system("cls");
    printf("\n\n***INFORME EMPLEADOS*** \n\n");
    printf("\n\n***Gestion de informes***\n\n");
    printf("1) Listado de los empleados ordenados alfabeticamente por Apellido y Sector\n\n");
    printf("2) Total y promedio de los salarios, y cuantos empleados superan el salario promedio\n\n");
    printf("3) Salir \n\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);


    return opcion;
}



/** \brief funcion que calcula el total de sueldos en las empleados del vector asi como tambien el promedio y cuantos empleados superan ese promedio y los muestra en pantalla.
 *
 * \param eEmpleado vec[].
 * \param tamanio del vector.
 * \return void.
 *
 */

void informarSueldos(eEmpleado vec[], int tam)
{
    float total =0;
    int contador = 0;
    float promedio;
    int contadorEmpleados =0;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            total += vec[i].sueldo;
            contador++;

        }

    }
    promedio = total / contador;

    for(int j=0; j<tam; j++)
    {
        if(vec[j].isEmpty == 0 && vec[j].sueldo > promedio)
        {
            contadorEmpleados++;

        }

    }


    printf("\nel Total de los sueldos es de $ %.2f \n", total);
    printf("\nEl promedio de sueldos es de %.2f y la cantidad de empleados cuyo sueldo supera el promedio es de %d\n", promedio, contadorEmpleados);

    system("pause");
}

/** \brief Carga de empleados guardados en datawarehouse con proposito de testing
 *
 * \param eEmpleado vec[].
 * \param cantidad que se quieran cargar en sistema
 * \return void
 *
 */

void harcodearEmpleados (eEmpleado vec[], int cant)
{
    for(int i=0; i<cant; i++)

    {
        vec[i].id = ids[i];
        vec[i].sector = sectores[i];
        strcpy (vec[i].nombre, nombres[i]);
        strcpy (vec[i].apellido, apellidos[i] );
        vec[i].sueldo = sueldos[i];
        vec[i].isEmpty =0;

    }
}
