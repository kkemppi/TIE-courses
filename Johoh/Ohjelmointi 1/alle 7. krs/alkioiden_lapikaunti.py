def main():
    print("Give 5 numbers:")
    lkm = 0
    lista = []
    while lkm < 5:
        luku = int(input(("Next number: ")))
        lista.append(luku)
        lkm += 1
    print("The numbers you entered that were greater than zero were:")
    for luku in lista:
        if luku > 0:
            print(luku)
main()