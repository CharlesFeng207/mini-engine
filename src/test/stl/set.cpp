#include <algorithm>
#include <functional>
#include <iostream>
#include <set>
#include <string>

using namespace std;

class Student
{
public:
    string name;
    int id;
    int score;

    friend ostream &operator<<(ostream &out, const Student &point);
};

ostream &operator<<(ostream &out, const Student &s)
{
    out << s.name << " id " << s.id << " score " << s.score << " ";
    return out;
}

class studentSortCriterion
{
public:
    bool
    operator()(Student const *a, Student const *b) const
    {
        return (a->id == b->id) ? (a->score > b->score) : (a->id > b->id);
    }
};

template <typename T>
void printSet(T &s)
{
    for (auto i = s.begin(); i != s.end(); i++)
    {
        cout << *i << " ";
    }

    cout << endl;
}

int testSetSort()
{
    set<Student *, studentSortCriterion> stuSet;
    set<Student *> stus;

    auto stu1 = new Student();
    stu1->name = "ZhangSan";
    stu1->id = 2;
    stu1->score = 100;

    auto stu2 = new Student();
    stu2->name = "LiShi";
    stu2->id = 1;
    stu2->score = 90;

    auto stu3 = new Student();
    stu3->name = "XiaoMing";
    stu3->id = 3;
    stu3->score = 80;

    stuSet.insert(stu1);
    stus.insert(stu1);
    stuSet.insert(stu2);
    stus.insert(stu2);
    stuSet.insert(stu3);
    stus.insert(stu3);

    auto stu4 = new Student();
    stuSet.insert(stu4);
    stuSet.erase(stu4);

    cout << "sorted" << endl;
    for (auto i = stuSet.begin(); i != stuSet.end(); i++)
    {
        cout << **i << " ";
    }
    cout << endl;

    cout << "unsorred" << endl;
    for (auto i = stus.begin(); i != stus.end(); i++)
    {
        cout << **i << " ";
    }

    cout << endl;

    return 0;
}

int main()
{
    testSetSort();
    getchar();
    return 0;

    set<string> s;
    s.insert("asd");
    s.insert("asd1");
    s.insert("asd");
    s.insert("asd2");

    printSet<set<string>>(s);

    cout << endl;

    auto iter = s.find("asd");
    if (iter != s.end())
    {
        cout << "666 " << *iter << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    getchar();
}