#include <iostream>
#include <cmath>

using namespace std;

// --- PROTOTIPOS ---
void mostrarMenu();

// Basicas
double sumar(double a, double b);
int sumar(int a, int b); // Sobrecarga
double restar(double a, double b);
double multiplicar(double a, double b);
double dividir(double a, double b);

// Avanzadas
// Parametro por omision: si no envian exp, se eleva al cuadrado
double potencia(double base, int exp = 2);
double raizCuadrada(double num);
long long factorial(int n); // Recursividad

int main() {
    int opcion;
    double num1, num2;

    do {
        mostrarMenu();
        cout << "Seleccione una operacion: ";
        while (!(cin >> opcion)) {
            cout << "Entrada invalida. Ingrese numero: ";
            cin.clear(); cin.ignore(10000, '\n');
        }

        switch(opcion) {
            case 1: // Suma con demostracion de sobrecarga
                cout << "Ingrese dos numeros: "; cin >> num1 >> num2;
                // Si ambos son enteros, se podria llamar a la version int, aqui usamos double general
                cout << "Resultado: " << sumar(num1, num2) << endl;
                break;
            case 2:
                cout << "Ingrese dos numeros: "; cin >> num1 >> num2;
                cout << "Resultado: " << restar(num1, num2) << endl;
                break;
            case 3:
                cout << "Ingrese dos numeros: "; cin >> num1 >> num2;
                cout << "Resultado: " << multiplicar(num1, num2) << endl;
                break;
            case 4:
                cout << "Ingrese dos numeros: "; cin >> num1 >> num2;
                if (num2 != 0) cout << "Resultado: " << dividir(num1, num2) << endl;
                else cout << "Error: Division por cero." << endl;
                break;
            case 5: // Factorial
                int n;
                cout << "Ingrese numero entero positivo para factorial: ";
                cin >> n;
                if (n < 0) cout << "No existe factorial de negativos.\n";
                else cout << "Factorial de " << n << " es: " << factorial(n) << endl;
                break;
            case 6: // Potencia
                int exp;
                cout << "Ingrese base: "; cin >> num1;
                cout << "Desea ingresar exponente? (1: Si, 0: No, usar cuadrado): ";
                int usaExp; cin >> usaExp;
                if (usaExp == 1) {
                    cout << "Ingrese exponente: "; cin >> exp;
                    cout << "Resultado: " << potencia(num1, exp) << endl;
                } else {
                    // Llamada usando parametro por omision
                    cout << "Resultado (al cuadrado): " << potencia(num1) << endl;
                }
                break;
            case 7: // Raiz
                cout << "Ingrese numero: "; cin >> num1;
                if (num1 >= 0) cout << "Raiz: " << raizCuadrada(num1) << endl;
                else cout << "Error: Raiz negativa." << endl;
                break;
            case 8:
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

    } while (opcion != 8);

    return 0;
}

// --- IMPLEMENTACION ---
void mostrarMenu() {
    cout << "--- CALCULADORA AVANZADA ---" << endl;
    cout << "1. Sumar" << endl;
    cout << "2. Restar" << endl;
    cout << "3. Multiplicar" << endl;
    cout << "4. Dividir" << endl;
    cout << "5. Factorial (Recursivo)" << endl;
    cout << "6. Potencia (Parametros por omision)" << endl;
    cout << "7. Raiz Cuadrada" << endl;
    cout << "8. Salir" << endl;
    cout << "----------------------------" << endl;
}

double sumar(double a, double b) { return a + b; }
int sumar(int a, int b) { return a + b; } // Sobrecarga
double restar(double a, double b) { return a - b; }
double multiplicar(double a, double b) { return a * b; }
double dividir(double a, double b) { return a / b; }

// Parametro por omision definido en prototipo, aqui solo implementacion
double potencia(double base, int exp) {
    return pow(base, exp);
}

double raizCuadrada(double num) {
    return sqrt(num);
}

long long factorial(int n) {
    if (n <= 1) return 1; // Caso base
    return n * factorial(n - 1); // Llamada recursiva
}
