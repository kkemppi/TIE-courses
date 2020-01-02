def main():
    x=1
    z=-2
    for x in range(13):
        i=1
        while x == 1 or x == 3 or x == 5 or x == 7 or x == 8 or x == 10 or x == 12:
            while i <= 31:
                if z & 7 == 0:
                    print(i, ".", x, ".", sep="")
                    i = i + 1
                    z = z + 2
                else:
                    i = i + 1
                    z = z + 1
            x=x+1
        while x == 2:
            while i <= 28:
                if z & 7 == 0:
                    print(i,".",x,".", sep="")
                    i = i + 1
                    z = z + 2
                else:
                    i = i + 1
                    z = z + 1
            x = x + 1
        while x == 4 or x == 6 or x == 9 or x == 11:
            while i <= 30:
                if z & 7 == 0:
                    print(i,".",x,".", sep="")
                    i = i + 1
                    z = z + 2
                else:
                    i = i + 1
                    z = z + 1
            x = x + 1

main()