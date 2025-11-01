/*
 * conecta4.cpp
 * Segmento 1: Estructura Básica y Tablero
 */

#include <iostream>
#include <vector>
#include <string>

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

/**
 * @brief Función Principal
 */
int main() {
    // 1. Crear el tablero
    Tablero tablero(FILAS, std::vector<char>(COLUMNAS));

    // 2. Inicializar el tablero
    inicializarTablero(tablero);

    // 3. Mostrar el tablero inicial
    std::cout << "¡Bienvenido a Conecta 4!" << std::endl;
    imprimirTablero(tablero);

    return 0;
}

/**
 * @brief Llena el tablero con celdas vacías ('.')
 * @param tablero El tablero de juego (pasado por referencia)
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
 * @param tablero El tablero de juego (pasado por const-referencia)
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
