# TIE-02100 Johdatus ohjelmointiin



def main():
    english_spanish = {"hey": "hola", "thanks": "gracias", "home": "casa"}
    print("Dictionary contents:")
    print(", ".join(sorted(english_spanish)))

    while True:
        command = input("[W]ord/[A]dd/[R]emove/[P]rint/[T]ranslate/[Q]uit: ")

        if command == "W":

            word = input("Enter the word to be translated: ")
            if word in english_spanish:
                print(word, "in Spanish is", english_spanish[word])
            else:
                print("The word", word, "could not be found from the dictionary.")

        elif command == "A":
            english = input("Give the word to be added in English: ")
            spanish = input("Give the word to be added in Spanish: ")
            english_spanish[english] = spanish
            print("Dictionary contents:")
            print(", ".join(sorted(english_spanish)))

        elif command == "R":
            word = input("Give the word to be removed: ")
            if word in english_spanish:
                del english_spanish[word]
            else:
                print("The word hey could not be found from the dictionary.")

        elif command == "P":
            print()
            print("English-Spanish")
            for word in sorted(english_spanish):
                print(word, english_spanish[word])
            print()
            print("Spanish-English")
            spanish_english = {}
            for word in english_spanish:
                spanish_english[english_spanish[word]] = word
            for word in sorted(spanish_english):
                print(word, spanish_english[word])
            print()

        elif command == "T":
            row = input("Enter the text to be translated into Spanish: ")
            row_split = row.split()
            new_row = []
            for word in row_split:
                if word in english_spanish:
                    new_row.append(english_spanish[word])
                else:
                    new_row.append(word)
            new_text = " ".join(new_row)
            print("The text, translated by the dictionary:")
            print(new_text)


        elif command == "Q":
            print("Adios!")
            return

        else:
            print("Unknown command, enter W, A, R, P, T or Q!")


main()