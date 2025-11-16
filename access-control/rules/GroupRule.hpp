#pragma once 
#include "PermissionRule.hpp"
#include "../models/AccessContext.hpp"
#include "../services/PermissionService.hpp"

class GroupRule: public PermissionRule {
    bool evaluate(const AccessContext& ctx, PermissionService &svc) override;
};