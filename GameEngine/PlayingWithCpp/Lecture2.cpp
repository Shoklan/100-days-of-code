#include <iostream>
#include <vector>
#include <fstream>

// using namespace std;
// This tells the compiler what the default namespace is

class Student {

    std::string _first = "FIRST";
    std::string _last = "LAST";
    int _id           = 0;
    float _avg        = 0;

public:
    Student(){}

    Student(std::string first, std::string last, int id, float avg)
    : _first(first)
    , _last(last)
    , _id(id)
    , _avg(avg)
    {}

    float getAvg() const { return _avg; }
    int   getId() const  { return _id; }
    std::string getFirstName() const { return _first; }
    std::string getLastName () const { return _last; }

    void print() const {
        std::cout
            << _first + " "
            << _last + " "
            << _id 
            << " "
            << _avg
            << std::endl;
    }
};

class Course{
    std::string _name = "COURSE";
    std::vector<Student> _students;

public:
    Course(){}
    Course(const std::string& name)
    :   _name(name)
    {}

    void addStudent(const Student& s){ _students.push_back(s); }
    const std::vector<Student>& getStudents() const {return _students;}
    void print() const {
        for( const auto& s:_students){
            s.print();
        }
     }
     void loadFromFile(const std::string& filename){
        std::ifstream fin(filename);
        std::string first, last;
        int id;
        float avg;

        while(fin >> first){
            fin
            >> last
            >> id
            >> avg;

            addStudent(Student(first, last, id, avg));
        }
     }
};


int main(int argc, char * arrgv[]){
    std::string first = "Dave";
    std::string last = "Mitchell";

    std::cout
        << "Hello, "
        << first + " " + last 
        << std::endl;


    // Vector time!
    std::vector<int> v;
    v.push_back(42);
    v.push_back(10);
    
    std::cout
        << v[0] 
        << std::endl
        << v[1]
        << std::endl;

    // Always try to use a size_t when doing loops
    for( size_t i=0; i < v.size(); i++ ){
        std::cout
            << v[i]
            << std::endl;
    }

    for( int a:v ){
        std::cout
            << a
            << std::endl;
    }

    // Student s1;
    // Student s2("David", "Mitchell", 423, 3.1);
    // const Student s3("Rachel", "Marshall", 101, 3.0);

    // s2.print();
    // s3.print();

    Course course("COMP 4300");
    // course.addStudent(s1);
    // course.addStudent(s2);
    // course.addStudent(s3);

    // It is very unsurprising that this fails silently with C++
    // I never created this file.
    course.loadFromFile("Students.txt");
    course.print();

    return 0;
}
