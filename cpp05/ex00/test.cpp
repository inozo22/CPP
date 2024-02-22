#include <iostream>
#include <stdexcept>

class Bureaucrat {
private:
    const std::string name;
    int grade;

public:
    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw() {
            return "Grade too high";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw() {
            return "Grade too low";
        }
    };

    Bureaucrat(const std::string &name, int grade) : name(name) {
        if (grade < 1)
            throw GradeTooHighException();
        if (grade > 150)
            throw GradeTooLowException();
        this->grade = grade;
    }

    const std::string& getName() const {
        return name;
    }

    int getGrade() const {
        return grade;
    }

    void incrementGrade() {
        if (grade > 1)
            grade--;
        else
            throw GradeTooHighException();
    }

    void decrementGrade() {
        if (grade < 150)
            grade++;
        else
            throw GradeTooLowException();
    }

    friend std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
        out << bureaucrat.name << ", bureaucrat grade " << bureaucrat.grade;
        return out;
    }
};

int main() {
    try {
        Bureaucrat highGradeBureaucrat("John", 1);
        Bureaucrat lowGradeBureaucrat("Alice", 150);

        std::cout << highGradeBureaucrat << std::endl;
        std::cout << lowGradeBureaucrat << std::endl;

        highGradeBureaucrat.incrementGrade();
        lowGradeBureaucrat.decrementGrade();

        std::cout << highGradeBureaucrat << std::endl;
        std::cout << lowGradeBureaucrat << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}