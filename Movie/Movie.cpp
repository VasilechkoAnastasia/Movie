#include<iostream>
using namespace std;

class Movie
{
    char* name;
    double time;
    int year;
public:
    Movie()
    {
        name = nullptr;
        time = 0;
        year = 0;
    }
    Movie(const char* n, double t, int y)
    {
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
        time = t;
        year = y;
    }
    Movie(const Movie& obj)
    {
        name = new char[strlen(obj.name) + 1];
        strcpy_s(name, strlen(obj.name) + 1, obj.name);
        time = obj.time;
        year = obj.year;

    }
    ~Movie()
    {
        delete[] name;
    }
    const char* GetName()
    {
        return name;
    }
    double GetTime()
    {
        return time;
    }
    int GetYear()
    {
        return year;
    }
    friend ostream& operator<<(ostream& os, Movie& obj);
    friend istream& operator>>(istream& os, Movie& obj);
};

istream& operator>>(istream& is, Movie& obj)
{
    char buff[20];
    cout << "Enter name: ";
    cin >> buff;
    if (obj.name != nullptr)
    {
        delete[] obj.name;
    }
    obj.name = new char[strlen(buff) + 1];
    strcpy_s(obj.name, strlen(buff) + 1, buff);
    cout << "Enter time: ";
    is >> obj.time;
    cout << "Enter year: ";
    is >> obj.year;
    return is;
}

ostream& operator<<(ostream& os, Movie& obj)
{
    os << obj.name << "\t" << obj.time << "\t" << obj.year << endl;
    return os;
}

int main()
{
    Movie obj1("Avatar", 2.55, 1998);
    cout << obj1 << endl;
    cin >> obj1;
}

