#include <iostream>
#include <vector>
#include <string>

class Person {
protected:
    std::string name;
    std::string phone;
    std::string email;

    struct Address {
        std::string street, city, state, postal_code, country;

        Address() = default;
        ~Address() = default;

        void output_as_label() const {
            std::cout << "Address: " << '\n' << "    " <<
                      "Country: " << country << '\n' << "    " <<
                      "State: " << state << '\n' << "    " <<
                      "City: " << city << '\n' << "    " <<
                      "Street: " << street << '\n' << "    " <<
                      "Postal Code: " << postal_code << '\n';
        }

    } address;

public:

    Person() = default;
    ~Person() = default;

    virtual void print() const {
        std:: cout << "Name: " << name << '\n' <<
                      "Phone : " << phone << '\n' <<
                      "Email: " << email << '\n';
        address.output_as_label();

    }
};


class Student : public Person {
private:
    int number{};
    int average_mark{};

public:

    Student() = default;
    ~Student() = default;

    static bool is_eligibale_to_enroll() {
        std::cout << "Yes." << '\n';
        return true;
    }

    static void get_seminars_taken() {
        std::cout << "Get seminars taken." << '\n';
    }

    void print() const override {
        std:: cout << "Name: " << name << '\n' <<
                   "Phone : " << phone << '\n' <<
                   "Email: " << email << '\n' <<
                   "Student number: " << number << '\n' <<
                   "Average mark: " << average_mark << '\n';
        address.output_as_label();

    }

    friend class Mirea;
};


class Worker : public Person {
private:
    int salary{};
    int experience{};
    int hours{};
    int premy{};

public:

    Worker() = default;
    ~Worker() = default;


    void set_worker(int s, int e, int h, int p) {
        salary = s;
        experience = e;
        hours = h;
        premy = p;
    }

    Worker& get_worker() {
        return *this;
    }

    void print() const override {
        std:: cout << "Name: " << name << '\n' <<
                   "Phone : " << phone << '\n' <<
                   "Email: " << email << '\n' <<
                   "Salary: " << salary << '\n' <<
                   "Experience: " << experience << '\n' <<
                   "Hours: " << hours << '\n' <<
                   "Premy: " << premy << '\n';
        address.output_as_label();

    }

    friend class Mirea;
};


class Mirea {
private:
    std::vector<Student> students;
    std::vector<Worker> workers;

public:

    Mirea() = default;
    ~Mirea() = default;

    void add_student(const Student& student) {
        students.push_back(student);
    }

    void add_worker(const Worker& worker) {
        workers.push_back(worker);
    }

    void print_students() {
        for (auto &&student : students) {
            student.print();
        }
    }

    void print_workers() {
        for (auto &&worker : workers) {
            worker.print();
        }
    }

    void print_info() {
        std::cout << "Number of students: " << students.size() << '\n' <<
                     "Number of workers: " << workers.size() << '\n';
    }

};

