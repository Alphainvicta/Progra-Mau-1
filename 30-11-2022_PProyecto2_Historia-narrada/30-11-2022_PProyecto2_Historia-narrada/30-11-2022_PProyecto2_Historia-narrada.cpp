#include <iostream>
#include <string>
#include <Windows.h>


//Funcion reloj de consola
void reloj(std::string hora) {

    int digitos = hora.length();
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
    std::string dos_puntos[] = { "   ##  ", "   ##  ", "       ", "   ##  ", "   ##  " };

    while (j < 5) {
        if (hora[i] == '0') {
            std::cout << cero[j];
            i++;
        }
        if (hora[i] == '1') {
            std::cout << uno[j];
            i++;
        }
        if (hora[i] == '2') {
            std::cout << dos[j];
            i++;
        }
        if (hora[i] == '3') {
            std::cout << tres[j];
            i++;
        }
        if (hora[i] == '4') {
            std::cout << cuatro[j];
            i++;
        }
        if (hora[i] == '5') {
            std::cout << cinco[j];
            i++;
        }
        if (hora[i] == '6') {
            std::cout << seis[j];
            i++;
        }
        if (hora[i] == '7') {
            std::cout << siete[j];
            i++;
        }
        if (hora[i] == '8') {
            std::cout << ocho[j];
            i++;
        }
        if (hora[i] == '9') {
            std::cout << nueve[j];
            i++;
        }
        if (hora[i] == ':') {
            std::cout << dos_puntos[j];
            i++;
        }
        if (i == digitos) {
            std::cout << std::endl;
            j++;
            i = 0;
        }
    }
    std::cout << "\n";
    system("pause");
    system("cls");
}

int main()
{
    std::cout << "recuerda que tienes clases a las 07:00 no lo olvides, hoy es el examen final...";
    std::cout << "\n";
    std::cout << "\n";
    Sleep(2000);
    std::string hora;
    reloj(hora = "05:00");

    std::cout << "Deseas levantarte ahora? \n";
    std::cout << "1: si     2: no\n";
    int x;
    std::cin >> x;
    std::cout << "\n";
    std::cout << "\n";

    if (x == 1) {
        reloj(hora = "05:30");
        std::cout << "ya levantado de la cama todo cansado y preocupado porque don vergas no estudio nada...\n";
        reloj(hora = "06:30");
        std::cout << "bajando las escaleras te debes decidir sobre dos opciones\n";
        std::cout << "1: ir a la parada, 2: comer algo\n";
        std::cin >> x;
        std::cout << "\n";
        std::cout << "\n";
        if (x == 1) {
            reloj(hora = "07:00");
            std::cout << "ya con hambre en la parada te das cuenta que no se ve para una hora el camion\n";
            std::cout << "abriendo el telefono ves que todos siguen hablando sobre que cosa van a venir en el examen y que nadie sabe de donde estudiar algo rapido\n";
            reloj(hora = "07:30");
            std::cout << "el primer camion llega y llega con todas las personas de la universida porque neta que pedo esta a reventar, un tremendo asco pero no queda de otra\n";
            std::cout << "para tu mala suerte te quedas dormidito por culpa de no comer nada y ademas seguias bien cansado\n";
            reloj(hora = "09:00");
            std::cout << "terminas en la central camionera y viendo la hora ya todo esta perdido y aun te rugen las tripas, simplemente quedan dos opciones...\n";
            std::cout << "1: ir a la escuela desde ahi, 2: comer en la central\n";
            std::cin >> x;
            std::cout << "\n";
            std::cout << "\n";
            if (x == 1) {
                reloj(hora = "10:00");
                std::cout << "ya en la escuela te encuentras con tus compas risa y risa de eso a que llegas a donde estan\n";
                std::cout << "preguntando todo aguitado y como el pelele que eres sobre el examen te responden que ni hubo y se cambio\n";
                std::cout << "con harta hambre y entre un enojo/alivio te pones a tragar un lonche todo chafa de la ecuela mientras tus compas se burlan de tu viaje\n";
                std::cout << "worst ending\n";
            }
            if (x == 2) {
                reloj(hora = "12:00");
                std::cout << "el cadaver de un estudiante es rodeado por un grupo forence que han encontrado tacos de suaperro de 10 x 1 peso dentro del alumno\n";
                std::cout << "definitivamente su sistema inmunologico jamas fue lo suficientemente puro para poder consumir alimento divino\n";
                std::cout << "True ending\n";
            }
        }
        if (x == 2) {
            reloj(hora = "07:30");
            std::cout << "ya todo desayunado te lanzas a la parada\n";
            reloj(hora = "08:00");
            std::cout << "pero ya en la parada te das cuenta que esto va para largo y decides ponerte al corriente con todo el spam del grupo\n";
            std::cout << "enterandote que nadie sabe nada de donde esta el profe\n";
            reloj(hora = "08:30");
            std::cout << "apenas vas podiendo subirte a un camion llenito pero uno no esta para pensar en esas cosas\n";
            reloj(hora = "09:00");
            std::cout << "ya llegando a la escuela te topas a tus compas igual de sacados de onda que tu\n";
            reloj(hora = "12:30");
            std::cout << "sin darse cuenta ya paso un ratote y alch el profe bien vergas apenas manda mensaje diciendo que ni va a llegar y ya movio fecha a la siguente semana\n";
            std::cout << "por lo que replicas a tus compas con un bien merecido...\n";
            std::cout << "de aqui a donde?\n";
            std::cout << "Canon ending\n";
        }
    }

    if (x == 2) {
        reloj(hora = "07:00");
        std::cout << "Un molesto ruido de alarma sigue sonando hasta que ya no puedes estar dormido, al ver la hora tienes dos opciones\n";
        std::cout << "1: tratar de dormir de nuevo, 2: levantarse\n";
        std::cin >> x;
        std::cout << "\n";
        std::cout << "\n";
        if (x == 1) {
            reloj(hora = "11:00");
            std::cout << "Finalmente estas agusto con lo que has dormido, te sientes un poco culpable por no haber ido pero te dices a ti mismo que uno va primero\n";
            std::cout << "Tienes dos opciones\n";
            std::cout << "1: bajar a comer, 2: abrir el telefono\n";
            std::cin >> x;
            std::cout << "\n";
            std::cout << "\n";
            if (x == 1) {
                reloj(hora = "12:30");
                std::cout << "Panza llena corazon contento, ahora si agusto relajado alch pensando cuanto cuesta el extra decides abrir el telefono para ver el grupo\n";
                std::cout << "Tan solo para darte cuenta que el profe se quedo mas dormido que tu (osea nmms a quien se le ocurre dar clases a las 07:00 wakala) y ha dejado el examen para la siguente semana (sirve que de neta sube la presentacion para poder estudiar), como siempre a tilin le salen las cosas bien\n";
                std::cout << "Excelente, ya es pedo de tilin del futuro si se levanta o no para el examen\n";
                std::cout << "Best ending\n";
            }

            if (x == 2) {
                reloj(hora = "11:30");
                std::cout << "Decides tomar iniciativa y sin verguenza alguna preguntas en el grupo que pedo con el examen\n";
                std::cout << "A lo que para tu sorpresa nadie sabe nada aun del maestro\n";
                std::cout << "tienes dos opciones\n";
                std::cout << "1: ponerte a comer de una, 2: irse a cambiar\n";
                std::cin >> x;
                std::cout << "\n";
                std::cout << "\n";
                if (x == 1) {
                    reloj(hora = "12:30");
                    std::cout << "Agusto ya comido te pega la necesidad chismosa de saber si ya saben algo del profe\n";
                    std::cout << "Abriendo el grupo terminas enterandote que el profe termino crudisimo y el examen se pospone para la siguiente semana\n";
                    std::cout << "Finalmente sin preocupaciones y con una risa amarga decides dejarle el pedo a tilin del futuro\n";
                    std::cout << "Good ending\n";
                }

                if (x == 2) {
                    reloj(hora = "12:00");
                    std::cout << "ya cambiado estas algo preocupado por lo que debes elegir entre dos opciones\n";
                    std::cout << "1: ponerse a comer, 2: salir de tu casa a la parada\n";
                    std::cin >> x;
                    std::cout << "\n";
                    std::cout << "\n";
                    if (x == 1) {
                        reloj(hora = "01:00");
                        std::cout << "Todo el rato estuviste comiendo pegado un ojo al reloj y ya con suficiente tension decides abrir el telefono\n";
                        std::cout << "Ya en el grupo te enteras que el maestro simplemente no dio el examen y que se pospuso para la siguente semana\n";
                        std::cout << "finalmente puedes estar tranquilo... al menos por una semana mas\n";
                        std::cout << "Neutral ending\n";
                    }

                    if (x == 2) {
                        reloj(hora = "12:30");
                        std::cout << "ya en la parada con el corazon agitado decides ver que ha pasado abriendo el telefono\n";
                        std::cout << "para tu buena y mala sorpresa el examen nunca se hizo y ahora solo estas en la parada como pelele sin necesidad de ir el dia de hoy\n";
                        std::cout << "neutral ending\n";
                    }
                }
            }
        }

        if (x == 2) {
            reloj(hora = "07:30");
            std::cout << "Ya levantado de la cama viendo la hora estas preocupado y alterado\n";
            reloj(hora = "08:00");
            std::cout << "ya cambiado bajas corriendo abajo donde tienes dos opciones...\n";
            std::cout << "1: irse a la parada, 2: comer algo\n";
            std::cin >> x;
            std::cout << "\n";
            std::cout << "\n";
            if (x == 1) {
                reloj(hora = "08:30");
                std::cout << "ya en la parada con hambre y sin saber si ya estan haciendo el examen decides abrir el telefono\n";
                std::cout << "nadie responde el chat... pero es normal en cualquier hora eso... parece que solo queda esperar el camion o regresar a casa\n";
                std::cout << "1: esperar, 2: regresar\n";
                std::cin >> x;
                std::cout << "\n";
                std::cout << "\n";
                if (x == 1) {
                    reloj(hora = "09:00");
                    std::cout << "Finalmente un camion abarrotado y aun asi de forma milagrosa un asiento para ti... pero al estar tan hambriado te quedaste dormido en el camion\n";
                    reloj(hora = "10:30");
                    std::cout << "Para tu mala suerte el camion te ha despertado en la central... ahora tendras que esperar otro camion para poder regresar y peor aun nadie te ha nada en el grupo\n";
                    reloj(hora = "12:30");
                    std::cout << "Ya para esta hora recibes mensajes del grupo etiquetandote como todo un pelele y el maximo tilin porque ni hubo examen y ademas estas re wey por estar hasta la central camionera jajajaja\n";
                    std::cout << "esto es una historia que no te dejaran olvidar por un buen tiempo xd\n";
                    std::cout << "bad ending\n";
                }

                if (x == 2) {
                    reloj(hora = "09:30");
                    std::cout << "Ya de regreso a tu casa todo enojado por el inutil camion y con hambre te pones a comer algo bien hecho sin que te importe lo demas...\n";
                    reloj(hora = "12:30");
                    std::cout << "sin duda una buena comida, te rifaste y ya mas tranquilo te pones a revisar el grupo...\n";
                    std::cout << "resulta que el profe jamas llego y el examen se pospuso\n";
                    std::cout << "al menos no estabas esperando el camion como si fueras su gato y te diste la buena vida con este desayuno\n";
                    std::cout << "neutral ending\n";
                }
            }

            if (x == 2) {
                reloj(hora = "09:00");
                std::cout << "ya comido ahora te vas a la parada con la insertidumbre de lo que espera en la escuela...\n";
                reloj(hora = "09:30");
                std::cout << "llegando a la parada ves que de ningun lado se ve un camion y aun nadie responde en el chat... \n";
                reloj(hora = "10:00");
                std::cout << "finalmente llega un camion, ya por la hora esta hasta eso vacio\n";
                reloj(hora = "11:00");
                std::cout << "llegando a la escuela fingiendo que no te come la ansiedad por saber que ocurrio te encuentras con tus compas que igual de sacados de onda dicen que el profe jamas llego\n";
                reloj(hora = "12:30");
                std::cout << "finalmente despues de un rato de estar perdiendo el tiempo con los compas llega un mensaje diciendo que el exmen sera la proxima semana\n";
                std::cout << "por lo que como buen tilin preguntas a tus compas de aqui a donde?\n";
                std::cout << "neutral ending\n";
            }
        }
    }
    Sleep(5000);
}