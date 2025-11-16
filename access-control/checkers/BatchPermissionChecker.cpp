#include "BatchPermissionChecker.hpp"
#include <vector>
#include <string>

BatchPermissionChecker::BatchPermissionChecker(PermissionService& _svc, std::vector<std::unique_ptr<PermissionRule>>& _rules)
    : svc(_svc), rules(std::move(_rules)) {}

bool BatchPermissionChecker::can_access(const AccessContext& ctx) {
    std::vector<std::string> conditions = {"direct", "group", "folder"};
    return svc.has_any_permission(ctx, conditions);
}
