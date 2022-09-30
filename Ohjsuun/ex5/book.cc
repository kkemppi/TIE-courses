#include "book.hh"
#include <iostream>

Book::Book(std::string author, std::string title, BookContent content, BookLocation location):
    author_(author),
    title_(title),
    content_(content),
    currentPage_ (content.front()),
    currentPageIterator_(content.begin()),
    location_(location)
{

}

std::string Book::getTitle()
{
    return title_;

}

std::string Book::getAuthor() const
{
    return author_;
}

void Book::turnPage()
{
    ++currentPageIterator_;
    currentPage_ = *currentPageIterator_;
}

void Book::printCurrentPage() const
{
    for (auto row : currentPage_){
        std::cout<< row << std::endl;
    }
}

void Book::save() const
{
    // Saves the book to a file
}

Book::BookLocation Book::getLocation() const
{
    return location_;
}
