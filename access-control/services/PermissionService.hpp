#pragma once
#include "../models/AccessContext.hpp"
#include <vector>
#include <string>

class PermissionService {

public:
    virtual bool query_database(const AccessContext &ctx, const char* condition) = 0;
    virtual ~PermissionService() = default;
    
    virtual bool has_any_permission(const AccessContext &ctx, const std::vector<std::string> &conditions) {
        for (const auto &c : conditions) {
            if (query_database(ctx, c.c_str())) return true;
        }
        return false;
    }
};