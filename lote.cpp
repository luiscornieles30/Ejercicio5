
#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 100;


struct Defectos {
    int falla1;
    int falla2;
    int falla3;
    int falla4;
};

struct Lote {
    char codigo[20];
    char producto[50];
    char fecha[15];
    int cantidad;
    Defectos defectos2;
    float porcentaje;
};

Lote lotes[MAX];
int total = 0;


void limpiarBuffer() {
    cin.clear();
    cin.ignore(10000, '\n');
}
