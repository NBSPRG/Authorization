#include "GroupRule.hpp"

bool GroupRule::evaluate(const AccessContext& ctx, PermissionService &svc) {
    return svc.query_database(ctx, "group");
}