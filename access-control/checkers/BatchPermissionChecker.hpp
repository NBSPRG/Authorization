#pragma once
#include "PermissionChecker.hpp"
#include "../rules/PermissionRule.hpp"
#include <vector>
#include <memory>

class BatchPermissionChecker: public PermissionChecker {
public:
    BatchPermissionChecker(PermissionService& svc, std::vector<std::unique_ptr<PermissionRule>>& rules);
    bool can_access(const AccessContext& ctx) override;

private:
    PermissionService& svc;
    std::vector<std::unique_ptr<PermissionRule>> rules;
};
