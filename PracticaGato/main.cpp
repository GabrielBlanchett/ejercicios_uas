// ... (incluir las funciones anteriores: inicializarTablero, mostrarTablero, realizarJugada, cambiarJugador) ...

/**
 * @brief Verifica si el jugador actual ha ganado.
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


int main() {
    bool juegoTerminado = false;
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

    return 0;
}
