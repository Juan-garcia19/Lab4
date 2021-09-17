#ifndef ENRUTADOR_H
#define ENRUTADOR_H
#include <iostream>
#include <vector>
#include <map>


using namespace std;

class Enrutador
{
public:
    Enrutador();

    void lecturaCaminos(char router, string caminoRecorrido, char destino,char copi,char an,int ValorCami,int &B,string &caminoMayor);

    string LectuArchi();

    void Actualizacion();

private:
    vector <int> valConexRuter;

    vector <string> NomConexRuter;

    map <char,vector<string>> routers;
};



#endif // ENRUTADOR_H
