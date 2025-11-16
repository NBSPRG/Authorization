#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "Group.hpp"

class User {

public:
    User(int _id, std::string name, std::vector<std::unique_ptr<Group>> groups);
    ~User();

    const int getId() const;
    const std::string& getName() const;
    const std::vector<std::unique_ptr<Group>>& getGroups() const;

private:
    int id;
    std::string name;
    std::vector<std::unique_ptr<Group>> groups;
};

#endif