# Practica_3TM4C123
Utilizando el UART se envía el nombre de la persona mediante una cadena de caracteres para ésta ser devuelta de manera invertida y con números entre cada letra según el tamaño del nombre.

Una de las consideraciones que se tomaron al momento de realizar la prácitca es que no fue posible utilizar el UART2 para realizar la lecutra dentro de la comunicación
ya que según la páina 911 del datasheet menciona que el registro UART FR contiene un espacio de memoria reservado para el UART2. Esta restricción me llevó a probar la
práctica con UART'S diferentes siendo los resultados exitosos. En este ejemplo se configuró el UART1 para realizar la comunicación con la velocidad asignada previamente
en el inciso correspondiente [50MHz - 57600]
