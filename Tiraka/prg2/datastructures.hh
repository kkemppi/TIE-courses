// Datastructures.hh

#ifndef DATASTRUCTURES_HH
#define DATASTRUCTURES_HH

#include <string>
#include <vector>
#include <tuple>
#include <utility>
#include <limits>
#include <functional>
#include <cmath>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <unordered_set>
#include <QDebug>

// Types for IDs
using PlaceID = long long int;
using AreaID = long long int;
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

// Example: Defining < for Coord so that it can be used
// as key for std::map/set
inline bool operator<(Coord c1, Coord c2)
{
    if (c1.y < c2.y) { return true; }
    else if (c2.y < c1.y) { return false; }
    else { return c1.x < c2.x; }
}

// Return value for cases where coordinates were not found
Coord const NO_COORD = {NO_VALUE, NO_VALUE};

// Type for a distance (in metres)
using Distance = int;

// Return value for cases where Duration is unknown
Distance const NO_DISTANCE = NO_VALUE;

// This is the class you are supposed to implement

class Datastructures
{
public:
    Datastructures();
    ~Datastructures();

    // Estimate of performance:
    // Short rationale for estimate:
    int place_count();

    // Estimate of performance:
    // Short rationale for estimate:
    void clear_all();

    // Estimate of performance:
    // Short rationale for estimate:
    std::vector<PlaceID> all_places();

    // Estimate of performance:
    // Short rationale for estimate:
    bool add_place(PlaceID id, Name const& name, PlaceType type, Coord xy);

    // Estimate of performance:
    // Short rationale for estimate:
    std::pair<Name, PlaceType> get_place_name_type(PlaceID id);

    // Estimate of performance:
    // Short rationale for estimate:
    Coord get_place_coord(PlaceID id);

    // We recommend you implement the operations below only after implementing the ones above

    // Estimate of performance:
    // Short rationale for estimate:
    std::vector<PlaceID> places_alphabetically();

    // Estimate of performance:
    // Short rationale for estimate:
    std::vector<PlaceID> places_coord_order();

    // Estimate of performance:
    // Short rationale for estimate:
    std::vector<PlaceID> find_places_name(Name const& name);

    // Estimate of performance:
    // Short rationale for estimate:
    std::vector<PlaceID> find_places_type(PlaceType type);

    // Estimate of performance:
    // Short rationale for estimate:
    bool change_place_name(PlaceID id, Name const& newname);

    // Estimate of performance:
    // Short rationale for estimate:
    bool change_place_coord(PlaceID id, Coord newcoord);

    // We recommend you implement the operations below only after implementing the ones above

    // Estimate of performance:
    // Short rationale for estimate:
    bool add_area(AreaID id, Name const& name, std::vector<Coord> coords);

    // Estimate of performance:
    // Short rationale for estimate:
    Name get_area_name(AreaID id);

    // Estimate of performance:
    // Short rationale for estimate:
    std::vector<Coord> get_area_coords(AreaID id);

    // Estimate of performance:
    // Short rationale for estimate:
    std::vector<AreaID> all_areas();

    // Estimate of performance:
    // Short rationale for estimate:
    bool add_subarea_to_area(AreaID id, AreaID parentid);

    // Estimate of performance:
    // Short rationale for estimate:
    std::vector<AreaID> subarea_in_areas(AreaID id);

    // Non-compulsory operations

    // Estimate of performance:
    // Short rationale for estimate:
    void creation_finished();

    // Estimate of performance:
    // Short rationale for estimate:
    std::vector<AreaID> all_subareas_in_area(AreaID id);

    // Estimate of performance:
    // Short rationale for estimate:
    std::vector<PlaceID> places_closest_to(Coord xy, PlaceType type);

    // Estimate of performance:
    // Short rationale for estimate:
    bool remove_place(PlaceID id);

    // Estimate of performance:
    // Short rationale for estimate:
    AreaID common_area_of_subareas(AreaID id1, AreaID id2);

    // Phase 2 operations

    // Estimate of performance: O(n)
    // Short rationale for estimate: Have to iterate over the vector and save
    // data to another vector. Push back is constant, but in case we go over
    // the reserved size it becomes slower.
    std::vector<WayID> all_ways();

    // Estimate of performance: O(n/2) where n=size of coordinates in the given road
    // Short rationale for estimate: Reversing a vector has complexity of half of the size.
    // May have O(n) if adding a lot of ways to a single crossroad, since emplace and push_back is amortized
    // constant on average, but linear in worst case.
    bool add_way(WayID id, std::vector<Coord> coords);

    // Estimate of performance: O(n)
    // Short rationale for estimate: Have to iterate over a vector and create another vector
    std::vector<std::pair<WayID, Coord>> ways_from(Coord xy);

    // Estimate of performance:On average constant, but O(n) since getting values from
    // unordered map can be linear in case of bad hashing.
    // Short rationale for estimate: Just a return value from an unordered map
    std::vector<Coord> get_way_coords(WayID id);

    // Estimate of performance: O(n) amount of crossroads and roads
    // Short rationale for estimate: Clear is a linear complexity method
    void clear_ways();

    // Estimate of performance: O(V+E) where V is amount of crossroads and E is amount
    // of roads.
    // Short rationale for estimate: BFS search using FIFO container is O(V+E)
    std::vector<std::tuple<Coord, WayID, Distance>> route_any(Coord fromxy, Coord toxy);

    // Non-compulsory operations

    // Estimate of performance: O(n+m) where n is amount of roads starting from at the same crossroad
    // and m is the amount of crossroads left after the removed one in the vector
    // Short rationale for estimate: Have to iterate over all roads starting from a single crossroad
    // to find the one to delete, and erasing single element is linear in the number of elements
    // after the erased one
    bool remove_way(WayID id);

    // Estimate of performance: Not implemented
    // Short rationale for estimate:
    std::vector<std::tuple<Coord, WayID, Distance>> route_least_crossroads(Coord fromxy, Coord toxy);

    // Estimate of performance: Not implemented
    // Short rationale for estimate:
    std::vector<std::tuple<Coord, WayID>> route_with_cycle(Coord fromxy);

    // Estimate of performance: Amortized O((V+E)*log(V)*r) where V is amount of crossroads and
    // E is the amount of roads and r is the amount of crossroads in the resulting path.
    // Short rationale for estimate: A* algorithm. While loop might have to go trough all crossroads
    // and for loop all roads. Every loop can have a log(n) where n = amount of crossroads in the queue.
    // Amortized because creating the result vector has push_back that can increase complexity to
    // O((V+E)*log(V)*r*n) where n = amount of result items, but is constant on average.
    std::vector<std::tuple<Coord, WayID, Distance>> route_shortest_distance(Coord fromxy, Coord toxy);

    // Estimate of performance:
    // Short rationale for estimate:
    Distance trim_ways();

private:
    // Add stuff needed for your class implementation here

    enum class Visited {NO, SEEN, YES};
    Distance calcDist(std::vector<Coord> coords);

    struct Way;

    struct Crossroad {
        Crossroad(Coord coords, std::vector<std::pair<std::shared_ptr<Way>, std::shared_ptr<Crossroad>>> ways)
            : coords(coords)
            , ways(ways) {}
        Coord coords;
        std::vector<std::pair<std::shared_ptr<Way>, std::shared_ptr<Crossroad>>> ways;
        Visited visited = Visited::NO;
        std::shared_ptr<Crossroad> previous = nullptr;
        std::shared_ptr<Way> cameFrom = nullptr;
        Distance minDist = 9999;
        Distance estimate = 9999;
    };

    struct Way {
        Way(WayID id, Distance dist, std::vector<Coord> coords)
            : id(id)
            , dist(dist)
            , coords(coords)
            {}
        WayID id;
        Distance dist;
        std::vector<Coord> coords;
    };

    std::unordered_map<Coord, std::shared_ptr<Crossroad>, CoordHash> crossroads;
    std::unordered_map<WayID, std::shared_ptr<Way>> roads;


};

#endif // DATASTRUCTURES_HH
