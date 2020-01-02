# Mikko Kemppi, 272670, mikko.kemppi@tuni.fi
# TIE-02101, Johdatus ohjelmointiin
# Ohjelma joka tekee tenttituloksista pylvastiagrammin


def montako_numeroa(lista, arvo):
    #Laskee montako kertaa tietty arvo esiintyy listassa
    tuloslista = []
    for i in range(0, len(lista)):
        if lista[i] == arvo:
            tuloslista.append(i)
    kpl = len(tuloslista) - 1
    return kpl


def tulosrajat():
    # Tallennetaan tulosrajat listaan
    print("Please input the grade ranges.")
    pisterajat = []
    pisterajat.append(int(input("Maximum score qualifying for grade 0: ")))
    i = 1
    while i <= 5:
        raja = int(input("Maximum score qualifying for grade {:1d}: ".format(i)))
        if not arvon_tarkistus(raja, pisterajat):
            print("Entered value", raja, " is not valid. Program terminating.")
            return False
        pisterajat.append(raja)
        i += 1
    return pisterajat

def opiskelijoiden_pisteet():
    # Tallennetaan opiskelijoiden pisteet listaan
    print("Please input the scores for individual students.")
    print("Finish by entering an empty line.")

    pisteet = []


def arvon_tarkistus(arvo, pisterajat):
    # Tarkistetaan onko annettu arvo käypä
    if arvo < 0:
        return False
    elif arvo in pisterajat:
        return False
    else:
        return True

def main():
    if not tulosrajat():
        print
        pisteet = opiskelijoiden_pisteet()