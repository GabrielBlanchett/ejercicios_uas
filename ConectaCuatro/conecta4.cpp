/*
 * conecta4.cpp
 * Segmento 3: Detección de Victoria y Empate
 */

#include <iostream>
#include <vector>
#include <string>
#include <limits>

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
bool verificarVictoria(const Tablero& tablero, char jugador, int f, int c); // Nueva función

/**
 * @brief Función Principal
 */
int main() {
    Tablero tablero(FILAS, std::vector<char>(COLUMNAS));
    inicializarTablero(tablero);

    char jugadorActual = JUGADOR_X;
    bool juegoEnCurso = true;
    int movimientos = 0; // Nuevo contador de movimientos

    std::cout << "¡Bienvenido a Conecta 4!" << std::endl;

    while (juegoEnCurso) {
        // 1. Mostrar tablero
        imprimirTablero(tablero);

        // 2. Pedir jugada
        int col = obtenerMovimientoValido(tablero, jugadorActual);

        // 3. Colocar ficha
        int fila;
        soltarFicha(tablero, col, jugadorActual, fila);
        movimientos++; // Incrementar contador de movimientos

        // 4. Verificar si hay ganador
        if (verificarVictoria(tablero, jugadorActual, fila, col)) {
            imprimirTablero(tablero); // Mostrar el tablero ganador
            std::cout << "¡¡¡FELICIDADES JUGADOR " << jugadorActual << " GANA!!!" << std::endl;
            juegoEnCurso = false;
            continue; // Salta al final del bucle
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
 * @param tablero El tablero de juego.
 * @param jugador El jugador que acaba de mover.
 * @param f La fila de la última ficha.
 * @param c La columna de la última ficha.
 * @return true si el jugador ha ganado, false en caso contrario.
 */
bool verificarVictoria(const Tablero& tablero, char jugador, int f, int c) {
    int contador;

    // 1. Comprobar Vertical (Solo hacia abajo, ya que la ficha cae)
    contador = 0;
    // Solo necesitamos contar 4 hacia abajo desde la ficha actual (f, c)
    // No puede haber 4 en raya vertical *hacia arriba* de la ficha que acaba de caer.
    for (int i = f; i < FILAS; ++i) {
        if (tablero[i][c] == jugador) {
            contador++;
        } else {
            break; // No son consecutivas
        }
    }
    if (contador >= 4) return true;

    // 2. Comprobar Horizontal
    contador = 0;
    for (int i = 0; i < COLUMNAS; ++i) {
        if (tablero[f][i] == jugador) {
            contador++;
            if (contador >= 4) return true;
        } else {
            contador = 0; // Reiniciar contador si se rompe la secuencia
        }
    }

    // 3. Comprobar Diagonal Descendente (↘)
    contador = 0;
    // Ir al inicio de esta diagonal (arriba-izquierda)
    int tempF = f;
    int tempC = c;
    while (tempF > 0 && tempC > 0) {
        tempF--;
        tempC--;
    }
    // Recorrer la diagonal hacia abajo-derecha
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
    // Ir al inicio de esta diagonal (abajo-izquierda)
    tempF = f;
    tempC = c;
    while (tempF < FILAS - 1 && tempC > 0) {
        tempF++;
        tempC--;
    }
    // Recorrer la diagonal hacia arriba-derecha
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

    return false; // No se encontró ninguna victoria
}
