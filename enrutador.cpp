#include "enrutador.h"

Enrutador::Enrutador()
{

}

void Enrutador::lecturaCaminos(char router, string caminoRecorrido, char destino, char copi, char an, int ValorCami, int &B, string &caminoMayor)
{
    int longitud=NomConexRuter.size();

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
                lecturaCaminos(router,caminoRecorrido,destino,copi,an,ValorCami,B,caminoMayor);
                copi=NomConexRuter[i][0];

                ValorCami-=valConexRuter[i];
                caminoRecorrido.pop_back();
                caminoRecorrido.pop_back();
            }
        }
    }
}

void Enrutador::Actualizacion()
{
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

            lecturaCaminos(DefinicionR->first,caminoRecorrido,parametros->first,copi,an,ValorCami,B,caminoMayor);
            routers[DefinicionR->first].push_back(claveInter);
            if (B==100){
                B=0;
            }
            routers[DefinicionR->first].push_back(to_string(B));
            routers[DefinicionR->first].push_back(caminoMayor);


        }
    }

}
