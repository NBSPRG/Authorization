#include "FolderInheritanceRule.hpp"

bool FolderInheritanceRule::evaluate(const AccessContext &ctx, PermissionService &svc) {
    svc.query_database(ctx, "folder");
}