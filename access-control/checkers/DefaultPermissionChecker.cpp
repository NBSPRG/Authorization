#include "DefaultPermissionChecker.hpp"

DefaultPermissionChecker::DefaultPermissionChecker(PermissionService& _svc, std::vector<std::unique_ptr<PermissionRule>>& _rules)
    : svc(_svc), rules(std::move(_rules)) {}

bool DefaultPermissionChecker::can_access(const AccessContext& ctx) {
    for(auto &rule: rules) {
        if(rule->evaluate(ctx, svc)) return true;
    }
    return false;
}