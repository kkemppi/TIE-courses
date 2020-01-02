def main():
    m = 1
#31
#28
#31
#30
#31
#30
#31
#31
#30
#31
#30
#31
    for m in range(13):
        d = 1
        while m == 1 or m == 3 or m == 5 or m == 7 or m == 8 or m == 10 or m == 12:
            while d <= 31:
                print(d, ".", m, ".", sep="")
                d = d+1
            m = m+1
        while m == 2:
            while d <= 28:
                print(d, ".", m, ".", sep="")
                d = d + 1
            m = m + 1
        while m == 4 or m == 6 or m == 9 or m == 11:
            while d <= 30:
                print(d, ".", m, ".", sep="")
                d = d + 1
            m = m + 1
main()