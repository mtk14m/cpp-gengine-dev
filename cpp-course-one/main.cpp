#include <iostream>
#include <vector>
#include <fstream>

class Student
{
    std::string m_first = "Fisrt";
    std::string m_last  = "Last";
    int         m_id    = 0;
    float       m_avg   = 0;


public:
    Student() {}
    Student(std::string first, std::string last, int id, float avg)
        : m_first   (first)
        , m_last    (last)
        , m_id      (id)
        , m_avg     (avg)
    {
    }

    int getAvg() const
    {
        return  m_avg;
    }

    int getID() const
    {
        return m_id;
    }

    std::string getFist() const
    {
        return m_first;
    }

    std::string getLast() const
    {
        return m_last;
    }

    void print() const
    {
        std::cout << m_first << " " << m_last<< " ";
        std::cout << m_id << " " << m_avg<< "\n";

    }

};

//course class

class Course
{
    std::string m_name = "Course";
    std::vector<Student> m_students;

public:
    Course(){}
    Course(const std::string& name)
    : m_name(name)
    {

    }
    //Je passe la reference car je ne veux pas copier le student dicetement
    //mais je ne veux qu'une reference vers lui
    void addStudent(const Student& s)
    {
        m_students.push_back(s);
    }

    const std::vector<Student>& getStudents() const
    {
        return m_students;
    }

    void print() const
    {
        for( const auto& s: m_students)
        {
            s.print();
        }
    }

    //load student's info from file
    void loadFromFile(const std::string filename)
    {
        std::ifstream fin(filename);
        std::string first, last;
        int id;
        float avg;

        while ( fin >> first)
        {
            fin >> last >> id >> avg;
            addStudent(Student(first, last, id, avg));
        }
    }
};

int main(int argc, char * argv[] )
{
    /*
    std::vector<float> vec;
    vec.push_back(42.1f);
    vec.push_back(10.2f);
    vec.push_back(11.0f);

    std::cout << vec[0] << "\n";
    std::cout << vec[1] << "\n";
    std::cout << vec[2] << "\n";// you get whatever is at this place in memory

    for (size_t i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << "\n";
    }

    for (auto a : vec)
    {
        std::cout << a << "\n";
    }*/

    /*
    Student s1;
    Student s2("Minou", "Matoko", 1, 3.14);
    Student s3("hola", "Marta", 2, 3.9);

    comp4300.addStudent(s1);
    comp4300.addStudent(s2);
    comp4300.addStudent(s3);
    comp4300.addStudent(Student("Ehol", "Martin", 3, 2.6));
    */

    Course comp4300("COMP 4300");
    comp4300.loadFromFile("../students.txt");
    comp4300.print();

    return 0;
}
