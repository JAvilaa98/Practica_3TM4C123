#ifndef UART_UART_H_
#define UART_UART_H_

extern void Configurar_UART0(void);
extern char readChar(void);
extern void printChar(char c);
extern void printString(char* string);
extern void readString(char UART2_String[], char delimitador);


#endif /* UART_UART_H_ */