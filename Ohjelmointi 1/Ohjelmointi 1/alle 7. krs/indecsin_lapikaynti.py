def main():
    print("Give 5 numbers:")
    lkm = 0
    lista = []
    while lkm < 5:
        luku = int(input(("Next number: ")))
        lista.append(luku)
        lkm += 1
    print("The numbers you entered, in reverse order:")
    i = 4       # Koska viides alkio on indeksillä 4 ja ensimmöinen 0
    while 0 <= i <= 4:
        print(lista[i])
        i = i - 1
main()