/*Написати програм на програмском језику C који ће бесконачно понављати исписивање неког текста. 
Није дозвољено користити петље и програм мора бити исправан, тј.
 да оперативни систем никада не пријави грешку за тај програм.*/

/*#include "../lib/hw.h"
#include "../lib/console.h"

uint64 savedPc;

void a() {    
    asm volatile("mv %0, ra" : "=r" (savedPc)); // savedPc = ra; "=r" = mi ovde znaci da ima povratnu vrednost
}

void b() {    
    asm volatile("mv ra, %0" : : "r" (savedPc)); ra = savedPc;
}

void main() {
    a();
    __putc('a');
    __putc('\n');
    b();
}*/

//Mogu da dobijem vredfnost pc-a na dva nacina: 1) kao sto sam ovde pozvao random fju a() samo da bi sa ra registra uzeo pc
//2) auipc ra, 0x0; koriste se za skokove i sabira const (0x0) i siftuje je 12 bita ulev, sabere je sa pc-ijem i vr sacuva u ra