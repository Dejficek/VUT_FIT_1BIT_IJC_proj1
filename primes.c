// primes.c
// Řešení IJC-DU1, příklad a), 21.3.2019
// Autor: David Rubý, FIT
// Přeloženo: gcc 7.3.0
// zdrojový soubor pro výpis indexů bitů s hodnotou 0

#include "eratosthenes.h"
#include<stdio.h>
#include<stdlib.h>

int main(){
    //deklarace a definice proměnných
    bit_array_alloc(pole,123000000);        //deklarace pole
    unsigned long results[10];
    int increment = 0;
    unsigned long array_size = bit_array_size(pole);

    //použití funkce Eratosthenes, která nastaví bity na prvočíselných indexech na hodnotu 0.
    Eratosthenes(pole);

    //smyčka pojede odzadu, aby se ukládaly jen poslední hodnoty
    for(int i = array_size - 1; i >= 0; i--){
        /*
        kód:
            if(bit_array_getbit(pole, i) == 0){
                result[increment++] = i;
            }
        nefungoval... proto nutno použít v elsu.
        */

       //Pokud je bit nastaven na hodnotu 0, uloží se jeho index do proměnné pro výsledky
        if(bit_array_getbit(pole, i) == 1){
        }
        else{
            results[increment++] = i;
        }
        //Pokud se uložilo už 10 výsledků, smyčka skončí
        if(increment == 10){
            break;
        }
    }

    //výsledky se ukládaly pozpátku, proto, běží smyčka opět pozpátku
    for(int j = 9; j >= 0; j--){
        printf("%lu\n", results[j]);
    }
}