#include "DirectRule.hpp"

bool DirectRule::evaluate(const AccessContext& ctx, PermissionService &svc) {
    svc.query_database(ctx, "direct");
}