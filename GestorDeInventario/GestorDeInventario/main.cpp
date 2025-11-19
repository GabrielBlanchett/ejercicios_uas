#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept> // Para excepciones

using namespace std;

struct Producto {
    int id;
    string nombre;
    double precio;
    int cantidad;
};

// --- PROTOTIPOS ---
void mostrarMenu();
void mostrarInventario(Producto inventario[], int total);
void buscarProducto(Producto inventario[], int total);
void ordenarPorPrecio(Producto inventario[], int total);

int main() {
    const int MAX_PRODUCTOS = 10;
    Producto inventario[MAX_PRODUCTOS] = {
        {101, "Teclado USB", 250.50, 15},
        {102, "Mouse Optico", 120.00, 30},
        {103, "Monitor 24in", 3500.00, 5},
        {104, "Silla Gamer", 2800.00, 3},
        {105, "Audifonos", 500.00, 20},
        {106, "Webcam HD", 850.00, 10},
        {107, "Disco SSD 1TB", 1200.00, 8},
        {108, "Memoria RAM 8GB", 900.00, 12},
        {109, "Cable HDMI", 150.00, 50},
        {110, "Funda Laptop", 350.00, 25}
    };

    int opcion;

    do {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        while (!(cin >> opcion)) {
            cout << "Entrada invalida. Ingrese un numero: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        switch(opcion) {
            case 1:
                mostrarInventario(inventario, MAX_PRODUCTOS);
                break;
            case 2:
                // Búsqueda con manejo de excepciones
                try {
                    buscarProducto(inventario, MAX_PRODUCTOS);
                } catch (const runtime_error& e) {
                    cout << "\n>> ALERTA: " << e.what() << endl;
                }
                break;
            case 3:
                ordenarPorPrecio(inventario, MAX_PRODUCTOS);
                cout << "\n>> Inventario ordenado por precio (menor a mayor).\n";
                mostrarInventario(inventario, MAX_PRODUCTOS);
                break;
            case 4:
                cout << "\n[LOGICA DE MODIFICACION PENDIENTE]\n";
                break;
            case 5:
                cout << "Saliendo del gestor...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
        }

        cout << "\nPresione Enter para continuar...";
        cin.ignore();
        cin.get();
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

    } while (opcion != 5);

    return 0;
}

// --- IMPLEMENTACION ---
void mostrarMenu() {
    cout << "==================================" << endl;
    cout << "       GESTOR DE INVENTARIO       " << endl;
    cout << "==================================" << endl;
    cout << "1. Mostrar Inventario Completo" << endl;
    cout << "2. Buscar Producto (ID)" << endl;
    cout << "3. Ordenar Inventario (Precio)" << endl;
    cout << "4. Modificar Stock (Punteros)" << endl;
    cout << "5. Salir" << endl;
    cout << "==================================" << endl;
}

void mostrarInventario(Producto inventario[], int total) {
    cout << "\n--- LISTA DE PRODUCTOS ---" << endl;
    cout << left << setw(6) << "ID"
         << setw(20) << "Nombre"
         << setw(10) << "Precio"
         << setw(10) << "Cantidad" << endl;
    cout << "---------------------------------------------" << endl;
    for(int i = 0; i < total; i++) {
        cout << left << setw(6) << inventario[i].id
             << setw(20) << inventario[i].nombre
             << "$" << setw(9) << inventario[i].precio
             << setw(10) << inventario[i].cantidad << endl;
    }
}

void buscarProducto(Producto inventario[], int total) {
    int idBuscado;
    bool encontrado = false;
    cout << "Ingrese el ID del producto a buscar: ";
    cin >> idBuscado;

    for(int i = 0; i < total; i++) {
        if (inventario[i].id == idBuscado) {
            cout << "\n>> PRODUCTO ENCONTRADO:\n";
            cout << "Nombre: " << inventario[i].nombre << endl;
            cout << "Precio: $" << inventario[i].precio << endl;
            cout << "Stock:  " << inventario[i].cantidad << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        // Lanzamos excepcion si no se encuentra
        throw runtime_error("Producto no encontrado en la base de datos.");
    }
}

void ordenarPorPrecio(Producto inventario[], int total) {
    // Metodo de Burbuja
    Producto temp;
    for(int i = 0; i < total - 1; i++) {
        for(int j = 0; j < total - 1 - i; j++) {
            if (inventario[j].precio > inventario[j+1].precio) {
                // Intercambio
                temp = inventario[j];
                inventario[j] = inventario[j+1];
                inventario[j+1] = temp;
            }
        }
    }
}
