def main():
    row1 = input("Answer Y or N: ")
    vastaus = str(row1)
    while vastaus != "Y" and vastaus != "y" and vastaus != "N" and vastaus != "n":
        print("Incorrect entry.")
        row1 = input("Please retry: ")
        vastaus = str(row1)
    if vastaus == "Y" or vastaus == "y" or vastaus == "N" or vastaus == "n":
        print("You answered", vastaus)

main()