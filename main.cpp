#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool busqueda(string);

int main() {
    while (true) {
        string aux;
        int opcion = 0;
        cout << "Menú" << endl;
        cout << "1. Buscar una palabra" << endl;
        cout << "2. Buscar una frase." << endl;
        cout << "3. Salir." << endl;
        cout << "Ingrese una opción:" << endl << ">>";
        
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
            case 1:
                cout << endl << "Ingrese una palabra" << endl << ">>";
                cin>>aux;
                busqueda(aux);
                break;
            case 2: 
                cout << endl << "Ingrese una frase" << endl << ">>";
                getline(cin, aux);
                busqueda(aux);
                break;
            case 3:
                cout << "Salir" << endl;
                exit(1);
                break;
            default:
                cout << "Ingrese una opción válida." << endl;
                opcion = 0;
                cin.ignore();
                break;
        }
    }
    return 0;
}

bool busqueda(string palabra) {
    regex reg(palabra);
    if (regex_search("Hola mucho gusto, mi nombre es diego.", reg)) {
        cout << "¡Matched!." << endl;
        return true;
    } else {
        cout << "Not found." << endl;
        return false;
    }
}

void mkdisk() {
    
}