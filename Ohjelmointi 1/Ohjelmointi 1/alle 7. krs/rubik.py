def main():
    LKM = 5                      # Tulosten lukumäärä
    tulokset = []
    for i in range(LKM):
        tulos = float(input("Enter the time for performance {:1.0f}: ".format(1+i)))
        tulokset.append(tulos)
    tulokset.sort()
    pituus = len(tulokset)
    viimeinen = pituus - 1      # Viimeisen arvon indeksi
    del tulokset[0]
    viimeinen -= 1              # Listasta poistettiin yksi arvo
    del tulokset[viimeinen]
    summa = 0
    for arvo in tulokset:
        summa += arvo
    ka = float(summa/(len(tulokset)))
    print("The official competition score is {:1.2f} seconds.".format(ka))
main()