#include<iostream>
using namespace std;
class Course {
private:
    string name;
    int level;
public:
    Course() {
        name = "Assembler";
        level = 99999;
    }

    Course(string name,int level) {
    this->name = name;
    this->level = level;
    }

    ~Course() {}
};
