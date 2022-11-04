//Programa de batalla tipo pokemon
#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>

//funcion de menu principal
void menu_principal() {
	std::cout << "#############################" << "\n";
	std::cout << "EPICA BATALLA POKEMON!!!" << "\n";
	std::cout << "#############################" << "\n";
	std::cout << "\n";
	std::cout << "Elige a tu pokemon!";
	std::cout << "\n";
	std::cout << "1: tilin, 2: el pepe, 3: ete sech";
	std::cout << "\n";
}

//funcion de eleccion pokemon
void eleccion_pokemon(int &eleccion, std::string &nombre, std::string &eleccion_com) {
	while (true) {
		std::cin >> eleccion;
		std::cout << "\n";
		if (eleccion < 1 || eleccion > 3) {
			std::cout << "Por favor elige una opcion valida";
			std::cout << "\n";
			std::cout << "1: tilin, 2: elpepe, 3: etesech";
			std::cout << "\n";
			std::cout << "\n";
		}
		else {
			if (eleccion == 1) {
				//la computadora elige el contrario
				eleccion_com = "dios pepe";

				//poner un nombre personalizado al pokemon elegido
				std::cout << "Como quieres llamar a tu tilin?";
				std::cout << "\n";
				getline(std::cin, nombre);
				getline(std::cin, nombre);
			}
			if (eleccion == 2) {
				//la computadora elige el contrario
				eleccion_com = "big sech";

				//poner un nombre personalizado al pokemon elegido
				std::cout << "Como quieres llamar a tu elpepe?";
				std::cout << "\n";
				getline(std::cin, nombre);
				getline(std::cin, nombre);
			}
			if (eleccion == 3) {
				//la computadora elige el contrario
				eleccion_com = "tilin supremo";

				//poner un nombre personalizado al pokemon elegido
				std::cout << "Como quieres llamar a tu etesech?";
				std::cout << "\n";
				getline(std::cin, nombre);
				getline(std::cin, nombre);
			}

			Sleep(500);
			std::cout << "\n";
			std::cout << "Excelente nombre! Parece que le gusta";
			std::cout << "\n";
			break;
		}
	}
}

//funcion de batalla
void batalla(int &vida, int &vida_com, int &eleccion, int &eficiencia, int &curaciones, std::string &eleccion_com, std::string &nombre) {
	std::cout << "Es hora de la batalla!";
	std::cout << "\n";
	std::cout << "\n";

	//ciclo de batalla
	while (true) {
		//muestra de la vida
		std::cout << "vida de " << eleccion_com << ": " << vida_com << "\n";
		std::cout << "vida de " << nombre << ": " << vida << "\n";
		std::cout << "\n";

		//Turno del jugador jugador
		std::cout << "que quieres hacer?";
		std::cout << "\n";
		std::cout << "1: atacar, 2: curarte";
		std::cout << "\n";
		std::cout << "\n";

		//comprobador de eleccion posible
		while (true) {
			std::cin >> eleccion;
			std::cout << "\n";
			if (eleccion < 1 || eleccion > 2) {
				std::cout << "Por favor elige una opcion valida";
				std::cout << "\n";
				std::cout << "1: atacar, 2: curarte";
				std::cout << "\n";
				std::cout << "\n";
			}
			else {
				std::cout << "*********************************************************" << "\n";
				//eleccion de atacar
				if (eleccion == 1) {
					Sleep(1000);
					std::cout << nombre << " ataca a " << eleccion_com << "\n";
					std::cout << "\n";
					Sleep(2000);

					//se elige de forma aleatoria la eficiencia del ataque
					eficiencia = rand() % 4;

					if (eficiencia == 0) {
						std::cout << "Pero fue completamente esquivado";
						std::cout << "\n";
					}

					if (eficiencia == 1) {
						std::cout << eleccion_com << " esquiva por poco";
						std::cout << "\n";
						vida_com -= 10;
					}

					if (eficiencia == 2) {
						std::cout << eleccion_com << " recibe el golpe";
						std::cout << "\n";
						vida_com -= 15;
					}

					if (eficiencia == 3) {
						std::cout << eleccion_com << "recibe un golpe critico!";
						std::cout << "\n";
						vida_com -= 20;
					}
				}

				//eleccion de curarte
				if (eleccion == 2) {
					//comprobacion de daño
					if (vida == 100) {
						std::cout << nombre << " esta completamente sano";
						std::cout << "\n";
					}

					if (curaciones == 0) {
						std::cout << nombre << " ya no quedan mas curaciones!";
						std::cout << "\n";
					}

					else {
						Sleep(1000);
						std::cout << nombre << " se cura ligeramente";
						std::cout << "\n";
						vida += 20;
						curaciones -= 1;
					}
				}
				std::cout << "*********************************************************" << "\n";
				std::cout << "\n";
				break;
			}
		}
		Sleep(2000);

		//turno de la computadora
		std::cout << "##################################################################" << "\n";
		if (vida_com < 10) {
			Sleep(1000);
			std::cout << eleccion_com << " se cura ligeramente";
			std::cout << "\n";
			vida += 10;
		}
		else {
			Sleep(1000);
			std::cout << eleccion_com << " ataca a " << nombre << "\n";
			std::cout << "\n";
			Sleep(2000);
			eficiencia = rand() % 3;

			if (eficiencia == 0) {
				std::cout << nombre << " apenas logra esquivar el golpe";
				std::cout << "\n";
				vida -= 15;
			}
			if (eficiencia == 1) {
				std::cout << nombre << " recive el golpe";
				std::cout << "\n";
				vida -= 20;
			}
			if (eficiencia == 2) {
				std::cout << nombre << " recive un golpe critico!";
				std::cout << "\n";
				vida -= 25;
			}
		}
		std::cout << "##################################################################";
		Sleep(2000);

		system("cls");
		Sleep(1000);
		//escaneo de vida
		if (vida <= 0) {
			std::cout << nombre << " ha caido!";
			std::cout << "\n";
			std::cout << "el ganador es " << eleccion_com << "!";
			std::cout << "\n";
			break;
		}
		if (vida_com <= 0) {
			std::cout << eleccion_com << " ha caido!";
			std::cout << "\n";
			std::cout << "el ganador es " << nombre << "!";
			std::cout << "\n";
			break;
		}
	}
}

//funcion de reinicio
void reinicio(int & reiniciar) {
	std::cout << "Deseas volver a iniciar papu?" << "\n";
	std::cout << "1: si, 2: no" << "\n";
	std::cin >> reiniciar;
	system("cls");
}

int main()
{
	//ciclo de reinicio
	int reiniciar = 1;
	do {
		//variables
		int eleccion = 0;
		std::string eleccion_com = "";
		std::string nombre = "";
		int vida = 100;
		int vida_com = 100;
		int curaciones = 3;
		int eficiencia;
		srand(time(NULL));

		//menu principal
		menu_principal();

		//comprobador de eleccion posible
		eleccion_pokemon(eleccion, nombre, eleccion_com);

		Sleep(1000);
		system("cls");
		
		//batalla pokemon
		batalla(vida, vida_com, eleccion, eficiencia, curaciones, eleccion_com, nombre);

		Sleep(2000);
		system("cls");

		//reicio del programa
		reinicio(reiniciar);
		
	} while (reiniciar == 1);
}
