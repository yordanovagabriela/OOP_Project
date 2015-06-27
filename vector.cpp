#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>

class Vector {
private:
    int size, capacity, back;
    T *array;
    static const int front = 0;
public:
    Vector () {
        size = 0;
        capacity = 16;
        back = -1;
        array = new T[capacity];
    }

    Vector (int size, T value) {
        this->size = size;
        capacity = size;
        back = -1;
        array = new T[capacity];
        for (int i = 0;i < size;i ++) {
            array[i] = value;
        }
    }

    ~Vector() {
        delete [] array;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }

    void allocateSpace() {
        int new_capacity = capacity*2;
        T *bigger_array = new T[new_capacity];
        for (int i = 0;i < size;i ++) {
            bigger_array[i] = array[i];
        }
        delete [] array;
        array = bigger_array;
        capacity = new_capacity;

    }

    void pushBack(const T &element) {
        if (size != capacity) {
            array[++back] = element;
            size ++;
        }
        else {
            allocateSpace();
            array[++back] = element;
            size ++;
        }
    }

    void resize(int newSize) {
        if (newSize < size) {
            for (int i = newSize;i < size;i++) {
                array[i] = NULL;
            }
        }
        if (newSize > size) {
            while (newSize > capacity) {
                allocateSpace();
            }
            for (int i = size;i < newSize;i++) {
                array[i] = 0;
            }
        }
        size = newSize;
        back = newSize - 1;
    }

    T& getBack() {
        return array[back];
    }
    void popBack() {
        array[back--] = NULL;
        size = size - 1;
    }

    T& getFront() {
        return array[front];
    }
    bool isEmpty() {
        return size == 0;
    }

    void clear() {
        array = NULL;
        size = 0;
        back = -1;
    }

    T& operator [] (int n) {
        return array[n];
    }

    Vector& operator=(const Vector& v) {
      if(this != v) {
        size = v.size;
        capacity = v.capacity;
        T *temp_array = new T[v.capacity];
        for (int i = 0;i < v.size;i++) {
          temp_array[i] = array[i];
        }
        delete [] array;
        array = temp_array;
      }
      return *this;

    }

    void insert(int index, T value) {
        T *temp_array = new T[this->size +1];
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of range!");
        }
        for (int i = 0;i < size + 1;i++) {
            if (i < index) {
                temp_array[i] = array[i];
            }
            if (i == index) {
                temp_array[i] = value;
            }
            if (i > index) {
                temp_array[i] = array[i - 1];
            }
        }
        delete [] array;
        array = temp_array;
        size ++;
        back ++;
        while (size > capacity) {
            allocateSpace();
        }
    }

    void erase(int index) {
        if (index < 0 || index > size -1) {
            throw std::out_of_range("Index out of range!");
        }
        else {
            T *temp = new T[this->size - 1];
            for (int i = 0;i < (size - 1);i ++) {
                if(i < index) {
                    temp[i] = array[i];
                }
                if (i >= index) {
                    if (index != (size - 1) ) {
                        temp[i] = array[i+1];
                    }
                }
            }
            delete [] array;
            array = temp;
            size --;
            back --;
        }
    }

    void shrink_to_fit() {
        capacity = size;
    }

};

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

int main()
{
    Vector<int> *m = new Vector<int>();

    for  (int i = 4;i < 60;i ++) {
        m->pushBack(i);
        cout << m->getBack() << endl;
    }

    cout << m->getSize() << endl;
    cout << m->getCapacity() << endl;
    cout << m->getFront() << endl;
    cout << m->getBack() << endl;
    cout << m->operator[](1);

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
