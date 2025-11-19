#include <iostream>
#include <cmath>
#include <stdexcept> // Para manejo de excepciones

using namespace std;

// --- PROTOTIPOS ---
void mostrarMenu();
double sumar(double a, double b);
double restar(double a, double b);
double multiplicar(double a, double b);
// Funciones que lanzaran excepciones
double dividir(double a, double b);
double potencia(double base, int exp = 2);
double raizCuadrada(double num);
long long factorial(int n);

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

        if (opcion == 8) break;

        // BLOQUE TRY-CATCH PRINCIPAL
        try {
            switch(opcion) {
                case 1:
                    cout << "Ingrese dos numeros: "; cin >> num1 >> num2;
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
                    // La funcion lanzara throw si num2 es 0
                    cout << "Resultado: " << dividir(num1, num2) << endl;
                    break;
                case 5:
                    int n;
                    cout << "Ingrese numero entero positivo: "; cin >> n;
                    cout << "Factorial: " << factorial(n) << endl;
                    break;
                case 6:
                    int exp;
                    cout << "Ingrese base: "; cin >> num1;
                    cout << "Desea ingresar exponente? (1: Si, 0: No): ";
                    int usaExp; cin >> usaExp;
                    if (usaExp == 1) {
                        cout << "Ingrese exponente: "; cin >> exp;
                        cout << "Resultado: " << potencia(num1, exp) << endl;
                    } else {
                        cout << "Resultado (al cuadrado): " << potencia(num1) << endl;
                    }
                    break;
                case 7:
                    cout << "Ingrese numero: "; cin >> num1;
                    cout << "Raiz: " << raizCuadrada(num1) << endl;
                    break;
                default:
                    cout << "Opcion no valida." << endl;
            }
        }
        catch (const runtime_error& e) {
            cout << "\n>>> ERROR MATEMATICO: " << e.what() << " <<<\n";
        }
        catch (const invalid_argument& e) {
            cout << "\n>>> ERROR DE ARGUMENTO: " << e.what() << " <<<\n";
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
    cout << "4. Dividir (Excepciones)" << endl;
    cout << "5. Factorial (Recursivo)" << endl;
    cout << "6. Potencia" << endl;
    cout << "7. Raiz Cuadrada (Excepciones)" << endl;
    cout << "8. Salir" << endl;
    cout << "----------------------------" << endl;
}

double sumar(double a, double b) { return a + b; }
double restar(double a, double b) { return a - b; }
double multiplicar(double a, double b) { return a * b; }

double dividir(double a, double b) {
    if (b == 0) {
        // Lanzamos excepcion estandar
        throw runtime_error("Division entre cero no permitida.");
    }
    return a / b;
}

double potencia(double base, int exp) {
    return pow(base, exp);
}

double raizCuadrada(double num) {
    if (num < 0) {
        // Lanzamos excepcion para raices imaginarias
        throw runtime_error("No se puede calcular raiz cuadrada de numero negativo.");
    }
    return sqrt(num);
}

long long factorial(int n) {
    if (n < 0) {
        throw invalid_argument("El factorial no esta definido para numeros negativos.");
    }
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
