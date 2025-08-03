/*Написати програм на програмском језику C који ће помоћу једне функције бесконачно исписивати неки текст.
Решење може да буде некоректно у смислу да ће оперативни систем у коначном времену пријавити грешку у 
извршавању програма и прекинути његово извршавање. Није дозвољено коришћење петљи.
*/
//SVAKI REGISTAR JE 64b (8B)
//povratna adresa iz steka:
//stara vrednost PC i s0 - frame pointer (offseti lokalnih promenljivih)
//po 8B je svaka rec u steku pa je prva PC na offset 0 i posle toga S0 od proslog poziva na +8
//frame pointer bukv pokazuje gde je bio stek pointer pre ulaska u funkciju
#include <stdio.h>
#include <stdlib.h>

void f(){
    __putc('f');
    __putc('\n');
    f();
}
//problem: svaki put se odvaja 16B na stek da se sacuvaju PC i s0 tj fp i nikad se ne vracamo da to skinemo
//znaci mem se trosi beskonacno i popunice se eventualno tjt
