#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

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
// Retorna puntero para poder modificarlo despues
Producto* buscarProductoPtr(Producto inventario[], int total, int idBuscado);
void ordenarPorPrecio(Producto inventario[], int total);
void modificarStock(Producto* prod);

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
            case 2: {
                int id;
                cout << "Ingrese ID a buscar: ";
                cin >> id;
                Producto* p = buscarProductoPtr(inventario, MAX_PRODUCTOS, id);
                if (p != nullptr) {
                    cout << "\n>> ENCONTRADO: " << p->nombre << " | Stock: " << p->cantidad << endl;
                } else {
                    cout << "\n>> ERROR: Producto no encontrado.\n";
                }
                break;
            }
            case 3:
                ordenarPorPrecio(inventario, MAX_PRODUCTOS);
                cout << "\n>> Inventario ordenado por precio (menor a mayor).\n";
                mostrarInventario(inventario, MAX_PRODUCTOS);
                break;
            case 4: {
                // Modificacion usando punteros
                int id;
                cout << "Ingrese ID del producto a modificar: ";
                cin >> id;
                Producto* p = buscarProductoPtr(inventario, MAX_PRODUCTOS, id);

                if (p != nullptr) {
                    modificarStock(p); // Pasamos el puntero
                } else {
                    cout << "\n>> ERROR: No se puede modificar, producto no existe.\n";
                }
                break;
            }
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

Producto* buscarProductoPtr(Producto inventario[], int total, int idBuscado) {
    for(int i = 0; i < total; i++) {
        if (inventario[i].id == idBuscado) {
            return &inventario[i]; // Retorna direccion de memoria
        }
    }
    return nullptr;
}

void ordenarPorPrecio(Producto inventario[], int total) {
    Producto temp;
    for(int i = 0; i < total - 1; i++) {
        for(int j = 0; j < total - 1 - i; j++) {
            if (inventario[j].precio > inventario[j+1].precio) {
                temp = inventario[j];
                inventario[j] = inventario[j+1];
                inventario[j+1] = temp;
            }
        }
    }
}

void modificarStock(Producto* prod) {
    int nuevoStock;
    cout << "Producto seleccionado: " << prod->nombre << endl;
    cout << "Stock actual: " << prod->cantidad << endl;
    cout << "Ingrese nueva cantidad: ";
    cin >> nuevoStock;

    if (nuevoStock >= 0) {
        // Modificamos el valor original a traves del puntero
        prod->cantidad = nuevoStock;
        cout << ">> Stock actualizado correctamente.\n";
    } else {
        cout << ">> ERROR: La cantidad no puede ser negativa.\n";
    }
}
