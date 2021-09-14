#include <iostream>
#include <vector>

using namespace std;

void lecturaCamino(char router, vector<string> NomConexRuter, string caminoRecorrido, char destino,char copi,char an);

void lecturaCaminos(char router, vector<string> NomConexRuter,vector<int> valConexRuter, string caminoRecorrido, char destino,char copi,char an,int ValorCami,int &B);

int main()
{
    vector <int> valConexRuter ={4,1,10,4,3,1,10,2,1,2,1,3};
    vector <string> NomConexRuter = {"AB","AE","AC","BA","BE","BD","CA","CD","DB","DC","EA","EB"};

    char router='A',an=NomConexRuter[0][0];
    char destino='D',copi=router;

    int ValorCami=0;
    int B=0;


    string caminoRecorrido;

    cout << valConexRuter[0]<<endl;
    cout << NomConexRuter[0][0]<<endl;

    lecturaCaminos(router,NomConexRuter,valConexRuter,caminoRecorrido,destino,copi,an,ValorCami,B);





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
