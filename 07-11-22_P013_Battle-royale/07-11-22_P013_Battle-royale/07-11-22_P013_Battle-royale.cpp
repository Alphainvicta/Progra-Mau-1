//Programa de battle royale
#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>
#include <fstream>
#include <vector>
#include <locale.h>

//Clase estudiante
class Estudiante {
public:
    std::string nombre;
    int vida = 100;
    int fuerza;
    int velocidad;
    int defensa;
};

//Estructura para enlistar de forma ordenada
struct Lista {
    std::string nombre;
    int numero;
};

//Funcion imprimir lista de estudiantes con su rango segun la habilidad
void imprimir_lista_rangos(std::vector<Lista> lista_temporal, std::string rangos) {
    int j = 1;
    for (int i = lista_temporal.size() - 1; i > -1; i--) {
        std::cout << "En la posicion ";
        std::cout << j++ << ": ";
        std::cout << lista_temporal[i].nombre;
        std::cout << " con un valor de... ";
        std::cout << lista_temporal[i].numero;
        std::cout << " puntos de " << rangos << "!";
        std::cout << "\n";

    }
}

// merges two subarrays of array[].
void merge(std::vector<Lista>& lista_temporal, int start, int middle, int end) {

    std::vector<Lista> lado_izquierdo(middle - start + 1);
    std::vector<Lista> lado_derecho(end - middle);

    // fill in left array
    for (int i = 0; i < lado_izquierdo.size(); ++i) {
        lado_izquierdo[i].nombre = lista_temporal[start + i].nombre;
        lado_izquierdo[i].numero = lista_temporal[start + i].numero;
    }


    // fill in right array
    for (int i = 0; i < lado_derecho.size(); ++i) {
        lado_derecho[i].nombre = lista_temporal[middle + 1 + i].nombre;
        lado_derecho[i].numero = lista_temporal[middle + 1 + i].numero;
    }

    /* Merge the temp arrays */

    // initial indexes of first and second subarrays
    int leftIndex = 0, rightIndex = 0;

    // the index we will start at when adding the subarrays back into the main array
    int currentIndex = start;

    // compare each index of the subarrays adding the lowest value to the currentIndex
    while (leftIndex < lado_izquierdo.size() && rightIndex < lado_derecho.size()) {
        if (lado_izquierdo[leftIndex].numero <= lado_derecho[rightIndex].numero) {
            lista_temporal[currentIndex].nombre = lado_izquierdo[leftIndex].nombre;
            lista_temporal[currentIndex].numero = lado_izquierdo[leftIndex].numero;
            leftIndex++;
        }
        else {
            lista_temporal[currentIndex].nombre = lado_derecho[rightIndex].nombre;
            lista_temporal[currentIndex].numero = lado_derecho[rightIndex].numero;
            rightIndex++;
        }
        currentIndex++;
    }

    // copy remaining elements of leftArray[] if any
    while (leftIndex < lado_izquierdo.size()) {
        lista_temporal[currentIndex].nombre = lado_izquierdo[leftIndex].nombre;
        lista_temporal[currentIndex].numero = lado_izquierdo[leftIndex].numero;
        currentIndex++;
        leftIndex++;
    }

    // copy remaining elements of rightArray[] if any
    while (rightIndex < lado_derecho.size()) {
        lista_temporal[currentIndex].nombre = lado_derecho[rightIndex].nombre;
        lista_temporal[currentIndex].numero = lado_derecho[rightIndex].numero;
        currentIndex++;
        rightIndex++;
    }
}

// Funcion para ordenar estructuras de datos con el metodo merge
void mergeSort(std::vector<Lista>& lista_temporal, int start, int end) {
    // base case
    if (start < end) {
        // find the middle point
        int middle = (start + end) / 2;

        mergeSort(lista_temporal, start, middle); // sort first half
        mergeSort(lista_temporal, middle + 1, end);  // sort second half

        // merge the sorted halves
        merge(lista_temporal, start, middle, end);
    }
}

//Funcion para ordenar de mayor a menor
void orden_rango(std::vector<Estudiante> lista_estudiantes, int rango) {
    std::vector<Lista> lista_temporal(lista_estudiantes.size());
    std::vector<std::string> rangos = { "vida", "fuerza", "velocidad", "defensa" };

    switch (rango) {
    case 0:
        for (int i = 0; i < lista_estudiantes.size(); i++) {
            lista_temporal[i].nombre = lista_estudiantes[i].nombre;
            lista_temporal[i].numero = lista_estudiantes[i].vida;
        }

        mergeSort(lista_temporal, 0, (lista_temporal.size() - 1));
        std::cout << "Este es el rango de los alumnos segun su vida";
        std::cout << "\n";
        std::cout << "\n";
        imprimir_lista_rangos(lista_temporal, rangos[0]);
        break;

    case 1:
        for (int i = 0; i < lista_estudiantes.size(); i++) {
            lista_temporal[i].nombre = lista_estudiantes[i].nombre;
            lista_temporal[i].numero = lista_estudiantes[i].fuerza;
        }

        mergeSort(lista_temporal, 0, (lista_temporal.size() - 1));
        std::cout << "Este es el rango de los alumnos segun su fuerza";
        std::cout << "\n";
        std::cout << "\n";
        imprimir_lista_rangos(lista_temporal, rangos[1]);
        break;

    case 2:
        for (int i = 0; i < lista_estudiantes.size(); i++) {
            lista_temporal[i].nombre = lista_estudiantes[i].nombre;
            lista_temporal[i].numero = lista_estudiantes[i].velocidad;
        }

        mergeSort(lista_temporal, 0, (lista_temporal.size() - 1));
        std::cout << "Este es el rango de los alumnos segun su velocidad";
        std::cout << "\n";
        std::cout << "\n";
        imprimir_lista_rangos(lista_temporal, rangos[2]);
        break;

    case 3:
        for (int i = 0; i < lista_estudiantes.size(); i++) {
            lista_temporal[i].nombre = lista_estudiantes[i].nombre;
            lista_temporal[i].numero = lista_estudiantes[i].defensa;
        }

        mergeSort(lista_temporal, 0, (lista_temporal.size() - 1));
        std::cout << "Este es el rango de los alumnos segun su defensa";
        std::cout << "\n";
        std::cout << "\n";
        imprimir_lista_rangos(lista_temporal, rangos[3]);
        break;
    }
}

//Funcion para asignar nombres
void asignar_nombre(std::vector<Estudiante>& lista_estudiantes) {
    std::ifstream MyReadFile("lista-nombres.txt");
    for (int i = 0; i < lista_estudiantes.size(); i++) {
        if (i > 28) lista_estudiantes[i].nombre = "Estudiante generico";
        else getline(MyReadFile, lista_estudiantes[i].nombre);
    }
    MyReadFile.close();
}

//Funcion para asignar valores de forma aleatoria
void aptitud_aleatoria(std::vector<Estudiante>& lista_estudiantes) {
    int r;
    for (int i = 0; i < lista_estudiantes.size(); i++) {
        r = rand() % 49;
        lista_estudiantes[i].vida += r;
        r = rand() % 49;
        lista_estudiantes[i].fuerza = r;
        r = rand() % 49;
        lista_estudiantes[i].velocidad = r;
        r = rand() % 49;
        lista_estudiantes[i].defensa = r;
    }
}

//Funcion para imprimir los alumnos restantes
void alumnos_restantes(int estudiantes) {
    std::cout << "Alumnos restantes";
    std::cout << "\n";
    Sleep(500);
    std::cout << ". ";
    Sleep(500);
    std::cout << ". ";
    Sleep(500);
    std::cout << ".";
    Sleep(500);
    std::cout << "\n";
    std::cout << "\n";

    std::string numero = std::to_string(estudiantes);
    int digitos = numero.length();
    int i = 0;
    int j = 0;

    std::string cero[] = { "  #### ", " ##  ##", " ##  ##", " ##  ##", "  #### " };
    std::string uno[] = { "     ##", "     ##", "     ##", "     ##", "     ##" };
    std::string dos[] = { " ##### ", "     ##", "  #### ", " ##    " , "  #####" };
    std::string tres[] = { " ######", "     ##", "   ####", "     ##", " ######" };
    std::string cuatro[] = { " ##  ##", " ##  ##", " ######", "     ##", "     ##" };
    std::string cinco[] = { " ######", " ##    ", "  #### ", "     ##", " ##### " };
    std::string seis[] = { "  #####", " ##    ", " ######", " ##    #", "  #####" };
    std::string siete[] = { " ######", "     ##", "    ## ", "   ##  ", "  ##   " };
    std::string ocho[] = { "  #### ", " ##  ##", "  #### ", " ##  ##", "  #### " };
    std::string nueve[] = { "  #####", " ##  ##", "  #####", "     ##", "     ##" };

    while (j < 5) {
        if (numero[i] == '0') {
            std::cout << cero[j];
            i++;
        }
        if (numero[i] == '1') {
            std::cout << uno[j];
            i++;
        }
        if (numero[i] == '2') {
            std::cout << dos[j];
            i++;
        }
        if (numero[i] == '3') {
            std::cout << tres[j];
            i++;
        }
        if (numero[i] == '4') {
            std::cout << cuatro[j];
            i++;
        }
        if (numero[i] == '5') {
            std::cout << cinco[j];
            i++;
        }
        if (numero[i] == '6') {
            std::cout << seis[j];
            i++;
        }
        if (numero[i] == '7') {
            std::cout << siete[j];
            i++;
        }
        if (numero[i] == '8') {
            std::cout << ocho[j];
            i++;
        }
        if (numero[i] == '9') {
            std::cout << nueve[j];
            i++;
        }
        if (i == digitos) {
            std::cout << std::endl;
            j++;
            i = 0;
        }
    }
}

int main()
{
    //Asignar el lenguaje a caracteres en español
    setlocale(LC_ALL, "es_ES.UTF-8");

    //Variables del programa
    srand(time(NULL));
    int rango;
    int estudiantes;
    estudiantes = 100;
    std::vector<Estudiante> lista_estudiantes(estudiantes);

    //Asignar los nombres de los alumnos
    asignar_nombre(lista_estudiantes);

    //Asignar de forma aleatoria todos los valores de estudiante
    aptitud_aleatoria(lista_estudiantes);

    //mostrar el rango de mayor a menor
    orden_rango(lista_estudiantes, rango = 0);
    std::cout << "\n";
    system("pause");
    system("cls");

    orden_rango(lista_estudiantes, rango = 1);
    std::cout << "\n";
    system("pause");
    system("cls");

    orden_rango(lista_estudiantes, rango = 2);
    std::cout << "\n";
    system("pause");
    system("cls");

    orden_rango(lista_estudiantes, rango = 3);
    std::cout << "\n";
    system("pause");
    system("cls");

    std::cout << "Se predice que " << lista_estudiantes[rango = rand() % estudiantes].nombre << " va a ganar!";
    std::cout << "\n";
    Sleep(2000);
    system("cls");

    //mostrar los alumnos restantes
    alumnos_restantes(estudiantes);
}