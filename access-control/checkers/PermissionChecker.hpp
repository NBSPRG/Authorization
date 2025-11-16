#pragma once
#include "../models/AccessContext.hpp"

class PermissionChecker {
public:
    virtual bool can_access(const AccessContext& ctx) = 0;
    virtual ~PermissionChecker() = default;

};