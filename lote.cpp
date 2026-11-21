#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;

struct falla{
    int falla1,falla2,falla3,falla4;
};

struct lote{
    string codigo,producto,fecha;
    int cantidad;
    falla defectos;
    float promedio;
}datos;

int main(){
    int opcion,i,j,n,mejor,totalDefectos;
    ofstream archivo;
    ifstream archivo2;
    string texto;
    char rpt;
    lote lotes[100],aux;

    do{
        cout<<"\t.:MENU:."<<endl;
        cout<<"1. Registrar Lote de Produccion"<<endl;
        cout<<"2. Visualizar Lotes"<<endl;
        cout<<"3. Visualizar el Lote de Calidad"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;