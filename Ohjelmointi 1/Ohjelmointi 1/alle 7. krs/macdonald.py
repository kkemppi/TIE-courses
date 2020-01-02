# TIE-02100 Johdatus ohjelmointiin
# TIE-02100 Introduction to programming
# Template song b, Old MacDonald


def print_verse(elain, aani):
    print("Old MACDONALD had a farm")
    print("E-I-E-I-O")
    print("And on his farm he had a", elain)
    print("E-I-E-I-O")
    print("With a", aani, aani, "here")
    print("And a", aani, aani, "there")
    print("Here a {:1s}, there a {:1s}".format(aani, aani))
    print("Everywhere a", aani, aani)
    print("Old MacDonald had a farm")
    print("E-I-E-I-O")
    print("")

def main():

    print_verse("cow", "moo")
    print_verse("pig", "oink")
    print_verse("duck", "quack")
    print_verse("horse", "neigh")
    print_verse("lamb", "baa")

main()

