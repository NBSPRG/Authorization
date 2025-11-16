#include "Group.hpp"

Group::Group(int _id, std::string _name)
    : id(_id), name(std::move(_name)) {}

Group::~Group() {}

const int Group::getId() const {
    return id;
}

const std::string& Group::getName() const {
    return name;
}