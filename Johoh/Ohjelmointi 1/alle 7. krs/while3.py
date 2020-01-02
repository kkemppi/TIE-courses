def main():
    row1 = input("Bored? (y/n) ")
    vastaus = str(row1)
    while vastaus != "Y" and vastaus != "y" and vastaus != "N" and vastaus != "n":
        print("Incorrect entry.")
        row1 = input("Please retry: ")
        vastaus = str(row1)
    while vastaus == "n" or vastaus == "N":
        row1 = input("Bored? (y/n) ")
        vastaus = str(row1)
        while vastaus != "Y" and vastaus != "y" and vastaus != "N" and vastaus != "n":
            print("Incorrect entry.")
            row1 = input("Please retry: ")
            vastaus = str(row1)
    if vastaus == "y" or vastaus == "Y":
        print("Well, let's stop this, then.")
main()