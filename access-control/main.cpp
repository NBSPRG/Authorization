#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "./models/User.hpp"
#include "./models/Document.hpp"
#include "./models/Permission.hpp"
#include "./models/AccessContext.hpp"
#include "./services/RealPermissionService.hpp"
#include "./rules/DirectRule.hpp"
#include "./rules/GroupRule.hpp"
#include "./rules/FolderInheritanceRule.hpp"
#include "./checkers/PermissionChecker.hpp"
#include "./checkers/DefaultPermissionChecker.hpp"
#include "./checkers/BatchPermissionChecker.hpp"

int main(int argc, const char* argv[]) {

    User user(1, "Alice", {});
    Document doc(1, "Doc1", "content");
    Permission perm(1, "view");
    AccessContext ctx(&user, &doc, &perm);

    auto svc = std::make_unique<RealPermissionService>();

    std::vector<std::unique_ptr<PermissionRule>> rules;
    rules.emplace_back(std::make_unique<DirectRule>());
    rules.emplace_back(std::make_unique<GroupRule>());
    rules.emplace_back(std::make_unique<FolderInheritanceRule>());

    // Use BatchPermissionChecker to demonstrate optimized batch checking
    auto checker = std::make_unique<BatchPermissionChecker>(*svc, rules);
    if(checker->can_access(ctx)) {
        std::cout << "Permission granted !!!" << std::endl;
        return 0;
    }
    std::cout << "Permission denied !!!" << std::endl;

    return 0;
}