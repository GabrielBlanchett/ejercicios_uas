#include <iostream>
#include <string>
#include <vector>

using namespace std;

// --- ESTRUCTURAS ---
struct Cuenta {
    int numeroCuenta;
    int nip;
    double saldo;
    string titular;
};

// --- PROTOTIPOS DE FUNCIONES ---
void mostrarMenu();

int main() {
    // Requerimiento: Mínimo 3 cuentas simuladas con saldo inicial.
    // Usamos un arreglo de estructuras.
    const int NUM_CUENTAS = 3;
    Cuenta cuentas[NUM_CUENTAS] = {
        {1001, 1234, 5000.00, "Juan Perez"},
        {1002, 5678, 1500.50, "Maria Lopez"},
        {1003, 9999, 300.00,  "Carlos Ruiz"}
    };

    int opcion;
    int cuentaActualIndex = -1; // Índice de la cuenta logueada (-1 significa nadie)

    do {
        mostrarMenu();
        cout << "Seleccione una opcion: ";

        // Validación básica de entrada numérica (evita bucles infinitos si meten letras)
        while (!(cin >> opcion)) {
            cout << "Entrada invalida. Ingrese un numero: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        switch (opcion) {
            case 1:
                cout << "\n[LOGICA DE INICIO DE SESION PENDIENTE]\n";
                break;
            case 2:
                cout << "\n[LOGICA DE RETIRO PENDIENTE]\n";
                break;
            case 3:
                cout << "\n[LOGICA DE DEPOSITO PENDIENTE]\n";
                break;
            case 4:
                cout << "\n[LOGICA DE TRANSFERENCIA PENDIENTE]\n";
                break;
            case 5:
                cout << "\n[LOGICA DE CONSULTA DE SALDO PENDIENTE]\n";
                break;
            case 6:
                cout << "\nSaliendo del sistema...\n";
                break;
            default:
                cout << "\nOpcion no valida. Intente de nuevo.\n";
        }

        cout << "\nPresione Enter para continuar...";
        cin.ignore();
        cin.get();
        // Limpiar pantalla (forma simple portable)
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

    } while (opcion != 6);

    return 0;
}

// --- IMPLEMENTACION DE FUNCIONES ---
void mostrarMenu() {
    cout << "======================================" << endl;
    cout << "       CAJERO AUTOMATICO - ATM        " << endl;
    cout << "======================================" << endl;
    cout << "1. Iniciar Sesion (Cambiar Cuenta)" << endl;
    cout << "2. Retirar Efectivo" << endl;
    cout << "3. Depositar Fondos" << endl;
    cout << "4. Transferir a otra cuenta" << endl;
    cout << "5. Consultar Saldo" << endl;
    cout << "6. Salir" << endl;
    cout << "======================================" << endl;
}
