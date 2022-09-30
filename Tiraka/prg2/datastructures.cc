// Datastructures.cc

#include "datastructures.hh"

#include <random>

#include <cmath>

std::minstd_rand rand_engine; // Reasonably quick pseudo-random generator

template <typename Type>
Type random_in_range(Type start, Type end)
{
    auto range = end-start;
    ++range;

    auto num = std::uniform_int_distribution<unsigned long int>(0, range-1)(rand_engine);

    return static_cast<Type>(start+num);
}

// Modify the code below to implement the functionality of the class.
// Also remove comments from the parameter names when you implement
// an operation (Commenting out parameter name prevents compiler from
// warning about unused parameters on operations you haven't yet implemented.)

Datastructures::Datastructures()
{
    // Replace this comment with your implementation
}

Datastructures::~Datastructures()
{
    // Replace this comment with your implementation
}

int Datastructures::place_count()
{
    // Replace this comment with your implementation
    return 0;
}

void Datastructures::clear_all()
{
    // Replace this comment with your implementation
}

std::vector<PlaceID> Datastructures::all_places()
{
    // Replace this comment with your implementation
    return {};
}

bool Datastructures::add_place(PlaceID id, const Name& name, PlaceType type, Coord xy)
{
    // Replace this comment with your implementation
    return false;
}

std::pair<Name, PlaceType> Datastructures::get_place_name_type(PlaceID id)
{
    // Replace this comment with your implementation
    return {NO_NAME, PlaceType::NO_TYPE};
}

Coord Datastructures::get_place_coord(PlaceID id)
{
    // Replace this comment with your implementation
    return NO_COORD;
}

bool Datastructures::add_area(AreaID id, const Name &name, std::vector<Coord> coords)
{
    // Replace this comment with your implementation
    return false;
}

Name Datastructures::get_area_name(AreaID id)
{
    // Replace this comment with your implementation
    return NO_NAME;
}

std::vector<Coord> Datastructures::get_area_coords(AreaID id)
{
    // Replace this comment with your implementation
    return {NO_COORD};
}

void Datastructures::creation_finished()
{
    // Replace this comment with your implementation
    // NOTE!! It's quite ok to leave this empty, if you don't need operations
    // that are performed after all additions have been done.
}


std::vector<PlaceID> Datastructures::places_alphabetically()
{
    // Replace this comment with your implementation
    return {};
}

std::vector<PlaceID> Datastructures::places_coord_order()
{
    // Replace this comment with your implementation
    return {};
}

std::vector<PlaceID> Datastructures::find_places_name(Name const& name)
{
    // Replace this comment with your implementation
    return {};
}

std::vector<PlaceID> Datastructures::find_places_type(PlaceType type)
{
    // Replace this comment with your implementation
    return {};
}

bool Datastructures::change_place_name(PlaceID id, const Name& newname)
{
    // Replace this comment with your implementation
    return false;
}

bool Datastructures::change_place_coord(PlaceID id, Coord newcoord)
{
    // Replace this comment with your implementation
    return false;
}

std::vector<AreaID> Datastructures::all_areas()
{
    // Replace this comment with your implementation
    return {};
}

bool Datastructures::add_subarea_to_area(AreaID id, AreaID parentid)
{
    // Replace this comment with your implementation
    return false;
}

std::vector<AreaID> Datastructures::subarea_in_areas(AreaID id)
{
    // Replace this comment with your implementation
    return {NO_AREA};
}

std::vector<PlaceID> Datastructures::places_closest_to(Coord xy, PlaceType type)
{
    // Replace this comment with your implementation
    return {};
}

bool Datastructures::remove_place(PlaceID id)
{
    // Replace this comment with your implementation
    return false;
}

std::vector<AreaID> Datastructures::all_subareas_in_area(AreaID id)
{
    // Replace this comment with your implementation
    return {NO_AREA};
}

AreaID Datastructures::common_area_of_subareas(AreaID id1, AreaID id2)
{
    // Replace this comment with your implementation
    return NO_AREA;
}

std::vector<WayID> Datastructures::all_ways()
{
    std::vector<WayID> result = {};
    for (auto way : roads) {
        result.push_back(way.second->id);
    }
    return result;
}

bool Datastructures::add_way(WayID id, std::vector<Coord> coords)
{   
    if (roads.find(id) != roads.end()){
        return false;
    }else{
        int distance = calcDist(coords);
        Coord end_coord = coords.back();
        Coord start_coord = coords.front();
        bool start_added = false;
        bool end_added = false;

        std::shared_ptr<Crossroad> start = nullptr;
        std::shared_ptr<Crossroad> end = nullptr;

        std::shared_ptr<Way> new_way_forward = std::make_shared<Way>(id, distance, coords);
        roads.emplace(id, new_way_forward);

        if (crossroads.find(start_coord) == crossroads.end()) {
            std::vector<std::pair<std::shared_ptr<Way>, std::shared_ptr<Crossroad>>> ways = {{new_way_forward, nullptr}};
            std::shared_ptr<Crossroad> newStartCrossroad = std::make_shared<Crossroad>(start_coord, ways);
            crossroads.emplace(start_coord, newStartCrossroad);
            start = newStartCrossroad;
            start_added = true;
        }else{
            start = crossroads.at(start_coord);
        }

        std::reverse(coords.begin(), coords.end());
        std::shared_ptr<Way> new_way_backward = std::make_shared<Way>(id, distance, coords);
        if (crossroads.find(end_coord) == crossroads.end()) {
            std::vector<std::pair<std::shared_ptr<Way>, std::shared_ptr<Crossroad>>> ways = {{new_way_backward, nullptr}};
            std::shared_ptr<Crossroad> newEndCrossroad = std::make_shared<Crossroad>(end_coord, ways);
            crossroads.emplace(end_coord, newEndCrossroad);
            end = newEndCrossroad;
            end_added = true;
        }else{
            end = crossroads.at(end_coord);
        }


        if (!start_added) {
            crossroads.at(start_coord)->ways.push_back(std::make_pair(new_way_forward, end));
        }else{
            start->ways.front().second = end;
        }
        if (!end_added) {
            crossroads.at(end_coord)->ways.push_back(std::make_pair(new_way_backward, start));
        }else{
            end->ways.front().second = start;
        }

    }
    return true;
}

std::vector<std::pair<WayID, Coord>> Datastructures::ways_from(Coord xy)
{
    std::vector<std::pair<WayID, Coord>> ways;
    if (crossroads.find(xy) == crossroads.end()){
        return {};
    }else{
        for (auto way : crossroads.at(xy)->ways) {
            ways.push_back({way.first->id, way.second->coords});
        }
        return ways;
    }

}

std::vector<Coord> Datastructures::get_way_coords(WayID id)
{
    if (roads.find(id) == roads.end()){
        return {NO_COORD};
    }else{
        return roads.at(id)->coords;
    }


}

void Datastructures::clear_ways()
{
    crossroads.clear();
    roads.clear();
}

std::vector<std::tuple<Coord, WayID, Distance> > Datastructures::route_any(Coord fromxy, Coord toxy)
{
    std::vector<std::tuple<Coord, WayID, Distance> > result;
    if (crossroads.find(fromxy) == crossroads.end() || crossroads.find(toxy) == crossroads.end()) {
        return {{NO_COORD, NO_WAY, NO_DISTANCE}};
    }else{
        std::shared_ptr<Crossroad> root = crossroads.at(fromxy);
        root->minDist = 0;
        std::queue<std::shared_ptr<Crossroad>> que;
        std::unordered_set<Coord, CoordHash> visited;
        bool resultFound = false;

        que.push({root});
        while (!que.empty()) {
            std::shared_ptr<Crossroad> crossroad = que.front();
            que.pop();
            if (crossroad->coords == toxy) {
                result.push_back({crossroad->coords, NO_WAY, crossroad->minDist});
                while (crossroad->previous != nullptr) {
                    std::shared_ptr<Way> way = crossroad->cameFrom;
                    crossroad = crossroad->previous;
                    result.push_back({crossroad->coords, way->id, crossroad->minDist});
                }
                std::reverse(result.begin(), result.end());
                resultFound = true;
                break;
            }else{
                for (auto way : crossroad->ways) {
                    if (way.second->visited == Visited::NO) {
                        way.second->previous = crossroad;
                        way.second->cameFrom = way.first;
                        way.second->minDist = crossroad->minDist+way.first->dist;
                        crossroad->visited = Visited::YES;
                        que.push(way.second);
                    }
                }
            }
        }
        for (auto crossroad : crossroads) {
            crossroad.second->minDist = 9999;
            crossroad.second->visited = Visited::NO;
            crossroad.second->previous = nullptr;
            crossroad.second->cameFrom = nullptr;
        }
        if (resultFound) {
            return result;
        }
        return {};
    }
}

bool Datastructures::remove_way(WayID id)
{
    if (roads.find(id) == roads.end()){
        return false;
    }else{
        std::pair<Coord, Coord> endpoints = {roads.at(id)->coords.front(), roads.at(id)->coords.back()};


        std::shared_ptr<Crossroad> start = crossroads.at(endpoints.first);
        std::shared_ptr<Crossroad> end = crossroads.at(endpoints.second);

        std::shared_ptr<Way> roadToRemove = roads.at(id);
        std::shared_ptr<Way> roadToRemoveEnd;
        for (auto way : end->ways) {
            if (way.first->id == id) {
                roadToRemoveEnd = way.first;
            }
        }

        std::vector<std::pair<std::shared_ptr<Way>, std::shared_ptr<Crossroad>>> &startRoads = start->ways;
        std::vector<std::pair<std::shared_ptr<Way>, std::shared_ptr<Crossroad>>> &endRoads = end->ways;
        int i = 0,j = 0;
        for (auto road : startRoads) {
            if (road.first == roadToRemove) {
                startRoads.erase(startRoads.begin()+i);
                if (startRoads.empty()) {
                    crossroads.erase(start->coords);
                }
            }
            ++i;
        }
        for (auto road : endRoads) {
            if (road.first == roadToRemoveEnd) {
                endRoads.erase(endRoads.begin()+j);
                if (endRoads.empty()) {
                    crossroads.erase(end->coords);
                }
            }
            ++j;
        }

        roads.erase(id);

        return true;
    }
}

std::vector<std::tuple<Coord, WayID, Distance> > Datastructures::route_least_crossroads(Coord fromxy, Coord toxy)
{
    // Replace this comment with your implementation
    return {{NO_COORD, NO_WAY, NO_DISTANCE}};
}

std::vector<std::tuple<Coord, WayID> > Datastructures::route_with_cycle(Coord fromxy)
{
    // Replace this comment with your implementation
    return {{NO_COORD, NO_WAY}};
}

std::vector<std::tuple<Coord, WayID, Distance> > Datastructures::route_shortest_distance(Coord fromxy, Coord toxy)
{
    if (crossroads.find(fromxy) == crossroads.end() || crossroads.find(toxy) == crossroads.end() || fromxy == toxy) {
        return {{NO_COORD, NO_WAY, NO_DISTANCE}};
    }else if (fromxy == toxy)
    {
        return {{fromxy, NO_WAY, 0}};
    }
    std::shared_ptr<Crossroad> start = crossroads.at(fromxy);
    start->visited = Visited::SEEN;
    start->minDist = 0;
    Distance startEstimate = calcDist({fromxy, toxy});
    std::vector<std::tuple<Coord, WayID, Distance>> result;
    bool resultFound = false;


    std::priority_queue<std::pair<int, std::shared_ptr<Crossroad>>, std::vector<std::pair<int, std::shared_ptr<Crossroad>>>, std::greater<std::pair<int, std::shared_ptr<Crossroad>>>> que;
    que.push(std::make_pair(startEstimate, start));
    while (!que.empty()) {
        std::pair<int, std::shared_ptr<Crossroad>> u = que.top();
        que.pop();
        for (auto v : u.second->ways) {
            if (v.second->visited == Visited::NO) {
                v.second->visited = Visited::SEEN;
                que.push(std::make_pair(9999, v.second));
            }
            if(v.second->minDist > u.second->minDist + v.first->dist) {
                v.second->previous = u.second;
                v.second->cameFrom = v.first;
                v.second->minDist = u.second->minDist + v.first->dist;
                Distance estimate = v.second->minDist + calcDist({v.second->coords, toxy});
                que.push({estimate, v.second});
            }
            if (u.second->coords == toxy) {
                std::shared_ptr<Crossroad> crossroad = u.second;
                result.push_back({crossroad->coords, NO_WAY, crossroad->minDist});
                while (crossroad->previous != nullptr) {
                    std::shared_ptr<Way> way = crossroad->cameFrom;
                    crossroad = crossroad->previous;
                    result.push_back({crossroad->coords, way->id, crossroad->minDist});
                }
                std::reverse(result.begin(), result.end());
                resultFound = true;
                break;
            }
        }
        u.second->visited = Visited::YES;
        if (resultFound) {
            break;
        }
    }

    for (auto crossroad : crossroads) {
        crossroad.second->minDist = 9999;
        crossroad.second->estimate = 9999;
        crossroad.second->visited = Visited::NO;
        crossroad.second->previous = nullptr;
        crossroad.second->cameFrom = nullptr;
    }

    if (resultFound) {
        return result;
    }else {
        return {};
    }
}


Distance Datastructures::trim_ways()
{
    // Replace this comment with your implementation
    return NO_DISTANCE;
}

Distance Datastructures::calcDist(std::vector<Coord> coords)
{
    Distance distance = 0;
    for (unsigned int i = 0; i+1 < coords.size(); ++i) {
        int dist = floor(sqrt(pow(coords.at(i).x-coords.at(i+1).x, 2)+pow(coords.at(i).y-coords.at(i+1).y, 2)));
        distance+=dist;
    }
    return distance;
}


