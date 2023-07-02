/**
 * Plik źródłowy zawierający funkcję pomocniczą do
 * generacji liczb pseudolosowych.
 */
#include "generator.h"
#include <random>

/**
 * Funkcja generująca liczbę całkowitą z danego przedziału
 * @param n Górna granica liczby
 */
int generate_random_number(int n) {
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> distr(0 ,n);
   return (int)distr(gen);
}