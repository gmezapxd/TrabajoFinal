#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
using namespace System;
struct jugador
{
    char* nombre = new char[20];
    char ficha;
    int color;
    int direccion;
    int x, y;
    int cantidadfichas = 12;
    int movimientos = 0;
    char reina;


};
void ingresarDatos(jugador* jugadores)
{
    for (int i = 0; i < 2; i++)
    {
        Console::ForegroundColor = ConsoleColor::Cyan;
        cout << "Ingrese nombre jugador " << i + 1 << ": "; cin >> jugadores[i].nombre;
        cout << "Ingrese ficha jugador " << i + 1 << ": "; cin >> jugadores[i].ficha;
        cout << "Ingrese color jugador " << i + 1 << "(del 0 al 17): "; cin >> jugadores[i].color;
        cout << endl;
    }
}
void mostraryrellenarTablero(jugador* jugadores, int tablero[8][8])
{
    cout << "Cantidad de fichas de " << jugadores[0].nombre << " : " << jugadores[0].cantidadfichas << endl;
    cout << "Cantidad de fichas de " << jugadores[1].nombre << " : " << jugadores[1].cantidadfichas << endl;
    cout << "Numero de movimientos de " << jugadores[0].nombre << " : " << jugadores[0].movimientos << endl;
    cout << "Numero de movimientos de " << jugadores[1].nombre << " : " << jugadores[1].movimientos << endl;
    for (int z = 0; z < 8; z++)
    {
        Console::ForegroundColor = ConsoleColor::DarkRed;
        cout << "  " << z;
    }
    cout << endl;
    for (int i = 0; i < 8; i++)
    {
        Console::BackgroundColor = ConsoleColor::Black;
        Console::ForegroundColor = ConsoleColor::DarkRed;
        cout << i;
        cout << " ";
        for (int j = 0; j < 8; j++)
        {
            switch (tablero[i][j])
            {
            case 1:
                Console::BackgroundColor = ConsoleColor(8);
                cout << "   ";
                break;
            case 2:
                Console::BackgroundColor = ConsoleColor(15);
                Console::ForegroundColor = (ConsoleColor)jugadores[1].color;
                cout << " ";
                cout << jugadores[1].ficha;
                cout << " ";
                break;
            case 3:
                Console::BackgroundColor = ConsoleColor(15);
                Console::ForegroundColor = (ConsoleColor)jugadores[0].color;
                cout << " ";
                cout << jugadores[0].ficha;
                cout << " ";
                break;
            case 4:
                Console::BackgroundColor = ConsoleColor(15);
                cout << "   ";
                break;
            case 6:
                jugadores[0].reina = toupper(jugadores[0].ficha);
                Console::BackgroundColor = ConsoleColor(15);
                Console::ForegroundColor = (ConsoleColor)jugadores[0].color;
                cout << " ";
                cout << jugadores[0].reina;
                cout << " ";
                break;
            case 8:
                jugadores[1].reina = toupper(jugadores[1].ficha);
                cout << jugadores[1].reina;
            }

        }
        cout << endl;
    }
}
void movimientojugador1(jugador* jugadores, int tablero[8][8])
{
    Console::ForegroundColor = (ConsoleColor)jugadores[0].color;
    Console::BackgroundColor = ConsoleColor::Black;
    cout << endl << endl;
    cout << " Turno de " << jugadores[0].nombre << ":" << endl;
    cout << " SELECCIONE FICHA: " << endl;
    do
    {
        cout << " Ingrese fila: ";
        cin >> jugadores[0].x;
        cout << " Ingrese columna: ";
        cin >> jugadores[0].y;
        if (tablero[jugadores[0].x][jugadores[0].y] != 3)
            cout << " [ERROR] NO HAY FICHA VUELVA A SELECCIONAR" << endl;
        if (((tablero[jugadores[0].x - 1][jugadores[0].y - 1] == 3) && (tablero[jugadores[0].x - 1][jugadores[0].y + 1] == 3))
            || (jugadores[0].y == 7 && tablero[jugadores[0].x - 1][jugadores[0].y - 1] == 3) || (jugadores[0].y == 0 && tablero[jugadores[0].x - 1][jugadores[0].y + 1] == 3) ||
            ((tablero[jugadores[0].x - 1][jugadores[0].y - 1] == 2 && tablero[jugadores[0].x - 2][jugadores[0].y - 2] == 2) &&
                (tablero[jugadores[0].x - 1][jugadores[0].y + 1] == 2 && tablero[jugadores[0].x - 2][jugadores[0].y + 2] == 2)))
            cout << " [ERROR] TU FICHA ESTA BLOQUEADA" << endl;
    } while (tablero[jugadores[0].x][jugadores[0].y] != 3 || (((tablero[jugadores[0].x - 1][jugadores[0].y - 1] == 3) && (tablero[jugadores[0].x - 1][jugadores[0].y + 1] == 3)) ||
        (jugadores[0].y == 7 && tablero[jugadores[0].x - 1][jugadores[0].y - 1] == 3) || (jugadores[0].y == 0 && tablero[jugadores[0].x - 1][jugadores[0].y + 1] == 3)) ||
        ((tablero[jugadores[0].x - 1][jugadores[0].y - 1] == 2 && tablero[jugadores[0].x - 2][jugadores[0].y - 2] == 2) &&
            (tablero[jugadores[0].x - 1][jugadores[0].y + 1] == 2 && tablero[jugadores[0].x - 2][jugadores[0].y + 2] == 2)));
    cout << " SELECCIONE MOVIMIENTO: [1]IZQUIERDA-ARRIBA | [2] DERECHA-ARRIBA" << endl;
    do {
        cin >> jugadores[0].direccion;
        if (jugadores[0].direccion < 1 || jugadores[0].direccion > 2)
            cout << " ESCOJA UNA DIRECCION DISPONIBLE: " << endl;
        if ((jugadores[0].y == 7 && jugadores[0].direccion == 2) || (jugadores[0].y == 0 && jugadores[0].direccion == 1))
            cout << " [ERROR] TE SALES DEL TABLERO" << endl;
        if ((jugadores[0].direccion == 1 && tablero[jugadores[0].x - 1][jugadores[0].y - 1] == 3) || (jugadores[0].direccion == 2 && tablero[jugadores[0].x - 1][jugadores[0].y + 1] == 3))
            cout << " [ERROR] ESTA CASILLA ESTA OCUPADA POR UNA FICHA PROPIA ELIJA OTRA DIRECCION " << endl;
        if ((jugadores[0].direccion == 1 && tablero[jugadores[0].x - 1][jugadores[0].y - 1] == 2 && tablero[jugadores[0].x - 2][jugadores[0].y - 2] == 2) ||
            (jugadores[0].direccion == 2 && tablero[jugadores[0].x - 1][jugadores[0].y + 1] == 2 && tablero[jugadores[0].x - 2][jugadores[0].y + 2] == 2))
            cout << "[ERROR]  NO PUEDES COMER,VUELVE A ELEGIR DIRECCION:";
    } while ((jugadores[0].direccion < 1 || jugadores[0].direccion>2) || ((jugadores[0].y == 7 && jugadores[0].direccion == 2) || (jugadores[0].y == 0 && jugadores[0].direccion == 1)) ||
        ((jugadores[0].direccion == 1 && tablero[jugadores[0].x - 1][jugadores[0].y - 1] == 3) || (jugadores[0].direccion == 2 && tablero[jugadores[0].x - 1][jugadores[0].y + 1] == 3)) ||
        ((jugadores[0].direccion == 1 && tablero[jugadores[0].x - 1][jugadores[0].y - 1] == 2 && tablero[jugadores[0].x - 2][jugadores[0].y - 2] == 2) ||
            (jugadores[0].direccion == 2 && tablero[jugadores[0].x - 1][jugadores[0].y + 1] == 2 && tablero[jugadores[0].x - 2][jugadores[0].y + 2] == 2)));

    if (tablero[jugadores[0].x][jugadores[0].y] == 3 && jugadores[0].direccion == 1 && tablero[jugadores[0].x - 1][jugadores[0].y - 1] == 4)
    {
        tablero[jugadores[0].x][jugadores[0].y] = 4;
        if (tablero[jugadores[0].x - 1][jugadores[0].y - 1] == tablero[0][jugadores[0].y - 1])
            tablero[jugadores[0].x - 1][jugadores[0].y - 1] = 6;
        else tablero[jugadores[0].x - 1][jugadores[0].y - 1] = 3;
    }
    else if (tablero[jugadores[0].x][jugadores[0].y] == 3 && jugadores[0].direccion == 2 && tablero[jugadores[0].x - 1][jugadores[0].y + 1] == 4)
    {
        tablero[jugadores[0].x][jugadores[0].y] = 4;
        if (tablero[jugadores[0].x - 1][jugadores[0].y + 1] == tablero[0][jugadores[0].y + 1])
            tablero[jugadores[0].x - 1][jugadores[0].y + 1] = 6;
        else
            tablero[jugadores[0].x - 1][jugadores[0].y + 1] = 3;
    }
    else if (tablero[jugadores[0].x][jugadores[0].y] == 3 && jugadores[0].direccion == 1 && tablero[jugadores[0].x - 1][jugadores[0].y - 1] == 2 && tablero[jugadores[0].x - 2][jugadores[0].y - 2] == 4)
    {
        tablero[jugadores[0].x][jugadores[0].y] = 4;
        tablero[jugadores[0].x - 1][jugadores[0].y - 1] = 4;
        if (tablero[jugadores[0].x - 2][jugadores[0].y - 2] == tablero[0][jugadores[0].y - 2])
            tablero[jugadores[0].x - 2][jugadores[0].y - 2] = 6;
        else
            tablero[jugadores[0].x - 2][jugadores[0].y - 2] = 3;
        jugadores[1].cantidadfichas = jugadores[1].cantidadfichas - 1;
    }

    else if (tablero[jugadores[0].x][jugadores[0].y] == 3 && jugadores[0].direccion == 2 && tablero[jugadores[0].x - 1][jugadores[0].y + 1] == 2 && tablero[jugadores[0].x - 2][jugadores[0].y + 2] == 4)
    {
        tablero[jugadores[0].x][jugadores[0].y] = 4;
        tablero[jugadores[0].x - 1][jugadores[0].y + 1] = 4;
        if (tablero[jugadores[0].x - 2][jugadores[0].y + 2] == tablero[0][jugadores[0].y + 2])
            tablero[jugadores[0].x - 2][jugadores[0].y + 2] = 6;
        else
            tablero[jugadores[0].x - 2][jugadores[0].y + 2] = 3;
        jugadores[1].cantidadfichas = jugadores[1].cantidadfichas - 1;

    }
    jugadores[0].movimientos++;
}
void movimientojugador2(jugador* jugadores, int tablero[8][8])
{
    Console::ForegroundColor = (ConsoleColor)jugadores[1].color;
    Console::BackgroundColor = ConsoleColor::Black;
    cout << endl << endl;
    cout << " Turno de " << jugadores[1].nombre << ":" << endl;
    cout << " SELECCIONE FICHA " << endl;
    do
    {
        cout << " Ingrese fila: ";
        cin >> jugadores[1].x;
        cout << " Ingrese columna: ";
        cin >> jugadores[1].y;
        if (tablero[jugadores[1].x][jugadores[1].y] != 2)
            cout << " [ERROR] NO HAY FICHA VUELVA A SELECCIONAR" << endl;
        if (((tablero[jugadores[1].x + 1][jugadores[1].y - 1] == 2) && (tablero[jugadores[1].x + 1][jugadores[1].y + 1] == 2))
            || (jugadores[1].y == 7 && tablero[jugadores[1].x + 1][jugadores[1].y - 1] == 2) || (jugadores[1].y == 0 && tablero[jugadores[1].x + 1][jugadores[1].y + 1] == 2) ||
            ((tablero[jugadores[1].x + 1][jugadores[1].y + 1] == 3 && tablero[jugadores[1].x + 2][jugadores[1].y + 2] == 3) &&
                (tablero[jugadores[1].x + 1][jugadores[1].y - 1] == 3 && tablero[jugadores[1].x + 2][jugadores[1].y - 2] == 3)))
            cout << " [ERROR] TU FICHA ESTA BLOQUEADA" << endl;
    } while (tablero[jugadores[1].x][jugadores[1].y] != 2 || (((tablero[jugadores[1].x + 1][jugadores[1].y - 1] == 2) && (tablero[jugadores[1].x + 1][jugadores[1].y + 1] == 2)) ||
        (jugadores[1].y == 7 && tablero[jugadores[1].x + 1][jugadores[1].y + 1] == 2) || (jugadores[1].y == 0 && tablero[jugadores[1].x + 1][jugadores[1].y - 1] == 2)) ||
        ((tablero[jugadores[1].x + 1][jugadores[1].y + 1] == 3 && tablero[jugadores[1].x + 2][jugadores[1].y + 2] == 3) &&
            (tablero[jugadores[1].x + 1][jugadores[1].y - 1] == 3 && tablero[jugadores[1].x + 2][jugadores[1].y - 2] == 3)));

    cout << " SELECCIONE MOVIMIENTO: [1] IZQUIERDA - ABAJO | [2] DERECHA-ABAJO" << endl;
    do {
        cin >> jugadores[1].direccion;
        if (jugadores[1].direccion < 1 || jugadores[1].direccion > 2)
            cout << " ESCOJA UNA DIRECCION DISPONIBLE: " << endl;
        if ((jugadores[1].y == 7 && jugadores[1].direccion == 2) || (jugadores[1].y == 0 && jugadores[1].direccion == 1))
            cout << " [ERROR] TE SALES DEL TABLERO" << endl;
        if ((jugadores[1].direccion == 2 && tablero[jugadores[1].x + 1][jugadores[1].y + 1] == 2) || (jugadores[1].direccion == 1 && tablero[jugadores[1].x + 1][jugadores[1].y - 1] == 2))
            cout << " [ERROR] ESTA CASILLA ESTA OCUPADA POR UNA FICHA PROPIA ELIJA OTRA DIRECCION" << endl;
        if ((jugadores[1].direccion == 2 && tablero[jugadores[1].x + 1][jugadores[1].y + 1] == 3 && tablero[jugadores[1].x + 2][jugadores[1].y + 2] == 3) ||
            (jugadores[1].direccion == 1 && tablero[jugadores[1].x + 1][jugadores[1].y - 1] == 3 && tablero[jugadores[1].x + 2][jugadores[1].y - 2] == 3))
            cout << "[ERROR]  NO PUEDES COMER,VUELVE A ELEGIR DIRECCION:";
    } while ((jugadores[1].direccion < 1 || jugadores[1].direccion > 2) || ((jugadores[1].y == 7 && jugadores[1].direccion == 2) || (jugadores[1].y == 0 && jugadores[1].direccion == 1)) ||
        ((jugadores[1].direccion == 2 && tablero[jugadores[1].x + 1][jugadores[1].y + 1] == 2) || (jugadores[1].direccion == 1 && tablero[jugadores[1].x + 1][jugadores[1].y - 1] == 2)) ||
        ((jugadores[1].direccion == 2 && tablero[jugadores[1].x + 1][jugadores[1].y + 1] == 3 && tablero[jugadores[1].x + 2][jugadores[1].y + 2] == 3) ||
            (jugadores[1].direccion == 1 && tablero[jugadores[1].x + 1][jugadores[1].y - 1] == 3 && tablero[jugadores[1].x + 2][jugadores[1].y - 2] == 3)));

    if (tablero[jugadores[1].x][jugadores[1].y] == 2 && jugadores[1].direccion == 2 && tablero[jugadores[1].x + 1][jugadores[1].y + 1] == 4)
    {
        tablero[jugadores[1].x][jugadores[1].y] = 4;
        tablero[jugadores[1].x + 1][jugadores[1].y + 1] = 2;
    }
    if (tablero[jugadores[1].x][jugadores[1].y] == 2 && jugadores[1].direccion == 1 && tablero[jugadores[1].x + 1][jugadores[1].y - 1] == 4)
    {
        tablero[jugadores[1].x][jugadores[1].y] = 4;
        tablero[jugadores[1].x + 1][jugadores[1].y - 1] = 2;
    }
    if (tablero[jugadores[1].x][jugadores[1].y] == 2 && jugadores[1].direccion == 2 && tablero[jugadores[1].x + 1][jugadores[1].y + 1] == 3 && tablero[jugadores[1].x + 2][jugadores[1].y + 2] == 4)
    {
        tablero[jugadores[1].x][jugadores[1].y] = 4;
        tablero[jugadores[1].x + 1][jugadores[1].y + 1] = 4;
        tablero[jugadores[1].x + 2][jugadores[1].y + 2] = 2;
        jugadores[0].cantidadfichas = jugadores[0].cantidadfichas - 1;
    }
    if (tablero[jugadores[1].x][jugadores[1].y] == 2 && jugadores[1].direccion == 1 && tablero[jugadores[1].x + 1][jugadores[1].y - 1] == 3 && tablero[jugadores[1].x + 2][jugadores[1].y - 2] == 4)
    {
        tablero[jugadores[1].x][jugadores[1].y] = 4;
        tablero[jugadores[1].x + 1][jugadores[1].y - 1] = 4;
        tablero[jugadores[1].x + 2][jugadores[1].y - 2] = 2;
        jugadores[0].cantidadfichas = jugadores[0].cantidadfichas - 1;
    }

    jugadores[1].movimientos++;
}
void mostrarintrucciones()
{
    cout << "\t\t-------------------- INSTRUCCIONES --------------------" << endl;
    cout << "* Cada jugador controla las piezas de un color situadas al comienzo a cada lado del tablero. Empieza el juego las blancas.\n" << endl;
    cout << "* Los movimientos se hacen alternativamente, uno por jugador, en diagonal, una sola casilla y en sentido de avance, o sea, hacia el campo del oponente.\n" << endl;
    cout << "* Si un jugador consigue llevar una de sus fichas al lado contrario del tablero cambiará dicho peón por una dama o reina (dos fichas del mismo color una encima de otra).\n" << endl;
    cout << "* La dama o reina se mueve también en diagonal, pero puede hacerlo hacia delante y hacia atrás. Según las opciones de mesa puede avanzar una casilla como el peón o recorrer cualquier número de casillas mientras estén libres. Nunca podrá saltar por encima de sus propias piezas o dos piezas contiguas.\n" << endl;
    cout << "* Una pieza puede capturar otra si puede saltar por encima de ella siempre en dirección de ataque y en diagonal y caer en la casilla inmediatamente detrás de aquella\n" << endl;
    cout << "* Además, las damas pueden capturar en cualquier dirección. Si pueden mover más de una casilla (véanse las opciones de mesa), pueden capturar cualquier ficha que esté en la misma diagonal siempre y cuando se cumplan las reglas anteriores.\n" << endl;
    cout << "* La captura es obligatoria. Si una o más piezas están en situación de realizar capturas, será obligatorio realizar tal captura, no pudiendo optar por mover otra pieza.\n" << endl;
    cout << "* Una vez realizada una captura, tanto un peón como una dama deben volver a capturar si es posible según las reglas anteriores y en el mismo turno del jugador, y así sucesivamente.\n" << endl;
    cout << "* Finaliza la partida cuando un jugador abandona, se queda sin fichas o estas no tienen posibilidad de movimiento (bloqueo o ahogada).\n" << endl;
    cout << "* Se llega a tablas o empate cuando ambos jugadores lo pactan.\n" << endl;
}
void mostrarOpciones(int& opcion)
{
    cout << "\t\t\t1. Iniciar juego" << endl;
    cout << "\t\t\t2. Salir" << endl;
    cin >> opcion;
}
void mostrarbanner(jugador* jugadores)
{
    char  c = 219;
    int banner[9][60] = {
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,1,1,1,1,0,1,1,1,0,1,0,0,0,1,1,0,1,1,1,0,1,1,0,1,1,1,0,0,0,1,1,0,0,1,1,1,0,0,1,1,1,0,1,1,1,0,0,1,0,1,0,1,0,0,0,0,0,0,0 },
        { 0,1,1,0,0,0,1,0,0,0,1,0,0,0,1,1,0,1,0,0,0,1,1,0,1,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0 },
        { 0,1,1,1,0,0,1,1,0,0,1,0,0,0,1,1,0,1,0,0,0,1,1,0,1,0,0,1,0,1,1,1,1,0,1,0,0,1,0,1,1,0,0,1,1,1,0,0,1,0,1,0,1,0,0,0,0,0,0,0 },
        { 0,1,1,0,0,0,1,0,0,0,1,0,0,0,1,1,0,1,0,0,0,1,1,0,1,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,1,1,0,0,0,1,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,0,1,1,1,0,0,1,0,0,1,0,1,1,1,0,0,1,1,1,0,1,1,1,0,0,1,0,1,0,1,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
    for (int i = 0; i < 9; i++)
    {
        cout << "\t\t\t";
        for (int j = 0; j < 60; j++) {
            if (banner[i][j] == 1) {

                Console::ForegroundColor = ConsoleColor::Blue;
                cout << c;
            }
            else cout << ' ';
        }
        cout << endl;
    }
    Console::ForegroundColor = ConsoleColor::Blue;
    if (jugadores[0].cantidadfichas == 0)
        cout << "\t\t\t EL GANADOR ES " << jugadores[1].nombre;
    if (jugadores[1].cantidadfichas == 0)
        cout << "\t\t\t EL GANADOR ES " << jugadores[0].nombre;
}
void imprimirLogoyCreditos()
{
    int opcion;
    int logo[13][41] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                       {0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0},
                       {0,1,1,0,0,0,1,1,0,0,1,0,0,0,1,0,0,1,1,1,0,1,1,1,0,0,1,0,0,0,1,0,0,1,1,0,0,0,0,1,0},
                       {0,1,1,0,0,0,0,1,0,0,1,0,0,0,1,0,0,1,1,0,1,0,1,1,0,0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0},
                       {0,1,1,0,0,0,0,1,0,0,1,0,0,0,1,0,0,1,1,0,0,0,1,1,0,0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0},
                       {0,1,1,0,0,0,0,1,0,0,1,0,0,0,1,0,0,1,1,0,0,0,1,1,0,0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0},
                       {0,1,1,0,0,0,0,1,0,0,1,0,0,0,1,0,0,1,1,0,0,0,1,1,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1,0,0},
                       {0,1,1,0,0,0,0,1,0,0,1,0,0,0,1,0,0,1,1,0,0,0,1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,1,0},
                       {0,1,1,0,0,0,0,1,0,0,1,1,1,1,1,0,0,1,1,0,0,0,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,1,0},
                       {0,1,1,0,0,0,1,1,0,0,1,0,0,0,1,0,0,1,1,0,0,0,1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,1,0},
                       {0,1,1,0,0,0,1,1,0,0,1,0,0,0,1,0,0,1,1,0,0,0,1,1,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,1,0},
                       {0,1,1,1,1,1,1,0,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,0,1,1,1,1,1,0,0},
                       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };
    for (int i = 0; i < 13; i++)
    {
        Console::SetCursorPosition(19, 3);
        for (int j = 0; j < 41; j++) {
            if (logo[i][j] == 1) {
                Console::SetCursorPosition(19 + j, 3 + i);
                Console::ForegroundColor = ConsoleColor::DarkMagenta;
                cout << char(219);
            }
            else cout << " ";
        }
        cout << endl;
    }
    Console::ForegroundColor = ConsoleColor::DarkYellow;
    Console::SetCursorPosition(20, 15);
    cout << "Hecho por Arian, Gabriel y Sebastian" << endl;
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(20, 20);
    cout << endl;
}
void logoUPC() {
    int upc[20][40] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,0,1,0,0,0,0,0,0},
                       {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0},
                       {0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };
    for (int i = 0; i < 20; i++) {
        cout << "\t\t\t";
        for (int j = 0; j < 40; j++) {
            if (upc[i][j] == 1) {

                Console::ForegroundColor = ConsoleColor::Red;
                cout << '*';
            }
            else cout << ' ';
        }
        cout << endl;
    }
}
bool ganador(jugador* jugadores)
{
    if ((jugadores[0].cantidadfichas == 0) || (jugadores[1].cantidadfichas == 0))

        return true;
    return false;
}

bool repetirJ1(jugador* jugadores, int tablero[8][8]) {
    if (
        (tablero[jugadores[0].x - 3][jugadores[0].y - 3] == 2 && tablero[jugadores[0].x - 4][jugadores[0].y - 4] == 4) ||
        (tablero[jugadores[0].x - 3][jugadores[0].y - 1] == 2 && tablero[jugadores[0].x - 4][jugadores[0].y] == 4) ||
        (tablero[jugadores[0].x - 3][jugadores[0].y + 1] == 2 && tablero[jugadores[0].x - 4][jugadores[0].y] == 4) ||
        (tablero[jugadores[0].x - 3][jugadores[0].y + 3] == 2 && tablero[jugadores[0].x - 4][jugadores[0].y + 4] == 4)
        ) {
        Console::ForegroundColor = ConsoleColor::White;
        cout << "SELECCIONA LA MISMA FICHA !!!!" << endl;
        cout << "Vuelve a comer una ficha!!!!!" << endl;
        return true;
    }
    return false;
}
bool repetirJ2(jugador* jugadores, int tablero[8][8])
{
    if (
        (tablero[jugadores[1].x + 3][jugadores[1].y - 1] == 3 && tablero[jugadores[1].x + 4][jugadores[1].y] == 4) ||
        (tablero[jugadores[1].x + 3][jugadores[1].y + 1] == 3 && tablero[jugadores[1].x + 4][jugadores[1].y] == 4) ||
        (tablero[jugadores[1].x + 3][jugadores[1].y - 3] == 3 && tablero[jugadores[1].x + 4][jugadores[1].y - 4] == 4) ||
        (tablero[jugadores[1].x + 3][jugadores[1].y + 3] == 3 && tablero[jugadores[1].x + 4][jugadores[1].y + 4] == 4)
        ) {
        Console::ForegroundColor = ConsoleColor::White;
        cout << "SELECCIONA LA MISMA FICHA !!!!" << endl;
        cout << "Vuelve a comer una ficha!!!!!" << endl;
        return true;
    }
    return false;
}
int main()
{
    int ganadores;
    int tablero[8][8] = {
                        {1,2,1,2,1,2,1,2},
                        {2,1,2,1,2,1,2,1},
                        {1,2,1,2,1,2,1,2},
                        {4,1,4,1,4,1,4,1},
                        {1,4,1,4,1,4,1,4},
                        {3,1,3,1,3,1,3,1},
                        {1,3,1,3,1,3,1,3},
                        {3,1,3,1,3,1,3,1} };
    int opcion;
    Console::SetWindowSize(90, 30);
    Console::CursorVisible = false;
    jugador* jugadores = new jugador[2];
    logoUPC();
    _sleep(2000);
    Console::Clear();
    imprimirLogoyCreditos();
    mostrarOpciones(opcion);
    Console::Clear();
    switch (opcion)
    {
    case 1: mostrarintrucciones();
        getch();






         

        Console::Clear();
        ingresarDatos(jugadores);
        Console::Beep();
        while (ganador(jugadores) == false)
        {
            do {
                mostraryrellenarTablero(jugadores, tablero);
                movimientojugador1(jugadores, tablero);
                Console::Clear();
            } while (repetirJ1(jugadores, tablero) == true);
            do 
            {
                mostraryrellenarTablero(jugadores, tablero);
                movimientojugador2(jugadores, tablero);
                Console::Clear();
            } while (repetirJ2(jugadores, tablero) == true);
        }
        if (ganador(jugadores) == true)
            mostrarbanner(jugadores);
        break;
    case 2:
        Console::Clear();
        cout << endl << endl << endl;
        cout << "\t\t\tGRACIAS POR JUGAR ADIOS";
        break;
    }
    getch();
    return 0;
}