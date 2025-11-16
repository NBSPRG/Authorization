#pragma once
#include "PermissionChecker.hpp"
#include "../rules/PermissionRule.hpp"

class DefaultPermissionChecker: public PermissionChecker {

public:
    DefaultPermissionChecker(PermissionService& svc, std::vector<std::unique_ptr<PermissionRule>>& rules);
    bool can_access(const AccessContext& ctx) override;

private:
    PermissionService& svc;
    std::vector<std::unique_ptr<PermissionRule>> rules;
};