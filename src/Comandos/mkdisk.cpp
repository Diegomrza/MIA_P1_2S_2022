#ifndef MKDISK_H
#define MKDISK_H

#include <regex>
#include <fstream>
#include <iostream>
#include <filesystem>


using namespace std;

/*
Esta clase crea archivos binarios que simularán discos
*/
class mkdisk{
    
    public:
        int guion_S = 0;        //Positivo > 0
        string guion_F = "ff";  //BF ó FF ó WF
        string guion_U = "m";   //K ó M
        string guion_Path = ""; //Ruta

    //Constructor
    mkdisk(/*Args*/){
    }

    //Destructor
    ~mkdisk(){
    }

    bool busquedaParametros(string texto) {

        /* Definiciones de las expresiones 
            regulares para reconocer el comando mkdisk */
        regex m_k("mkdisk"); 
        smatch mk;

        regex m_s("-s->([0-9]+|-[0-9]+)");  
        smatch ms;

        regex m_f("-f->[a-z0-9]{2}");
        smatch mf;

        regex m_u("-u->[a-z0-9]");
        smatch mu;

        regex m_path("(-path->(/[a-z0-9]+)*\\.dsk|-path->\"(/[a-z0-9 ]+)*\\.dsk\")"); 
        smatch mp;

        /* Convirtiendo el comando 
            de entrada a minusculas */
        texto = minuscula(texto);

        //cout<<endl<<endl<<"Comando: "<<texto<<endl<<endl;

        /* muestra true ó false en vez de 1 ó 0 */
        cout<<boolalpha;    

        if(regex_search(texto, mk, m_k)) {
            if (regex_search(texto, ms, m_s)) {
                this->guion_S = stoi(split_text(ms.str(), 2));
            } else {
                cout<<"ERROR parámetro obligatorio -s no encontrado."<<endl;
            }

            if (regex_search(texto, mf, m_f)) {
                this->guion_F = split_text(mf.str(), 2);
            }

            if (regex_search(texto, mu, m_u)) {
                this->guion_U = split_text(mu.str(), 2);
            }

            if (regex_search(texto, mp, m_path)) {
                this->guion_Path = split_text(mp.str(), 2);
            } else {
                cout<<"ERROR parámetro obligatorio -path no encontrado."<<endl;
            }

            if (integridadParametros()) {
                cout<<":::::Parámetros encontrados:::::"<<endl;
                cout<<"-s: "<<this->guion_S<<endl;
                cout<<"-u: "<<this->guion_U<<endl;
                cout<<"-f: "<<this->guion_F<<endl;
                cout<<"-path: "<<this->guion_Path<<endl;
                cout<<"::::::::::::::::::::::::::::::::"<<endl;
                if (!crearArchivo(this->guion_Path)) {
                    return false;
                }
                return true;
            }
            return false;
        
        } else {
            return false;
        }
    }

    string minuscula(string frase) { //Convierte un texto recibido a minusculas
        string aux = "";
        for (int i = 0; i < frase.length(); i++) {
            aux += tolower(frase[i]);
        }    
        return aux;
    }

    string split_text(string texto, int tam) {
        string aux;
        stringstream input_stringstream(texto);
        for (int i = 0; i<tam; i++) {
            getline(input_stringstream, aux, '>');
        }
        //getline(input_stringstream, aux, '>'); //Lee lo primero y lo guarda
        //getline(input_stringstream, aux, '>'); //Lee lo segundo y lo guarda (reemplaza lo de antes)
        //cout<<"Parámetro extraído: "<<aux<<endl;
        return aux;
    }

    bool integridadParametros() {
        bool bandera = true;

        if (this->guion_S <= 0) {
            cout<<"Error: -s inválido    ->    "<<this->guion_S<<endl;
            bandera = false;
        } 
        if (this->guion_F != "ff" && this->guion_F != "bf" && this->guion_F != "wf") {
            cout<<"Error: -f inválido    ->    "<<this->guion_F<<endl;
            bandera = false;
        }
        if (this->guion_U != "m" && this->guion_U != "k") {
            cout<<"Error: -u inválido    ->    "<<this->guion_U<<endl;
            bandera = false;
        }
        if (this->guion_Path == "") {
            cout<<"Error: Ruta inválida    ->    "<<this->guion_Path<<endl;
            bandera = false;
        }

        return bandera;
    }

    bool exist(string ruta) {
        FILE *archivo;
        if ((archivo == fopen(ruta.c_str(), "r"))) {
            fclose(archivo);
            return true;
        }
        return false;
    }

    bool crearArchivo(string ruta) {
        
        /*
            Expresión regular que extrae todo lo que esté antes del nombre del archivo
        */
        regex reg_directorio("[a-z][a-z0-9]*.dsk");
        smatch d;

        string nombreDirectorio = regex_replace(ruta, reg_directorio, "");
        cout<<nombreDirectorio<<endl;

        //int n = mkdir(nombreDirectorio.c_str(), S_IRWXU);
        bool bn = std::filesystem::create_directories(nombreDirectorio);
        if (bn == false) {
            cout<<"No se pudo crear el directorio ó ya existe."<<endl;
        }

        ifstream myfile;
        myfile.open(ruta);
        if (!myfile) {
            ofstream fichero(ruta);
            for (int i = 0; i < this->guion_S*1024*1024; i++)
            {
                char c = '\0';
                fichero.write(&c, 1);
            }
            fichero.close();
            return true;
        }
        myfile.close();
        
        cout<<"Disco creado con exito"<<endl;
        
        return false;
        // if (!exist(ruta)) {
        //     FILE *Archivo;
        //     Archivo = fopen(ruta.c_str(),"wb"); // ABRIMOS EL ARCHIVO EN FORMA WRITE BYTES
            
        //     for (int i = 0; i < 10*1024*1024; i++)
        //     {
        //         char c = '\0';
        //         fwrite(&c, 1, 1, Archivo);
        //     }
        //     fclose(Archivo);
        // }
    }

};

#endif