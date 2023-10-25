#include <iostream>
#include <string>

class ClapTrap {
public:
    ClapTrap(const std::string& name) : name(name), hitPoints(100), energyPoints(50), attackDamage(20) {
        std::cout << "ClapTrap " << name << " created" << std::endl;
    }

    ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
        std::cout << "ClapTrap " << name << " copied" << std::endl;
    }

    ~ClapTrap() {
        std::cout << "ClapTrap " << name << " destroyed" << std::endl;
    }

    void attack(const std::string& target) {
        std::cout << "ClapTrap " << name << " attacks " << target << " with " << attackDamage << " damage!" << std::endl;
    }

protected:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;
};

class ScavTrap : public ClapTrap {
public:
    ScavTrap(const std::string& name) : ClapTrap(name) {
        std::cout << "ScavTrap " << name << " created" << std::endl;
    }

    ~ScavTrap() {
        std::cout << "ScavTrap " << this->name << " destroyed" << std::endl;
    }

    void guardGate() {
        std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
    }
};

int main() {
    ClapTrap clapTrap("CL4P-TP");
    ScavTrap scavTrap("SC4V-TP");

    clapTrap.attack("Bandit");
    scavTrap.attack("Bandit");

    scavTrap.guardGate();

    return 0;
}
