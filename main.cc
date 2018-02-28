// author: charles pantoga [github varcharlie] [gmail suspects]
// Software provided as-is, no warranty, use at your own risk
#include <cstdint>
#include <cstdio>
#include "stringhash.h"

#define CHARBUFSIZE 4096

using std::puts;
using std::scanf;
using std::printf;
using std::malloc;
using utils::strhash;

int main(int argc, char* argv[], char* environ[])
{
    char* input = static_cast<char*>(malloc(CHARBUFSIZE));
    printf("Enter serial number: d11ddd-1: ");
    scanf("%8s", input);
    printf("Hashed serial number: %u\n", strhash(input));
    return 0;
}
