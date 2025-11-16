#pragma once
#include "PermissionService.hpp"
#include <vector>
#include <string>

class RealPermissionService: public PermissionService {

public:
    bool query_database(const AccessContext& ctx, const char* condition) override;
    bool has_any_permission(const AccessContext &ctx, const std::vector<std::string> &conditions) override;
};