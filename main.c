#include <stdio.h>
#include "slip_api.h"

void print_package(uint8_t *__package, uint8_t __size)
{
    printf("package: ");
    for(int byte = 0; byte < __size; byte++)
    {
        printf("%x ", __package[byte]);
    }
    printf("\n");
}

int main(void)
{
    uint8_t package[] = {0xc0, 1, 2, 3, 0xc0, 0xce, 0xdb, 2, 0xce};
    uint8_t coded_package[32];
    uint8_t encoded_package[32];
    print_package(package, sizeof(package));
    uint8_t coded_size = SLIP_code(package, sizeof(package), coded_package);
    print_package(coded_package, coded_size);
    uint8_t encoded_size = SLIP_decode(coded_package, coded_size, encoded_package);
    print_package(encoded_package, encoded_size);
    return 0;
}