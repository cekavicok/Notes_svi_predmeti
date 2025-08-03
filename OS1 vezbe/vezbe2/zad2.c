/*Написати програм на програмском језику C који ће бесконачно понављати исписивање неког текста. 
Није дозвољено користити петље и програм мора бити исправан, тј.
 да оперативни систем никада не пријави грешку за тај програм.*/

/*#include "../lib/hw.h"
#include "../lib/console.h"

uint64 savedPc;

void a() {    
    asm volatile("mv %0, ra" : "=r" (savedPc));
}

void b() {    
    asm volatile("mv ra, %0" : : "r" (savedPc));
}

void main() {
    a();
    __putc('a');
    __putc('\n');
    b();
}*/