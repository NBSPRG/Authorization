#ifndef PERMISSION_HPP
#define PERMISSION_HPP

#include <vector>
#include <string>
#include <iostream>

class Permission {

public:
    Permission(int _id, std::string _permission_type);
    ~Permission();

    const int getId() const;
    const std::string& getPermissionType() const;
    
private:
    int id;
    std::string permission_type;
};

#endif