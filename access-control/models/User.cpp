#include "User.hpp"

User::User(int _id, std::string _name, std::vector<std::unique_ptr<Group>> _groups)
    : id(id), name(std::move(_name)), groups(std::move(_groups)) {}

User::~User() {}

const int User::getId() const {
    return id;
}

const std::string& User::getName() const {
    return name;
}

const std::vector<std::unique_ptr<Group>>& User::getGroups() const {
    return groups;
}


