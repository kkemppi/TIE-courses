# TIE-02100 Johdatus ohjelmointiin
# TIE-02106 Introduction to Programming
# Task: ristinolla, program code template


def laudan_tulostus(lauta):
    valimerkki = ""
    r1 = valimerkki.join(lauta[0])
    r2 = valimerkki.join(lauta[1])
    r3 = valimerkki.join(lauta[2])
    print(r1)
    print(r2)
    print(r3)


def onko_kaytetty(pelatut, koordinaatti):
    if koordinaatti in pelatut:
        return True
    else:
        return False



def main():

    lauta = [[".", ".", "."], [".", ".", "."], [".", ".", "."]]
    turns = 0  # How many turns have been played
    pelatut =[]
    # The game continues until the board is full.
    # 9 marks have been placed on the board when the player has been
    # switched 8 times.
    laudan_tulostus(lauta)
    while turns < 9:
        # Change the mark for the player
        if turns % 2 == 0:
            mark = "X"
        else:
            mark = "O"
        coordinates = input("Player " + mark + ", give coordinates: ")
        while onko_kaytetty(pelatut, coordinates):
            print("Error: a mark has already been placed on this square.")
            coordinates = input("Player " + mark + ", give coordinates: ")
        pelatut.append(coordinates)
        try:
            x, y = coordinates.split(" ")
            x = int(x)
            y = int(y)
            lauta[y][x] = mark
            turns += 1
            laudan_tulostus(lauta)

        except ValueError:
            print("Error: enter two integers, separated with spaces.")

        except IndexError:
            print("Error: coordinates must be between 0 and 2.")


main()
