// bit_array.h
// Řešení IJC-DU1, příklad a), 21.3.2019
// Autor: David Rubý, FIT
// Přeloženo: gcc 7.3.0
// hlavičkový soubor s definicemi makro a inline funkcí


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<errno.h>

typedef unsigned long* bit_array_t;
//Vytvoří staticky deklarované pole unsigned longů o určené velikosti
//Vytvoří pole unsigned longů o takové velikosti, aby se do něj vešly všechny bity
//Do proměnné typu unsigned long na indexu 0 uloží počet bitů
#define bit_array_create(jmeno_pole,velikost) \
unsigned long jmeno_pole[ceil(velikost / (float)(sizeof(unsigned long) * 8)) + 1] = {0}; \
jmeno_pole[0] = velikost;

//Vytvoří dynamicky deklarované pole proměnných datového typu unsigned long o určené velikosti tak,
//aby se do něj vešly všechny bity a veškeré bity nastaví na hodnotu 0
#define bit_array_alloc(jmeno_pole,velikost) \
unsigned long size = (ceil(velikost / (float)(sizeof(unsigned long))) + sizeof(unsigned long)); \
bit_array_t jmeno_pole = malloc(size * sizeof(unsigned long)); \
if(jmeno_pole == NULL) \
    fprintf(stderr, "bit_array_alloc: Chyba alokace paměti\n"); \
for(unsigned long i = 0; i < size; i++){ \
    jmeno_pole[i] = 0; }\
jmeno_pole[0] = velikost;

#ifndef USE_INLINE

//Uvolní paměť dynamicky alokovaného pole
#define bit_array_free(jmeno_pole) \
free(jmeno_pole);

//vrátí velikost bole(počet bitů, které je možno do něj uložit)
#define bit_array_size(jmeno_pole) \
jmeno_pole[0]

//Nastaví bit na určité pozici na určitou hodnotu
//V případě, že je argument pro hodnotu bytu zadán jako hodnota 0, aloží se na pozici hodnota 0
//V případě, že je argument pro hodnotu bytu zadán jako hodnota jiné než 0, aloží se na požici hodnota 1
#define bit_array_setbit(jmeno_pole,index,vyraz) \
if(vyraz != 0){ \
    jmeno_pole[(index / ((sizeof(unsigned long) * 8)) + 1)] |= 1UL << (index % (sizeof(unsigned long) * 8)); \
} \
else { \
    jmeno_pole[(index / (sizeof(unsigned long) * 8)) + 1] &= ~(1UL << (index % (sizeof(unsigned long) * 8))); \
}

//Zjistí hodnotu bitu v poli na určeném indexu a vrátí ji
#define bit_array_getbit(jmeno_pole,index) \
(jmeno_pole[(index / (sizeof(unsigned long) * 8)) + 1] >> (index % (sizeof(unsigned long) * 8))) & 1UL


/*--------------------------------------------------------------------------------------------------------------*/

#else

//vrátí velikost bole(počet bitů, které je možno do něj uložit)
inline unsigned long bit_array_size(bit_array_t jmeno_pole){
    return jmeno_pole[0];
}

//Nastaví bit na určité pozici na určitou hodnotu
//V případě, že je argument pro hodnotu bytu zadán jako hodnota 0, aloží se na pozici hodnota 0
//V případě, že je argument pro hodnotu bytu zadán jako hodnota jiné než 0, aloží se na požici hodnota 1
inline void bit_array_setbit(bit_array_t jmeno_pole, unsigned long index, int vyraz){
    if(vyraz != 0){
        jmeno_pole[(index / ((sizeof(unsigned long) * 8)) + 1)] |= 1UL << (index % (sizeof(unsigned long) * 8));
    } 
    else {
        jmeno_pole[(index / (sizeof(unsigned long) * 8)) + 1] &= ~(1UL << (index % (sizeof(unsigned long) * 8)));
    }
}

//Zjistí hodnotu bitu v poli na určeném indexu a vrátí ji
inline int bit_array_getbit(bit_array_t jmeno_pole, unsigned long index){
    return (jmeno_pole[(index / (sizeof(unsigned long) * 8)) + 1] >> (index % (sizeof(unsigned long) * 8))) & 1UL;
}

#endif