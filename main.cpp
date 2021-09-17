#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string>

using namespace std;


void lecturaCaminos(char router, vector<string> NomConexRuter,vector<int> valConexRuter, string caminoRecorrido, char destino,char copi,char an,int ValorCami,int &B,string &caminoMayor);
string LectuArchi(vector<string> &NomConexRuter,vector<int> &valConexRuter);

void Actualizacion(vector<string> &NomConexRuter,vector<int> &valConexRuter,map <char,vector<string>> &routers);
void IngresoManualRouters(vector<string> &NomConexRuter, vector<int> &valConexRuter);
void borrarConexiones(vector<string> &NomConexRuter, vector<int> &valConexRuter);
void borrarRouter(vector<string> &NomConexRuter, vector<int> &valConexRuter);

int main()
{
    vector <int> valConexRuter ={4,10,4,3,1,10,2,1,2,1,3,1};
    vector <string> NomConexRuter = {"AB","AC","BA","BE","BD","CA","CD","DB","DC","EA","EB","AE"};

    //vector <int> valConexRuter;
    //vector <string> NomConexRuter;

    map <char,vector<string>> routers;

    //IngresoManualRouters(NomConexRuter,valConexRuter);









    //Actualizacion(NomConexRuter,valConexRuter,routers);
    //routers['A'].push_back("B");
    //routers['A'].push_back("7");

    return 0;
}

void Actualizacion(vector<string> &NomConexRuter,vector<int> &valConexRuter,map <char,vector<string>> &routers){

    for (auto router:NomConexRuter){
        routers[router[0]]={};
    }
    for (map <char,vector<string>>::iterator DefinicionR =routers.begin();DefinicionR != routers.end();++DefinicionR){
        for (map <char,vector<string>>::iterator parametros =routers.begin();parametros != routers.end();++parametros){

            char copi=DefinicionR->first, an=DefinicionR->first;
            int ValorCami=0;
            int B=100;
            string caminoRecorrido,claveInter,Valor;
            string caminoMayor;
            claveInter.push_back(parametros->first);

            lecturaCaminos(DefinicionR->first,NomConexRuter,valConexRuter,caminoRecorrido,parametros->first,copi,an,ValorCami,B,caminoMayor);
            routers[DefinicionR->first].push_back(claveInter);
            if (B==100){
                B=0;
            }
            routers[DefinicionR->first].push_back(to_string(B));
            routers[DefinicionR->first].push_back(caminoMayor);


        }
    }

}

void lecturaCaminos(char router, vector<string> NomConexRuter,vector<int> valConexRuter, string caminoRecorrido, char destino, char copi,char an,int ValorCami,int &B,string &caminoMayor){
    //copi=router;
    int longitud=NomConexRuter.size();

    //caminoMayor="";

    for(int i=0;i<longitud;i++){
        if ( NomConexRuter[i][0] == copi){
            int cont=0;
            for (auto letra:caminoRecorrido){
                if(NomConexRuter[i][1]==letra){
                    cont++;
                }
            }
            if (cont>1){

            }

            else if (NomConexRuter[i][1]==router or an==NomConexRuter[i][1]){

            }
            else if(NomConexRuter[i][1]==destino){
                caminoRecorrido+=NomConexRuter[i];
                ValorCami+=valConexRuter[i];

                if(ValorCami<B){
                    B=ValorCami;
                    caminoMayor=caminoRecorrido;
                    cout<<"el camino es: "<<caminoMayor<<" y el valor es "<<B<<endl;
                    ValorCami-=valConexRuter[i];
                    caminoRecorrido.pop_back();
                    caminoRecorrido.pop_back();
                }


                //copi=router;
            }
            else{
                caminoRecorrido+=NomConexRuter[i];
                ValorCami+=valConexRuter[i];

                copi=NomConexRuter[i][1];
                an=NomConexRuter[i][0];
                lecturaCaminos(router,NomConexRuter,valConexRuter,caminoRecorrido,destino,copi,an,ValorCami,B,caminoMayor);
                copi=NomConexRuter[i][0];

                ValorCami-=valConexRuter[i];
                caminoRecorrido.pop_back();
                caminoRecorrido.pop_back();
            }
        }
    }
}



string LectuArchi(vector<string> &NomConexRuter, vector<int> &valConexRuter){
   string data;

   // Abre el archivo en modo lectura
   ifstream infile;

   // Se pone de manera explicita la ruta relativa donde se encuentra el archivo
   infile.open("../Lab4/BD/Enrutadores.txt");

   if (!infile.is_open())
   {
     cout << "Error abriendo el archivo" << endl;
     exit(1);
   }
   infile >> data;

   string linea;

   while(!infile.eof()){
       string conexionRuter,ValorConex;
       getline(infile,linea);
       if (linea ==""){
           linea=data;
       }

       int longitud =data.length();
       int separador=0;
       for (int i =0;i < longitud;i++){
           if (linea[i]==','){
               separador++;
           }
           else if(separador==0){
               conexionRuter+=linea[i];

           }
           else if(separador==1){
               ValorConex+=linea[i];
           }
       }

       NomConexRuter.push_back(conexionRuter);
       valConexRuter.push_back(stoi(ValorConex));

   }

   // Se cierra el archivo abierto
   infile.close();
   return data;
}

void IngresoManualRouters(vector<string> &NomConexRuter, vector<int> &valConexRuter){

    cout<<"para agregar un enrutador a la red debe ingresar las conexiones con los demas routers "<<endl;
    cout<<"la siguiente manera: "<<endl;
    cout<<"<enturador+enrutador al que esta conectado>,< , >,<valor que tendra la conexion>"<<endl;
    cout<<"Ejemplo: AB,7"<<endl;
    cout<<"para dejar de ingresar conexiones entre routers ingrese la letra 'n' "<<endl;



    while (true){
        string linea,conexionRuter,ValorConex;


        cout<<"==> ";
        cin>>linea;

        if (linea == "n"){
            break;
        }
        else{
            int separador=0,longitud=linea.size();
            for (int i =0;i < longitud;i++){
                if (linea[i]==','){
                    separador++;
                }
                else if(separador==0){

                    conexionRuter+=linea[i];

                }
                else if(separador==1){
                    ValorConex+=linea[i];
                }
            }
            int cont=0;
            int longitudVector=NomConexRuter.size();
            for(int i =0;i<longitudVector;i++){
                if (NomConexRuter[i] == conexionRuter){
                    cont++;
                }

            }
            if(cont==0){
                NomConexRuter.push_back(conexionRuter);
                valConexRuter.push_back(stoi(ValorConex));
            }
            else{
                cout<<"Ingreso no valido, las conexiones estan repetidas"<<endl;
            }

        }
    }
}

void borrarConexiones(vector<string> &NomConexRuter, vector<int> &valConexRuter){
    int longitud=NomConexRuter.size();
    string datoPop;

    cout<<"para eliminar alguna conexion entre routers ingrese de la siguente manera: "<<endl;
    cout<<"<enturador+enrutador al que esta conectado>"<<endl;
    cout<<" ejemplo: AB "<<endl;
    cout<<"para dejar de borrar conexiones entre routers ingrese la letra 'n' "<<endl;

    while(true){
        for(int i=0;i<longitud;i++){
            cout<<" [ "<<NomConexRuter[i]<<" ] ";
        }
        cout<<" ==> ";
        cin>>datoPop;

        if (datoPop == "n"){
            break;
        }
        else{
            int posicion=-1;
            for (auto it = NomConexRuter.begin(); it != NomConexRuter.end(); ) {
                posicion++;
                if (*it == datoPop ) {
                    it = NomConexRuter.erase(it);
                    break;
                } else {
                    ++it;
                }
            }
            int cont=-1;
            for (auto it = valConexRuter.begin(); it != valConexRuter.end(); ) {
                cont++;
                if (cont == posicion ) {
                    it = valConexRuter.erase(it);
                    break;
                } else {
                    ++it;
                }

            }
        }
    }

}

void borrarRouter(vector<string> &NomConexRuter, vector<int> &valConexRuter){
    char datoPop;

    cout<<"para eliminar alguna conexion entre routers ingrese de la siguente manera: "<<endl;
    cout<<"<Nombre del Enrutador>"<<endl;
    cout<<" ejemplo: A "<<endl;
    cout<<"para dejar de borrar conexiones entre routers ingrese la letra 'n' "<<endl;

    while(true){
        int longitud=NomConexRuter.size();
        for(int i=0;i<longitud;i++){
            cout<<" [ "<<NomConexRuter[i]<<" ] ";
        }
        cout<<endl;
        cout<<" ==> ";
        cin>>datoPop;

        if (datoPop == 'n'){
            break;
        }
        else{
            int iter=0;

            while(iter<longitud){
            int posicion=-1;
            for (auto it = NomConexRuter.begin(); it != NomConexRuter.end(); ) {
                posicion++;
                if ((*it)[0] == datoPop or (*it)[1] == datoPop ) {
                    it = NomConexRuter.erase(it);
                    int cont=-1;
                    for (auto il = valConexRuter.begin(); il != valConexRuter.end(); ) {
                        cont++;
                        if (cont == posicion ) {
                            il = valConexRuter.erase(il);
                            break;}
                        else {
                            ++il;}
                    }
                    break;}
                 else {
                    ++it;}
            }
            iter++;}
    }
}
}
