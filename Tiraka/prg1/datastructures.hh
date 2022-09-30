// Datastructures.hh

#ifndef DATASTRUCTURES_HH
#define DATASTRUCTURES_HH

#include <string>
#include <set>
#include <vector>
#include <tuple>
#include <utility>
#include <limits>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <cmath>
#include <QDebug>


// Types for IDs
using PlaceID = long long int;
using AreaID = long int;
using Name = std::string;
using WayID = std::string;

// Return values for cases where required thing was not found
PlaceID const NO_PLACE = -1;
AreaID const NO_AREA = -1;
WayID const NO_WAY = "!!No way!!";

// Return value for cases where integer values were not found
int const NO_VALUE = std::numeric_limits<int>::min();

// Return value for cases where name values were not found
Name const NO_NAME = "!!NO_NAME!!";

// Enumeration for different place types
// !!Note since this is a C++11 "scoped enumeration", you'll have to refer to
// individual values as PlaceType::SHELTER etc.
enum class PlaceType { OTHER=0, FIREPIT, SHELTER, PARKING, PEAK, BAY, AREA, NO_TYPE };

// Type for a coordinate (x, y)
struct Coord
{
    int x = NO_VALUE;
    int y = NO_VALUE;
};

// Type for sorting distances
struct Dist
{
    int y = NO_VALUE;
    float distance = NO_VALUE;
};



// Example: Defining == and hash function for Coord so that it can be used
// as key for std::unordered_map/set, if needed
inline bool operator==(Coord c1, Coord c2) { return c1.x == c2.x && c1.y == c2.y; }
inline bool operator!=(Coord c1, Coord c2) { return !(c1==c2); } // Not strictly necessary

struct CoordHash
{
    std::size_t operator()(Coord xy) const
    {
        auto hasher = std::hash<int>();
        auto xhash = hasher(xy.x);
        auto yhash = hasher(xy.y);
        // Combine hash values (magic!)
        return xhash ^ (yhash + 0x9e3779b9 + (xhash << 6) + (xhash >> 2));
    }
};

// Defining < for Coord so that it can be used
// as key for std::map/set, which sorts according to distance from 0,0
inline bool operator<(Coord a, Coord b)
{
    double dist1 = std::sqrt(pow(a.x, 2)+pow(a.y, 2));
    double dist2 = std::sqrt(pow(b.x, 2)+pow(b.y, 2));
    if (dist1 == dist2) {
        return a.y < b.y;
    }else{
        return dist1 < dist2;
    }
}

// Defining < for Dist structs so map stays sorted
inline bool operator<(Dist a, Dist b)
{
    if (a.distance == b.distance) {
        return a.y < b.y;
    }else{
        return a.distance < b.distance;
    }
}

// Return value for cases where coordinates were not found
Coord const NO_COORD = {NO_VALUE, NO_VALUE};

// Type for a distance (in metres)
using Distance = int;

// Return value for cases where Duration is unknown
Distance const NO_DISTANCE = NO_VALUE;

// Define iterators for traversing maps
typedef std::multimap<Name, PlaceID>::iterator name_It;
typedef std::unordered_multimap<PlaceType, PlaceID>::iterator type_It;
typedef std::multimap<Coord, PlaceID>::iterator coord_It;



// This is the class you are supposed to implement

class Datastructures
{
public:
    Datastructures();
    ~Datastructures();

    // Estimate of performance: O(n)
    // Short rationale for estimate: Counting all places requires iteraing over the whole structure
    int place_count();

    // Estimate of performance: O(n)
    // Short rationale for estimate: Deleting everything requires iterating over the whole structure
    void clear_all();

    // Estimate of performance: O(n)
    // Short rationale for estimate: Requires iterating all elements
    std::vector<PlaceID> all_places();

    // Estimate of performance: O(log n)
    // Short rationale for estimate: Adding to orderd map is logarithmic
    bool add_place(PlaceID id, Name const& name, PlaceType type, Coord xy);

    // Estimate of performance:Θ(1) on avereage, worst case O(n)
    // Short rationale for estimate: Searching from unordered map
    std::pair<Name, PlaceType> get_place_name_type(PlaceID id);

    // Estimate of performance: Θ(1) on average, worst case O(n)
    // Short rationale for estimate: Searching from unordered map
    Coord get_place_coord(PlaceID id);

    // We recommend you implement the operations below only after implementing the ones above

    // Estimate of performance: O(n)
    // Short rationale for estimate: Iterating from map to vector is linear
    std::vector<PlaceID> places_alphabetically();

    // Estimate of performance: O(n)
    // Short rationale for estimate: Iterating from map to vector is linear
    std::vector<PlaceID> places_coord_order();

    // Estimate of performance: O(n) where n is amount of places with same name, Θ(1) when only one of same name
    // Short rationale for estimate: Iterating over all places with the same name is linear
    std::vector<PlaceID> find_places_name(Name const& name);

    // Estimate of performance: O(n) where n is amount of places with same type, Θ(1) when only one of same type
    // Short rationale for estimate: Iterating over all places with same type is linear
    std::vector<PlaceID> find_places_type(PlaceType type);

    // Estimate of performance: O(n) where n is amount of places with same name, Θ(1) when only one of same name
    // Short rationale for estimate: Iterating over all places with same name is linear
    bool change_place_name(PlaceID id, Name const& newname);

    // Estimate of performance: O(n) where n is amount of places with same coordinate, Θ(1) when only one of same coordinate
    // Short rationale for estimate: Iterating over all places with same coordinate is linear
    bool change_place_coord(PlaceID id, Coord newcoord);

    // We recommend you implement the operations below only after implementing the ones above

    // Estimate of performance: Constant
    // Short rationale for estimate: Adding to unordered map and adding to end of vector are constant
    bool add_area(AreaID id, Name const& name, std::vector<Coord> coords);

    // Estimate of performance: Θ(1) on average, worst case O(n)
    // Short rationale for estimate: Finding from unordered map is constant on average
    Name get_area_name(AreaID id);

    // Estimate of performance: Θ(1)
    // Short rationale for estimate: Finding from unordered map is constant
    std::vector<Coord> get_area_coords(AreaID id);

    // Estimate of performance: Θ(1)
    // Short rationale for estimate: Contains just a return value
    std::vector<AreaID> all_areas();

    // Estimate of performance: Constant
    // Short rationale for estimate: Finding from map and inserting to unordered map is constant
    bool add_subarea_to_area(AreaID id, AreaID parentid);

    // Estimate of performance: O(h) where h is height of tree from root to given node
    // Short rationale for estimate: Must iterate all nodes to root
    std::vector<AreaID> subarea_in_areas(AreaID id);

    // Non-compulsory operations

    // Estimate of performance: Θ(1)
    // Short rationale for estimate: Not used
    void creation_finished();

    // Estimate of performance: O(n)
    // Short rationale for estimate: If all areas are in a single subarea tree
    std::vector<AreaID> all_subareas_in_area(AreaID id);

    // Estimate of performance: O(n)
    // Short rationale for estimate: Iterating from map to vector is linear
    std::vector<PlaceID> places_closest_to(Coord xy, PlaceType type);

    // Estimate of performance: O(n) where n is amount of same names/types/coordinates
    // Short rationale for estimate: Must iterate over whole range of same names/types/coordinates
    bool remove_place(PlaceID id);

    // Estimate of performance: O(h)
    // Short rationale for estimate: Uses subarea_in_areas which is O(h)
    AreaID common_area_of_subareas(AreaID id1, AreaID id2);

private:
    // Add stuff needed for your class implementation here

    struct Place {
        Name const name;
        PlaceType type;
        Coord xy;
        };

    struct Area {
        Name const name;
        std::vector<Coord> coords;
        std::unordered_set<AreaID> subareas = {};
        AreaID parent = -1;
    };



    std::unordered_map<PlaceID, Place> places_;
    std::unordered_map<AreaID, Area> areas_;
    std::vector<PlaceID> place_ids;
    std::vector<AreaID> area_ids;
    std::multimap<Name, PlaceID> name_map;
    std::multimap<Coord, PlaceID> coord_map;
    std::unordered_multimap<PlaceType, PlaceID> type_map;

    std::vector<AreaID> minVec(std::vector<AreaID> a, std::vector<AreaID> b);
    std::vector<AreaID> maxVec(std::vector<AreaID> a, std::vector<AreaID> b);
};

#endif // DATASTRUCTURES_HH
