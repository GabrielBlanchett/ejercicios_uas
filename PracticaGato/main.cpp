#include <iostream>
#include <stdlib.h> // Para system("cls") o system("clear")

using namespace std;

// --- Variables Globales ---
char tablero[3][3];     // Matriz que representa el tablero
char jugadorActual;     // Almacena el turno actual ('X' o 'O')

// --- Prototipos de Funciones ---
void inicializarTablero();
void mostrarTablero();
void realizarJugada();
bool verificarGanador();
bool verificarEmpate();
void cambiarJugador();
void jugarPartida();

/**
 * @brief Inicializa el tablero con números del 1 al 9.
 * Se llama al inicio de cada nueva partida.
 */
void inicializarTablero() {
    char contador = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = contador;
            contador++;
        }
    }
}

/**
 * @brief Dibuja el estado actual del tablero en la consola.
 */
void mostrarTablero() {
    // Limpia la consola (cls en Windows, clear en Linux/macOS)
    system("cls");

    cout << "===== TIC TAC TOE =====" << endl << endl;

    for (int i = 0; i < 3; i++) {
        cout << "     |     |     " << endl;
        cout << "  " << tablero[i][0] << "  |  " << tablero[i][1] << "  |  " << tablero[i][2] << "  " << endl;
        cout << "     |     |     " << endl;
        if (i < 2) {
            cout << "-----------------" << endl;
        }
    }
    cout << endl << "=====================" << endl;
}

/**
 * @brief Pide al jugador actual que ingrese su jugada.
 * Valida que la entrada sea un número (1-9) y que
 * la casilla seleccionada esté disponible.
 */
void realizarJugada() {
    char eleccion;
    bool jugadaValida = false;

    while (!jugadaValida) {
        cout << "Turno del Jugador " << jugadorActual << ". Elige una casilla (1-9): ";
        cin >> eleccion;

        // Validación 1: ¿Es un número entre 1 y 9?
        if (eleccion < '1' || eleccion > '9') {
            cout << "Entrada invalida. Debes ingresar un numero del 1 al 9." << endl;
            continue; // Vuelve a pedir
        }

        // Búsqueda de la casilla
        bool casillaEncontrada = false;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tablero[i][j] == eleccion) {
                    // Validación 2: Casilla encontrada y disponible
                    tablero[i][j] = jugadorActual;
                    jugadaValida = true;
                    casillaEncontrada = true;
                    break;
                }
            }
            if (casillaEncontrada) break;
        }

        // Validación 3: Casilla ya ocupada
        if (!casillaEncontrada && jugadaValida == false) {
            cout << "Casilla invalida o ya ocupada. Intenta de nuevo." << endl;
        }
    }
}

/**
 * @brief Verifica si el jugador actual ha ganado la partida.
 * @return true si el jugador actual ganó, false en caso contrario.
 */
bool verificarGanador() {
    // Verificar filas
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == jugadorActual && tablero[i][1] == jugadorActual && tablero[i][2] == jugadorActual) {
            return true;
        }
    }

    // Verificar columnas
    for (int j = 0; j < 3; j++) {
        if (tablero[0][j] == jugadorActual && tablero[1][j] == jugadorActual && tablero[2][j] == jugadorActual) {
            return true;
        }
    }

    // Verificar diagonales
    if (tablero[0][0] == jugadorActual && tablero[1][1] == jugadorActual && tablero[2][2] == jugadorActual) {
        return true;
    }
    if (tablero[0][2] == jugadorActual && tablero[1][1] == jugadorActual && tablero[2][0] == jugadorActual) {
        return true;
    }

    return false;
}

/**
 * @brief Verifica si el juego ha terminado en empate (tablero lleno).
 * @return true si es empate, false en caso contrario.
 */
bool verificarEmpate() {
    // Si no hay ganador, revisamos si el tablero está lleno
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Si encuentra una casilla que NO sea X o O, el juego sigue
            if (tablero[i][j] != 'X' && tablero[i][j] != 'O') {
                return false;
            }
        }
    }
    // Si salimos del bucle, el tablero está lleno
    return true;
}

/**
 * @brief Cambia el turno al otro jugador.
 */
void cambiarJugador() {
    if (jugadorActual == 'X') {
        jugadorActual = 'O';
    } else {
        jugadorActual = 'X';
    }
}

/**
 * @brief Contiene toda la lógica para ejecutar una partida completa.
 * Maneja el bucle de la partida hasta que haya un ganador o empate.
 */
void jugarPartida() {
    bool juegoTerminado = false;
    jugadorActual = 'X'; // 'X' siempre empieza
    inicializarTablero();

    while (!juegoTerminado) {
        mostrarTablero();
        realizarJugada();

        if (verificarGanador()) {
            juegoTerminado = true;
            mostrarTablero(); // Muestra el tablero final
            cout << "¡Felicidades! El Jugador " << jugadorActual << " ha ganado." << endl;
        } else if (verificarEmpate()) {
            juegoTerminado = true;
            mostrarTablero(); // Muestra el tablero final
            cout << "¡Es un empate!" << endl;
        } else {
            // Si nadie ha ganado y no hay empate, cambiamos de jugador
            cambiarJugador();
        }
    }
}

/**
 * @brief Función principal (main).
 * Muestra el menú principal y permite al usuario
 * jugar o salir del programa.
 */
int main() {
    char opcion;

    do {
        system("cls");
        cout << "===== BIENVENIDO A TIC TAC TOE =====" << endl;
        cout << "1. Jugar Partida" << endl;
        cout << "2. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        if (opcion == '1') {
            jugarPartida();
            cout << "\nPresiona Enter para continuar...";
            cin.ignore(); // Limpia el buffer de entrada (importante despues de un cin)
            cin.get();    // Espera a que el usuario presione Enter
        }

    } while (opcion != '2');

    cout << "Gracias por jugar. ¡Adios!" << endl;

    return 0;
}
