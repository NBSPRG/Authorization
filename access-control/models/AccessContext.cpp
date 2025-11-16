#include "AccessContext.hpp"

AccessContext::AccessContext(User* _user, Document* _document, Permission* _permission)
    : user(std::move(_user)), document(std::move(_document)), permission(std::move(_permission)) {}

AccessContext::~AccessContext() {}

const User* AccessContext::getUser() const {
    return user;
}

const Document* AccessContext::getDocument() const {
    return document;
}

const Permission* AccessContext::getPermission() const {
    return permission;
}

