def main():
    syote = input("Enter the name of the file: ")
    tiedostonnimi = str(syote)
    try:
        tiedosto = open(syote, "w")
        print("Enter rows of text. Quit by entering an empty row.")
        rivi = str(input())
        rivinro = 1
        while rivi != "":
            tiedosto.write("{} ".format(rivinro) + rivi + "\n")
            rivi = str(input())
            rivinro += 1
        tiedosto.close()
        print("File {} has been written.".format(tiedostonnimi))
    except:
        print("Writing the file {} was not successful.".format(tiedostonnimi))

main()