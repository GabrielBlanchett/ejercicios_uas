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
// Función que devuelve un puntero a la cuenta encontrada o nullptr si no existe
Cuenta* buscarCuenta(Cuenta cuentas[], int totalCuentas, int id, int nip);
void consultarSaldo(Cuenta* cuenta);

int main() {
    const int NUM_CUENTAS = 3;
    Cuenta cuentas[NUM_CUENTAS] = {
        {1001, 1234, 5000.00, "Juan Perez"},
        {1002, 5678, 1500.50, "Maria Lopez"},
        {1003, 9999, 300.00,  "Carlos Ruiz"}
    };

    int opcion;
    // Puntero a la cuenta actualmente logueada. nullptr indica que no hay sesión.
    Cuenta* cuentaActual = nullptr;

    do {
        mostrarMenu();
        if (cuentaActual != nullptr) {
            cout << ">> Usuario activo: " << cuentaActual->titular << " (Cuenta: " << cuentaActual->numeroCuenta << ")" << endl;
        } else {
            cout << ">> NO HAY SESION INICIADA. Por favor inicie sesion primero." << endl;
        }
        cout << "--------------------------------------" << endl;
        cout << "Seleccione una opcion: ";

        while (!(cin >> opcion)) {
            cout << "Entrada invalida. Ingrese un numero: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        switch (opcion) {
            case 1: {
                int id, nip;
                cout << "Ingrese Numero de Cuenta: ";
                cin >> id;
                cout << "Ingrese NIP: ";
                cin >> nip;

                // Buscamos la cuenta y asignamos la dirección al puntero
                cuentaActual = buscarCuenta(cuentas, NUM_CUENTAS, id, nip);

                if (cuentaActual != nullptr) {
                    cout << "\n>> Bienvenido, " << cuentaActual->titular << "!\n";
                } else {
                    cout << "\n>> ERROR: Credenciales incorrectas.\n";
                }
                break;
            }
            case 2:
                if (cuentaActual == nullptr) { cout << "\n>> DEBE INICIAR SESION PRIMERO.\n"; break; }
                cout << "\n[LOGICA DE RETIRO PENDIENTE]\n";
                break;
            case 3:
                if (cuentaActual == nullptr) { cout << "\n>> DEBE INICIAR SESION PRIMERO.\n"; break; }
                cout << "\n[LOGICA DE DEPOSITO PENDIENTE]\n";
                break;
            case 4:
                if (cuentaActual == nullptr) { cout << "\n>> DEBE INICIAR SESION PRIMERO.\n"; break; }
                cout << "\n[LOGICA DE TRANSFERENCIA PENDIENTE]\n";
                break;
            case 5:
                if (cuentaActual == nullptr) { cout << "\n>> DEBE INICIAR SESION PRIMERO.\n"; break; }
                // Pasamos el puntero a la función
                consultarSaldo(cuentaActual);
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
    cout << "1. Iniciar Sesion / Cambiar Usuario" << endl;
    cout << "2. Retirar Efectivo" << endl;
    cout << "3. Depositar Fondos" << endl;
    cout << "4. Transferir a otra cuenta" << endl;
    cout << "5. Consultar Saldo" << endl;
    cout << "6. Salir" << endl;
    cout << "======================================" << endl;
}

// Retorna puntero a la cuenta si coincide ID y NIP, sino retorna nullptr
Cuenta* buscarCuenta(Cuenta cuentas[], int totalCuentas, int id, int nip) {
    for(int i = 0; i < totalCuentas; i++) {
        if(cuentas[i].numeroCuenta == id && cuentas[i].nip == nip) {
            return &cuentas[i]; // Retornamos la dirección de memoria de esa cuenta
        }
    }
    return nullptr;
}

void consultarSaldo(Cuenta* cuenta) {
    // Accedemos a los miembros de la estructura a través del puntero usando ->
    cout << "\n--- CONSULTA DE SALDO ---" << endl;
    cout << "Titular: " << cuenta->titular << endl;
    cout << "Saldo Disponible: $" << cuenta->saldo << endl;
}
