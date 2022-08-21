#ifndef REP_H
#define REP_H

#include <iostream>
#include <regex>

using namespace std;

class rep {
    private:

    public:


    rep(){

    }

    ~rep(){

    }

    void busqueda() {

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