# Johdatus ohjelmointiin
# Introduction to programming
# Mikko Kemppi, 272670, mikko.kemppi@tuni.fi
# Area

from math import sqrt


def area(a, b, c):
    s = float((a + b + c)/2)
    ala = float(sqrt(s*(s - a)*(s - b)*(s - c)))
    return ala


def main():
    line1 = float(input("Enter the length of the first side: "))
    line2 = float(input("Enter the length of the second side: "))
    line3 = float(input("Enter the length of the third side: "))
    kolmio = area(line1, line2, line3)
    print("The triangle's area is {:.1f}".format(kolmio))
    

main()
