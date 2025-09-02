/*#include "../lib/console.h"
#include "../lib/hw.h"

uint64 savedPc;
void f() {
    __putc('a');
    __putc('\n');

    __asm__ volatile("mv ra, %0" : : "r" (savedPc));
    __asm__ volatile("sd ra, 8(sp)");
}

void dispatch() {
    __asm__ volatile ("mv %[savedVal], ra" : [savedVal] "=r" (savedPc));
    __asm__ volatile ("mv ra, %[fadr]" : : [fadr] "r" (&f));
}

void main(){
    dispatch();
}*/