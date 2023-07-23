#include "cpu.h"

int main()
{
    cpu cpu;
    uint8_t num = 0;
    set_status_reg_bit(&num, overflow);
    set_status_reg_bit(&num, negative);
    return 0;
}