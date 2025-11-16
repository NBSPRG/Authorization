#pragma once 

#include "PermissionRule.hpp"
#include "../services/PermissionService.hpp"

class FolderInheritanceRule: public PermissionRule {
    bool evaluate(const AccessContext& ctx, PermissionService& svc) override;
};