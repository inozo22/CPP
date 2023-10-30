// #include <iostream>
// #include <string>

// class ClapTrap {
// private:
//     std::string Name;
//     int HitPoints;
//     int EnergyPoints;
//     int AttackDamage;

// public:
//     // Constructor
//     ClapTrap(const std::string& name) : Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0) {
//         std::cout << "ClapTrap " << Name << " has been created with " << HitPoints << " HP and " << EnergyPoints << " Energy." << std::endl;
//     }

//     // Destructor
//     ~ClapTrap() {
//         std::cout << "ClapTrap " << Name << " has been destroyed." << std::endl;
//     }

//     // Member function to attack a target
//     void attack(const std::string& target) {
//         if (HitPoints > 0 && EnergyPoints > 0) {
//             std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
//             EnergyPoints--;
//         } else {
//             std::cout << "ClapTrap " << Name << " can't attack because it has no hit points or energy points left." << std::endl;
//         }
//     }

//     // Member function to take damage
//     void takeDamage(unsigned int amount) {
//         if (HitPoints > 0) {
//             HitPoints -= amount;
//             if (HitPoints < 0) HitPoints = 0;
//             std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage. It has " << HitPoints << " hit points left." << std::endl;
//         } else {
//             std::cout << "ClapTrap " << Name << " can't take damage because it has no hit points left." << std::endl;
//         }
//     }

//     // Member function to be repai
//     void beRepai(unsigned int amount) {
//         if (HitPoints > 0 && EnergyPoints > 0) {
//             HitPoints += amount;
//             std::cout << "ClapTrap " << Name << " is repai for " << amount << " hit points. It now has " << HitPoints << " hit points." << std::endl;
//             EnergyPoints--;
//         } else {
//             std::cout << "ClapTrap " << Name << " can't be repai because it has no hit points or energy points left." << std::endl;
//         }
//     }
// };

// int main() {
//     ClapTrap claptrap1("ClapTrap1");
//     ClapTrap claptrap2("ClapTrap2");

//     claptrap1.attack("Enemy");
//     claptrap1.takeDamage(5);
//     claptrap1.beRepai(3);
//     claptrap1.attack("Enemy");

//     claptrap2.takeDamage(15);
//     claptrap2.beRepai(8);
//     claptrap2.attack("Enemy");

//     return 0;
// }


# include <string>

class ClapTrap
{
	public:
		static unsigned int const	defaultHitPoints = 10;
		static unsigned int const	defaultEnergyPoints = 10;
		static unsigned int const	defaultAttackDamage = 0;

		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap(void);

		ClapTrap &	operator=(ClapTrap const & src);
		
		std::string		getName(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;
		
		void		attack(std::string & target);
		void		takeDamage(unsigned int amount);
		void		beRepai(unsigned int amount);

	private:
		ClapTrap(void);
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#include <iostream>
#include <string>

ClapTrap::ClapTrap(void)
	: _name("Default"),
	_hitPoints(ClapTrap::defaultHitPoints),
	_energyPoints(ClapTrap::defaultEnergyPoints),
	_attackDamage(ClapTrap::defaultAttackDamage) {
	std::cerr << "ClapTrap default constructor called."<< std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name),
	_hitPoints(ClapTrap::defaultHitPoints),
	_energyPoints(ClapTrap::defaultEnergyPoints),
	_attackDamage(ClapTrap::defaultAttackDamage) {
	std::cerr << "A ClapTrap named \"" << name << "\" was constructed."<< std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	std::cerr << "ClapTrap copy constructor called."  << std::endl;
	*this = src;
	return ;
}

ClapTrap::~ClapTrap(void) {
	std::cerr << "The ClapTrap named \"" << this->_name << "\" was destroyed." << std::endl;
	return ;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & src) {
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}

std::string	ClapTrap::getName(void) const {
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints(void) const {
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const {
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const {
	return (this->_attackDamage);
}

void	ClapTrap::attack(std::string & target) {
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name
			<< " can't attack: it is destroyed."  << std::endl;
		return ;
	}
	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << this->_name
			<< " can't attack: its battery is depleted." 
			<< std::endl;
		return ;
	}
	if (target == this->_name)
		target = "itself";
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name
		<< " attacks " << target << " and hits for " << this->_attackDamage
		<< " damage!"  << std::endl; 
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout <<  "ClapTrap " << this->_name
			<< " can't take anymore damage: it is already beyond repair!" 
			<< std::endl;
		return;
	}
	if ((int)this->_hitPoints - (int)amount <= 0) {
		this->_hitPoints = 0;
		std::cout <<  "ClapTrap " << this->_name
			<< " takes " << amount << " damage and is destroyed!"  << std::endl;
	}
	else {
		this->_hitPoints -= amount;
		std::cout <<  "ClapTrap " << this->_name
			<< " takes " << amount << " damage!"  << std::endl;
	}
	return ;
}

void	ClapTrap::beRepai(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout <<  "ClapTrap " << this->_name
			<< " can't repair itself: it is too severely damaged."  << std::endl;
		return ;
	}
	if (this->_energyPoints == 0) {
		std::cout <<  "ClapTrap " << this->_name
			<< " can't repair itself: its battery is depleted and needs recharging."
			 << std::endl;
		return ;
	}
	if ((this->_hitPoints + amount) > ClapTrap::defaultHitPoints)
		amount = ClapTrap::defaultHitPoints - this->_hitPoints;
	if (amount == 0) {
		this->_energyPoints--;
		std::cout <<  "ClapTrap " << this->_name
			<< " wastes energy trying to repair itself when it is already in tip top shape."
			 << std::endl;
		return ;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout <<  "ClapTrap " << this->_name << " repairs itself for "
		<< amount << "."  << std::endl;
	return ;
}

int	main(void) {
	std::string trapName0 = "CT000";
	std::string trapName1 = "CT-42";

	ClapTrap	trap0(trapName0);
	ClapTrap	trap1(trapName1);

	trap0.beRepai(0);
	for (int i = 0; i < 9; i++) {
		trap0.attack(trapName1);
		trap1.takeDamage(ClapTrap::defaultAttackDamage);
	}
    std::cout << "hello, after a loop!" << std::endl;
	trap0.attack(trapName1);
	trap1.takeDamage(5);
	trap1.beRepai(4);
	trap1.attack(trapName0);
	trap0.takeDamage(5);
	trap0.beRepai(5000);
	trap1.beRepai(5000);
	trap1.attack(trapName1);
	trap1.takeDamage(5000);
	trap1.beRepai(5000);
	trap1.takeDamage(1);
	return (0);
}
