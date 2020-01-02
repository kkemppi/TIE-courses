# Fill in all TODOs in this file

from math import sqrt

# This is a text-based menu. You should ONLY touch TODOs inside the menu.
# TODOs in the menu call functions that you have implemented and take care
# of the return values of the function calls.


def menu():
    tank_size = float(read_number("How much does the vehicle's gas tank hold? "))
    gas = tank_size  # Tank is full when we start
    gas_consumption = float(read_number("How many liters of gas does the car " +
                                  "consume per hundred kilometers? "))
    x = 0.0  # Current X coordinate of the car
    y = 0.0  # Current Y coordinate of the car
    in_tank = tank_size
    while True:
        print("Coordinates x={:.1f}, y={:.1f}, "
              "the tank contains {:.1f} liters of gas.".format(x, y, gas))

        choice = input("1) Fill 2) Drive 3) Quit\n-> ")

        if choice == "1":
            to_fill = float(read_number("How many liters of gas to fill up? "))
            gas = float(fill(tank_size, to_fill, gas))

        elif choice == "2":
            new_x = read_number("x: ")
            new_y = read_number("y: ")
            gas, x, y = drive(x, y, new_x, new_y, gas, gas_consumption)

        elif choice == "3":
            break

    print("Thank you and bye!")


# This function has three parameters which are all FLOATs:
#       (1) the size of the tank
#       (2) the amount of gas that is requested to be filled in
#       (3) the amount of gas in the tank currently
#
# The parameters have to be in this order.
# The function returns one FLOAT that is the amount of gas in the
# tank AFTER the filling up.
#
# The function does not print anything and does not ask for any
# input.
def fill(tank_size, to_fill, in_tank):
    if in_tank + to_fill <= tank_size:
        in_tank = in_tank + to_fill
        return in_tank
    if in_tank + to_fill > tank_size:
        return tank_size


# This function has six parameters. They are all floats.
#   (1) The current x coordinate
#   (2) The current y coordinate
#   (3) The destination x coordinate
#   (4) The destination y coordinate
#   (5) The amount of gas in the tank currently
#   (6) The consumption of gas per 100 km of the car
#
# The parameters have to be in this order.
# The function returns three floats:
#   (1) The amount of gas in the tank AFTER the driving
#   (2) The reached (new) x coordinate
#   (3) The reached (new) y coordinate
#
# The return values have to be in this order.
# The function does not print anything and does not ask for any
# input.
def drive(x, y, new_x, new_y, in_tank, kulutus):
    d_x = abs(new_x - x)
    d_y = abs(new_y - y)
    x, y, in_tank = drive2(x, y, new_x, new_y, in_tank, kulutus, d_x, d_y)
    return in_tank, x, y


def drive2(x, y, new_x, new_y, in_tank, kulutus, d_x, d_y):
    max_distance = float((in_tank / kulutus) * 100)
    kulutettu = float(consumption(d_x, d_y, kulutus, in_tank))
    if check_tank(in_tank, kulutettu):
        in_tank = in_tank - kulutettu
        x = float(new_x)
        y = float(new_y)
        return x, y, in_tank
    if not check_tank(in_tank, kulutettu):
        tarvittava_bensa = kulutettu
        bensalla_kulkee = float(distance(d_x, d_y, kulutus, in_tank))
        d_x, d_y = tank_empty(d_x, d_y, bensalla_kulkee, tarvittava_bensa)
        in_tank = float(0)
        x = x + d_x
        y = y + d_y
        return x, y, in_tank


def consumption(d_x, d_y, kulutus, in_tank):     # Matkaan kulutettu bensa
    if d_x == 0 and d_y == 0:
        consumed = 0
        return consumed
    elif d_x == 0 or d_y == 0:
        if d_y != 0:
            consumed = float((kulutus * d_y) / 100)
            return consumed
        else:
            consumed = float((kulutus * d_x) / 100)
            return consumed
    else:
        distance_a = distance(d_x, d_y, kulutus, in_tank)
        consumed = (distance_a * kulutus) / 100
        return consumed


def distance(d_x, d_y, kulutus, in_tank):           # Tässä on huonot rakenteet
    max_distance = float((in_tank / kulutus) * 100)
    if d_x != 0 and d_y != 0:                                # Vino liike
            matka = sqrt(d_x**2+d_y**2)
            if matka > max_distance:
                matka = gas_distance(d_x, d_y, matka)
                return matka
            return matka
    elif d_x != 0 or d_y != 0:                                 # Suora liike
        if d_x != 0:
            if d_x > max_distance:
                matka = gas_distance(d_x, d_y, d_x)
                return matka
            return d_x
        elif d_y != 0:
            if d_y > max_distance:
                matka = gas_distance(d_x, d_y, d_y)
                return matka
            return d_y
    elif d_x == 0 and d_y == 0:
        return 0


def gas_distance(d_x, d_y, bensalla_kulkee):
    d_x, d_y = tank_empty(d_x, d_y, bensalla_kulkee, tarvittava_bensa)
    matka = float(sqrt(d_x**2+d_y**2))
    return matka


def tank_empty(d_x, d_y, bensalla_kulkee, tarvittava_bensa):
    d_x = (tarvittava_bensa * d_x) / bensalla_kulkee
    d_y = (tarvittava_bensa * d_y) / bensalla_kulkee
    return d_x, d_y


def check_tank(in_tank, kulutettu):
    if kulutettu <= in_tank:
        return True
    if kulutettu > in_tank:
        return False


def read_number(prompt, error_message="Incorrect input!"):

    # This function reads input from the user.
    # Do not touch this function.
    try:
        return float(input(prompt))
    except ValueError:
        print(error_message)
        return read_number(prompt, error_message)


def main():
    menu()

main()
