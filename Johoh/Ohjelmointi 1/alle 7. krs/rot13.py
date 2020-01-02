# TIE-02100 Johdatus ohjelmointiin
# TIE-02106 Introduction to Programming
# Task: ROT13, program code template


def encrypt(alphabet):
    alphabet_low = alphabet.lower()
    regular_chars = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k",
                     "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v",
                     "w", "x", "y", "z"]
    if alphabet_low not in regular_chars:
        return alphabet
    encrypted_chars = ["n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x",
                       "y", "z", "a", "b", "c", "d", "e", "f", "g", "h", "i",
                       "j", "k", "l", "m"]
    location = regular_chars.index(alphabet_low)
    alphabet_new = encrypted_chars[location]
    if alphabet == regular_chars[location]:
        return alphabet_new
    else:
        return alphabet_new.upper()


def row_encryption(string):
    new_string = ""
    for mark in string:
        new_string += encrypt(mark)
    return new_string