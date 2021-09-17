#include <iostream>
#include <fstream>
#include <map>
#include "enrutador.h"
#include "modelarred.h"

using namespace std;


int main()
{

    Enrutador ruter;
    ModelarRed Manejored;

    unsigned int opcion=0;


    cout<<"como desea optener la red de enrutadores?"<<endl;
    cout<<"introduzca el numero que le aparece en pantalla para ingresar: "<<endl;
    cout<<"0. archivo.txt"<<endl;
    cout<<"1.ingresarlo a mano"<<endl;
    cout<<">> ";cin>>opcion;
    if(opcion ==0){
        ruter.LectuArchi();
        ruter.Actualizacion();
    }
    else if(opcion == 1){
        ruter.IngresoManualRouters();
        ruter.Actualizacion();
    }

    while(true){

        cout<<"introduzca el numero que le aparece en pantalla para ingresar: "<<endl;
        cout<<"1. Ingresar nuevas conexiones o routers"<<endl;
        cout<<"2. Eliminar conexiones entre routers"<<endl;
        cout<<"3. Eliminar routers"<<endl;;
        cout<<"4. Cambio el valor de la conexion entre routers"<<endl;;
        cout<<"5. mostrar el mejor camino entre un enrutador y otro"<<endl;
        cout<<"0. salir;"<<endl;
        cout<<"==> ";cin>>opcion;

        switch(opcion){
            case 0:
               break;

            break;
            case 1:
                Manejored.setNomConexRuter(ruter.getNomConexRuter());
                Manejored.setValConexRuter(ruter.getValConexRuter());
                Manejored.setRouters(ruter.getRouters());

                Manejored.IngresoManualRouters();
                ruter.setNomConexRuter(Manejored.getNomConexRuter());
                ruter.setValConexRuter(Manejored.getValConexRuter());
                ruter.setRouters(Manejored.getRouters());
                ruter.Actualizacion();

            break;

            case 2:
                Manejored.setNomConexRuter(ruter.getNomConexRuter());
                Manejored.setValConexRuter(ruter.getValConexRuter());
                Manejored.setRouters(ruter.getRouters());

                Manejored.borrarConexiones();
                ruter.setNomConexRuter(Manejored.getNomConexRuter());
                ruter.setValConexRuter(Manejored.getValConexRuter());
                ruter.setRouters(Manejored.getRouters());
                ruter.Actualizacion();

            break;

            case 3:
                Manejored.setNomConexRuter(ruter.getNomConexRuter());
                Manejored.setValConexRuter(ruter.getValConexRuter());
                Manejored.setRouters(ruter.getRouters());

                Manejored.borrarRouter();
                ruter.setNomConexRuter(Manejored.getNomConexRuter());
                ruter.setValConexRuter(Manejored.getValConexRuter());
                ruter.setRouters(Manejored.getRouters());
                ruter.Actualizacion();

            break;

            case 4:
                Manejored.setNomConexRuter(ruter.getNomConexRuter());
                Manejored.setValConexRuter(ruter.getValConexRuter());
                Manejored.setRouters(ruter.getRouters());

                Manejored.cambioValorConex();
                ruter.setNomConexRuter(Manejored.getNomConexRuter());
                ruter.setValConexRuter(Manejored.getValConexRuter());
                ruter.setRouters(Manejored.getRouters());
                ruter.Actualizacion();

            break;

            case 5:
                char Inicio;
                string destino;
                Manejored.setNomConexRuter(ruter.getNomConexRuter());
                Manejored.setValConexRuter(ruter.getValConexRuter());
                Manejored.setRouters(ruter.getRouters());
                cout<<"ingrese el router de partida: ";
                cin>>Inicio;
                cout<<"ingrese el router de destino: ";
                cin>>destino;

                Manejored.mostrarCamino(Inicio, destino);
                ruter.setNomConexRuter(Manejored.getNomConexRuter());
                ruter.setValConexRuter(Manejored.getValConexRuter());
                ruter.setRouters(Manejored.getRouters());
                ruter.Actualizacion();

            break;

        }

    }



    return 0;
}



