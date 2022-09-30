#ifndef ITEMSAVER_H
#define ITEMSAVER_H

#include <loanItem.h>

class itemSaver
{
public:
    itemSaver();

    /**
     * @brief Saves the given item to a file.
     */
    void save(loanItem)const;
};

#endif // ITEMSAVER_H
