def main():
    row1 = input("Bored? (y/n) ")
    onko = str(row1)
    while onko == "n":
        row1 = input("Bored? (y/n) ")
        onko = str(row1)
    if onko == "y":
        print("Well, let's stop this, then.")
main()

