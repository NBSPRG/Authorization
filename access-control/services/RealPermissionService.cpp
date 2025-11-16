#include "RealPermissionService.hpp"
#include <iostream>

bool RealPermissionService::query_database(const AccessContext& ctx, const char* condition) {
    std::cout << "[DB Query]: for " << ctx.getUser()->getName() << " for condition: " << condition << " ";
    return false; // for now
}