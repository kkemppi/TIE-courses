#ifndef CD_HH
#define CD_HH

#include <loanItem.h>

/**
 * Forward declaration for the Track class.
 */
class Track;

/**
 * @brief The CD class implements a loanable CD disc in the library.
 * @note Unfinished, and badly!
 */
class CD : public loanItem
{
public:
    /**
     * @brief
     * A List of shared pointer to the Track objects.
     */
    typedef std::list<std::shared_ptr<Track>> CDContent;

    CD(CDContent content);

    /**
     * @brief Changes the current track to the next track.
     */
    void next();

private:
    CDContent content_;
    CDContent::iterator currentTrack_;
};

#endif // CD_HH
