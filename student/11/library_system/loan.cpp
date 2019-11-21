#include "loan.hh"
#include "library.hh"
#include "book.hh"
#include "person.hh"
#include "date.hh"
#include <map>
#include <iostream>
#include <memory>
#include <utility>
Library lib;

Loan::Loan(Date* today, Person *borrower_id,
           Book *book_title, int renew_count):
    due_date_(new Date(today->getDay(), today->getMonth(), today->getYear())),
    borrower_id_(borrower_id),
    book_title_(book_title),
    renew_count_(renew_count)


{
    due_date_->advance_by_loan_length();
}

Loan::~Loan(){
    delete due_date_;
    due_date_ = nullptr;

}

void Loan::renew()
{
    if (renew_count_ >= DEFAULT_RENEWAL_AMOUNT){
        std::cout << OUT_OF_RENEWALS_ERROR << std::endl;
    }else{
        due_date_->advance_by_loan_length();
        renew_count_++;
        std::cout << "Renewal was successful. New due date: " << due_date_->to_string() << std::endl;
    }
}

Date* Loan::get_due_date()
{
    return due_date_;
}



std::string Loan::get_borrower()
{
    return borrower_id_->get_name();
}

std::string Loan::get_book_title()
{
    return book_title_->get_title();
}

bool Loan::is_late(Date* today)
{
    if (*due_date_ < *today){
        return true;
    }
    else{
        return false;
    }

}


