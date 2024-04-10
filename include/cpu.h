#ifndef CPU_H
#define CPU_H
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#include <memory.h>

#define MEMORY_SIZE 1024 * 64

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

typedef struct
{
    uint16_t pc;
    uint8_t a;
    uint8_t x;
    uint8_t y;
    uint8_t stack_ptr;
    uint8_t status;
    uint8_t cycles_to_instruction_completion;
    uint8_t *memory;

} cpu;

typedef void (*cpu_instruction)(cpu*, uint32_t*);

void LDA_IMM(cpu*, uint32_t*);



void set_status_reg_bit(uint8_t *status_register, status_flags flag);
void unset_status_reg_bit(uint8_t *status_register, status_flags flag);
void init(cpu *cpu);
void destroy(cpu *cpu);
void execute(cpu *cpu, uint32_t cycles);
uint8_t fetch_byte(cpu *cpu, uint32_t* cycles);

#endif