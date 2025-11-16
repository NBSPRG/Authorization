#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <iostream>
#include <vector>

class Document {

public:
    Document(int _id, std::string _title, std::string _content);
    ~Document();

    const int getId() const;
    const std::string& getTitle() const;
    const std::string& getContent() const;

private:
    int id;
    std::string title;
    std::string content;
};

#endif DOCUMENT_HPP