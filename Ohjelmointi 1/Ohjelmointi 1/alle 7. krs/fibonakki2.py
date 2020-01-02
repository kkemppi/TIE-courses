def main():
    row = input("How many Fibonacci numbers do you want? ")
    lkm = int(row)
    i = 0
    a = 1
    b = 1
    if lkm > i:
        if lkm <= 0:
            print("")
            i += 2
        elif lkm <= 2 and lkm > 0:
            for i in range(lkm):
                i += 1
                print(i, ".", sep=(""), end=" ")
                print(1)
        elif lkm > 2:
            print(1, ".", sep=(""), end=" ")
            print(1)
            print(2, ".", sep=(""), end=" ")
            print(1)
            while lkm-2 > i:
                f = a + b
                a = b
                print(i+3, ".", sep=(""), end=" ")
                print(f)
                b = f
                i += 1
main()