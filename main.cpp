#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string>
using namespace std;


void lecturaCaminos(char router, vector<string> NomConexRuter,vector<int> valConexRuter, string caminoRecorrido, char destino,char copi,char an,int ValorCami,int &B,string &caminoMayor);
string LectuArchi(vector<string> &NomConexRuter,vector<int> &valConexRuter);

int main()
{
    vector <int> valConexRuter ={4,10,4,3,1,10,2,1,2,1,3,1};
    vector <string> NomConexRuter = {"AB","AC","BA","BE","BD","CA","CD","DB","DC","EA","EB","AE"};
    string caminoMayor;
    //vector <int> valConexRuter = {} ;
    //vector <string> NomConexRuter ={} ;

    //int ValorCami=0;
    //int B=100;


    map <char,vector<string>> routers={};

    vector <char> Ruter={};






    //LectuArchi(NomConexRuter,valConexRuter);

    //char router='C',an='C';
    //char destino='D',copi=router;
    string caminoRecorrido;

    //lecturaCaminos(router,NomConexRuter,valConexRuter,caminoRecorrido,destino,copi,an,ValorCami,B,caminoMayor);

    for (auto router:NomConexRuter){
        routers[router[0]]={};
    }

    for (auto DefinicionR:routers){
        for (auto parametros:routers){

            char copi=DefinicionR.first, an=DefinicionR.first;
            int ValorCami=0;
            int B=100;
            string caminoRecorrido,claveInter,Valor;
            string caminoMayor;
            claveInter.push_back(parametros.first);

            lecturaCaminos(DefinicionR.first,NomConexRuter,valConexRuter,caminoRecorrido,parametros.first,copi,an,ValorCami,B,caminoMayor);
            routers[DefinicionR.first].push_back(claveInter);
            routers[DefinicionR.first].push_back(to_string(B));
            routers[DefinicionR.first].push_back(caminoMayor);


        }
    }
    routers['A'].push_back("B");
    routers['A'].push_back("7");

    return 0;
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

   // Se comprueba si el archivo fue abierto exitosamente
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
