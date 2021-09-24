#include <iostream>
#include <conio.h>
//clases
#include "restriccion.h"

using namespace std;

int main()
{

    int _tamano = 12;
    int _cantidad = 1;
    int _infracciones[12] = {20, 134, 43, 12, 5, 787, 980, 1123, 436, 974, 162, 209};

    //e.1
    Restriccion *R1 = new Restriccion(_tamano, _cantidad, _infracciones);
    float promedio = R1->promedio();

    printf("El promedio anual de infracciones de la ciudad: %f\n", promedio);

    if (R1->pruebaTeoria())
    {
        // retorna true si el promedio de meses pares > promedio 12 meses
        printf("La teor%ca de los meses pares es Verdadera.\n", 161);
    }
    else
    {
        printf("La teor%ca de los meses pares es Falso.\n", 161);
    }

    //e.2
    int _tamano2 = 12;
    int _cantidad2 = 1;
    int _infracciones2[12] = {200, 34, 438, 121, 50, 781, 90, 123, 936, 774, 622, 509};
    Restriccion *R2 = new Restriccion(_tamano2, _cantidad2, _infracciones2);

    if (R1->comparaCiudades(*R2))
    {
        // retorna true si r1 realiza al menos 7 meses mas infracciones
        printf("La R1 realiza un mejor control de la restricci%cn vehicular que la R2.\n", 162);
    }
    else
    {
        printf("La R2 realiza un mejor control de la restricci%cn vehicular que la R1.\n", 162);
    }

    //e.3
    Restriccion *R3 = new Restriccion();
    R3->estadoAmbasCiudades(*R1, *R2);
    R3->imprimir();
}

/* 
    notas: usar tílde
    á -> 160; 
    é -> 130; 
    í -> 161; 
    ó -> 162; 
    ú -> 163; 
    ñ -> 164;
    Ejemplo:
    printf("Hay un %crbol, que mat%c a un colibr%c.",160,162,161);

 */