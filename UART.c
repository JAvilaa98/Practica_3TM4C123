#include "lib/include.h"

extern void Configurar_UART0(void)
{
    SYSCTL->RCGCUART  = (1<<1);   //Habilitamos UART pág 344
    SYSCTL->RCGCGPIO |= (1<<1);     //Habilitamos el puerto del GPIO pág 340
    GPIOB->AFSEL |= (1<<0) | (1<<1); //Habilitamos la función alternativa de los puertos pag 671
    GPIOB->DIR |= (1<<0) | (0<<1); //Habilitamos la dirección
    //GPIO Port Control (GPIOPCTL) PA0-> U0Rx PA1-> U0Tx pag.688
    GPIOB->PCTL |= (GPIOB->PCTL&0xFFFFFF00) | 0x00000011;// 
    GPIOB->DEN |= (1<<0) | (1<<1);// Habilitamos canales digitales
    //UART0 UART Control (UARTCTL) pag.918 DISABLE!!
    UART1->CTL |= (0<<9) | (0<<8) | (0<<0);


    // UART Integer Baud-Rate Divisor (UARTIBRD) pag.914
    /*
    BRD = 50,000,000 / (16*57600) = 54.2534
    UARTFBRD[DIVFRAC] = integer(.2534 * 64 + 0.5) = 16.71
    */
    UART1->IBRD = 54;
    // UART Fractional Baud-Rate Divisor (UARTFBRD) pag.915
    UART1->FBRD = 17;
    //  UART Line Control (UARTLCRH) pag.916
    UART1->LCRH = (0x3<<5)|(1<<4);
    //  UART Clock Configuration(UARTCC) pag.939
    UART1->CC =(0<<0);
    //Disable UART0 UART Control (UARTCTL) pag.918
    UART1->CTL = (1<<0) | (1<<8) | (1<<9);

}

extern char readChar(void)
{
    //UART FR flag pag 911
    //UART DR data 906
    int v;
    char c;
    while((UART1->FR & (1<<4)) != 0 );
    v = UART1->DR & 0xFF;
    c = v;
    return c;
}
extern void printChar(char c)
{
    while((UART1->FR & (1<<5)) != 0 );
    UART1->DR = c;
}
extern void printString(char* string)
{
    while(*string)
    {
        printChar(*(string++));
    }
}

extern void readString(char UART2_String[], char delimitador)
{

   int i=0;
   char string [20]; //= (char *)calloc(10,sizeof(char));
   char c = readChar();
   while(c != delimitador)
   {
       (UART2_String[i]) = c;
       i++;
       c = readChar();
   }

     UART2_String[i]= '\0';

}
