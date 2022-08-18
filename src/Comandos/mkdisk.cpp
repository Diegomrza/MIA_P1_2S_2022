#ifndef MKDISK_H
#define MKDISK_H

#include <string>
#include <regex>
#include <iostream>

using namespace std;

/*
Esta clase crea archivos binarios que simularán discos
*/
class mkdisk{
    
    private:
        //Obligatorio
        int guion_S = 0; //Positivo > 0

        //Opcional
        string guion_F = "BF"; //BF ó FF ó WF

        //Opcional
        string guion_U = "M"; //K ó M

        //Obligatorio
        string guion_Path = ""; //Ruta
        
    public:
        /* Data */

    //Constructor
    mkdisk(/*Args*/){

    }

    //Destructor
    ~mkdisk(){
    }

    void busquedaParametros(string palabra) {

        regex mk_disk("mkdisk");
        regex m_s("-s->[0-9]+");
        regex m_f("-f->(BF|FF|WF)");
        regex m_u("-u->(m|k)");
        regex m_path("(-path->(/[a-z0-9]+)*\\.dsk|-path->\"(/[a-z0-9 ]+)*\\.dsk\")");

        //  mkdisk  -u->K -s->3000 -path->/home/user/Disco1.dsk

        palabra = minuscula(palabra);

        if(regex_search(palabra, mk_disk)) {
            cout<<"mkdisk Encontrado."<<endl;
        }
        if (regex_search(palabra, m_s)) {
            cout<<"-s Encontrado"<<endl;
        }
        if (regex_search(palabra, m_f)) {
            std::cout<<"-m Encontrado"<<endl;
        }
        if (regex_search(palabra, m_u)) {
            std::cout<<"-u Encontrado"<<endl;
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
        //cout<<aux<<endl;
        return aux;
    }


};

#endif