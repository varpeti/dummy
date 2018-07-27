#include <iostream>
#include <stdlib.h>
#include <time.h>


char randChar()
{
    if (rand()%2) return rand() % 26 + 65;
    return rand() % 26 + 97;
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    for (int i = 0; i < 9; ++i)
    {
        std::cout << randChar();
    }
    std::cout << "\n";

    getchar();
    return 0;
}