/*
    Let's suppose building document management system.
    Simple start: user -> view/edit document.
*/

/*
    Thus we will create three table in SQL and find it from there
    
    CREATE TABLE users(id, name)
    CREATE TABLE document(id, title, content)
    CREATE TABLE permission(user_id, document_id, permission_type)
*/

/*
    Let's ask a question: Can Alice view document 1 ?
    Ans: Select 1 from permission where user_id = 'ALICE' and document_id = '1' and permission_type = 'edit'
*/

/* ---------------------------------------------------------------------------------------------------------------------- */

/*
    But then your product manager arrives with new requirements

    Requirement 1: User Groups: 
    “We need teams. Marketing team members should access marketing documents.”
*/

/*
    Now, we need to extend our current implementation

    CREATE TABLE groups(id, name)
    CREATE TABLE group_memberships(group_id, user_id)
    CREATE TABLE group_permission(group_id, document_id, permission_type)
*/

/*
    Let's resolve the issue of product manager, again. 
    Q. Do alice have permission of view on document 1, either direct or via group.

    Ans: Select 1 from permission where user_id = 'ALICE' and document_id = '1' and permission_type = 'edit'
         UNION
         Select 1 from group_memberships gm join group_permission gp where gm.group_id = gp.group_id where gm.user_id = 'Alice' and gp.document_id = 'Document 1' and gp.permission_type = 'edit'
*/

/*
    Now, the product manager comes with another requirement but this time, it looks like simple, but huge in implement. 
    
    Hierarchical permissions → recursive queries
    Folder inheritance → folder & mapping tables
    Conditional access → application-side business logic

    This causes explosion of new table, thus can't be handled in SQL alone, 
    also it can make the query execution very slow, if we keep increasing the database tables and joining frequently. 
*/

/*
    This is where now, we need to come up with some application level logic instead of searching in database.
*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>

struct Group {
    int id;
    std::string name;

    Group(int _id, std::string _name): id(_id), name(_name) {}
    ~Group() {}
};

struct User {
    int id;
    std::string name;
    std::vector<Group> groups;

    User(int _id, std::string _name, std::vector<Group> _groups)
    : id(_id), name(_name), groups(_groups) {}

    ~User() {}
};

struct Document {
    int id;
    std::string name;
    std::string content;

    Document(int _id, std::string _name, std::string _content)
    : id(_id), name(_name), content(_content) {}

    ~Document() {}
};

struct Permission {
    int id;
    std::string permission_type;

    Permission(int _id, std::string _permission_type)
    : id(id), permission_type(_permission_type) {}

    ~Permission() {}
};

struct AccessContext {
    User* user;
    Document* doc;
    Permission* permission;

    AccessContext(User* _user, Document* _document, Permission* _permission)
    : user(_user), doc(_document), permission(_permission) {}

    ~AccessContext() {}
};


class PermissionService {
public:
    virtual bool query_database(const AccessContext& ctx, const char* condition) = 0;
    virtual ~PermissionService() = default;
};


class PermissionRule {
public:
    virtual bool evaluate(const AccessContext& ctx, PermissionService &svc) = 0;
    ~PermissionRule() = default;
};


class DirectRule: public PermissionRule {
public:
    bool evaluate(const AccessContext &ctx, PermissionService &svc) override {
        return svc.query_database(ctx, "direct");
    }
};


class GroupRule: public PermissionRule {
public: 
    bool evaluate(const AccessContext &ctx, PermissionService &svc) override {
        return svc.query_database(ctx, "group");
    }
};


class FolderInheritanceRule: public PermissionRule {
public:
    bool evaluate(const AccessContext &ctx, PermissionService &svc) override {
        return svc.query_database(ctx, "folder");
    }
};


class PermissionChecker {
public:
    virtual bool can_access(const AccessContext &ctx) = 0;
    virtual ~PermissionChecker() = default;
};

class DefaultPermissionChecker: public PermissionChecker {
private:
    std::vector<std::unique_ptr<PermissionRule>> rules;
    PermissionService& service;

public:
    DefaultPermissionChecker(std::vector<std::unique_ptr<PermissionRule>> _rules, PermissionService &svc)
    : rules(std::move(_rules)), service(svc) {}
    
    ~DefaultPermissionChecker() {}

    bool can_access(const AccessContext &ctx) override {

        /*
            Since here we want that any of the rule exists true, meaning it has permission,
            so, we need to check for (rule->evaluate(ctx, service)) in loop
        */
        for(auto &rule: rules) {
            if(rule->evaluate(ctx, service)) return true;
        }
        return false;
    }
};


class RealPermissionService: public PermissionService{
public:
    bool query_database(const AccessContext &ctx, const char* condition) override {
        std::cout << "Querying from database for condition [ " << condition << " ] for user\n";
        return false; 
    }
};

int main(int argc, char* argv[]) {
    return 0;
}