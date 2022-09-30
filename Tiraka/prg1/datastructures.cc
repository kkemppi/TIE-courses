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
    return places_.size();
}

void Datastructures::clear_all()
{
    places_.clear();
    place_ids.clear();
    name_map.clear();
    coord_map.clear();
    type_map.clear();
    areas_.clear();
    area_ids.clear();
}

std::vector<PlaceID> Datastructures::all_places()
{
    return place_ids;
}

bool Datastructures::add_place(PlaceID id, const Name& name, PlaceType type, Coord xy)
{
    Place p = {name, type, xy};
    std::pair<std::unordered_map<PlaceID, Place>::iterator, bool> inserted = places_.emplace(id, p);
    if (inserted.second){
        place_ids.push_back(id);
        name_map.emplace(name, id);
        coord_map.emplace(xy, id);
        type_map.emplace(type, id);
        return true;
    }else{
        return false;
    }
}

std::pair<Name, PlaceType> Datastructures::get_place_name_type(PlaceID id)
{
    std::unordered_map<PlaceID, Place>::iterator it = places_.find(id);
    if (it == places_.end()) {
        return std::make_pair(NO_NAME, PlaceType::NO_TYPE);
    }else{
        Place &p = places_.find(id)->second;
        return std::make_pair(p.name, p.type);
    }
}

Coord Datastructures::get_place_coord(PlaceID id)
{
    std::unordered_map<PlaceID, Place>::iterator it = places_.find(id);
    if (it == places_.end()) {
        return NO_COORD;
    }else{
        Coord xy = it->second.xy;
        return xy;
    }
}

bool Datastructures::add_area(AreaID id, const Name &name, std::vector<Coord> coords)
{
    Area a = {name, coords, {}};
    std::pair<std::unordered_map<AreaID, Area>::iterator, bool> inserted = areas_.emplace(id, a);
    if (inserted.second){
        area_ids.push_back(id);
        return true;
    }else{
        return false;
    }
    return false;
}

Name Datastructures::get_area_name(AreaID id)
{
    std::unordered_map<AreaID, Area>::iterator a = areas_.find(id);
    if (a == areas_.end()){
        return NO_NAME;
    }else{
        return a->second.name;
    }
}

std::vector<Coord> Datastructures::get_area_coords(AreaID id)
{

    std::unordered_map<AreaID, Area>::iterator a = areas_.find(id);
    if (a == areas_.end()){
        return {NO_COORD};
    }else{
        return a->second.coords;
    }

}

void Datastructures::creation_finished()
{

}


std::vector<PlaceID> Datastructures::places_alphabetically()
{
    std::vector<PlaceID> result = {};
    std::multimap<Name, PlaceID>::iterator it = name_map.begin();
    while (it != name_map.end()){
        result.push_back(it->second);
        it++;
    }
    return result;
}

std::vector<PlaceID> Datastructures::places_coord_order()
{
    std::vector<PlaceID> result = {};
    std::multimap<Coord, PlaceID>::iterator it = coord_map.begin();
    while (it != coord_map.end()){
        result.push_back(it->second);
        it++;
    }
    return result;
}

std::vector<PlaceID> Datastructures::find_places_name(Name const& name)
{
    std::vector<PlaceID> ids = {};
    std::pair<name_It, name_It> result = name_map.equal_range(name);
    for (name_It it = result.first; it != result.second; it++) {
        ids.push_back(it->second);
    }
    return ids;
}

std::vector<PlaceID> Datastructures::find_places_type(PlaceType type)
{
    std::vector<PlaceID> ids = {};
    std::pair<type_It, type_It> result = type_map.equal_range(type);
    for (type_It it = result.first; it != result.second; it++) {
        ids.push_back(it->second);
    }
    return ids;
}

bool Datastructures::change_place_name(PlaceID id, const Name& newname)
{
    std::unordered_map<PlaceID, Place>::iterator p = places_.find(id);
    if (p == places_.end()){
        return false;
    }
    Place &place = p->second;
    Place newplace = {newname, place.type, place.xy};

    std::pair<name_It, name_It> result = name_map.equal_range(place.name);

    places_.erase(p);
    places_.insert({id, newplace});

    for (name_It it = result.first; it != result.second; it++){
        if (it->second == id){
            auto node = name_map.extract(it);
            node.key() = newname;
            name_map.insert(std::move(node));
            return true;
        }
    }
    return false;
}

bool Datastructures::change_place_coord(PlaceID id, Coord newcoord)
{
    std::unordered_map<PlaceID, Place>::iterator p = places_.find(id);
    if (p == places_.end()){
        return false;
    }else{
        Place &place = p->second;
        std::pair<coord_It, coord_It> result = coord_map.equal_range(place.xy);
        place.xy = newcoord;
        for (coord_It it = result.first; it != result.second; it++){
            if (it->second == id){
                auto node = coord_map.extract(it);
                node.key() = newcoord;
                coord_map.insert(std::move(node));
                return true;
            }
        }
        return false;
    }
}

std::vector<AreaID> Datastructures::all_areas()
{
    return area_ids;
}

bool Datastructures::add_subarea_to_area(AreaID id, AreaID parentid)
{
    std::unordered_map<AreaID, Area>::iterator parent_it = areas_.find(parentid);
    std::unordered_map<AreaID, Area>::iterator subarea_it = areas_.find(id);
    if (parent_it == areas_.end() || subarea_it == areas_.end()) {
        return false;
    }else{
        Area &parent = parent_it->second;
        Area &subarea = subarea_it->second;
        parent.subareas.insert(id);
        subarea.parent = parentid;
        return true;
    }
}

std::vector<AreaID> Datastructures::subarea_in_areas(AreaID id)
{
    std::unordered_map<AreaID, Area>::iterator a = areas_.find(id);
    if (a == areas_.end()){
        return {NO_AREA};
    }else{
        Area &area = a->second;
        std::vector<AreaID> result;
        if (area.parent != -1){
            result.push_back(area.parent);
            std::vector<AreaID> parent_vec = subarea_in_areas(area.parent);
            result.insert(result.end(), parent_vec.begin(), parent_vec.end());
            return result;
        }else{
            return {};
        }
    }
    return {};
}


std::vector<PlaceID> Datastructures::places_closest_to(Coord xy, PlaceType type)
{
    // TODO same distances
    std::vector<PlaceID> result;
    std::multimap<Dist, PlaceID> distances = {};

    // Find all of given type
    if (type != PlaceType::NO_TYPE) {
        std::vector<PlaceID> places = find_places_type(type);
        for (PlaceID place : places) {
            Coord compare = places_.find(place)->second.xy;
            float dist = sqrt(pow(xy.x-compare.x, 2)+pow(xy.y-compare.y, 2));
            Dist item = {compare.y, dist};
            distances.emplace(item, place);
        }
    }else{
        for (std::pair<PlaceID, Place> it : places_) {
            Coord compare = it.second.xy;
            float dist = sqrt(pow(xy.x-compare.x, 2)+pow(xy.y-compare.y, 2));
            Dist item = {compare.y, dist};
            distances.emplace(item, it.first);
        }
    }
    std::multimap<Dist, PlaceID>::iterator it = distances.begin();
    int i = 0;
    while (i <= 2 && it != distances.end()) {
        result.push_back(it->second);
        std::advance(it, 1);
        i++;
    }
    return result;
}

bool Datastructures::remove_place(PlaceID id)
{
    std::unordered_map<PlaceID, Place>::iterator place = places_.find(id);
    if (place == places_.end()){
        return false;
    }else{
        std::pair<coord_It, coord_It> coord_result = coord_map.equal_range(place->second.xy);
        std::pair<name_It, name_It> name_result = name_map.equal_range(place->second.name);
        std::pair<type_It, type_It> type_result = type_map.equal_range(place->second.type);
        for (coord_It it = coord_result.first; it != coord_result.second; it++){
            if(it->second == id){
                coord_map.erase(it);
            }
        }
        for (name_It it = name_result.first; it != name_result.second; it++){
            if(it->second == id){
                name_map.erase(it);
            }
        }
        for (type_It it = type_result.first; it != type_result.second; it++){
            if(it->second == id){
                type_map.erase(it);
            }
        }
        place_ids.erase(std::find(place_ids.begin(), place_ids.end(), id));
        places_.erase(id);
        return true;
    }
}

std::vector<AreaID> Datastructures::all_subareas_in_area(AreaID id)
{
    std::unordered_map<AreaID, Area>::iterator a = areas_.find(id);
    if (a == areas_.end()){
        return {NO_AREA};
    }
    Area &area = a->second;
    std::vector<AreaID> result;
    if (!area.subareas.empty()){
        for (AreaID subarea : area.subareas){
            result.push_back(subarea);
            std::vector<AreaID> subarea_vec = all_subareas_in_area(subarea);
            result.insert(result.end(), subarea_vec.begin(), subarea_vec.end());
        }
        return result;
    }else{
        return {};
    }
}

AreaID Datastructures::common_area_of_subareas(AreaID id1, AreaID id2)
{
    std::unordered_map<AreaID, Area>::iterator area1 = areas_.find(id1);
    std::unordered_map<AreaID, Area>::iterator area2 = areas_.find(id2);

    if (area1 == areas_.end() || area2 == areas_.end()){
        return NO_AREA;
    }else if(id1 == id2) {
        return id1;
    }else{
        // Find out which Place has more parents
        std::vector<AreaID> area1_parents = subarea_in_areas(id1);
        std::vector<AreaID> area2_parents = subarea_in_areas(id2);

        std::vector<AreaID> deeper_parents = maxVec(area1_parents, area2_parents);
        std::vector<AreaID> higher_parents = minVec(area1_parents, area2_parents);

        if (higher_parents.size() == 0) {
            return NO_AREA;
        }

        int deeper_index;
        int higher_index = 0;

        int deeper_depth = deeper_parents.size();
        int higher_depth = higher_parents.size();

        if (deeper_depth == higher_depth){
            deeper_index = 0;

        }else{
            deeper_index = deeper_depth-higher_depth;
        }

        while (deeper_parents.at(deeper_index) != higher_parents.at(higher_index)) {
            deeper_index++;
            higher_index++;

            if (deeper_index >= deeper_depth || higher_index >= higher_depth){
                return NO_AREA;
            }
        }
        return higher_parents.at(higher_index);

    }
}

std::vector<AreaID> Datastructures::minVec(std::vector<AreaID> a, std::vector<AreaID> b)
{
    if (a.size() == b.size()) {
        return a;
    }
    return a.size() < b.size() ? a : b;
}
std::vector<AreaID> Datastructures::maxVec(std::vector<AreaID> a, std::vector<AreaID> b)
{
    if (a.size() == b.size()) {
        return b;
    }
    return a.size() > b.size() ? a : b;
}






