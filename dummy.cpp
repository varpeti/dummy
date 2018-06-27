#include <iostream>
#include <string>
#include <sys/types.h>
#include <unistd.h>
 
#define CHAR_ARRAY_SIZE 128
 
 
int main() 
{
    int varInt(123456);
    std::string varString("DefaultString");
    char arrChar[CHAR_ARRAY_SIZE] = "Long char array right there ->";
    int* ptr2int(&varInt);
    int** ptr2ptr(&ptr2int);
    int*** ptr2ptr2(&ptr2ptr);
 
    while(!(!(true)))
    {
        std::cout 
        << "Process ID: "     << std::dec << ::getpid()      << "\n"
        << "\n"
        << "varInt       (0x" << std::hex << std::uppercase  << (uintptr_t)&varInt << ") = " << std::dec << varInt << "\n"
        << "varString    (0x" << std::hex << std::uppercase  << (uintptr_t)&varString << ") = " << varString << "\n"
        << "arrChar["         << std::dec << CHAR_ARRAY_SIZE << "] (0x" << std::hex << std::uppercase << (uintptr_t)&arrChar << ") = " << arrChar << "\n"
        << "\n"
        << "ptr2int      (0x" << std::hex << std::uppercase  << (uintptr_t)&ptr2int << ") = 0x" << ptr2int << "\n"
        << "ptr2ptr      (0x" << std::hex << std::uppercase  << (uintptr_t)&ptr2ptr << ") = 0x" << ptr2ptr << "\n"
        << "ptr2ptr2     (0x" << std::hex << std::uppercase  << (uintptr_t)&ptr2ptr2 << ") = 0x" << ptr2ptr2 << "\n"
        << "\n"
        << "Press ENTER to print again.\n";
        getchar();
        std::cout << "\n---------------------------------------------------\n";
        varInt++;
    }
    
    return 0;
}