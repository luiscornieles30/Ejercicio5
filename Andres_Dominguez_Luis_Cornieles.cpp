#include <iostream> //Desarrolle un programa en C++ para gestionar el control de calidad de un proceso de producción.
#include <fstream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

struct falla {
    int falla;
};

struct lote {
    string codigo, producto, fecha;
    int cantidad;
    falla defectos;
    float promedio;
    char clasificacion[30];
};

int main() {
    int opcion, i, j, totalDefectos;
    int n = 0;
    char rpt;
    lote lotes[1000], aux;

    do {
        cout << "MENU" << endl;
        cout << "1. Registrar Lote de Produccion" << endl;
        cout << "2. Visualizar Lotes" << endl;
        cout << "3. Visualizar el Lote de Calidad" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {

            case 1:
                do {
                    if (n >= 1000) {
                        cout << "\nNo hay espacio para mas lotes" << endl;
                        break;
                    }

                    cin.ignore(100000000, '\n');
                    cout << "Codigo de Lote: " << endl;
                    getline(cin, lotes[n].codigo);
                    cout << "Producto: ";
                    getline(cin, lotes[n].producto);
                    cout << "Fecha: ";
                    getline(cin, lotes[n].fecha);
                    cout << "Cantidad Producida: ";
                    cin >> lotes[n].cantidad;

                    int cFallas, f;
                    totalDefectos = 0;
                    f = 1;

                    cout << "¿Cuantas fallas son? ";
                    cin >> cFallas;

                    while (f <= cFallas) {
                        if (f <= cFallas) {
                            cout << "Tipo de falla " << f << ": ";
                            cin >> lotes[n].defectos.falla;
                            totalDefectos += lotes[n].defectos.falla;
                            f++;
                        }
                    }

                    lotes[n].promedio = (float(totalDefectos) / lotes[n].cantidad) * 100;

                    cout << "Porcentaje promedio de defectos: " << lotes[n].promedio << "%" << endl;
                    n++;

                    cout << "¿Desea Agregar otro lote? (s/n) " << endl;
                    cin >> rpt;
                    while (rpt != 's' && rpt != 'S' && rpt != 'n' && rpt != 'N') {
                        cout << "<< Coloque un caracter valido acorde a las indicaciones la proxima vez" << endl;
                        cout << "¿Desea continuar? (s/n): " << endl;
                        cin >> rpt;
                        cin.ignore(100000000, '\n');
                    }

                } while ((rpt == 'S') || (rpt == 's'));

                if (rpt == 'n' || rpt == 'N') {
                    cout << "No se agregara otro lote, gracias por usar." << endl;
                }
                break;

            case 2:
                if (n == 0) {
                    cout << "No hay lotes registrados" << endl;
                } else {
                    for (i = 0; i < n - 1; i++) {
                        for (j = 0; j < n - i - 1; j++) {
                            if (lotes[j].codigo > lotes[j + 1].codigo) {
                                aux = lotes[j];
                                lotes[j] = lotes[j + 1];
                                lotes[j + 1] = aux;
                            }
                        }
                    }

                    for (i = 0; i < n; i++) {
                        cout << "Codigo: " << lotes[i].codigo << endl;
                        cout << "Producto: " << lotes[i].producto << endl;
                        cout << "Fecha: " << lotes[i].fecha << endl;
                        cout << "Cantidad Producida: " << lotes[i].cantidad << endl;
                        cout << "Total de Defectos: " << totalDefectos << endl;
                        cout << "Porcentaje de Defectos: " << lotes[i].promedio << "%" << endl;
                    }
                }

                cout << "\n";
                system("pause");
                break;

            case 3:
                if (n == 0) {
                    cout << "No hay lotes registrados" << endl;
                } else {
                    int loteMenor = 0;

                    for (i = 1; i < n; i++) {
                        if (lotes[i].promedio < lotes[loteMenor].promedio) {
                            loteMenor = i;
                        }
                    }

                    if (lotes[loteMenor].promedio <= 0.5) {
                        strcpy(lotes[loteMenor].clasificacion, "Aceptacion Maxima");
                    } else if (lotes[loteMenor].promedio <= 2.0) {
                        strcpy(lotes[loteMenor].clasificacion, "Aceptacion Estandar");
                    } else {
                        strcpy(lotes[loteMenor].clasificacion, "Revision Obligatoria");
                    }

                    cout << "===== LOTE DE CALIDAD =====" << endl;
                    cout << "Codigo de Lote: " << lotes[loteMenor].codigo << endl;
                    cout << "Producto: " << lotes[loteMenor].producto << endl;
                    cout << "Porcentaje promedio de defectos: "
                         << lotes[loteMenor].promedio << "%" << endl;
                    cout << "Clasificacion: "
                         << lotes[loteMenor].clasificacion << endl;
                }

                system("pause");
                break;

            case 4:
                cout << "Programa Finalizado" << endl;
                break;

            default:
                cout << "Porfavor seleccione una opcion valdia para el programa." << endl;
                break;
        }
        system("cls");
    } while (opcion != 4);

    system("pause");
    return 0;
}