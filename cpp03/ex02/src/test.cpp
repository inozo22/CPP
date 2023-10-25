#include <iostream>
#include <string>


class ClapTrap {
public:
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& other);
    virtual ~ClapTrap(); // Virtual destructor for proper chaining

    void attack(const std::string& target);

    // Getter for name
    std::string getName() const;

protected:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;
};

class FragTrap : public ClapTrap {
public:
    FragTrap(const std::string& name);
    ~FragTrap(); // Destructor

    void attack(const std::string& target); // Overriding the attack method
    void highFivesGuys();
};



ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(100), energyPoints(50), attackDamage(20) {
    std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
    std::cout << "ClapTrap " << name << " copied" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    std::cout << "ClapTrap " << name << " attacks " << target << " with " << attackDamage << " damage!" << std::endl;
}

std::string ClapTrap::getName() const {
    return name;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "FragTrap " << name << " is ready to frag!" << std::endl;
    // Customize attributes for FragTrap
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << name << " says goodbye and disappears in a puff of smoke!" << std::endl;
}

void FragTrap::attack(const std::string& target) {
    std::cout << "FragTrap " << name << " attacks " << target << " with a powerful attack, dealing " << attackDamage << " damage!" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << name << " requests a high-five from everyone!" << std::endl;
}

int main() {
    ClapTrap clapTrap("CL4P-TP");
    FragTrap fragTrap("FR4G-TP");

    clapTrap.attack("Bandit");
    fragTrap.attack("Bandit");

    fragTrap.highFivesGuys();

    return 0;
}
