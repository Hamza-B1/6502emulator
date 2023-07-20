#include "cpu.h"

int main()
{
    cpu cpu;
    uint8_t num = 4;
    uint8_t* nump = &num;
    status_flags test = overflow;
    set_bit_status_reg_bit(nump, overflow);
    return 0;
}