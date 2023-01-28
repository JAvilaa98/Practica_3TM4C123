#include "lib/include.h"


void caractconnume(char *S);
int main(void)
{
    uint16_t valor = 0;
    char c='5';
    //char b='a';
    Configurar_PLL(_50MHZ);  //Confiuracion de velocidad de reloj
    Configurar_UART0();//Yo FCLK 20MHZ Baudrate 9600

    //Experimento 1
    //  Configurar_UART1(); //Jorge,Alberto,Navarro,Saul,Fabela -fclk 25MHZ Baud-rate 57600
    //  Configurar_UART7(); //Angel,Fernanda,Sonia,Aleidis,Monse -fclk 50MHZ Baud-rate 57600
    //  Configurar_UART4(); //Argelia,Roxana,Yesica,Vanesa,Christian,Abiu -fclk 10MHZ Baud-rate 4800
    //  Configurar_UART2(); //Brizet,Monse,Luis,Majo,Alonso -fclk 40MHZ Baud-rate 115200
    //  Configurar_UART3(); //Jesus,Yesica,Carlos,Dulce,Rodolfo,Leonardo -fclk 80MHZ Baud-rate 19200
    //  Configurar_UART2(); //Andrea,Avila,Pamela,Paulina -fclk 50MHZ Baud-rate 57600
    //  Configurar_UART5(); //Hector,Cecilia,Carolina,Jozzafat -fclk 40MHZ Baud-rate 28800
    Configurar_GPIO();
   int w; // Número de caracteres que tiene la variable al revés
   int y;
   //char *alreves = (char *)calloc(16,sizeof(char)); // aparta memoria dinamica en la distribuccion donde le digas 16 porque la fifo no lee más de 16,
   char*alreves = ('\0'); // que la variable se esta inicializando en 0, borra la basura 
   char text[16];
   char  UART2_String [20]; //= '\0';
    
    

    while(1)
    {
         c = readChar();
         switch(c)
         {
             case 'r':
                 //GPIODATA port F 662
                 printChar('a');
                 GPIOF->DATA = (1<<1);
                 break;
             case 'b':
                 //GPIODATA port F 662
                 printChar('b');
                 GPIOF->DATA = (1<<2);
                 break;
             case 'g':
                 //GPIODATA port F 662
                 printChar('c');
                 GPIOF->DATA = (1<<3);
                 break;
             case 'y':
                 //GPIODATA port F 662
                 printChar('d');
                 GPIOF->DATA = (1<<3) | (1<<2);
                 break;
             default:
                 printChar((char)valor);
                 GPIOF->DATA = (0<<1) | (0<<2) | (0<<3);
                 break;
         }
         
          y = 0; //Contador
          readString(UART2_String, '%'); // se lee el UART
          w = strlen(&UART2_String);
         if(w != 0)
         {
            //GPIOF->DATAma =(1<<3);               //GREEN LED ENCENDIDO
            char * apuntador = &UART2_String;
            apuntador = apuntador + w - 1; 
            for(y=0;y<=w;y++)
            {
                text [y] = *(apuntador - y); 
            }
            
           printString(text);
           printChar('\n');
           caractconnume(text); 

        
    }
}
}

void caractconnume(char *S) // Mandamos a llamar la función que contiene el nombre invertido para posteriormente intercalar los números entre cada letra
{
    int num = 1;  // variables locales
    char numeros[9];

    numeros[1]='1';
    numeros[2]='2';
    numeros[3]='3';
    numeros[4]='4';
    numeros[5]='5';
    numeros[6]='6';
    numeros[7]='7';
    numeros[8]='8';
    numeros[9]='9';
    
    while(*S)
    {
        printChar(*(S++));    //Escribimos un carcater de la cadena de caracteres
        printChar(numeros[num]); //Contador
        num = num + 1;           // Aumentamos el contador
    }
    printChar('\n'); // Delimitador
}