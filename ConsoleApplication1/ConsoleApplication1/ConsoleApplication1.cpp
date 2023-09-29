#include <iostream>
#include <string.h>
#include "TresEnRaya.h"

using namespace std;
//----------------------------------------------------------------------------------------------------------------------------------
const int filas = 6;
const int columnas = 7;

char tablero[filas][columnas];

int main() {
    char jugadorActual = 'X';
    bool juegoTerminado = false;

    inicializarTablero();

    while (!juegoTerminado) {
        mostrarTablero();

        int fila, col;
        cout << "Turno del jugador " << jugadorActual << endl;
        cout << "Pon la fila (0-5) y la columna (0-6): ";
        cin >> fila >> col;

        if (validarMovimiento(fila, col)) {
            tablero[fila][col] = jugadorActual;

            if (verificarGanador(jugadorActual)) {
                mostrarTablero();
                cout << "Ha ganado: " << jugadorActual << endl;
                juegoTerminado = true;
            }
            else if (tableroLleno()) {
                mostrarTablero();
                cout << "Empate" << endl;
                juegoTerminado = true;
            }
            if (jugadorActual == 'X') {
                jugadorActual = 'O';
            }
            else {
                jugadorActual = 'X';
            }
        }
    }
    return 0;
}
//----------------------------------------------------------------------------------------------------------------------------------

/*void merge(int vector[], int i0, int k, int iN) {
    int n1 = k - i0 + 1;
    int n2 = iN - k;

    int* vector1 = new int[n1];
    int* vector2 = new int[n2];

    for (int i = 0; i < n1; i++) {
        vector1[i] = vector[i0 + i];
    }

    for (int j = 0; j < n2; j++) {
        vector2[j] = vector[k + 1 + j];
    }

    int i = 0, j = 0, k_merge = i0;

    while (i < n1 && j < n2) {
        if (vector1[i] <= vector2[j]) {
            vector[k_merge] = vector1[i];
            i++;
        }
        else {
            vector[k_merge] = vector2[j];
            j++;
        }
        k_merge++;
    }

    while (i < n1) {
        vector[k_merge] = vector1[i];
        i++;
        k_merge++;
    }

    while (j < n2) {
        vector[k_merge] = vector2[j];
        j++;
        k_merge++;
    }

    delete[] vector1;
    delete[] vector2;
}


void mergeSort(int vector[], int i0, int iN) {
    if (i0 < iN) {
        int k = i0 + (iN - i0) / 2;

        mergeSort(vector, i0, k);
        mergeSort(vector, k + 1, iN);

        merge(vector, i0, k, iN);
    }
}

int main() {
    int vector[] = { 1, 5, 3, 18, 6, 34, 3, 2, 9, 0 };
    int tamanio = sizeof(vector) / sizeof(vector[0]);

    for (int i = 0; i < tamanio; i++) {
        cout << vector[i] << " ";
    }
    cout << endl;

    mergeSort(vector, 0, tamanio - 1);

    for (int i = 0; i < tamanio; i++) {
        cout << vector[i] << " ";
    }
    cout << endl;

    return 0;
}*/
//----------------------------------------------------------------------------------------------------------------------------------
/*
const int inicio = 2;
const int fin = 10;
const int length = fin - inicio + 1;

int main() {
    string texto = "Hey muy buenas a todos guapisimos";
    cout << texto << endl;

    char textoCortado[length + 1];
    if (inicio >= 0 && fin >= 0 && inicio <= fin && fin < texto.length()) {
        int j = 0;
        for (int i = inicio; i <= fin; i++) {
            textoCortado[j++] = texto[i];
        }

        textoCortado[length] = '\0';

        cout << "Texto nuevo: " << textoCortado << endl;
    }

    return 0;
}*/
//--------------------------------------------------------------------------------------------------------
/*struct Usuario {
    string nombre;
    string apellido;
    
    string tlf;
};

void mostrarMenu() {
    cout << "-------------------------------------------" << endl;
    cout << "Pulsa 1 para ver los usuarios" << endl;
    cout << "Pulsa 2 para insertar un nuevo usuario" << endl;
    cout << "Pulsa 3 para eliminar un usuario" << endl;
    cout << "Pulsa 4 para buscar un usario" << endl;
    cout << "Pulsa 0 para salir" << endl;
    cout << "-------------------------------------------" << endl;
}

void CrearUsuario(Usuario lista[], int &tamanio, Usuario usr) {
    string nombre, apellido, tlf;
    cout << "Has seleccionado la opcion de insertar un usuario" << endl;
    if (tamanio < 100) {
        cout << "Introduce su nombre" << endl;
        cin >> nombre;
        cout << "Introduce su primer apellido" << endl;
        cin >> apellido;
        cout << "Introduce su telefono (+AAXXXXXXXXX)" << endl;
        cin >> tlf;

        usr.nombre = nombre;
        usr.apellido = apellido;
        usr.tlf = tlf;

        cout << "El usuario introducido es : " << usr.nombre << " " << usr.apellido << " " << usr.tlf << endl;
        lista[tamanio] = usr;
        tamanio++;  
    }
    else {
        cout << "La lista esta completa, no puedes insertar a nadie mas" << endl;
    }
}

void mostrarLista(Usuario lista[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        std::cout << lista[i].nombre << " " << lista[i].apellido << ", " << lista[i].tlf << std::endl;
    }
}

int buscarUsuario(Usuario lista[], int tamanio) {
    string nombreOtlf;
    int selector = -1;
    do {
        cout << "Has seleccionado la opcion de buscar un usuario, pulsa 1 si quieres buscarlo por nombre o 0 por telefono" << endl;
        cin >> selector;
    }
    while (selector < 0 || selector > 1);

    mostrarLista(lista, tamanio);

    if (selector == 1) {
        for (int i = 0; i < tamanio; i++) {
            if (lista[i].nombre == nombreOtlf) {
                return i;
            }
        }
    }
    else {
        for (int i = 0; i < tamanio; i++) {
            if (lista[i].tlf == nombreOtlf) {
                return i;
            }
        }
    }
    return -1; // No se encontró el nombre
}

void mostrarUsuarioBuscado(Usuario lista[], int pos) {
    cout << lista[pos].nombre << " " << lista[pos].apellido << ", " << lista[pos].tlf << endl;
}

void eliminarUsuario(Usuario lista[], int &tamanio) {
    int indiceAEliminar = -1; // Inicializar el índice a -1 (no encontrado)

    cout << "Has seleccionado la opcion de eliminar un usuario" << endl;

    
    indiceAEliminar = buscarUsuario(lista, tamanio);

    if (indiceAEliminar != -1) {
        for (int i = indiceAEliminar; i < tamanio - 1; i++) {
            lista[i] = lista[i + 1];
        }
        tamanio--;
        cout << "Persona eliminada" << endl;
    }
}

int main() {
    Usuario lista[100];
    Usuario usr;
    int tamanio = 0;
    int opcion;
    do {
        do {
            mostrarMenu();
            cin >> opcion;
        } while (opcion < 0 || opcion > 4);

        switch (opcion) {
        case 1:
            mostrarLista(lista, tamanio);
            break;
        case 2:
            CrearUsuario(lista, tamanio, usr);
            break;
        case 3:
            eliminarUsuario(lista, tamanio);
            break;
        case 4:
            buscarUsuario(lista, tamanio);
            break;
        case 0:
            exit;
            break;
        }
    } while (opcion != 0);
    return 0;
}*/


