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
Cuenta* buscarCuenta(Cuenta cuentas[], int totalCuentas, int id, int nip);
void consultarSaldo(Cuenta* cuenta);
void retirar(Cuenta* cuenta, double monto);
void depositar(Cuenta* cuenta, double monto);

int main() {
    const int NUM_CUENTAS = 3;
    Cuenta cuentas[NUM_CUENTAS] = {
        {1001, 1234, 5000.00, "Juan Perez"},
        {1002, 5678, 1500.50, "Maria Lopez"},
        {1003, 9999, 300.00,  "Carlos Ruiz"}
    };

    int opcion;
    Cuenta* cuentaActual = nullptr;

    do {
        mostrarMenu();
        if (cuentaActual != nullptr) {
            cout << ">> Usuario activo: " << cuentaActual->titular << " (Saldo: $" << cuentaActual->saldo << ")" << endl;
        } else {
            cout << ">> NO HAY SESION INICIADA." << endl;
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
                cuentaActual = buscarCuenta(cuentas, NUM_CUENTAS, id, nip);
                if (cuentaActual != nullptr) cout << "\n>> Bienvenido, " << cuentaActual->titular << "!\n";
                else cout << "\n>> ERROR: Credenciales incorrectas.\n";
                break;
            }
            case 2: {
                if (cuentaActual == nullptr) { cout << "\n>> DEBE INICIAR SESION PRIMERO.\n"; break; }
                double monto;
                cout << "Ingrese monto a retirar: $";
                cin >> monto;
                retirar(cuentaActual, monto);
                break;
            }
            case 3: {
                if (cuentaActual == nullptr) { cout << "\n>> DEBE INICIAR SESION PRIMERO.\n"; break; }
                double monto;
                cout << "Ingrese monto a depositar: $";
                cin >> monto;
                depositar(cuentaActual, monto);
                break;
            }
            case 4:
                if (cuentaActual == nullptr) { cout << "\n>> DEBE INICIAR SESION PRIMERO.\n"; break; }
                cout << "\n[LOGICA DE TRANSFERENCIA PENDIENTE]\n";
                break;
            case 5:
                if (cuentaActual == nullptr) { cout << "\n>> DEBE INICIAR SESION PRIMERO.\n"; break; }
                consultarSaldo(cuentaActual);
                break;
            case 6:
                cout << "\nSaliendo del sistema...\n";
                break;
            default:
                cout << "\nOpcion no valida.\n";
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

Cuenta* buscarCuenta(Cuenta cuentas[], int totalCuentas, int id, int nip) {
    for(int i = 0; i < totalCuentas; i++) {
        if(cuentas[i].numeroCuenta == id && cuentas[i].nip == nip) return &cuentas[i];
    }
    return nullptr;
}

void consultarSaldo(Cuenta* cuenta) {
    cout << "\n--- CONSULTA DE SALDO ---" << endl;
    cout << "Titular: " << cuenta->titular << endl;
    cout << "Saldo Disponible: $" << cuenta->saldo << endl;
}

void retirar(Cuenta* cuenta, double monto) {
    if (monto <= 0) {
        cout << ">> ERROR: El monto debe ser mayor a cero." << endl;
        return;
    }
    if (cuenta->saldo >= monto) {
        cuenta->saldo -= monto;
        cout << ">> RETIRO EXITOSO. Nuevo saldo: $" << cuenta->saldo << endl;
    } else {
        cout << ">> ERROR: Saldo insuficiente." << endl;
    }
}

void depositar(Cuenta* cuenta, double monto) {
    if (monto > 0) {
        cuenta->saldo += monto;
        cout << ">> DEPOSITO EXITOSO. Nuevo saldo: $" << cuenta->saldo << endl;
    } else {
        cout << ">> ERROR: El monto debe ser positivo." << endl;
    }
}
