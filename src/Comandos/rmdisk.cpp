#ifndef RMDISK_H
#define RMDISK_H

#include <string>
#include <regex>
#include <iostream>

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

    void busquedaParametros(string palabra) {
        palabra = minuscula(palabra);

        regex rm_disk("rmdisk");
        regex m_path("(-path->(/[a-z0-9]+)*\\.dsk|-path->\"(/[a-z0-9 ]+)*\\.dsk\")");

        if (regex_search(palabra, rm_disk)) {
            cout<<"rmdisk Encontrado"<<endl;
        }

        if (regex_search(palabra, m_path)) {
            cout<<"-path Encontrado"<<endl;
        }
    }

    string minuscula(string frase) {
        string aux = "";
        for (int i = 0; i < frase.length(); i++) {
            aux += tolower(frase[i]);
        }    
        cout<<aux<<endl;
        return aux;
    }
};

#endif