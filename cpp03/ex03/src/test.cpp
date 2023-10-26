#include <iostream>
#include <string>

class ClapTrap {
public:
    ClapTrap(std::string name) : name(name) {}

protected:
    std::string name;
};

class FragTrap {
public:
    FragTrap(std::string name) : hitPoints(100), energyPoints(100), attackDamage(30), name(name + "_clap_name") {}

    void attack(std::string target) {
        std::cout << "FragTrap " << name << " attacks " << target << " causing " << attackDamage << " points of damage!" << std::endl;
    }

protected:
    int hitPoints;
    int energyPoints;
    int attackDamage;
};

class ScavTrap {
public:
    ScavTrap(std::string name) : energyPoints(50), name(name + "_clap_name") {}

    void attack(std::string target) {
        std::cout << "ScavTrap " << name << " attacks " << target << " causing " << energyPoints << " points of damage!" << std::endl;
    }

protected:
    int energyPoints;
    std::string name;
};

class DiamondTrap : public FragTrap, public ScavTrap {
public:
    DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name) {}

    void whoAmI() {
        std::cout << "I am " << name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
    }
};

int main() {
    DiamondTrap diamond("Diamond");

    diamond.whoAmI();
    diamond.attack("Target");
    diamond.FragTrap::attack("Target");
    diamond.ScavTrap::attack("Target");

    return 0;
}
