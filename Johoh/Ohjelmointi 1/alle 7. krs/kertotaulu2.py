def main():
    row1 = input("Choose a number: ")
    luku = int(row1)
    i = 0
    tulos = i * luku
    while tulos <= 100:
        i += 1
        tulos = i * luku
        print(i, "*", luku, "=", tulos)
main()