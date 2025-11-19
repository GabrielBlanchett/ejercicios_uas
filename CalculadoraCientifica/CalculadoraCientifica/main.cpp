#include <iostream>
#include <cmath> // Necesario para operaciones futuras

using namespace std;

// --- PROTOTIPOS ---
void mostrarMenu();
double sumar(double a, double b);
double restar(double a, double b);
double multiplicar(double a, double b);
double dividir(double a, double b);

int main() {
    int opcion;
    double num1, num2, resultado;

    do {
        mostrarMenu();
        cout << "Seleccione una operacion: ";
        while (!(cin >> opcion)) {
            cout << "Entrada invalida. Ingrese numero: ";
            cin.clear(); cin.ignore(10000, '\n');
        }

        if (opcion == 5) break; // Salir

        // Entrada de datos para ops basicas
        if (opcion >= 1 && opcion <= 4) {
            cout << "Ingrese primer numero: "; cin >> num1;
            cout << "Ingrese segundo numero: "; cin >> num2;
        }

        switch(opcion) {
            case 1:
                resultado = sumar(num1, num2);
                cout << "Resultado: " << resultado << endl;
                break;
            case 2:
                resultado = restar(num1, num2);
                cout << "Resultado: " << resultado << endl;
                break;
            case 3:
                resultado = multiplicar(num1, num2);
                cout << "Resultado: " << resultado << endl;
                break;
            case 4:
                // Division basica sin manejo de error aun
                if (num2 != 0)
                    cout << "Resultado: " << dividir(num1, num2) << endl;
                else
                    cout << "Error: Division por cero." << endl;
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }

        cout << "\nPresione Enter...";
        cin.ignore(); cin.get();
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
    cout << "--- CALCULADORA BASICA ---" << endl;
    cout << "1. Sumar" << endl;
    cout << "2. Restar" << endl;
    cout << "3. Multiplicar" << endl;
    cout << "4. Dividir" << endl;
    cout << "5. Salir" << endl;
    cout << "--------------------------" << endl;
}

double sumar(double a, double b) { return a + b; }
double restar(double a, double b) { return a - b; }
double multiplicar(double a, double b) { return a * b; }
double dividir(double a, double b) { return a / b; }
