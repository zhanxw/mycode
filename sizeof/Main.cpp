#include <iostream>
#include <stdint.h>
using std::cout;
using std::endl;

#define PRINT_SIZEOF(x) cout << "sizeof(" << #x << ") = " << sizeof(x) << endl;
int main(int argc, char *argv[])
{
    PRINT_SIZEOF(char);
    PRINT_SIZEOF(unsigned char);
    PRINT_SIZEOF(signed char);
    PRINT_SIZEOF(short int);
    PRINT_SIZEOF(int);
    PRINT_SIZEOF(long int);
    PRINT_SIZEOF(long long);

    PRINT_SIZEOF(unsigned int);
    PRINT_SIZEOF(uint32_t );
    PRINT_SIZEOF(uint64_t );

    PRINT_SIZEOF(float);
    PRINT_SIZEOF(double);

    PRINT_SIZEOF(unsigned);
    PRINT_SIZEOF(bool);

    return 0;
}
