#include <iostream>
#include <string>
using namespace std;

class Cadena {
    private:
        string texto;

    public:
        Cadena(string texto = "");

        int longitud();

        // Concatenacion
        Cadena operator+(Cadena& c);

        // Comparacion
        bool operator==(Cadena& c);
        bool operator!=(Cadena& c);
        bool operator<(Cadena& c);
        bool operator>(Cadena& c);
        bool operator<=(Cadena& c);
        bool operator>=(Cadena& c);

        // Operador unario
        bool operator!();

       //operador subindice
        char operator[](int i);

        // Entrada y salida
        friend ostream& operator<<(ostream& os, Cadena c);
        friend istream& operator>>(istream& is, Cadena& c);
};

// Constructor: guarda el texto recibido
Cadena::Cadena(string texto) {
    this->texto = texto;
}

// Devuelve la cantidad de caracteres
int Cadena::longitud() {
    return texto.length();
}

// Une dos cadenas y devuelve una nueva
Cadena Cadena::operator+(Cadena& c) {
    return Cadena(texto + c.texto);
}
bool Cadena::operator==(Cadena& c) { return texto == c.texto; }
bool Cadena::operator!=(Cadena& c) { return texto != c.texto; }
bool Cadena::operator<(Cadena& c)  { return texto <  c.texto; }
bool Cadena::operator>(Cadena& c)  { return texto >  c.texto; }
bool Cadena::operator<=(Cadena& c) { return texto <= c.texto; }
bool Cadena::operator>=(Cadena& c) { return texto >= c.texto; }
bool Cadena::operator!() {
    return texto.empty();
}


char Cadena::operator[](int i) {
    if (i >= 0 && i < longitud())
        return texto[i];
    return '\0';
}


ostream& operator<<(ostream& os, Cadena c) {
    os << c.texto;
    return os;
}

istream& operator>>(istream& is, Cadena& c) {
    getline(is, c.texto);
    return is;
}

int main() {
    Cadena c1, c2;
    int opcion;

    do {
        cout << "\n----MENU----\n";
        cout << "1. Ingresar cadenas\n";
        cout << "2. Concatenar cadenas\n";
        cout << "3. Comparar cadenas\n";
        cout << "4. Determinar si una cadena esta vacia\n";
        cout << "5. Acceder a un caracter individual\n";
        cout << "6. Determinar la longitud\n";
        cout << "7. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore(); 

        switch (opcion) {
            case 1:
                cout << "Cadena 1: ";
                cin >> c1;
                cout << "Cadena 2: ";
                cin >> c2;
                break;

            case 2: {
                Cadena c3 = c1 + c2;
                cout << "Resultado: " << c3 << endl;
                break;
            }

            case 3:
                cout << "c1 == c2: " << (c1 == c2 ? "Si" : "No") << endl;
                cout << "c1 != c2: " << (c1 != c2 ? "Si" : "No") << endl;
                cout << "c1 <  c2: " << (c1 <  c2 ? "Si" : "No") << endl;
                cout << "c1 >  c2: " << (c1 >  c2 ? "Si" : "No") << endl;
                cout << "c1 <= c2: " << (c1 <= c2 ? "Si" : "No") << endl;
                cout << "c1 >= c2: " << (c1 >= c2 ? "Si" : "No") << endl;
                break;

            case 4:
                cout << "Cadena 1 " << (!c1 ? "esta vacia" : "no esta vacia") << endl;
                cout << "Cadena 2 " << (!c2 ? "esta vacia" : "no esta vacia") << endl;
                break;

            case 5: {
                int pos;
                cout << "Posicion: ";
                cin >> pos;
                if (c1[pos] != '\0')
                    cout << "Cadena 1 [" << pos << "] = " << c1[pos] << endl;
                else
                    cout << "Cadena 1: posicion fuera de rango\n";
                if (c2[pos] != '\0')
                    cout << "Cadena 2 [" << pos << "] = " << c2[pos] << endl;
                else
                    cout << "Cadena 2: posicion fuera de rango\n";
                break;
            }

            case 6:
                cout << "Longitud de cadena 1: " << c1.longitud() << endl;
                cout << "Longitud de cadena 2: " << c2.longitud() << endl;
                break;

            case 7:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion no valida\n";
        }
    } while (opcion != 7);

    return 0;
}
