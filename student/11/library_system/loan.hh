/* Module: Loan
 * ------------
 * This class and its bahaviour should be defined by the student.
 *
 * TIE-0220x S2019
 * */
#include <string>
#include <map>
#include <utility>
#include "date.hh"
#include "person.hh"
#include "library.hh"
#ifndef LOAN_HH
#define LOAN_HH

const int DEFAULT_RENEWAL_AMOUNT = 6;

class Loan
{

public:
    Loan(Date* due_date,
         Person* borrower_id,
         Book* book_title,
         int renew_count = 0
         );
    ~Loan();

void renew();

Date* get_due_date();

bool get_late();

std::string get_borrower();

std::string get_book_title();

bool is_late(Date* today);

private:

    Date* due_date_;
    Person* borrower_id_;
    Book* book_title_;
    int renew_count_;


};

#endif // LOAN_HH
