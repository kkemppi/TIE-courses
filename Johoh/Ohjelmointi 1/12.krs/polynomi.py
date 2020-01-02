# TIE-02107, Johdatus ohjelmointiin, Tampere University
# 12.3, Polynomilaskin
# Mikko Kemppi, 272670, mikko.kemppi@tuni.fi
# Olli Pettersson, 283651, olli.pettersson@tuni.fi


class Polynomial:
    """
    Creates a new polynomial object from a correctly formatted string.
    Sorts the terms by exponents in a dict, where key is exponent and value
    is multiplier.
    """
    def __init__(self, row):
        self.__string = row
        self.__termlist = row.split(";")
        self.__terms_string = {}
        self.__terms_nonsorted = {}
        self.__terms = {}  # Dict where key is exponent and value is multiplier
        for term in self.__termlist:
            multipliers = term.split(" ")
            self.__terms_nonsorted[int(multipliers[1])] = int(multipliers[0])

        self.__keylist = sorted(self.__terms_nonsorted, reverse=True)
        for key in self.__keylist:
            self.__terms[key] = self.__terms_nonsorted[key]
        zerolist = []
        for key in self.__terms:
            if self.__terms[key] == 0:
                zerolist.append(key)
        for key in zerolist:
            del self.__terms[key]

    def __str__(self):
        self.__printlist = []
        # First check for only one term where multiplier is 0
        x = 0
        if len(self.__terms) == 0:
            return "0"
        for value in self.__terms.values():
            if value == 0:
                x += 1
            if len(self.__terms.values()) == x:
                return "0"
        for key in self.__terms:
            string = "{}x^{}".format(self.__terms[key], key)
            self.__printlist.append(string)
        return " + ".join(self.__printlist)

    def keylist(self):                  # Returns keylist of terms
        return list(self.__terms.keys())

    def terms(self, num):               # Returns multiplier for given exponent
        return self.__terms[num]

    def negative(self):                 # Makes all terms negative
        for key in self.__terms:
            self.__terms[key] = -1 * self.__terms[key]

    def get_string(self):
        return self.__string

    def get_terms(self):
        return self.__terms

    def sum(self, poly):
        """
        Sums two polynomials together
        :param poly: Polynomial to be added to self
        :return: another polynomial added to self as an object
        """
        sum = {}    # Dict of resulting polynomial
        row = []
        for x in self.keylist():
            # Check if both polynomials have terms with same exponents
            if x in poly.keylist():
                value = self.__terms[x] + poly.terms(x)  # Sum of multipliers
                sum[x] = value
            else:
                value = self.__terms[x]
                sum[x] = value

        # Check terms that don't have equal exponents the other way
        for x in poly.keylist():
            if x not in self.keylist():
                value = poly.terms(x)
                sum[x] = value

        # Turn the resulting dict to a str
        for x in sum.keys():
            pol = "{} {}".format(sum[x], x)
            row.append(pol)
        string = ";".join(row)

        # Only nonzero terms have been added, so result
        # is zero if nothing has been added
        if len(string) == 0:
            return "0"
        else:
            sum_poly = Polynomial(string)
            return sum_poly

    def difference(self, poly):
        """
        Difference is the same as th sum with a negative polynom
        :param poly: Polynomial to be turned negative
        :return: another polynomial subratacted from self
        """
        neg_poly = Polynomial(poly.get_string())
        neg_poly.negative()
        return self.sum(neg_poly)

    def multiply(self, poly):
        """
        Multiplies two polynomials together
        :param poly: Polynomial to multiply with self
        :return: Resultin polynomial
        """
        multiply = {}   # Dict of resulting polynomial
        row = []

        # Multiply every term of self with every term of poly
        for a in self.keylist():
            for b in poly.keylist():
                new_key = a + b
                # Check if there is already a term with the same exponent
                if new_key in multiply:
                    old_value = multiply[new_key]
                    multiply[new_key] = self.__terms[a] * poly.terms(b) + old_value
                else:
                    if self.__terms[a] * poly.terms(b) != 0:
                        multiply[new_key] = self.__terms[a] * poly.terms(b)

        # Turn multiplied dict to str
        for x in multiply.keys():
            pol = "{} {}".format(multiply[x], x)
            row.append(pol)
        string = ";".join(row)

        # Only nonzero terms have been added, so result
        # is zero if nothing has been added
        if len(string) == 0:
            return "0"
        else:
            result_poly = Polynomial(string)
            return result_poly


def readfile(filename):
    """
    Reads a file row by row and creates a new Polynomial object if able, saves
    these objects to a list
    :param filename: Name of the file to be read
    :return: List of Polynomial objects, or False if the file
    is not compatible
    """
    polynomials = []
    try:
        file = open(filename, "r")
        for row in file:
            row = row.strip(" ")
            row = row.rstrip()
            poly = Polynomial(str(row))
            polynomials.append(poly)
        return polynomials
    except:
        return False


def main():
    # Displays the user interface of this calculator
    # Checks for errors on inputs
    filename = input("Enter file name: ")
    operators = {"+": lambda poly1, poly2: poly1.sum(poly2),
                 "-": lambda poly1, poly2: poly1.difference(poly2),
                 "*": lambda poly1, poly2: poly1.multiply(poly2)}
    if readfile(filename):
        polynomials = readfile(filename)

        while True:

            command = input("> ")
            commands = command.split(" ")

            try:                         # Check for correct input
                test1 = int(commands[0])
                test2 = int(commands[2])
                operator = commands[1]
            # If these raise an error, there cannot be an operator
            except IndexError:
                operator = None
            except ValueError:
                operator = None

            if operator in operators:
                try:
                    poly1 = polynomials[int(commands[0])]
                    poly2 = polynomials[int(commands[2])]
                    print("Memory location {}:".format(commands[0]), poly1)
                    print("Memory location {}:".format(commands[2]), poly2)
                    print("The simplified result:")
                    polynomial = operators[operator](poly1, poly2)
                    print(polynomial)

                except IndexError:
                    print("Error: the given memory location does not exist.")
                    pass

            elif command == "quit":     # Terminate program
                print("Bye bye!")
                break

            elif operator is None:
                print("Error: entry format is memory_location"
                      " operation memory_location.")

            else:       # If there is an operator, but it is not known
                print("Error: unknown operator.")
    else:
        print("Error in reading the file.")
main()


