#include <regex>
#include <ctime>
#include <iostream>

#include "./src/Comandos/mkdisk.cpp"
#include "./src/Comandos/rmdisk.cpp"
#include "./src/Comandos/exec.cpp"

using namespace std;

bool busqueda(string);

int main() {
    while (true) {
        string aux;
        int opcion = 0;
        cout << "Menú" << endl;
        cout << "1. Buscar una palabra." << endl;
        cout << "2. Ingresar un comando." << endl;
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

bool busqueda(string texto) {

    mkdisk *mk = new mkdisk();
    mk->busquedaParametros(texto); //mkdisk -s->10 -f->wf -path->/home/squery/discos/prueba/Disco4.dsk

    rmdisk *rm = new rmdisk();
    rm->busquedaParametros(texto);

    // exec *exec_ = new exec();
    // exec_->busquedaRuta("exec -path->/home/misdiscos/Disco4.mia");
    // cout<<"RUTA: "<<exec_->path<<endl;

    return false;
}
