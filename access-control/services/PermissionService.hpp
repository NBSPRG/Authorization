#pragma once 
#include "../models/AccessContext.hpp"

class PermissionService {

public:
    virtual bool query_database(const AccessContext &ctx, const char* condition) = 0;
    virtual ~PermissionService() = default;
};