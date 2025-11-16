#include "PermissionService.hpp"

class RealPermissionService: public PermissionService {

public:
    bool query_database(const AccessContext& ctx, const char* condition) override;
};