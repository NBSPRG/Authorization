#pragma once
#include "PermissionRule.hpp"

class DirectRule: public PermissionRule {
    bool evaluate(const AccessContext& ctx, PermissionService& svc) override;
};