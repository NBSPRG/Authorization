#include "RealPermissionService.hpp"
#include <iostream>

bool RealPermissionService::query_database(const AccessContext& ctx, const char* condition) {
    std::cout << "[DB Query]: for " << ctx.getUser()->getName() << " for condition: " << condition << " ";
    return false; // for now
}

bool RealPermissionService::has_any_permission(const AccessContext &ctx, const std::vector<std::string> &conditions) {
    std::cout << "[DB Combined Query]: for " << ctx.getUser()->getName() << " checking ";
    for (size_t i = 0; i < conditions.size(); ++i) {
        if (i) std::cout << ", ";
        std::cout << conditions[i];
    }
    std::cout << "\n";
    return false;
}