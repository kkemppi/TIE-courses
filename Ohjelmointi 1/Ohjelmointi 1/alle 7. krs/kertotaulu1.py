def main():
    row1 = input("Choose a number: ")
    luku = int(row1)
    i = 0
    while i < 10:
        i += 1
        tulos = i * luku
        print(i, "*", luku, "=", tulos)
main()