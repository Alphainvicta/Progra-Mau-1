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
    int fuerza = 0;
    int velocidad = 0;
    int defensa = 0;
};

//Estructura para enlistar de forma ordenada
struct Lista {
    std::string nombre;
    int numero = 0;
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

    std::string cero[] = { " ######", " ##  ##", " ##  ##", " ##  ##", " ######" };
    std::string uno[] = { "     ##", "     ##", "     ##", "     ##", "     ##" };
    std::string dos[] = { " ######", "     ##", " ######", " ##    " , " ######" };
    std::string tres[] = { " ######", "     ##", " ######", "     ##", " ######" };
    std::string cuatro[] = { " ##  ##", " ##  ##", " ######", "     ##", "     ##" };
    std::string cinco[] = { " ######", " ##    ", " ######", "     ##", " ######" };
    std::string seis[] = { " ######", " ##    ", " ######", " ##  ##", " ######" };
    std::string siete[] = { " ######", "     ##", "     ##", "     ##", "     ##" };
    std::string ocho[] = { " ######", " ##  ##", " ######", " ##  ##", " ######" };
    std::string nueve[] = { " ######", " ##  ##", " ######", "     ##", "     ##" };

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
    std::cout << "\n";
    Sleep(1000);
    system("cls");
}

//Funcion evento de pelea
void evento_pelea(int estudiante1, int estudiante2, std::vector<Estudiante>& lista_estudiantes, std::string& muertos_ronda) {
    std::cout << "Parece que " << lista_estudiantes[estudiante1].nombre << " esta peleando contra " << lista_estudiantes[estudiante2].nombre << "!";
    std::cout << "\n";
    if (lista_estudiantes[estudiante2].defensa >= lista_estudiantes[estudiante1].fuerza) {
        lista_estudiantes[estudiante2].defensa -= lista_estudiantes[estudiante1].fuerza;
        std::cout << "Pero tan solo logra reducir la defensa de " << lista_estudiantes[estudiante2].nombre << " a " << lista_estudiantes[estudiante2].defensa << " puntos de defensa!";
    }
    else {
        lista_estudiantes[estudiante2].vida -= (lista_estudiantes[estudiante1].fuerza - lista_estudiantes[estudiante2].defensa);
        lista_estudiantes[estudiante2].defensa = 0;
        if (lista_estudiantes[estudiante2].vida > 0) {
            std::cout << "Parece que " << lista_estudiantes[estudiante1].nombre << " logro herir a " << lista_estudiantes[estudiante2].nombre << " dejandolo a " << lista_estudiantes[estudiante2].vida << " puntos de vida!";
        }
        else {
            std::cout << "Increible!!! " << lista_estudiantes[estudiante1].nombre << " acaba de matar a " << lista_estudiantes[estudiante2].nombre << " terminado este enfrentamiento!";
            muertos_ronda += lista_estudiantes[estudiante2].nombre;
            muertos_ronda += ",";
            lista_estudiantes.erase(lista_estudiantes.begin() + estudiante2);
        }
    }
    std::cout << "\n";
    std::cout << "\n";
}

//Funcion evento comida
void evento_comida(int estudiante1, int estudiante2, std::vector<Estudiante>& lista_estudiantes) {
    std::cout << lista_estudiantes[estudiante1].nombre << " y " << lista_estudiantes[estudiante2].nombre << " han decidido dejar de pelear para para poder comer...";
    std::cout << "\n";
    int rango = rand() % 3;
    
    switch (rango)
    {
    case 0:
        std::cout << "Pero parece que ambos se han intoxicado perdiendo velocidad por su pesima cocina";
        if (lista_estudiantes[estudiante1].velocidad > 0) {
            lista_estudiantes[estudiante1].velocidad -= rand() % lista_estudiantes[estudiante1].velocidad;
        }
        if (lista_estudiantes[estudiante1].vida > 1) {
            lista_estudiantes[estudiante1].vida -= rand() % lista_estudiantes[estudiante1].vida;
        }
        if (lista_estudiantes[estudiante2].velocidad > 0) {
            lista_estudiantes[estudiante2].velocidad -= rand() % lista_estudiantes[estudiante2].velocidad;
        }
        if (lista_estudiantes[estudiante2].vida > 1) {
            lista_estudiantes[estudiante2].vida -= rand() % lista_estudiantes[estudiante2].vida;
        }
        break;
    case 1:
        std::cout << "Al parecer ninguno tenia algo para comer...";
        break;
    case 2:
        std::cout << "Increible! jamas habia visto una comida tan coordinada y deliciosa! su velocidad y su vida se han elevado!";
        lista_estudiantes[estudiante1].vida += rand() % 20;
        lista_estudiantes[estudiante1].velocidad += rand() % 20;
        lista_estudiantes[estudiante2].vida += rand() % 20;
        lista_estudiantes[estudiante2].velocidad += rand() % 20;
        break;
    }
    std::cout << "\n";
    std::cout << "\n";
}

//Funcion evento botin
void evento_botin(int estudiante1, int estudiante2, std::vector<Estudiante>& lista_estudiantes) {
    std::cout << "una caja de botin se encuentra frente a " << lista_estudiantes[estudiante1].nombre << " y " << lista_estudiantes[estudiante2].nombre;
    std::cout << "\n";
    int rango = rand() % 4;
    if (lista_estudiantes[estudiante1].velocidad > lista_estudiantes[estudiante2].velocidad) {
        std::cout << lista_estudiantes[estudiante1].nombre << " resulto ser mas rapido que " << lista_estudiantes[estudiante2].nombre << " quedandose con una mejora de ";
        switch (rango)
        {
        case 0:
            std::cout << "absolutamente nada!";
            break;
        case 1:
            lista_estudiantes[estudiante1].defensa += rand() % 20;
            std::cout << "defensa!";
            break;
        case 2:
            lista_estudiantes[estudiante1].fuerza += rand() % 20;
            std::cout << "fuerza!";
            break;
        case 3:
            lista_estudiantes[estudiante1].vida += rand() % 20;
            std::cout << "vida!";
            break;
        }
    }
    else {
        std::cout << lista_estudiantes[estudiante2].nombre << " resulto ser mas rapido que " << lista_estudiantes[estudiante1].nombre << " quedandose con una mejora de ";
        switch (rango)
        {
        case 0:
            std::cout << "absolutamente nada!";
            break;
        case 1:
            lista_estudiantes[estudiante2].defensa += rand() % 20;
            std::cout << "defensa!";
            break;
        case 2:
            lista_estudiantes[estudiante2].fuerza += rand() % 20;
            std::cout << "fuerza!";
            break;
        case 3:
            lista_estudiantes[estudiante2].vida += rand() % 20;
            std::cout << "vida!";
            break;
        }
    }
    std::cout << "\n";
    std::cout << "\n";
}

//Funcion evento tenis
void evento_tenis(int estudiante1, int estudiante2, std::vector<Estudiante>& lista_estudiantes) {
    std::cout << "Al parecer " << lista_estudiantes[estudiante1].nombre << " y " << lista_estudiantes[estudiante2].nombre << " estan intercambiando sus tenis para tener mas velocidad";
    std::cout << "\n";
    int rango = rand() % 3;
    switch (rango)
    {
    case 0:
        std::cout << "Parece que ha sido una terrible idea... ambos perdieron velocidad";
        if (lista_estudiantes[estudiante1].velocidad > 0) {
            lista_estudiantes[estudiante1].velocidad -= rand() % lista_estudiantes[estudiante1].velocidad;
        }
        if (lista_estudiantes[estudiante2].velocidad > 0) {
            lista_estudiantes[estudiante2].velocidad -= rand() % lista_estudiantes[estudiante2].velocidad;
        }
        break;
    case 1:
        std::cout << "Parece que no mejoro nada cambiar tenis";
        break;
    case 2:
        std::cout << "No lo puedo creer, de alguna manera se han vuelto mas rapidos con solo intercambiar sus tenis!";
        lista_estudiantes[estudiante1].velocidad += rand() % 20;
        lista_estudiantes[estudiante2].velocidad += rand() % 20;
        break;
    }
    std::cout << "\n";
    std::cout << "\n";
}

//Funcion evento muerte por ambiente
void evento_muerte_ambiente(int estudiante1, int estudiante2, std::vector<Estudiante>& lista_estudiantes, std::string& muertos_ronda) {
    int rango = rand() % 2;
    std::cout << "El suelo debajo de " << lista_estudiantes[estudiante1].nombre << " y " << lista_estudiantes[estudiante2].nombre << " ha empezado a caerse!";
    std::cout << "\n";
    if (lista_estudiantes[estudiante1].velocidad > lista_estudiantes[estudiante2].velocidad) {
        std::cout << lista_estudiantes[estudiante1].nombre << " toma la delantera ";
        if (lista_estudiantes[estudiante1].fuerza > lista_estudiantes[estudiante2].fuerza) {
            std::cout << "y con su fuerza termina empujando a " << lista_estudiantes[estudiante2].nombre << " hacia el vacio ";
            if (rango == 0){
                std::cout << "eliminandolo por completo!!!";
                muertos_ronda += lista_estudiantes[estudiante2].nombre;
                muertos_ronda += ",";
                lista_estudiantes.erase(lista_estudiantes.begin() + estudiante2);
            }
            else {
                std::cout << " pero logra sobrevivir de milagro!!!";
                if (lista_estudiantes[estudiante2].vida > 1) {
                    lista_estudiantes[estudiante2].vida -= rand() % lista_estudiantes[estudiante2].vida;
                }
            }
            return;
        }
        if (lista_estudiantes[estudiante1].fuerza < lista_estudiantes[estudiante2].fuerza) {
            std::cout << "pero en un giro inesperado " << lista_estudiantes[estudiante2].nombre << " con su fuerza superior empuja a " << lista_estudiantes[estudiante1].nombre << " al vacio ";
            if (rango == 0) {
                std::cout << "eliminandolo por completo!!!";
                muertos_ronda += lista_estudiantes[estudiante1].nombre;
                muertos_ronda += ",";
                lista_estudiantes.erase(lista_estudiantes.begin() + estudiante1);
            }
            else {
                std::cout << " pero logra sobrevivir de milagro!!!";
                if (lista_estudiantes[estudiante1].vida > 1) {
                    lista_estudiantes[estudiante1].vida -= rand() % lista_estudiantes[estudiante1].vida;
                }
            }
            return;
        }
    }

    if (lista_estudiantes[estudiante1].velocidad < lista_estudiantes[estudiante2].velocidad) {
        std::cout << lista_estudiantes[estudiante2].nombre << " toma la delantera ";
        if (lista_estudiantes[estudiante1].fuerza < lista_estudiantes[estudiante2].fuerza) {
            std::cout << "y con su fuerza termina empujando a " << lista_estudiantes[estudiante1].nombre << " hacia el vacio ";
            if (rango == 0) {
                std::cout << "eliminandolo por completo!!!";
                muertos_ronda += lista_estudiantes[estudiante1].nombre;
                muertos_ronda += ",";
                lista_estudiantes.erase(lista_estudiantes.begin() + estudiante1);
            }
            else {
                std::cout << " pero logra sobrevivir de milagro!!!";
                if (lista_estudiantes[estudiante1].vida > 1) {
                    lista_estudiantes[estudiante1].vida -= rand() % lista_estudiantes[estudiante1].vida;
                }
            }
            return;
        }
        if (lista_estudiantes[estudiante1].fuerza > lista_estudiantes[estudiante2].fuerza) {
            std::cout << "pero en un giro inesperado " << lista_estudiantes[estudiante1].nombre << " con su fuerza superior empuja a " << lista_estudiantes[estudiante2].nombre << " al vacio ";
            if (rango == 0) {
                std::cout << "eliminandolo por completo!!!";
                muertos_ronda += lista_estudiantes[estudiante2].nombre;
                muertos_ronda += ",";
                lista_estudiantes.erase(lista_estudiantes.begin() + estudiante2);
            }
            else {
                std::cout << " pero logra sobrevivir de milagro!!!";
                if (lista_estudiantes[estudiante2].vida > 1) {
                    lista_estudiantes[estudiante2].vida -= rand() % lista_estudiantes[estudiante2].vida;
                }
            }
            return;
        }
    }
}

//Funcion de evento aleatorio
void evento_aleatorio(std::vector<Estudiante>& lista_estudiantes, std::string& muertos_ronda) {
    int rango;
    int aleatorio1, aleatorio2;
    for (int i = 0; i < lista_estudiantes.size(); i++) {
        rango = rand() % 5;
        aleatorio1 = rand() % lista_estudiantes.size();
        aleatorio2 = rand() % lista_estudiantes.size();
        while (aleatorio1 == aleatorio2) {
            aleatorio2 = rand() % lista_estudiantes.size();
        }

        switch (rango) {
            case 0:
                evento_pelea(aleatorio1, aleatorio2, lista_estudiantes, muertos_ronda);
                break;

            case 1:
                evento_comida(aleatorio1, aleatorio2, lista_estudiantes);
                break;

            case 2:
                evento_botin(aleatorio1, aleatorio2, lista_estudiantes);
                break;

            case 3:
                evento_tenis(aleatorio1, aleatorio2, lista_estudiantes);
                break;
            case 4:
                evento_muerte_ambiente(aleatorio1, aleatorio2, lista_estudiantes, muertos_ronda);
                std::cout << "\n";
                std::cout << "\n";
                break;
        }
    }
}

//Funcion de mejorar al favorito
void estudiante_predicto(std::vector<Estudiante>& lista_estudiantes, int rango, int estudiantes) {
    std::cout << "Se predice que " << lista_estudiantes[rango = rand() % estudiantes].nombre << " va a ganar!";
    std::cout << "\n";
    Sleep(2000);
    lista_estudiantes[rango].defensa += 10;
    lista_estudiantes[rango].fuerza += 10;
    lista_estudiantes[rango].vida += 10;
    lista_estudiantes[rango].velocidad += 10;
}

//Funcion estudiantes muertos
void estudiantes_muertos(std::string muertos_ronda) {
    int j = 1;
    system("cls");
    std::cout << "Los estudiantes que perdieron su vida en esta ronda fueron los siguientes... ";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << j << ": ";
    for (int i = 0; i < muertos_ronda.size(); i++) {
        if(muertos_ronda[i] != ',')
            std::cout << muertos_ronda[i];
        else {
            j++;
            std::cout << "\n";
            if (i < muertos_ronda.size()-1)
            std::cout << j << ": ";
        } 
    }
    std::cout << "\n";
    system("pause");
}

//Funcion del battle royale
void battle_royale(int& vivos, int& estudiantes, int& ronda, std::vector<Estudiante>& lista_estudiantes) {
    std::string muertos_ronda;

    while (true) {
        system("cls");

        std::cout << "Ronda: " << ronda << "!";
        std::cout << "\n";
        std::cout << "\n";

        //mostrar los alumnos restantes
        if (vivos != estudiantes) {
            alumnos_restantes(estudiantes);
            vivos = estudiantes;
        }
        else {
            Sleep(1000);
            system("cls");
        }

        //eventos aleatorios
        evento_aleatorio(lista_estudiantes, muertos_ronda);
        system("pause");
        estudiantes = lista_estudiantes.size();

        //mostrar los estudiantes muertos de la ronda
        if (vivos != estudiantes && estudiantes != 1) {
            estudiantes_muertos(muertos_ronda);
            muertos_ronda.clear();
        }

        if (estudiantes == 1) {
            break;
        }
        ronda++;
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
    estudiantes = 1000;
    int vivos = estudiantes;
    int ronda = 1;
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

    //Se mejora a un estudiante elegido al azar
    estudiante_predicto(lista_estudiantes, rango, estudiantes);

    //Ciclo del battle royale
    battle_royale(vivos, estudiantes, ronda, lista_estudiantes);
    system("cls");

    std::cout << "Damas y caballeros despues de " << ronda << " rondas " << "restandole " << lista_estudiantes[0].vida << " puntos de vida... " << lista_estudiantes[0].nombre << " es nuestro campeon de este battle royale!";
    std::cout << "\n";
    std::cout << "\n";
}