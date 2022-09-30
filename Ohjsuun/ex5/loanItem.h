#ifndef LOANITEM_H
#define LOANITEM_H

#include <list>
#include <string>
#include <memory>

class loanItem
{
public:

    /**
     * @brief
     * The first part of the pair tells the room number, the second part the shelf number.
     */
    typedef std::pair<double, double> Location;

    loanItem(std::string author, std::string title, Location location);

    std::string getAuthor();

    std::string getTite();

    /**
     * @brief
     * Returns the location of the book in the library.
     * @return the location of the book in the library
     */
    Location getLocation();

    virtual void next();

private:
    Location location_;
    std::string author_;
    std::string title_;
};

#endif // LOANITEM_H


