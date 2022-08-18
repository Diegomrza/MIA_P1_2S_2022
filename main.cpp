#include <iostream>
#include <string>
#include <regex>

#include "./src/Comandos/mkdisk.cpp"
#include "./src/Comandos/rmdisk.cpp"

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
    
    mkdisk *mk = new mkdisk();
    mk->busquedaParametros("mkdisk -s->10 -path->\"/home/mis discos/Disco4.dsk\"");

    rmdisk *rm = new rmdisk();
    rm->busquedaParametros("rmdisk -path->\"/home/mis discos/Disco4.dsk\"");
    
    return false;
}
