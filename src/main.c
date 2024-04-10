#include "cpu.h"

int main()
{
    cpu cpu;
    init(&cpu);
    cpu.memory[0] = 0xA9;
    cpu.memory[1] = 0xFF;
    execute(&cpu, 2);
    destroy(&cpu);
    return 0;
}