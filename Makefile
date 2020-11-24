CFLAGS = -O2 -std=c11 -Wall -pedantic

all: primes primes-i

primes: bit_array.h eratosthenes.c eratosthenes.h primes.c
	gcc $(CFLAGS) -o primes bit_array.h eratosthenes.c eratosthenes.h primes.c -lm
primes-i: bit_array.h eratosthenes.c eratosthenes.h primes.c
	gcc $(CFLAGS) -DUSE_INLINE -o primes-i bit_array.h eratosthenes.c eratosthenes.h primes.c -lm
run: