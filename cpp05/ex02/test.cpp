#include <iostream>
#include <stdexcept>

class AForm {
private:
    const std::string name;
    bool signedStatus;
    const int gradeToSign;
    const int gradeToExecute;

public:
    class GradeTooHighException : public std::exception {
        const char* what() const throw() {
            return "Grade is too high";
        }
    };

    class GradeTooLowException : public std::exception {
        const char* what() const throw() {
            return "Grade is too low";
        }
    };

    AForm(const std::string& name, int gradeToSign, int gradeToExecute)
        : name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
        if (gradeToSign < 1 || gradeToSign > 150 || gradeToExecute < 1 || gradeToExecute > 150) {
            throw GradeTooHighException();
        }
    }

    const std::string& getName() const {
        return name;
    }

    bool isSigned() const {
        return signedStatus;
    }

    int getGradeToSign() const {
        return gradeToSign;
    }

    int getGradeToExecute() const {
        return gradeToExecute;
    }

    void beSigned(const class Bureaucrat& bureaucrat) {
        if (bureaucrat.getGrade() <= gradeToSign) {
            signedStatus = true;
        } else {
            throw GradeTooLowException();
        }
    }

    virtual void execute(const class Bureaucrat& executor) const = 0;
};

class ShrubberyCreationForm : public AForm {
private:
    const std::string target;

public:
    ShrubberyCreationForm(const std::string& target)
        : AForm("Shrubbery Creation Form", 145, 137), target(target) {}

    void execute(const class Bureaucrat& executor) const override {
        if (!isSigned() || executor.getGrade() > getGradeToExecute()) {
            throw GradeTooLowException();
        }

        std::ofstream outfile(target + "_shrubbery");
        if (outfile.is_open()) {
            outfile << "ASCII art of trees for " << target << std::endl;
            outfile.close();
        } else {
            throw std::runtime_error("Failed to create Shrubbery file");
        }
    }
};

class RobotomyRequestForm : public AForm {
private:
    const std::string target;

public:
    RobotomyRequestForm(const std::string& target)
        : AForm("Robotomy Request Form", 72, 45), target(target) {}

    void execute(const class Bureaucrat& executor) const override {
        if (!isSigned() || executor.getGrade() > getGradeToExecute()) {
            throw GradeTooLowException();
        }

        std::cout << "Making drilling noises..." << std::endl;

        // Randomly succeed or fail (50% chance)
        if (rand() % 2 == 0) {
            std::cout << target << " has been robotomized successfully!" << std::endl;
        } else {
            std::cout << "Robotomy failed for " << target << std::endl;
        }
    }
};

class PresidentialPardonForm : public AForm {
private:
    const std::string target;

public:
    PresidentialPardonForm(const std::string& target)
        : AForm("Presidential Pardon Form", 25, 5), target(target) {}

    void execute(const class Bureaucrat& executor) const override {
        if (!isSigned() || executor.getGrade() > getGradeToExecute()) {
            throw GradeTooLowException();
        }

        std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
};

class Bureaucrat {
private:
    const std::string name;
    int grade;

public:
    // ... (previous Bureaucrat implementation)

    void executeForm(const AForm& form) const {
        try {
            form.execute(*this);
            std::cout << name << " executed " << form.getName() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
        }
    }
};

// ... (rest of the Makefile remains unchanged)
