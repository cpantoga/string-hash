#!/usr/bin/env python
'''
author: charles pantoga
google: suspects
'''
import string

LSHIFT = 5
RSHIFT = 3

def mapascii(char):
    '''Maps a lowercase/digit to its ascii table value'''
    if char in string.ascii_lowercase:
        return ord(char) - ord('a')
    elif char in string.digits:
        return ord(char) - ord('0')
    else:
        raise ValueError(f"mapchar(char): {char} is not a valid character.")


def hasher(key):
    weights = (10, 26, 26, 10, 10, 10, 0,26)
    fold, total, cumulative_weight = 0, 0, 1
    for i in range(7, -1, -1):
        if weights[i] != 0:
            total += mapascii(key[i]) * cumulative_weight
            cumulative_weight *= weights[i]
    fold = (total & 2047) ^ ((total >> 8) & 2047) ^ ((total >> 17) & 2047)
    return fold * 1964 // 2047


def hashstring(String, seed, size):
    result = seed
    for char in String:
        result ^= ((result << LEFTSHIFT) + (result >> RSHIFT) + char)
    return result // size

