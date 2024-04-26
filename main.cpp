#include <iostream>
#include <vector>
#include <memory>

using namespace std;

struct Student {
    int id;
    string name;
    int age;
};

class StudentDatabase {
private:
    vector<shared_ptr<Student>> students;

public:
    void addStudent(const Student& student) {
        students.push_back(make_shared<Student>(student));
    }

    void removeStudent(int id) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if ((*it)->id == id) {
                students.erase(it);
                return;
            }
        }
        cout << "Student with ID " << id << " not found" << endl;
    }

    shared_ptr<Student> getStudent(int id) const {
        for (const auto& student : students) {
            if (student->id == id) {
                return student;
            }
        }
        return nullptr;
    }
};

int main() {
    StudentDatabase db;

    Student s1 {1, "Wassim", 20};
    Student s2 {2, "Ghadhab", 21};
    Student s3 {3, "Daria", 22};

    db.addStudent(s1);
    db.addStudent(s2);
    db.addStudent(s3);

    cout << "student with the ID 1: " << db.getStudent(1)->name << " (" << db.getStudent(1)->age << " years old)" << endl;

    db.removeStudent(2);
    cout << "Student with the ID 2 was removed" << endl;

    cout << "student with ID 3: " << db.getStudent(3)->name << " (" << db.getStudent(3)->age << " years old)" << endl;

    return 0;
}
