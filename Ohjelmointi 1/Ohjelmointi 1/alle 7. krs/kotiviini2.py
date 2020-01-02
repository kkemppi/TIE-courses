def main():
    luku = input("Enter the number of measurements: ")
    mittaukset = int(luku)
    #Lopetetaan koko homma jos antaa tyhmiä lukuja
    if mittaukset <= 0:
        print("The number of measurements must be a positive number.")
    #Muu homma
    else:
        i = 1
        epakelpoja = 0
        suhde = 0
        perakkais = 0
        while mittaukset > i-1:
            if suhde > 0.1 or perakkais >= 2:
                print("Your wine is ruined.")
                break
            luku = input("Enter the temperature {:1d}: ".format(i))
            lampotila = int(luku)
            if mittaukset == i:
                print("Your wine is ready.")
                break
            if lampotila >= 20 and lampotila <= 25:
                if perakkais >= 0:
                    perakkais = 0
            else:
                epakelpoja = epakelpoja + 1
                perakkais = perakkais + 1
            suhde = epakelpoja / mittaukset
            i = i + 1




main()