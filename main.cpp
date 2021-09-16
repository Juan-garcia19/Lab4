#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


void lecturaCaminos(char router, vector<string> NomConexRuter,vector<int> valConexRuter, string caminoRecorrido, char destino,char copi,char an,int ValorCami,int &B);
string LectuArchi(vector<string> &NomConexRuter,vector<int> &valConexRuter);

int main()
{
    //vector <int> valConexRuter ={4,1,10,4,3,1,10,2,1,2,1,3};
    //vector <string> NomConexRuter = {"AB","AE","AC","BA","BE","BD","CA","CD","DB","DC","EA","EB"};
    vector <int> valConexRuter = {} ;
    vector <string> NomConexRuter ={} ;

    int ValorCami=0;
    int B=0;


    string caminoRecorrido;

    LectuArchi(NomConexRuter,valConexRuter);

    char router='A',an=NomConexRuter[0][0];
    char destino='D',copi=router;

  //  lecturaCaminos(router,NomConexRuter,valConexRuter,caminoRecorrido,destino,copi,an,ValorCami,B);





    return 0;
}



void lecturaCaminos(char router, vector<string> NomConexRuter,vector<int> valConexRuter, string caminoRecorrido, char destino, char copi,char an,int ValorCami,int &B){
    //copi=router;
    int longitud=NomConexRuter.size();

    string caminoMayor;

    for(int i=0;i<longitud;i++){
        if ( NomConexRuter[i][0] == copi){

            if (NomConexRuter[i][1]==router or an==NomConexRuter[i][1]){
                //cout<<"Camino no valido"<<endl;
                //caminoRecorrido="";
            }
            else if(NomConexRuter[i][1]==destino){
                caminoRecorrido+=NomConexRuter[i];
                ValorCami+=valConexRuter[i];
                //cout<<"el camino es: "<<caminoRecorrido<<" y el valor es "<<ValorCami<<endl;

                if(ValorCami>B){
                    B=ValorCami;
                    caminoMayor=caminoRecorrido;
                    cout<<"el camino es: "<<caminoRecorrido<<" y el valor es "<<ValorCami<<endl;
                }


                //copi=router;
            }
            else{
                caminoRecorrido+=NomConexRuter[i];
                ValorCami+=valConexRuter[i];

                copi=NomConexRuter[i][1];
                an=NomConexRuter[i][0];
                lecturaCaminos(router,NomConexRuter,valConexRuter,caminoRecorrido,destino,copi,an,ValorCami,B);
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

   cout << "Leyendo el archivo" << endl;
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
