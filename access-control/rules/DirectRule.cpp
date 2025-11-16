#include "DirectRule.hpp"

bool DirectRule::evaluate(const AccessContext& ctx, PermissionService &svc) {
    return svc.query_database(ctx, "direct");
}