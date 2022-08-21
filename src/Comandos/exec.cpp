#ifndef EXEC_H
#define EXEC_H

#include <fstream>
#include <iostream>
#include <regex>
#include <cstring>

using namespace std;

class exec {

    private:
        

    public:
        string path; //Obligatorio
        
    //Constructor
    exec () {
    }

    //Destructor
    ~exec() {
    }

    void busquedaRuta(string ruta) {
        char *aux;
        ruta = minuscula(ruta);

        regex ecsec("exec");
        regex path("(-path->(/[a-z0-9]+)*\\.mia|-path->\"(/[a-z0-9 ]+)*\\.mia\")");
        smatch matchs;
        
        if (regex_search(ruta, ecsec)) {
            if (regex_search(ruta, matchs, path)) {
                char char_array[matchs.str().length()+1];
                strcpy(char_array, matchs.str().c_str());
                strtok(char_array, "->");
                aux = strtok(NULL, "->");
                this->path = aux;
            }
        }
        
    }

    string minuscula(string frase) {
        string aux = "";
        for (int i = 0; i < frase.length(); i++) {
            aux += tolower(frase[i]);
        }    
        return aux;
    }

};

#endif