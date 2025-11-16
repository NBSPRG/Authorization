#ifndef ACCESS_CONTEXT_HPP
#define ACCESS_CONTEXT_HPP

#include "User.hpp"
#include "Document.hpp"
#include "Permission.hpp"

class AccessContext {

public:
    AccessContext(User* _user, Document* _document, Permission* _permission);
    ~AccessContext();

    const User* getUser() const;
    const Document* getDocument() const;
    const Permission* getPermission() const;

private:
    User* user;
    Document* document;
    Permission* permission;
};

#endif