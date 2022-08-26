#ifndef FDISK_H
#define FDISK_H

#include <string>
#include <regex>

using namespace std;

class fdisk{

    private:
        int _S; //Positivo > 0     Obligatorio
        string _U; //B ó K ó M
        string _Path; //Ruta
        string _T = "P"; //P ó E ó L
        string _F = "WorstFit"; //BestFit ó FirstFit ó WorstFit
        string _Delete;
        string _name;
        string _add;

    public:

    //Constructor
    fdisk(/*Args*/){
        this->_S = 0;
        this->_U = "k";
        this->_Path = "";
        this->_T = "p";
    }

    //Destructor
    ~fdisk(){
    }

    bool busquedaParametros(string texto) {

        regex s("");

    }

};

#endif