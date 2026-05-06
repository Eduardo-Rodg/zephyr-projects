#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <string.h>
#include <stdlib.h>

#include "datos.h"   // <-- aquí entra tu "sensor simulado"

#define MAX_LINEA 16

int main(void)
{
    printk("Simulando sensor tipo I2C...\n");

    char buffer[MAX_LINEA];
    int i = 0;

    while (1) {

        int j = 0;

        // Reiniciar cuando llega al final del "archivo"
        if (datos_txt[i] == '\0') {
            i = 0;
        }

        // Leer una línea (hasta \n)
        while (datos_txt[i] != '\n' && datos_txt[i] != '\0') {
            buffer[j++] = datos_txt[i++];
        }

        buffer[j] = '\0';

        // Saltar el salto de línea
        if (datos_txt[i] == '\n') {
            i++;
        }

        // Convertir a número (como sensor real)
        float valor = atof(buffer);

        // Imprimir resultado
        printk("Sensor (simulado): %.2f C\n", valor);

        // Esperar 1 segundo
        k_sleep(K_SECONDS(1));
    }

    return 0;
}