#include <iostream>
#include <stdlib.h> // Para system("cls") o system("clear")

using namespace std;

// Matriz global para el tablero
char tablero[3][3];

/**
 * @brief Inicializa el tablero con números del 1 al 9.
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
 * @brief Dibuja el tablero de juego en la consola.
 */
void mostrarTablero() {
    // Limpia la consola (funciona en Windows)
    // Usa system("clear") en Linux/macOS
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

int main() {
    cout << "Iniciando el juego..." << endl;
    inicializarTablero();
    mostrarTablero();

    // Pausa para ver el tablero inicial
    cin.get();

    return 0;
}
