def main():
    file = input("Enter the name of the file: ")
    try:
        tiedosto = open(file, "r")
        rivi = tiedosto.readline()
        rivinro = 1
        while rivi != "":
            rivi = rivi.rstrip()
            print("{:1d} {}".format(rivinro, rivi), sep="")
            rivinro += 1
            rivi = tiedosto.readline()
        tiedosto.close()
    except OSError:
        print("There was an error in reading the file.")

main()