#ifndef FDISK_H
#define FDISK_H

#include <string>

using namespace std;

class fdisk{

    private:
        int _S; //Positivo > 0
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

    }

    //Destructor
    ~fdisk(){
    }
};

#endif