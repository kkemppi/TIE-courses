def main():
    sana = str(input("Enter a word: "))
    vokaalit = 0
    konsonantit = 0
    for merkki in sana:
        if vokaali_check(merkki):
            vokaalit += 1
        else:
            konsonantit += 1
    print("The word", sana, "contains", vokaalit, "vowels and", konsonantit, "consonants")


def vokaali_check(merkki):
    if merkki in "aeiouy":
        return True
    else:
        return False
main()