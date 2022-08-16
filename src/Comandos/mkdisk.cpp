#ifndef MKDISK_H
#define MKDISK_H

#include <string>

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
};

#endif