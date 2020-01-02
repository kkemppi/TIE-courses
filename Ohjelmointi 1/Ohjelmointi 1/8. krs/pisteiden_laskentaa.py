def main():
    tiedosto = input("Enter the name of the score file: ")

    try:
        pelaajien_pisteet = file_to_dict(tiedosto)
        if not isinstance(pelaajien_pisteet, dict):
            print(pelaajien_pisteet)
        else:
            jarjestetty = sorted(pelaajien_pisteet)
            print("Contestant score:")
            for i in jarjestetty:
                print(i, pelaajien_pisteet[i])

    except OSError:
        print("There was an error in reading the file.")


def file_to_dict(tiedosto):
    pisteet = open(tiedosto, "r")
    rivi = pisteet.readline()
    pelaajien_pisteet = {}
    while rivi != "":
        try:
            rivi = rivi.rstrip()
            rivin_arvot = rivi.split(" ")
            nimi = str(rivin_arvot[0])
            tulos = int(rivin_arvot[1])
            if nimi not in pelaajien_pisteet:
                pelaajien_pisteet[nimi] = 0
            pelaajien_pisteet[nimi] = pelaajien_pisteet[nimi] + tulos
            rivi = pisteet.readline()
        except IndexError:
            return "There was an erroneous line in the file:\n{}".format(rivi)
        except ValueError:
            return "There was an erroneous score in the file:\n{}".format(rivin_arvot[1])
    pisteet.close()
    return pelaajien_pisteet

main()


