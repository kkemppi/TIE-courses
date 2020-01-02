# TIE-02100 Johdatus ohjelmointiin
# Koodipohja laulu c, Yogi Bear
# Mikko Kemppi, 272670

def repeat_name(name, kerta):
    for i in range (0, kerta):
        print(name, ", ", name, " Bear", sep="")

def verse(sae, name):
    print(sae)
    print(name, ", ", name, sep=(""))
    print(sae)
    repeat_name(name, 3)
    print(sae)
    repeat_name(name, 1)
    print("")

def main():
    verse("I know someone you don't know", "Yogi")
    verse("Yogi has a best friend too", "Boo Boo")
    verse("Yogi has a sweet girlfriend", "Cindy")

main()
