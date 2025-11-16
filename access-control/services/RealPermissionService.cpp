#include "RealPermissionService.hpp"

bool RealPermissionService::query_database(const AccessContext& ctx, const char* condition) {
    std::cout << "[DB Query]: for " << ctx.getUser()->getName() << "for condition: " << condition << "\n";
    return false; // for now
}