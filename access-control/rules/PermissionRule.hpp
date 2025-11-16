#pragma once
#include "../models/AccessContext.hpp"
#include "../services/PermissionService.hpp"

class PermissionRule {

public:
    virtual bool evaluate(const AccessContext& ctx, PermissionService& svc) = 0;
    virtual ~PermissionRule() = default;
}