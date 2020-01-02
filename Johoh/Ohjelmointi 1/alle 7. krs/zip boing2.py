def main():
    row = input("How many numbers would you like to have? ")
    lkm = int(row)
    for i in range(1, lkm+1):
        if i % 3 == 0 and i % 7 == 0:
            print("zip boing")
        elif i % 7 == 0:
            print("boing")
        elif i % 3 == 0:
            print("zip")
        else:
            print(i)
main()