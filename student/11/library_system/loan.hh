/* Module: Loan
 * ------------
 * Class of a single loan instance. Contains the loaned date, book title and
 * borrower id. Borrower and book title are stored as pointers to original book
 * and person object. Date is a new object unique to this class.
 *
 * TIE-02207 S2019
 * */
#include "date.hh"
#include "person.hh"
#include "library.hh"
#include <string>
#include <map>
#include <utility>
#ifndef LOAN_HH
#define LOAN_HH

const int DEFAULT_RENEWAL_AMOUNT = 6;

class Loan
{

public:
    Loan(Date* due_date,
         Person* borrower_id,
         Book* book_title,
         int renew_count = 0);
    ~Loan();

// Extends loan due date by set amount of days. Checks if too many renewals
// have been made
void renew();

// Get methods
Date* get_due_date();
std::string get_borrower();
std::string get_book_title();

// Checks if loan is late compared to given Date
bool is_late(Date* today);

private:

    // Pointers to date, borrower and loaned book
    Date* due_date_;
    Person* borrower_id_;
    Book* book_title_;
    // Amount of renewals that have been made
    int renew_count_;


};

#endif // LOAN_HH
