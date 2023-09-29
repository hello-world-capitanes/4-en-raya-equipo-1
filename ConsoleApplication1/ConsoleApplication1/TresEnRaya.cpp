#include <iostream>
#include <string.h>
#include "TresEnRaya.h"

void inicializarTablero() {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            tablero[i][j] = ' ';
        }
    }
}

void mostrarTablero() {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "| " << tablero[i][j] << " ";
        }
        cout << "|" << endl;
    }
}

bool validarMovimiento(int fila, int col) {
    if (fila < 0 || fila >= filas || col < 0 || col >= columnas) {
        cout << "Posición no válida. 0-5 fila, 0-6 columna" << endl;
        return false;
    }
    if (tablero[fila][col] != ' ') {
        cout << "Casilla ocupada." << endl;
        return false;
    }
    return true;
}

bool verificarGanador(char jugador) {
    // Horizontal
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j <= columnas - 4; j++) { //El -4 es para que no intente a acceder a elementos que no existen y se valide el minion de 4 en raya
            if (tablero[i][j] == jugador && tablero[i][j + 1] == jugador && tablero[i][j + 2] == jugador && tablero[i][j + 3] == jugador)
                return true;
        }
    }

    // Vertical
    for (int i = 0; i <= filas - 4; i++) { //Igual que antes pero con filas
        for (int j = 0; j < columnas; j++) {
            if (tablero[i][j] == jugador && tablero[i + 1][j] == jugador && tablero[i + 2][j] == jugador && tablero[i + 3][j] == jugador)
                return true;
        }
    }

    // Diagonal izq der
    for (int i = 0; i <= filas - 4; i++) { //Lo mismo pero doble xq es diagonal
        for (int j = 0; j <= columnas - 4; j++) {
            if (tablero[i][j] == jugador && tablero[i + 1][j + 1] == jugador && tablero[i + 2][j + 2] == jugador && tablero[i + 3][j + 3] == jugador)
                return true;
        }
    }

    // Diagonal der izq
    for (int i = 0; i <= filas - 4; i++) {
        for (int j = 3; j < columnas; j++) { //Aqui no se hace xq empiexo en 3 y se desplaza en --
            if (tablero[i][j] == jugador && tablero[i + 1][j - 1] == jugador && tablero[i + 2][j - 2] == jugador && tablero[i + 3][j - 3] == jugador)
                return true;
        }
    }
    return false;
}

bool tableroLleno() {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (tablero[i][j] == ' ')
                return false;
        }
    }
    return true;
}