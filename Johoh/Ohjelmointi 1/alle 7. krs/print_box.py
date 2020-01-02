# TIE-02100 Johdatus ohjelmointiin
# TIE-02106 Introduction to Programming
# Mikko Kemppi, 272670, mikko.kemppi@tuni.fi
# Template for task: ruutu

def print_box(L, H, M1=):
    for i in range(0, H):
        print(L*M)

def main():
    L = int(input("Enter the width of a frame: "))
    H = int(input("Enter the height of a frame: "))
    M = input("Enter a print mark: ")
    print_box(L, H, M)

main()