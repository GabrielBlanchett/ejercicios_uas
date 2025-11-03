/*
 * conecta4.cpp
 * Segmento 4: Bucle de Revancha (Código Final)
 */

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cctype> // Para std::tolower

// --- Constantes del Juego ---
const int FILAS = 6;
const int COLUMNAS = 7;
const char JUGADOR_X = 'X';
const char JUGADOR_O = 'O';
const char CELDA_VACIA = '.';

// Definición del tipo 'Tablero' para más claridad
using Tablero = std::vector<std::vector<char>>;

// --- Prototipos de Funciones ---
void inicializarTablero(Tablero& tablero);
void imprimirTablero(const Tablero& tablero);
bool soltarFicha(Tablero& tablero, int col, char jugador, int& fila_colocada);
bool esColumnaLlena(const Tablero& tablero, int col);
int obtenerMovimientoValido(const Tablero& tablero, char jugador);
bool verificarVictoria(const Tablero& tablero, char jugador, int f, int c);

/**
 * @brief Función Principal
 */
int main() {
    char jugarDeNuevo;

    std::cout << "¡Bienvenido a Conecta 4!" << std::endl;

    do {
        // --- Reiniciar variables para un nuevo juego ---
        Tablero tablero(FILAS, std::vector<char>(COLUMNAS));
        inicializarTablero(tablero);

        char jugadorActual = JUGADOR_X;
        bool juegoEnCurso = true;
        int movimientos = 0;

        // --- Bucle principal del juego (como en Segmento 3) ---
        while (juegoEnCurso) {
            // 1. Mostrar tablero
            imprimirTablero(tablero);

            // 2. Pedir jugada
            int col = obtenerMovimientoValido(tablero, jugadorActual);

            // 3. Colocar ficha
            int fila;
            soltarFicha(tablero, col, jugadorActual, fila);
            movimientos++;

            // 4. Verificar si hay ganador
            if (verificarVictoria(tablero, jugadorActual, fila, col)) {
                imprimirTablero(tablero);
                std::cout << "¡¡¡FELICIDADES JUGADOR " << jugadorActual << " GANA!!!" << std::endl;
                juegoEnCurso = false;
                continue;
            }

            // 5. Verificar si hay empate
            if (movimientos == FILAS * COLUMNAS) {
                imprimirTablero(tablero);
                std::cout << "¡¡¡JUEGO TERMINADO!!! Es un EMPATE." << std::endl;
                juegoEnCurso = false;
                continue;
            }

            // 6. Cambiar de jugador
            jugadorActual = (jugadorActual == JUGADOR_X) ? JUGADOR_O : JUGADOR_X;
        }

        // --- Preguntar por revancha ---
        std::cout << "\n¿Quieren jugar de nuevo? (s/n): ";
        std::cin >> jugarDeNuevo;
        // Limpiar buffer por si escriben más de un carácter
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (std::tolower(jugarDeNuevo) == 's');

    std::cout << "\n¡Gracias por jugar! Adios.\n";

    return 0;
}

/**
 * @brief Llena el tablero con celdas vacías ('.')
 */
void inicializarTablero(Tablero& tablero) {
    for (int f = 0; f < FILAS; ++f) {
        for (int c = 0; c < COLUMNAS; ++c) {
            tablero[f][c] = CELDA_VACIA;
        }
    }
}

/**
 * @brief Imprime el estado actual del tablero en la consola.
 */
void imprimirTablero(const Tablero& tablero) {
    std::cout << "\n  1   2   3   4   5   6   7\n";
    std::cout << "-----------------------------\n";
    for (int f = 0; f < FILAS; ++f) {
        std::cout << "| ";
        for (int c = 0; c < COLUMNAS; ++c) {
            std::cout << tablero[f][c] << " | ";
        }
        std::cout << "\n";
    }
    std::cout << "-----------------------------\n\n";
}

/**
 * @brief Comprueba si una columna específica está llena.
 */
bool esColumnaLlena(const Tablero& tablero, int col) {
    return tablero[0][col] != CELDA_VACIA;
}

/**
 * @brief Coloca la ficha de un jugador en la columna especificada.
 */
bool soltarFicha(Tablero& tablero, int col, char jugador, int& fila_colocada) {
    for (int f = FILAS - 1; f >= 0; --f) {
        if (tablero[f][col] == CELDA_VACIA) {
            tablero[f][col] = jugador;
            fila_colocada = f;
            return true;
        }
    }
    return false;
}

/**
 * @brief Pide al jugador una columna y valida la entrada.
 */
int obtenerMovimientoValido(const Tablero& tablero, char jugador) {
    int col;
    while (true) {
        std::cout << "Jugador " << jugador << ", elija columna (1-7): ";

        if (!(std::cin >> col)) {
            std::cout << "Entrada invalida. Por favor ingrese un numero.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        col--;

        if (col < 0 || col >= COLUMNAS) {
            std::cout << "Numero fuera de rango. Debe ser entre 1 y 7.\n";
            continue;
        }

        if (esColumnaLlena(tablero, col)) {
            std::cout << "Esa columna esta llena. Elija otra.\n";
            continue;
        }

        break;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return col;
}

/**
 * @brief Comprueba si el último movimiento (f, c) resultó en una victoria.
 */
bool verificarVictoria(const Tablero& tablero, char jugador, int f, int c) {
    int contador;

    // 1. Comprobar Vertical
    contador = 0;
    for (int i = f; i < FILAS; ++i) {
        if (tablero[i][c] == jugador) contador++;
        else break;
    }
    if (contador >= 4) return true;

    // 2. Comprobar Horizontal
    contador = 0;
    for (int i = 0; i < COLUMNAS; ++i) {
        if (tablero[f][i] == jugador) {
            contador++;
            if (contador >= 4) return true;
        } else {
            contador = 0;
        }
    }

    // 3. Comprobar Diagonal Descendente (↘)
    contador = 0;
    int tempF = f, tempC = c;
    while (tempF > 0 && tempC > 0) { tempF--; tempC--; }
    while (tempF < FILAS && tempC < COLUMNAS) {
        if (tablero[tempF][tempC] == jugador) {
            contador++;
            if (contador >= 4) return true;
        } else {
            contador = 0;
        }
        tempF++;
        tempC++;
    }

    // 4. Comprobar Diagonal Ascendente (↗)
    contador = 0;
    tempF = f, tempC = c;
    while (tempF < FILAS - 1 && tempC > 0) { tempF++; tempC--; }
    while (tempF >= 0 && tempC < COLUMNAS) {
        if (tablero[tempF][tempC] == jugador) {
            contador++;
            if (contador >= 4) return true;
        } else {
            contador = 0;
        }
        tempF--;
        tempC++;
    }

    return false;
}
