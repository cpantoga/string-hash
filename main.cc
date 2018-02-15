// author: charles pantoga [github varcharlie] [gmail suspects]
// Software provided as-is, no warranty, use at your own risk
#include <cstdint>
#include <cstdio>
#include "stringhash.h"

#define CHARBUFSIZE 4096

using std::puts
using std::gets
using std::printf
using std::malloc

int main(int argc, char* argv[], char* environ[])
{
    char* input = static_cast<char*>(malloc(CHARBUFSIZE))
    puts("Enter serial number: d11ddd-1: ");
    printf("Hashed serial number: %s\n", input);
    return 0;
}
