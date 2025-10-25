# Proyecto: Tic Tac Toe (Gato) en C++

Este proyecto es una implementación del clásico juego "Tic Tac Toe" (también conocido como Gato, 3 en raya, o Ta-Te-Ti) desarrollado como una aplicación de consola en C++.

## Descripción del Programa

El programa implementa la lógica completa del juego para dos jugadores humanos. Utiliza una matriz de caracteres (char) de 3x3 para representar el tablero. El juego maneja los turnos de los jugadores 'X' y 'O', valida las entradas del usuario y detecta automáticamente cuándo un jugador ha ganado o cuándo la partida termina en empate.

El código está modularizado en funciones para mejorar la legibilidad y el mantenimiento, separando la lógica de inicialización, visualización, entrada de datos y verificación de estado.

### Características

* **Juego de 2 Jugadores:** Permite a dos jugadores (X y O) competir.
* **Tablero Interactivo:** Muestra el tablero en la consola, el cual se actualiza después de cada jugada.
* **Detección de Ganador:** Comprueba filas, columnas y diagonales para declarar un ganador.
* **Detección de Empate:** Identifica si el tablero está lleno sin un ganador.
* **Validación de Entradas:** Asegura que los jugadores solo puedan elegir casillas válidas (números del 1 al 9) que no estén ya ocupadas.
* **Menú Principal:** Incluye un menú para iniciar una nueva partida o salir del juego.
* **Opción de Reinicio:** Al finalizar una partida, permite a los usuarios volver al menú principal para jugar de nuevo.

## Instrucciones de Uso

### Requisitos

* Un compilador de C++ (como g++ o MinGW).
* (Opcional) Un IDE como Code::Blocks.

### Compilación y Ejecución (usando Code::Blocks)

1.  Abre Code::Blocks.
2.  Ve a `File > New > Project...`.
3.  Selecciona `Console application` y haz clic en `Go`.
4.  Elige el lenguaje `C++`.
5.  Asigna un título a tu proyecto (ej. `TicTacToe`) y elige una ubicación.
6.  En el panel izquierdo "Management", expande tu proyecto, expande la carpeta `Sources`, y haz doble clic en `main.cpp`.
7.  Borra el contenido por defecto y pega el código C++ proporcionado en este proyecto.
8.  Haz clic en el ícono "Build and run" (el engrane con el triángulo verde) o presiona `F9`.

### Cómo Jugar

1.  Al ejecutar el programa, verás un menú principal.
2.  Escribe `1` y presiona `Enter` para comenzar una nueva partida.
3.  El Jugador 'X' comienza primero.
4.  El tablero se mostrará con números del 1 al 9, representando las casillas.
5.  Cuando sea tu turno, escribe el número de la casilla donde deseas jugar y presiona `Enter`.
6.  Si la jugada es inválida (la casilla está ocupada o el número está fuera de rango), el programa te pedirá que intentes de nuevo.
7.  El juego continuará hasta que un jugador gane (conectando 3 de sus marcas) o hasta que el tablero esté lleno (empate).
8.  Al final de la partida, el programa anunciará el resultado.
9.  Presiona `Enter` para volver al menú principal.
10. Desde el menú, puedes elegir `1` para jugar otra vez o `2` para salir del programa.
