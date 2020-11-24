// eratosthenes.c
// Řešení IJC-DU1, příklad a), 21.3.2019
// Autor: David Rubý, FIT
// Přeloženo: gcc 7.3.0
// zdrojový soubor pro funkci Eratosthenes...

#include "eratosthenes.h"

void Eratosthenes(bit_array_t pole){
    bit_array_setbit(pole, 0, 1);               //Nastaví bit na nultém indexu na hodnotu 1
    bit_array_setbit(pole, 1, 1);               //Nastaví bit na prvním indexu na hodnotu 1
    for(unsigned long i = 2; i <= sqrt(pole[0]); i++){    
        if(bit_array_getbit(pole, i) == 1)
            continue;
        for(unsigned long j = 2*i; j < pole[0]; j += i){ //samotne citani
            bit_array_setbit(pole, j, 1); //nemuze byt z definice prvocislem (je nasobkem jineho cisla)
        }
    }
}