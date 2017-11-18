#ifndef _UTILS_H
#define _UTILS_H
#define LSHIFT 5
#define RSHIFT 2
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <ctype.h>


std::int32_t mapchar(char chr)
{
    // isX() Functions from <ctype.h>
    if (isdigit(chr)) {
        return static_cast<std::int32_t>(chr-'0');
    }
    if (islower(chr)) {
        return static_cast<std::int32_t>(chr-'a');
    }
    return 0;
}

// Key assumed to be d11ddd-1
std::uint32_t hash(char key[])
{
    int i;
    std::uint32_t code, B, A = 0, cumulative_weight = 1;
    std::uint32_t weights[] = {10, 26, 26, 10, 10, 10, 0, 26};
    std::int32_t temp;

    for (i = 7; i >= 0; i--) {
        if (weights[i] != 0) {
            temp = mapchar(key[i]);
            if ((temp = mapchar(key[i])) == -1) {
                std::cerr << "Invalid character passed to: mapchar(char)\n";
            } else {
                code = static_cast<std::uint32_t>(temp);
            }
            A +=  * cumulative_weight;
            cumulative_weight *= weights[i];
        }
    }

    // now fold 11-bit sections
    B = (A & 2047) ^ ((A >> 8) & 2047) ^ ((A >> 17) & 2047);

    // now scale to get return value
    return B * 1964 / 2047;
}

std::uint32_t hashstring(std::string str, std::uint32_t seed, std::uint32_t maxrange)
{
    std::uint32_t result = seed;
    for (std::string::iterator it = str.begin(); it < str.end(); it++) {
        result ^= ((res << LSHIFT) + (res >> RSHFIT) + *i);
    }
    return result;
}

#endif
