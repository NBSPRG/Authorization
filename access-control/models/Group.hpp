#ifndef GROUP_HPP
#define GROUP_HPP

#include <iostream>
#include <vector>

class Group {

public:
    Group(int _id, std::string _name);
    ~Group();

    const int getId() const;
    const std::string& getName() const;


private:
    int id;
    std::string name; 
};

#endif