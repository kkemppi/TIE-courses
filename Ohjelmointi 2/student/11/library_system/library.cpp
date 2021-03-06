#include "library.hh"
#include "loan.hh"
#include <iostream>
#include <algorithm>

// Let's use the date when the project was published as the first date.
Library::Library():
    today_(new Date(13, 11, 2019)),
    books_({}),
    authors_({}),
    accounts_({}),
    loans_(),
    is_loaned_({})

{

}

Library::~Library()
{
    // Free all memory reserved with the keyword new.
    delete today_; today_ = nullptr;
    for ( std::pair<std::string, Book*> book : books_ ){
        delete book.second;
        book.second = nullptr;
    }
    for ( std::pair<std::string, Person*> author : authors_ ){
        delete author.second;
        author.second = nullptr;
    }
    for ( std::pair<std::string, Person*> account : accounts_ ){
        delete account.second;
        account.second = nullptr;
    }

}

void Library::all_books()
{
    for ( std::pair<std::string, Book*> book : books_ ){
        std::cout << book.first << std::endl;
    }
}

void Library::all_books_with_info()
{
    std::cout << SEPARATOR_LINE << std::endl;
    for ( std::pair<std::string, Book*> book : books_ ){
        book.second->print_info();
        std::cout << SEPARATOR_LINE << std::endl;
    }
}

void Library::all_borrowers()
{
    for ( std::pair<std::string, Person*> borrower : accounts_ ){
        std::cout << borrower.first << std::endl;
    }
}

void Library::all_borrowers_with_info()
{
    std::cout << SEPARATOR_LINE << std::endl;
    for ( std::pair<std::string, Person*> borrower : accounts_ ){
        borrower.second->print_info();
        std::cout << SEPARATOR_LINE << std::endl;
    }
}

bool Library::add_book(const std::string &title, const std::vector<std::string> authors, const std::string &description, const std::set<std::string> genres)
{
    if ( authors.empty() ){
        std::cout << MISSING_AUTHOR_ERROR << std::endl;
        return false;
    }
    std::vector<Person*> author_ptrs;
    for ( std::string author : authors ){
        Person* n_person;
        if ( authors_.find(author) == authors_.end() ){
            n_person = new Person(author, "", "");
            authors_.insert({author, n_person});
        } else {
            n_person = authors_.at(author);
        }
        author_ptrs.push_back(n_person);
    }
    Book* n_book = new Book(title, author_ptrs, description, genres);
    books_.insert({title, n_book});
    is_loaned_.insert({title, false});
    return true;
}

void Library::add_borrower(const std::string &name, const std::string &email,
                           const std::string &address)
{
    if ( accounts_.find(name) != accounts_.end()){
        std::cout << DUPLICATE_PERSON_ERROR << std::endl;
        return;
    }

    Person* n_person = new Person(name, email, address);
    accounts_.insert({name, n_person});
}

void Library::set_date(int day, int month, int year)
{
    delete today_;
    today_ = new Date(day, month, year);
    today_->show();
}

void Library::advance_date(int days)
{
    today_->advance_by(days);
    today_->show();
}

Date* Library::get_today()
{
    return today_;
}

bool Library::is_book(const std::string &book_title)
{
    std::map<std::string, Book*>::iterator iter = books_.begin();
    while (iter != books_.end()){
        if (iter->first == book_title){
            return true;
        }else{
            iter++;
        }
    }return false;
}

bool Library::is_account(const std::string &borrower_id)
{
    std::map<std::string, Person*>::iterator iter = accounts_.begin();
    while (iter != accounts_.end()){
        if (iter->first == borrower_id){
            return true;
        }else{
            iter++;
        }
    }return false;
}

void Library::loaned_books()
{
    if (loans_.size() != 0){
        std::cout << "Book title : Borrower : Due date : Is late" << std::endl;
        for (Loan* item : loans_){
            bool is_late = item->is_late(today_);
            std::cout << item->get_book_title() << " : " << item->get_borrower() << " : " << item->get_due_date()->to_string() << " : " << is_late << std::endl;
        }
    }
}

void Library::loans_by(const std::string &borrower)
{
    if(!is_account(borrower)){
        std::cout << CANT_FIND_ACCOUNT_ERROR << std::endl;
    }else{
        for (Loan* item : loans_){
            if (item->get_borrower() == borrower){
                bool is_late = item->is_late(today_);
                std::cout << item->get_book_title() <<  " : " << item->get_due_date()->to_string() << " : " << is_late << std::endl;
            }
    }

    }
}

void Library::loan(const std::string &book_title, const std::string &borrower_id)
{
    if (is_loaned_[book_title]){
        std::cout << ALREADY_LOANED_ERROR << std::endl;
    }
    else if(!is_account(borrower_id)){
        std::cout << CANT_FIND_ACCOUNT_ERROR << std::endl;
    }
    else if(!is_book(book_title)){
        std::cout << CANT_FIND_BOOK_ERROR << std::endl;
    }else{
        Loan* n_loan = new Loan(today_, accounts_[borrower_id], books_[book_title]);
        loans_.push_back(n_loan);
        is_loaned_[book_title] = true;
    }

}

void Library::renew_loan(const std::string &book_title)
{

    if(!is_book(book_title)){
        std::cout << CANT_FIND_BOOK_ERROR << std::endl;
    }
    else if(!is_loaned_[book_title]){
            std::cout << LOAN_NOT_FOUND_ERROR << std::endl;
    }else{
        for (Loan* item : loans_){
            if (item->get_book_title() == book_title){
                item->renew();
            }
        }
    }
}

void Library::return_loan(const std::string &book_title)
{
    if(!is_book(book_title)){
        std::cout << CANT_FIND_BOOK_ERROR << std::endl;
    }
    else if (!is_loaned_[book_title]){
        std::cout << LOAN_NOT_FOUND_ERROR << std::endl;
    }else{
        int i = 0; // Keep i as the index of Loan to be removed
        for (Loan* item : loans_){
            if (item->get_book_title() == book_title){
                Loan* to_be_removed = item;
                loans_.erase(loans_.begin()+i);
                delete to_be_removed;
                to_be_removed = nullptr;
                is_loaned_[book_title] = false;
            }else{
                i++;
            }

        }
        std::cout << RETURN_SUCCESSFUL << std::endl;
    }

}

