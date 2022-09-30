#ifndef LIBRARYCOUNTER_HH
#define LIBRARYCOUNTER_HH

#include <loanItem.h>

class LibraryCounter
{
public:
    LibraryCounter();

    /**
     * @brief Mark the item as loaned.
     * @param cd the loaned item
     */
    void loan(std::weak_ptr<loanItem> item);

    /**
     * @brief Mark the item as returned.
     * @param cd the returned item
     */
    void returnItem(std::weak_ptr<loanItem> item);


private:


};

#endif // LIBRARYCOUNTER_HH
