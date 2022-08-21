#ifndef RMDISK_H
#define RMDISK_H

#include <string>
#include <regex>
#include <iostream>

#include <errno.h>

using namespace std;

/*
Esta clase elimina discos
*/
class rmdisk{

    private:
        std::string Path; //Ruta
       
    public:
        

    //Constructor
    rmdisk(/*Args*/){

    }

    //Destructor
    ~rmdisk(){
    }

    bool busquedaParametros(string palabra) {
        palabra = minuscula(palabra);

        regex rm_disk("rmdisk");
        regex m_path("(-path->(/[a-z0-9]+)*\\.dsk|-path->\"(/[a-z0-9 ]+)*\\.dsk\")");
        smatch mp;

        if (regex_search(palabra, rm_disk)) {
            cout<<"rmdisk Encontrado"<<endl;
            if (regex_search(palabra, mp, m_path)) {
                cout<<"Hola"<<endl;
                string aux = split_text(mp.str(), 2);
                eliminarArchivo(aux);
            }
        }
        return false;
    }

    string minuscula(string frase) {
        string aux = "";
        for (int i = 0; i < frase.length(); i++) {
            aux += tolower(frase[i]);
        }    
        cout<<aux<<endl;
        return aux;
    }

    string split_text(string texto, int tam) {
        string aux;
        stringstream input_stringstream(texto);
        for (int i = 0; i<tam; i++) {
            getline(input_stringstream, aux, '>');
        }
        return aux;
    }

    bool eliminarArchivo(string ruta) {
        cout<<"Ruta: "<<ruta<<endl;
        int n = remove(ruta.c_str());
        if (n == -1) {
            cout<<"No removido "<<strerror(errno)<<endl;
            return false;
        }
        cout<<"Removido"<<endl;
        return true;
    }

};

#endif