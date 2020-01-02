# TIE-02100 Johdatus ohjelmointiin
# TIE-02106 Introduction to Programming
# Task: ROT13, full

def read_message():
    syotteet = []
    syote = " "
    while syote is not "":
        syote = str(input())
        if syote == "":
            return syotteet
        syotteet.append(syote)


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

def main():
    print("Enter text rows to the message. Quit by entering an empty row.")
    msg = read_message()

    print("ROT13:")
    for rivi in msg:
        rivi = row_encryption(rivi)
        print(rivi)

main()