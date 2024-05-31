/**
 * Plik główny programu
 */
#include "core/app.h"
#include <iostream>

int main(int, char **)
{
    App app;
    app.run();
    std::cout << "Program zakończono.\n";
    return 0;
}