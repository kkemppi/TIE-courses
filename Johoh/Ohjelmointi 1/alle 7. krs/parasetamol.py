# Johdatus ohjelmointiin
# Parasetamol

def calculate_dose(paino, aika, annos):
    vrk_max = 4000
    max_kerta = int(paino*15)
    anna = max_kerta
    if aika < 6:
        anna = 0
        return anna
    else:
        if annos + max_kerta > vrk_max:
            anna = vrk_max - annos
            return anna
        else:
            return anna


def main():

    paino = int(input("Patient's weight (kg): "))
    aika = int(input("How much time has passed from the previous dose (full hours): "))
    annos = int(input("The total dose for the last 24 hours (mg): "))
    annettava = calculate_dose(paino, aika, annos)
    print("The amount of Parasetamol to give to the patient:", annettava)

    # calculate_dose assumes parameters to be of type int
    # and they should be passed in the order: weight, time, total_doze_24
    # (or more like the automated tests assume this)

main()
