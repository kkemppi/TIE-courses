class Fraction:
    """ This class represents one single fraction that consists of
        numerator and denominator """

    def __init__(self, numerator, denominator):
        """
        Constructor. Checks that the numerator and denominator are of
        correct type and initializes them.

        :param numerator: fraction's numerator
        :param denominator: fraction's denominator
        """

        if not isinstance(numerator, int) or not isinstance(denominator, int):
            raise TypeError
        elif denominator == 0:
            raise ValueError

        self.__numerator = numerator
        self.__denominator = denominator

    def __str__(self):
        return "{}/{}".format(self.__numerator, self.__denominator)

    def get_numerator(self):
        return self.__numerator

    def get_denominator(self):
        return self.__denominator

    def return_string(self):
        """ Returns a string-presentation of the fraction in the format
        numerator/denominator """

        if self.__numerator * self.__denominator < 0:
            sign = "-"
        else:
            sign = ""
        return "{:s}{:d}/{:d}".format(sign, abs(self.__numerator),
                                     abs(self.__denominator))

    def simplify(self):
        divisor = greatest_common_divisor(self.__numerator, self.__denominator)
        self.__numerator = int(self.__numerator / divisor)
        self.__denominator = int(self.__denominator / divisor)

    def reciprocal(self):
        reciprocal_object = Fraction(self.__denominator, self.__numerator)
        return reciprocal_object

    def complement(self):
        complement_object = Fraction(-self.__numerator, self.__denominator)
        return complement_object

    def multiply(self, frac2):
        prod_numerator = self.__numerator * frac2.get_numerator()
        prod_denominator = self.__denominator * frac2.get_denominator()
        product = Fraction(prod_numerator, prod_denominator)
        return product

    def divide(self, frac2):
        fraction2 = frac2.reciprocal()
        quotient = self.multiply(fraction2)
        return quotient

    def add(self, frac2):
        if self.__denominator != frac2.get_denominator():
            frac2_multiplier = Fraction(self.__denominator, self.__denominator)
            self_multiplier = Fraction(frac2.get_denominator(), frac2.get_denominator())
            new_self = self.multiply(self_multiplier)
            new_frac2 = frac2.multiply(frac2_multiplier)
            new_numerator = new_self.get_numerator() + new_frac2.get_numerator()
            new_denominator = new_self.get_denominator()
            product = Fraction(new_numerator, new_denominator)
            return product

        else:
            new_numerator = self.__numerator + frac2.get_numerator()
            new_denominator = self.__denominator + frac2.get_denominator()
            return Fraction(new_numerator, new_denominator)

    def deduct(self, frac2):
        if self.__denominator != frac2.get_denominator():
            frac2_multiplier = Fraction(self.__denominator, self.__denominator)
            self_multiplier = Fraction(frac2.get_denominator(), frac2.get_denominator())
            new_self = self.multiply(self_multiplier)
            new_frac2 = frac2.multiply(frac2_multiplier)
            new_numerator = new_self.get_numerator() - new_frac2.get_numerator()
            new_denominator = new_self.get_denominator()
            product = Fraction(new_numerator, new_denominator)
            return product

        else:
            new_numerator = self.__numerator + frac2.get_numerator()
            new_denominator = self.__denominator + frac2.get_denominator()
            return Fraction(new_numerator, new_denominator)

    def __lt__(self, frac2):
        if self.__denominator != frac2.get_denominator():
            frac2_multiplier = Fraction(self.__denominator, self.__denominator)
            self_multiplier = Fraction(frac2.get_denominator(), frac2.get_denominator())
            new_self = self.multiply(self_multiplier)
            new_frac2 = frac2.multiply(frac2_multiplier)
            new_self_numerator = new_self.get_numerator()
            new_frac2_numerator = new_frac2.get_numerator()
            return new_self_numerator < new_frac2_numerator

        else:
            return self.__numerator < frac2.get_numerator()

def greatest_common_divisor(a, b):
    """
    Euclidean algorithm.
    """

    while b != 0:
        a, b = b, a % b
    return a

def main():
    commands = ["add", "quit", "print", "list", "*", "file"]
    command = ""
    keylist = []
    fractions = {}
    while command != "quit":
        command = input("> ")
        if command not in commands:
            print("Unknown command!")
        if command == "add":
            frac = input("Enter a fraction in the form integer/integer: ")
            name = input("Enter a name: ")
            frac = frac.split("/")
            numerator = int(frac[0])
            denominator = int(frac[1])
            if numerator < 0 and denominator < 0:
                numerator = abs(numerator)
                denominator = abs(denominator)
            if denominator < 0 and numerator > 0:
                numerator = -1 * numerator
                denominator = abs(denominator)
            fractions[name] = Fraction(numerator, denominator)
            keylist = list(fractions.keys())
            keylist.sort()
        if command == "print":
            name = input("Enter a name: ")
            if name in fractions:
                print(name, "=", fractions[name])
            else:
                print("Name {} was not found".format(name))
        if command == "list":
            if len(keylist) == 0:
                pass
            for key in keylist:
                print(key, "=", fractions[key])
        if command == "*":
            first = input("1st operand: ")
            if first in keylist:
                second = input("2nd operand: ")
                if second in keylist:
                    product = fractions[first].multiply(fractions[second])
                    print(fractions[first], "*", fractions[second], "=", product)
                    product.simplify()
                    print("simplified", product)
                else:
                    print("Name {} was not found".format(second))
            else:
                print("Name {} was not found".format(first))
        if command == "file":
            filename = str(input("Enter the name of the file: "))
            try:
                source = open(filename, "r")
                row = str(source.readline())
                while row != "":
                    row = row.rstrip()
                    row = row.split("=")
                    name = row[0]
                    frac = row[1]
                    frac = frac.split("/")
                    numerator = int(frac[0])
                    denominator = int(frac[1])
                    fractions[name] = Fraction(numerator, denominator)
                    keylist = list(fractions.keys())
                    keylist.sort()
                    row = source.readline()
            except:
                print("Error: the file cannot be read.")

    print("Bye bye!")
main()