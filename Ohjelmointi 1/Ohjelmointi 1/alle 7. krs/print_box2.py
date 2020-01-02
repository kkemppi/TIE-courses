# Johdatus ohjelmointiin
# Print a box with input checking

def print_box(L, H, M):
    for i in range(0, H):
        print(L*M)


def read_input(arvo):
    luku = 0
    while luku <= 0:
        luku = int(input(arvo))
        if luku > 0:
            return luku
            break


def main():

    L = read_input("Enter the width of a frame: ")
    H = read_input("Enter the height of a frame: ")
    M = input("Enter a print mark: ")

    
    print_box(L, H, M)

main()
