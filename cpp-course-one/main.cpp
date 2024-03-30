#include <iostream>
#include <vector>

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
        std::cout << m_first << " " << m_last<< "\n";
        std::cout << m_id << " " << m_avg<< "\n";

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

    Student s1;
    Student s2("Minou", "Matoko", 1, 3.14);
    const Student s3("hola", "Marta", 2, 3.9);

    s3.print();
    s3.getLast();

    return 0;
}
