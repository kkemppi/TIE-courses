def main():
    lahtoajat = [630, 1015, 1415, 1620, 1720, 2000]
    lahtoaika = int(input("Enter the time (as an integer): "))
    ensimmainen = mika_eka(lahtoajat, lahtoaika)
    print("The next buses leave:")
    i = 1
    monesko = ensimmainen
    while i <= 3:
        if monesko >= 6:
            monesko = 0
        print(lahtoajat[monesko])
        monesko = monesko + 1
        i += 1


def mika_eka(lahtoajat, lahtoaika):
    hakulista = [] + lahtoajat
    hakulista.append(lahtoaika)
    hakulista.sort()
    paikka = hakulista.index(lahtoaika)
    return paikka
main()