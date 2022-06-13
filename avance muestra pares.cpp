#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;


//variables

int contador3=0;// solo funciona cuando el jugador gano sin perder intentos
int cordx=0;
int cordy=0;
int intentos=10;
int contador=0;
int contadorpares=10;
int matrizmemo[5][4]={0};
int matrizoculto[5][4]={0};
int guarda;//variable de "memoria"

//prototipos

void generadorDePares();//genera los pares de la matriz
void imprimeMatriz();//imprime la matriz
void generadorDeOcultos ();//"voltea las cartas"
void elegirCarta();//te permite elegir la carta con coordenadas
void volteaCarta(); //imprimne la carta dentro de la matriz de ocultos
void comparador ();//compara las dos cartas recientenmente volteadas
void contadorIntentos ();//contador de intentos
void pares ();//contador de pares
int verificador (); //Verifica si estan todas las cartas volteadas o no
void ganaste ();// pantalla que sale cuando el jugador gano sin perder o volteo todas las cartas antes de perder todos los intentos
void perdiste();// pantalla que sale cuando perdiste cuando el jugador cuando se le acabaron los inentos y no volteo todas las cartas
int main()
{
    cout<<"Hola usuario, estas son sus cartas"<<endl;
    Sleep(2000);
    generadorDePares();
    imprimeMatriz();
    Sleep(2000);
    cout<< "Vamos a voltear todas las cartas"<<endl;
    generadorDeOcultos();
    Sleep(2000);
    do
    {
    elegirCarta();
    Sleep (2000);
    volteaCarta();
    Sleep (2000);
    elegirCarta ();
    Sleep (2000);
    volteaCarta();
    Sleep(2000);
    comparador();
    contadorIntentos();
    pares ();
    }
    while (intentos>0);
    if (verificador()==0 || contador3==10)
    {
        ganaste();
    }
    else if (verificador()==1)
    {
        perdiste();
    }





    return 0;
}
void perdiste ()
{
    cout<<endl<<"perdiste :("<<endl;

}
void ganaste ()
{
    cout<<endl<<"ganaste!!!!!"<<endl;
}
void pares()
{
    cout<<endl<<"Quedan "<<contadorpares<<" pares"<<endl;
}
void contadorIntentos ()
{
    cout<<endl<<"Le restan "<<intentos<<" intentos" <<endl;

}
int verificador ()
{
    int todosvolteados=0;
     for (int x=0; x<5; x++)
    {

        for(int y=0; y<4; y++)
        {

            if (matrizoculto[x][y]==63)
            {
                todosvolteados=1;
                break;
            }


        }

    }
    return todosvolteados;
}


void comparador()
{
    if(matrizoculto[cordx][cordy]==guarda)
    {
        cout<<"las cartas son iguales!!!"<<endl;
        contador3++;
        guarda=0;
        contadorpares--;



    }
    else
    {
        cout<<"las cartas no son iguales :("<<endl;

        intentos--;
        matrizoculto[cordx][cordy]=63;

        for (int x=0; x<5; x++)
        {

            for(int y=0; y<4; y++)
            {

                if(matrizoculto[x][y]==guarda)
                {
                    matrizoculto[x][y]=63;

                }

            }

        }

        guarda=0;
    }
}
void volteaCarta ()
{
    int contador2=1;
    if (contador2>=2)
    {
        contador=0;


    }
    for (int x=0; x<5; x++)
    {
        cout<<"|  ";
        for(int y=0; y<4; y++)
        {


            if (x==cordx && y==cordy)
            {
                matrizoculto[cordx][cordy]=matrizmemo[cordx][cordy];

                if (contador==0 || guarda==0)
                {
                    guarda=matrizoculto[cordx][cordy];
                    contador=1;
                }
                cout<<matrizoculto[x][y]<<"  |  ";
            }

            if(matrizoculto[x][y]==63)
            {
                if (x!=cordx || y!=cordy)
                {
                cout<<(char)matrizoculto[x][y]<<"  |  ";

                }

            }
            else
            {
               if (x!=cordx || y!=cordy)
                {
                cout<<matrizoculto[x][y]<<"  |  ";

                }
            }

        }
        cout<<endl;
    }
contador2++;
}
void elegirCarta ()
{

    cout<< "ingrese la coordenadas de su carta: " <<endl;
    cout<<"cooredenada en y: ";
    cin >>cordx;
    cordx=cordx-1;
    cout <<"coordenada en x: ";
    cin>>cordy;
    cordy=cordy-1;
    while (cordx>4 || cordy>3)
    {

        cout <<"esta posicion no existe, intente con otra carta"<<endl;
        cout<< "ingrese la coordenadas de su carta: " <<endl;
        cout<<"cooredenada en y: ";
        cin >>cordx;
        cout <<"coordenada en x: ";
        cin>>cordy;
    }



}
void generadorDePares()
{
    srand(time(0));
    int contador=0;
    int numerox=0;
    int numeroy=0;
    int caracteres[20]={1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,0,0};
    do
    {
        numerox= rand()%5;
        numeroy=rand()%4;
        if (matrizmemo[numerox][numeroy]==0)
        {
             matrizmemo[numerox][numeroy] = caracteres[contador];
             contador++;
        }
        else
        {
            do
            {
                numerox= rand()%5;
                numeroy=rand()%4;
            }
            while(matrizmemo[numerox][numeroy]!=0);

            matrizmemo[numerox][numeroy] = caracteres[contador];

            contador++;

        }
    }
    while(contador<20);
}

void imprimeMatriz()
{


    for (int x=0; x<5; x++)
    {
        cout<<"|  ";
        for(int y=0; y<4; y++)
        {

            cout<<matrizmemo[x][y]<<"  |  ";

        }
        cout<<endl;
    }

}
void generadorDeOcultos ()
{

    for (int x=0; x<5; x++)
    {
        cout<<"|  ";
        for(int y=0; y<4; y++)
        {
            matrizoculto[x][y]=63;
            cout<<(char)matrizoculto[x][y]<<"  |  ";

        }
        cout<<endl;
    }
}
