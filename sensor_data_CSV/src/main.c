#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include "csv_data.h"

LOG_MODULE_REGISTER(csv_flash, LOG_LEVEL_INF);

int main(void)
{
    LOG_INF("CSV cargado desde flash:");

    printk("\n%s\n", csv_data);

    while (1) {
        k_sleep(K_SECONDS(1));
    }

    return 0;
}