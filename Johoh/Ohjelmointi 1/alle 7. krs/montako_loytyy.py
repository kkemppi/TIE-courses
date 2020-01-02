def main():
    lkm = int(input("How many numbers do you want to process: "))
    lista = input_to_list(lkm)
    mika_luku = int(input("Enter the number to be searched: "))
    maara = 0
    pituus = len(lista)
    for arvo in lista:
        if arvo == mika_luku:
            maara += 1
    if maara > 0:
        print(mika_luku, "shows up", maara, "times  among the numbers you have entered.")
    else:
        print(mika_luku, "is not among the numbers you have entered.")



def input_to_list(lkm):
    lista = []
    print("Enter", lkm,  "numbers:")
    i = 0
    while i < lkm:
        luku = int(input(""))
        lista.append(luku)
        i += 1
    return lista

main()