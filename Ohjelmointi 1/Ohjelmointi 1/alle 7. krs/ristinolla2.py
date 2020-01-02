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

def voitontarkistus(lauta, x, y, mark):
    if lauta[y][0] == lauta[y][1] == lauta[y][2] == mark:
        return True
    elif lauta[0][x] == lauta[1][x] == lauta[2][x] == mark:
        return True
    elif lauta[0][0] == lauta[1][1] == lauta[2][2] == mark:
        return True
    elif lauta[0][2] == lauta[1][1] == lauta[2][0] == mark:
        return True
    else:
        return False

def main():

    lauta = [[".", ".", "."], [".", ".", "."], [".", ".", "."]]
    turns = 0  # How many turns have been played
    pelatut =[]
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
            laudan_tulostus(lauta)
            if voitontarkistus(lauta, x, y, mark):
                print("The game ended, the winner is", mark)
                break
            turns += 1
            if turns == 9:
                print("Draw!")
                break

        except ValueError:
            print("Error: enter two integers, separated with spaces.")

        except IndexError:
            print("Error: coordinates must be between 0 and 2.")


main()
