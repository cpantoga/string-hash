// author: charles pantoga [github varcharlie] [gmail suspects]
// Software provided as-is, no warranty, use at your own risk
#ifndef _UTILS_H
#define _UTILS_H
#define LSHIFT 5
#define RSHIFT 2
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <cstdint>
#include <cctype>

using std::domain_error
using std::uint32_t
using std::string
using std::isdigit
namespace utils {
// Helper function - maps chars to uint32_t
// @param chr
//  character in set(a-z) U set(0-9)
uint32_t mapchar(char chr)
{
    // isX() Functions from <ctype.h>
    if (isdigit(chr)) {
        return static_cast<uint32_t>(chr-'0');
    } else if (islower(chr)) {
        return static_cast<uint32_t>(chr-'a');
    } else {
        throw domain_error("Invalid char provided to mapchar.");
    }
}

// Key assumed to be d11ddd-1
// @param key[]: chars that makeup key (in specified format)
uint32_t hash(char key[])
{
    int i;
    uint32_t B, A = 0, cumulative_weight = 1;
    uint32_t weights[] = {10, 26, 26, 10, 10, 10, 0, 26};

    for (i = 7; i >= 0; i--) {
        if (weights[i] != 0) {
            A += mapchar(key[i]) * cumulative_weight;
            cumulative_weight *= weights[i];
        }
    }

    // now fold 11-bit sections
    B = (A & 2047) ^ ((A >> 8) & 2047) ^ ((A >> 17) & 2047);

    // now scale to get return value
    return B * 1964 / 2047;
}

// Make a hash from a string
// Algorithm from Ramakrishna and Zobel
// @param str: string to transform into hash
// @param seed: seed value for hash
// @param size: bucket size
uint32_t hashstring(string str, uint32_t seed, uint32_t size)
{
    uint32_t result = seed;
    for (string::iterator it = str.begin(); it < str.end(); it++) {
        result ^= ((result << LSHIFT) + (result >> RSHFIT) + *it);
    }
    return result / size;
}

}
#endif
