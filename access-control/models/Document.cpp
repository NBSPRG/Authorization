#include "Document.hpp"

Document::Document(int _id, std::string _title, std::string _content)
    : id(_id), title(std::move(_title)), content(std::move(_content)) {}

Document::~Document() {}

const int Document::getId() const {
    return id;
}

const std::string& Document::getTitle() const {
    return title;
}

const std::string& Document::getContent() const {
    return content;
}

