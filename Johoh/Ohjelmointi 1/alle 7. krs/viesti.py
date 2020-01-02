# TIE-02100 Johdatus ohjelmointiin
# TIE-02106 Introduction to Programming
# Task: viesti, program code template


def read_message():
    syotteet = []
    syote = " "
    while syote is not "":
        syote = str(input())
        if syote == "":
            return syotteet
        syotteet.append(syote)


def main():
    print("Enter text rows to the message. Quit by entering an empty row.")
    msg = read_message()

    print("The same, shouting:")
    for sana in msg:
        sana = sana.upper()
        print(sana)


main()


