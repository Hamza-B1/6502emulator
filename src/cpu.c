#include "cpu.h"

const cpu_instruction instruction_table[255] =
{
    [0xA9] = &LDA_IMM
}; 


void set_status_reg_bit(uint8_t *status_register, status_flags flag)
{
    *status_register |= (1 << flag);
}

void unset_status_reg_bit(uint8_t *status_register, status_flags flag)
{
    *status_register &= ~(1 << flag);
}

void init(cpu *cpu)
{
    cpu->memory = (uint8_t*)malloc(MEMORY_SIZE);
    cpu->pc = 0x0;
    cpu->stack_ptr = 0x100;
    cpu->status = 0x0;
    cpu->x = cpu->y = cpu->a = 0x0;
}

void destroy(cpu *cpu)
{
    if (cpu->memory != NULL)
    {
        free(cpu->memory);
    }
}

void execute(cpu* cpu, uint32_t cycles)
{
    while (cycles > 0)
    {
        uint8_t instruction = fetch_byte(cpu, &cycles);
        instruction_table[instruction](cpu, &cycles); // call the instruction
    }
}

uint8_t fetch_byte(cpu* cpu, uint32_t* cycles)
{
    assert(cpu->pc < MEMORY_SIZE);
    uint8_t data = cpu->memory[cpu->pc];
    cpu->pc++;
    (*cycles)--;
    return data;
}

void LDA_IMM(cpu* cpu, uint32_t* cycles) 
{
    uint8_t data = fetch_byte(cpu, cycles);
    cpu->a = data;

    if (cpu->a == 0)
    {
        set_status_reg_bit(&cpu->status, zero);
    }
    if ((cpu->a & 0b10000000) > 0)
    {
        set_status_reg_bit(&cpu->status, negative);
    }
}
