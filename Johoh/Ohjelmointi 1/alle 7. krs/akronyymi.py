def create_an_acronym(nimi):
    sanat = nimi.split()
    kirjaimet = []
    for sana in sanat:
        kirjain = sana[0]
        kirjain = kirjain.upper()
        kirjaimet.append(kirjain)
    akronyymi = ""
    for kirjain in kirjaimet:
        akronyymi += kirjain
    return akronyymi
