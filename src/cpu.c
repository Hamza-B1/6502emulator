#include "cpu.h"

void set_status_reg_bit(uint8_t *status_register, status_flags flag)
{
    *status_register |= (1 << flag);
}

void unset_status_reg_bit(uint8_t *status_register, status_flags flag)
{
    *status_register &= ~(1 << flag);
}