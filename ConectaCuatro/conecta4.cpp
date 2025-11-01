/*
 * conecta4.cpp
 * Segmento 2: Bucle Principal, Lógica de Turnos y Validación de Entrada
 */

#include <iostream>
#include <vector>
#include <string>
#include <limits> // Necesario para la validación de entrada

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

/**
 * @brief Función Principal
 */
int main() {
    Tablero tablero(FILAS, std::vector<char>(COLUMNAS));
    inicializarTablero(tablero);

    char jugadorActual = JUGADOR_X;
    bool juegoEnCurso = true;

    std::cout << "¡Bienvenido a Conecta 4!" << std::endl;

    while (juegoEnCurso) {
        // 1. Mostrar tablero
        imprimirTablero(tablero);

        // 2. Pedir jugada (Ahora usa la función de validación)
        int col = obtenerMovimientoValido(tablero, jugadorActual);

        // 3. Colocar ficha
        int fila_colocada; // Para guardar dónde cayó la ficha (necesario para Segmento 3)
        soltarFicha(tablero, col, jugadorActual, fila_colocada);

        // (Aquí irá la lógica de ganar/empate en el próximo segmento)

        // 4. Cambiar de jugador
        jugadorActual = (jugadorActual == JUGADOR_X) ? JUGADOR_O : JUGADOR_X;

        // Por ahora, terminamos el juego después de un turno para probar
        // Elimina esta línea en el siguiente segmento:
        // juegoEnCurso = false;
    }

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
 * @param tablero El tablero de juego.
 * @param col La columna a comprobar (0-based).
 * @return true si la columna está llena, false en caso contrario.
 */
bool esColumnaLlena(const Tablero& tablero, int col) {
    // Solo necesita comprobar la celda superior (fila 0)
    return tablero[0][col] != CELDA_VACIA;
}

/**
 * @brief Coloca la ficha de un jugador en la columna especificada.
 * La ficha "cae" a la posición más baja disponible.
 * @param tablero El tablero de juego (por referencia).
 * @param col La columna elegida (0-based).
 * @param jugador El símbolo del jugador (X ó O).
 * @param fila_colocada (Salida) Guarda la fila donde la ficha aterrizó.
 * @return true si se pudo colocar, false si la columna estaba llena.
 */
bool soltarFicha(Tablero& tablero, int col, char jugador, int& fila_colocada) {
    // Itera de abajo hacia arriba
    for (int f = FILAS - 1; f >= 0; --f) {
        if (tablero[f][col] == CELDA_VACIA) {
            tablero[f][col] = jugador;
            fila_colocada = f; // Guarda la fila donde se colocó
            return true;
        }
    }
    return false; // No debería pasar si esColumnaLlena se usa primero
}

/**
 * @brief Pide al jugador una columna y valida la entrada.
 * Repite hasta que la entrada sea un número válido (1-7)
 * y la columna no esté llena.
 * @param tablero El tablero de juego (para comprobar si está llena).
 * @param jugador El jugador actual (para el mensaje).
 * @return El índice de la columna (0-based) válido.
 */
int obtenerMovimientoValido(const Tablero& tablero, char jugador) {
    int col;
    while (true) {
        std::cout << "Jugador " << jugador << ", elija columna (1-7): ";

        // Comprobar si la entrada es un número
        if (!(std::cin >> col)) {
            std::cout << "Entrada invalida. Por favor ingrese un numero.\n";
            std::cin.clear(); // Limpia el estado de error de cin
            // Descarta la entrada incorrecta del buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // Ajustar a índice 0-based
        col--;

        // Comprobar rango
        if (col < 0 || col >= COLUMNAS) {
            std::cout << "Numero fuera de rango. Debe ser entre 1 y 7.\n";
            continue;
        }

        // Comprobar si está llena
        if (esColumnaLlena(tablero, col)) {
            std::cout << "Esa columna esta llena. Elija otra.\n";
            continue;
        }

        // Si todo es válido, salir del bucle
        break;
    }

    // Limpiar cualquier carácter extra (como un 'Enter')
    // para futuras lecturas (ej. 'jugar de nuevo')
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return col;
}
