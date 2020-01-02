#ifndef GIRAFFE_HH
#define GIRAFFE_HH
#include "mammal.hh"

class Giraffe : public Mammal
{
public:
    Giraffe();
    void make_noise(std::ostream& output) const;

private:
    std::string moving_noise_;
};

#endif // GIRAFFE_HH
