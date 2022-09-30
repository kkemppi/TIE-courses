#ifndef BOOK_HH
#define BOOK_HH


#include <loanItem.h>

class Page
{
    public:
    /**
     * @brief
     * The text rows in a book page as a list.
     */
    typedef std::list<std::string> BookPage;

    /**
     * @brief
     * Prints the current page of the book to cout.
     */

    void printCurrentPage() const;

};

/**
 * @brief The Book class for the Library project
 * @note Only at the initial stage, could change a lot in the future.
 */
class Book : public loanItem
{
public:


    /**
     * @brief
     * The pages of a book as a list.
     */
    typedef std::list<Page::BookPage> BookContent;

    /**
     * @brief the constructor for the Book class
     * @param author the author of the book
     * @param title the title of the book
     * @param content the content of the book
     * @param location the location of the book
     */
    Book(std::string author, std::string title, BookContent content);

    /**
     * @brief Returns the title of the book.
     * @return the title of the book
     */
    std::string getTitle();

    /**
     * @brief Returns the author of the book.
     * @return the author of the book
     */
    std::string getAuthor();

    /**
     * @brief Turns the page of the book.
     */
    void next();



private:
    BookContent content_;
    BookContent::iterator currentPageIterator_;
};

#endif // BOOK_HH
