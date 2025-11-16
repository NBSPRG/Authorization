#include "Permission.hpp"

Permission::Permission(int _id, std::string _permission_type)
    : id(_id), permission_type(std::move(_permission_type)) {}

Permission::~Permission() {}

const int Permission::getId() const {
    return id;
}

const std::string& Permission::getPermissionType() const {
    return permission_type;
}

