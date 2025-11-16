#include "FolderInheritanceRule.hpp"

bool FolderInheritanceRule::evaluate(const AccessContext &ctx, PermissionService &svc) {
    return svc.query_database(ctx, "folder");
}