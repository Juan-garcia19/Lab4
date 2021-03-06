#ifndef ENRUTADOR_H
#define ENRUTADOR_H
#include <iostream>
#include <vector>
#include <map>
#include <fstream>


using namespace std;

class Enrutador
{
public:
    Enrutador();

    void lecturaCaminos(char router, string caminoRecorrido, char destino,char copi,char an,int ValorCami,int &B,string &caminoMayor);

    void LectuArchi();

    void Actualizacion();

    void IngresoManualRouters();

    vector<int> getValConexRuter() const;
    void setValConexRuter(const vector<int> &value);

    vector<string> getNomConexRuter() const;
    void setNomConexRuter(const vector<string> &value);

    map<char, vector<string> > getRouters() const;
    void setRouters(const map<char, vector<string> > &value);

private:
    vector <int> valConexRuter;

    vector <string> NomConexRuter;

    map <char,vector<string>> routers;
};



#endif // ENRUTADOR_H
