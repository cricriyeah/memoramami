#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;


//variables
char opcion2;
char opcion;
int codigoColor = 1;
int xT=44, yT=16;
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
void menu();// menu
void gotoxy (int,int);//funcion para ubicar el cursor en la posicion deseada
void color (int); //le pone color a la matriz c:
void instrucciones ();
void reiniciador ();//reinicia la matriz con 0;
int main()
{
    do
    {
        system("cls");
        PlaySound(TEXT("y2mate.wav"), NULL, SND_ASYNC);
        menu();
        getch ();
        PlaySound(NULL,0,0);
        if (GetKeyState(VK_RETURN) & 0x8000)
        {
            do
            {

                contador3=0;
                cordx=0;
                cordy=0;
                intentos=10;
                contador=0;
                contadorpares=10;
                matrizmemo[5][4]={0};
                matrizoculto[5][4]={0};
                guarda=0;
                system("cls");
                reiniciador();
                gotoxy(xT-4,yT=2);
                gotoxy(xT-4,yT++);
                cout<<"Hola!!!! :D"<<endl;
                gotoxy(xT-4,yT++);
                cout<<"Bienvenido a mi juego de memorama"<<endl;
                gotoxy(xT-4,yT++);
                cout<<"Estas son sus cartas:"<<endl;
                Sleep(2000);
                generadorDePares();
                imprimeMatriz();
                gotoxy(xT-4,yT++);
                cout<<"Tomate el tiempo que necesites para verlas"<<endl;
                gotoxy(xT-4,yT++);
                cout<<"Cuando estes listo pulsa cualquier boton :)"<<endl;
                getch();
                system("cls");
                gotoxy(xT-4,yT=2);
                Sleep(2000);
                gotoxy(xT-4,yT++);
                cout<< "Vamos a voltear todas las cartas"<<endl;
                gotoxy(xT-4,yT++);
                generadorDeOcultos();
                Sleep(2000);
                do
                {

                    color(7);
                    elegirCarta();
                    Sleep (2000);
                    system("cls");
                    volteaCarta();
                    Sleep (2000);
                    elegirCarta ();
                    Sleep (2000);
                    system("cls");
                    volteaCarta();
                    Sleep(2000);
                    comparador();
                    contadorIntentos();
                    pares ();


                }
                while (intentos>0 && pares>0);
                Sleep(2000);
                if (verificador()==0 || contador3==10)
                {

                }
                else if (verificador()==1)
                {
                    perdiste();
                }
                cout<<"quieres volver a jugar? (y/n)"<<endl;
                cin>>opcion;
            }
            while (opcion=='y');
            return 0;
        }

        if (GetKeyState('I') & 0x8000)
        {

            instrucciones();
        }
    }
    while (opcion2=='y');




    return 0;
}
void reiniciador()
{
    for (int x=0; x<5; x++)
    {
        for(int y=0; y<4; y++)
        {
            matrizmemo[x][y]=0;
        }

    }

}
void instrucciones ()
{
cout<<"Instrucciones"<<endl;
cout<<"Las instrucciones para jugar son muy simples:"<<endl;
cout<<"1. Cuando empieces el juego en la pantalla se van a desplegar tus pares de manera aleatoria OJO"<<endl;
cout<<"tienes que tener en cuenta que es la unica vez que vas a poder ver los pares asi que memorizalos"<<endl;
cout<<"bien"<<endl;
cout<<"2. Para elegir tu carta tienes que ingresar las coordenadas en la que esta respecto a la matriz de"<<endl;
cout<<"5x4, por ejemplo, (1,1) voltearia la primera carta. "<<endl;
cout<<"3. para ganar tienes que voltear todas las cartas sin que se terminen los intentos"<<endl;
cout<<"4. pierdes si se terminaron los intentos y no volteaste todas las cartas "<<endl;
cout<<"Y ya eso seria todo :) que lo disfrutes. "<<endl;
cout<<"quieres jugar? (y/n)"<<endl;
cin>>opcion2;
}
void menu ()
{
    color(6);
    gotoxy(20,2);
    cout<<" _______  _______  _______  _______  ______  _______  _______  _______"<<endl;
    gotoxy(20,3);
    cout<<"|   |   ||    ___||   |   ||       ||   __ ||   _   ||   |   ||   _   |"<<endl;
    gotoxy(20,4);
    cout<<"|       ||    ___||       ||   -   ||      <|       ||       ||       |"<<endl;
    gotoxy(20,5);
    cout<<"|__|_|__||_______||__|_|__||_______||___|__||___|___||__|_|__||___|___|"<<endl;
    gotoxy(35,6);
    color (7);
    cout<<"________________________________________"<<endl;
    gotoxy(40,7);
    cout<<" By Cristofer Jimenez Fernadez" <<endl;
    gotoxy(35,8);
    cout<<"----------------------------------------"<<endl;
    gotoxy(40,10);
    cout<<"==>   Play";
    color (14);
    cout<<"(Enter)"<<endl;
    color(7);
    gotoxy(40,12);
    cout<<"==>   Instrucciones";
    color (14);
    cout<<"(i)"<<endl;
    color(7);



}
void perdiste ()
{
    gotoxy(10,yT=9);
    system("cls");
    color(12);
    gotoxy(10,yT++);
    cout<<" ::::::::      :::     ::::    ::::  ::::::::::   ::::::::  :::     ::: :::::::::: :::::::::"<<endl;
    gotoxy(10,yT++);
    cout<<":+:    :+:   :+: :+:   +:+:+: :+:+:+ :+:         :+:    :+: :+:     :+: :+:        :+:    :+:"<<endl;
    gotoxy(10,yT++);
    cout<<"+:+         +:+   +:+  +:+ +:+:+ +:+ +:+         +:+    +:+ +:+     +:+ +:+        +:+    +:+"<<endl;
    gotoxy(10,yT++);
    cout<<":#:        +#++:++#++: +#+  +:+  +#+ +#++:++#    +#+    +:+ +#+     +:+ +#++:++#   +#++:++#:"<<endl;
    gotoxy(10,yT++);
    cout<<"+#+   +#+# +#+     +#+ +#+       +#+ +#+         +#+    +#+  +#+   +#+  +#+        +#+    +#+"<<endl;
    gotoxy(10,yT++);
    cout<<"#+#    #+# #+#     #+# #+#       #+# #+#         #+#    #+#   #+#+#+#   #+#        #+#    #+#"<<endl;
    gotoxy(10,yT++);
    cout<<" ########  ###     ### ###       ### ##########   ########      ###     ########## ###    ###"<<endl;
    gotoxy(10,yT++);
    color(7);
    gotoxy(10,yT++);
    color(12);
    gotoxy(50,yT++);
    cout <<"perdiste :("<<endl;
    color (7);
}
void ganaste ()
{
    gotoxy(21,yT=9);
    system ("cls");
    color(10);
    gotoxy(21,yT++);
    cout<<":::   :::  ::::::::  :::    :::  :::       ::: ::::::::::: ::::    :::"<<endl;
    gotoxy(21,yT++);
    cout<<":+:   :+: :+:    :+: :+:    :+:  :+:       :+:     :+:     :+:+:   :+:"<<endl;
    gotoxy(21,yT++);
    cout<<" +:+ +:+  +:+    +:+ +:+    +:+  +:+       +:+     +:+     :+:+:+  +:+"<<endl;
    gotoxy(21,yT++);
    cout<<"  +#++:   +#+    +:+ +#+    +:+  +#+  +:+  +#+     +#+     +#+ +:+ +#+"<<endl;
    gotoxy(21,yT++);
    cout<<"   +#+    +#+    +#+ +#+    +#+  +#+ +#+#+ +#+     +#+     +#+  +#+#+#"<<endl;
    gotoxy(21,yT++);
    cout<<"   #+#    #+#    #+# #+#    #+#   #+#+# #+#+#      #+#     #+#   #+#+#"<<endl;
    gotoxy(21,yT++);
    cout<<"   ###     ########   ########     ###   ###   ########### ###    ####"<<endl;
    gotoxy(21,yT++);
    color(7);
    gotoxy(21,yT++);
    color(10);
    gotoxy(50,yT++);
    cout <<"Ganaste :)"<<endl;
    color (7);
}
void pares()
{
    gotoxy(0,1);
    cout<<endl<<"Quedan "<<contadorpares<<" pares"<<endl;
}
void contadorIntentos ()
{
    gotoxy(0,0);
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
        gotoxy(xT-4,yT++);
        cout<<"las cartas son iguales!!!"<<endl;
        contador3++;
        guarda=0;
        contadorpares--;



    }
    else
    {
        gotoxy(xT-4,yT++);
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
    gotoxy(xT-4,yT=2);
    for (int x=0; x<5; x++)
    {
        gotoxy(xT-4,yT++);
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
                color(10);
                cout<<matrizoculto[x][y];
                color(7);
                cout<<"  |  ";
            }

            if(matrizoculto[x][y]==63)
            {
                if (x!=cordx || y!=cordy)
                {
                color(12);
                cout<<(char)matrizoculto[x][y];
                color (7);
                cout<<"  |  ";

                }

            }
            else
            {
               if (x!=cordx || y!=cordy)
                {
                color(10);
                cout<<matrizoculto[x][y];
                color(7);
                cout<<"  |  ";

                }
            }

        }
        cout<<endl;
    }
contador2++;
}
void elegirCarta ()
{
    gotoxy(xT-4,yT++);
    cout<< "ingrese la coordenadas de su carta: " <<endl;
    gotoxy(xT-4,yT++);
    cout<<"coordenada en y: ";
    gotoxy(xT-4,yT++);
    cin >>cordx;
    cordx=cordx-1;
    gotoxy(xT-4,yT++);
    cout <<"coordenada en x: ";
    gotoxy(xT-4,yT++);
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
    const int caracteres[20]={1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10};
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
        gotoxy(xT,yT++);
        cout<<"|  ";
        for(int y=0; y<4; y++)
        {
            color (10);
            cout<<matrizmemo[x][y];
            color (7);
            cout<<"  |  ";

        }
        cout<<endl;
    }

}
void generadorDeOcultos ()
{

    for (int x=0; x<5; x++)
    {

        gotoxy(xT,yT++);
        cout<<"|  ";

        for(int y=0; y<4; y++)
        {
            matrizoculto[x][y]=63;
            color(12);
            cout<<(char)matrizoculto[x][y];
            color(7);
            cout<<"  |  ";


        }
        cout<<endl;
    }

}
void color(int codigoColor)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, codigoColor);
}
void gotoxy (int xT,int yT)
{
   COORD posicion;
    posicion.X = xT;
    posicion.Y = yT;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posicion);
}
