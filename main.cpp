#include <iostream>
#include <vector>

using namespace std;

void lecturaCamino(char router, vector<string> NomConexRuter, string caminoRecorrido, char destino,char copi,char an);



int main()
{
    vector <int> valConexRuter ={4,1,10,4,3,1,10,2,1,2,1,3};
    vector <string> NomConexRuter = {"AB","AE","AC","BA","BE","BD","CA","CD","DB","DC","EA","EB"};

    char router='A',an=NomConexRuter[0][0];
    char destino='D',copi=router;


    string caminoRecorrido;

    cout << valConexRuter[0]<<endl;
    cout << NomConexRuter[0][0]<<endl;

    lecturaCamino(router,NomConexRuter,caminoRecorrido,destino,copi,an);





    return 0;
}

void lecturaCamino(char router, vector<string> NomConexRuter, string caminoRecorrido, char destino, char copi,char an){
    //copi=router;

    for(string n :NomConexRuter){
        if ( n[0] == copi){

            if (n[1]==router or an==n[1]){
                cout<<"Camino no valido"<<endl;
                //caminoRecorrido="";
            }
            else if(n[1]==destino){
                caminoRecorrido+=n;
                cout<<"el camino es: "<<caminoRecorrido<<endl;
                //copi=router;
            }
            else{
                caminoRecorrido+=n;
                copi=n[1];
                an=n[0];
                lecturaCamino(router,NomConexRuter,caminoRecorrido,destino,copi,an);
                copi=n[0];
                caminoRecorrido.pop_back();
                caminoRecorrido.pop_back();
            }


        }
    }
}
