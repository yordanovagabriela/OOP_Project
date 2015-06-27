#include<iostream>
#include "courses.cpp"
#include "vector.cpp"
using namespace std;
int main()
{
    Vector<int> *m = new Vector<int>();

    for  (int i = 4;i < 60;i ++) {
        m->pushBack(i);
    }

    cout << m->getSize() << endl;
    cout << m->getCapacity() << endl;
    cout << m->getFront() << endl;
    cout << m->getBack() << endl;
    cout << m->operator[](1) << endl;

    m->insert(0,32);
    m->erase(0);
    m->resize(100);

    Vector<Course> *cr = new Vector<Course>();

    Course *cpp = new Course("C++",100);
    Course *python = new Course("Python",200);
    Course *java = new Course("Java",300);

    cr->pushBack(*cpp);
    cr->pushBack(*python);
    cr->pushBack(*java);

    delete cpp;
    delete python;
    delete java;

    return 0;
}
