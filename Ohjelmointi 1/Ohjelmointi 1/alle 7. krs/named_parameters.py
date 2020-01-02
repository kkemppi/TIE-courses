# Introduction to Programming
# Named parameters
# Mikko Kemppi, 272670, mikko.kemppi@tuni.fi


def print_box(width, height, border_mark="#", inner_mark=" "):
    width = int(width)
    hieght = int(height)
    border_mark = str(border_mark)
    inner_mark = str(inner_mark)
    print(width*border_mark)
    for i in range (0, height-2):
        print(border_mark, (width-2)*inner_mark, border_mark, sep="")
    print(width*border_mark)


def main():
    print_box(5, 4)
    print("")
    print_box(3, 8, "*")
    print("")
    print_box(5, 4, "O", "o")
    print("")
    print_box(inner_mark=".", border_mark="O", height=4, width=6)

main()
