# TIE-02100 Johdatus ohjelmointiin
# TIE-02106 Introduction to Programming
# BMI

from tkinter import *


class Userinterface:

    def __init__(self):
        self.__mainwindow = Tk()
        self.__mainwindow.title("BMI calculator")

        self.__weight_label = Label(self.__mainwindow, text="Weight")
        self.__height_label = Label(self.__mainwindow, text="Height")
        self.__result_label = Label(self.__mainwindow, text="Resulting BMI:", bg="white")
        self.__empty_label = Label(self.__mainwindow, text="")

        self.__weight_value = Entry()

        self.__height_value = Entry()

        # TODO: Create a Button that will call the calculate_BMI-method.
        # TODO: Change the colour of the Button to something else than
        # the default colour.
        self.__calculate_button = Button(self.__mainwindow, text="Calculate",
                                         bg="blue", fg="yellow", relief=GROOVE
                                         , padx=30, pady=10,
                                         activebackground="green",
                                         activeforeground="red",
                                         borderwidth=3,
                                         command=self.calculate_BMI)
        # TODO: Create a Label that will show the decimal value of the BMI 
        # after it has been calculated.
        self.__result_text = Label(self.__mainwindow, bg="white", width=17)
        # TODO: Create a Label that will show a verbal description of the BMI
        # after the BMI has been calculated.
        self.__explanation_text = Label(self.__mainwindow, text="explanation", width=45)
        # TODO: Create a button that will call the stop-method.
        self.__stop_button = Button(self.__mainwindow, text="quit", command=self.stop)

        # TODO: Place the components in the GUI as you wish.
        # If you read the Gaddis book, you can use pack here instead of grid!

        self.__weight_label.grid(row=0, column=0,  columnspan=2)
        self.__height_label.grid(row=0, column=2,  columnspan=2)
        self.__weight_value.grid(row=1, column=0,  columnspan=2)
        self.__height_value.grid(row=1, column=2,  columnspan=2)
        self.__calculate_button.grid(row=2, column=0,  columnspan=4,  rowspan=2)
        self.__result_label.grid(row=4, column=0,  columnspan=2, sticky=W)
        self.__result_text.grid(row=4, column=2,  columnspan=2)
        self.__explanation_text.grid(row=5, column=0,  columnspan=4)
        self.__stop_button.grid(row=6, column=0, columnspan=4)

    # TODO: Implement this method.
    def calculate_BMI(self):
        """ Section b) This method calculates the BMI of the user and
            displays it. First the method will get the values of
            height and weight from the GUI components
            self.__height_value and self.__weight_value.  Then the
            method will calculate the value of the BMI and show it in
            the element self.__result_text. 
            
            Section e) Last, the method will display a verbal
            description of the BMI in the element
            self.__explanation_text. 
        """
        try:
            weight = float(self.__weight_value.get())
            height = float(self.__height_value.get()) / 100
            bmi = weight / (height * height)
            if weight < 0 or height < 0:
                self.__explanation_text.configure(
                    text="Error: height and weight must be positive.")
                self.reset_fields()
                pass
            else:
                self.__result_text.configure(text="{:.2f}".format(bmi))
                if bmi > 25:
                    self.__explanation_text.configure(
                        text="You are overweight.")
                elif 25 >= bmi >= 18.5:
                    self.__explanation_text.configure(
                        text="Your weight is normal.")
                else:
                    self.__explanation_text.configure(
                        text="You are underweight.")

        except ValueError:
            self.__explanation_text.configure(text="Error: height and weight must be numbers.")
            self.reset_fields()

    def reset_fields(self):
        self.__height_value.delete(0, END)
        self.__weight_value.delete(0, END)
        self.__result_text.configure(text="")


    def stop(self):
        """ Ends the execution of the program.
        """
        self.__mainwindow.destroy()

    def start(self):
        """ Starts the mainloop. 
        """
        self.__mainwindow.mainloop()


def main():
    ui = Userinterface()
    ui.start()


main()
