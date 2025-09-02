#include "../lib/hw.h"
#include "../lib/console.h"

uint64 timerCount = 0;

extern "C" void handleSupervisorTrap(){
    uint64 scauseVar;
    __asm__ volatile("csrr %[uOvoCitam], scause" : [uOvoCitam] "=r" (scauseVar));
    if(scauseVar == (0x01UL << 63 | 0x01)){ //proveravam da li je prekid od tajmera
        // software interrupt timer
        timerCount++;
        if(timerCount >= 50){
            __putc('a');
            __putc('\n');
            timerCount = 0;
        }
        __asm__ volatile("csrc sip, 0x02");
    }
    console_handler();
}

extern "C" void supervisorTrap();

void main() {
    __asm__ volatile("csrw stvec, %[vector]" : : [vector] "r" (&supervisorTrap));
    __asm__ volatile("csrs sstatus, 0x02"); // 0b00000010
                                            //   76543210
    while(1) {}
}