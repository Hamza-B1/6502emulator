#ifndef CPU_H
#define CPU_H
#include <stdint.h>

typedef struct
{
    uint16_t pc;
    uint8_t a;
    uint8_t x;
    uint8_t y;
    uint8_t status;
    uint8_t cycles_to_instruction_completion;

} cpu;

typedef struct 
{

} memory;

typedef enum
{
    carry = 0,
    zero,
    irq_disable,
    decimal,
    break_bit,
    unused,
    overflow,
    negative
} status_flags;


void set_bit_status_reg_bit(uint8_t *status_register, status_flags flag);
void unset_status_reg_bit(uint8_t *status_register, status_flags flag);


#endif