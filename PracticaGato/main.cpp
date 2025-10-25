#include <iostream>
#include <stdlib.h>

using namespace std;

char tablero[3][3];
char jugadorActual = 'X'; // 'X' siempre empieza

void inicializarTablero() {
    char contador = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = contador;
            contador++;
        }
    }
}

void mostrarTablero() {
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
 */
void realizarJugada() {
    char eleccion;
    cout << "Turno del Jugador " << jugadorActual << ". Elige una casilla (1-9): ";
    cin >> eleccion;

    // Lógica simple para encontrar la casilla (se mejorará en el Segmento 4)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] == eleccion) {
                tablero[i][j] = jugadorActual;
                return; // Jugada realizada
            }
        }
    }
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

int main() {
    bool juegoTerminado = false;

    inicializarTablero();

    // Bucle principal del juego
    while (!juegoTerminado) {
        mostrarTablero();
        realizarJugada();
        // Por ahora, solo jugamos 9 turnos
        // En el siguiente segmento añadiremos la lógica de ganador

        cambiarJugador();

        // Lógica temporal para terminar
        // static int turnos = 0;
        // turnos++;
        // if (turnos == 9) juegoTerminado = true;
    }

    mostrarTablero();
    cout << "Fin del juego." << endl;

    return 0;
}
