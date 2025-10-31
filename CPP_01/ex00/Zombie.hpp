#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string _name;

public:
	// Default constructor
	Zombie();

	// Parameterized constructer
	Zombie(std::string n);

	// Copy constructor
	Zombie(const Zombie &other);

	// Copy assignment operator
	Zombie &operator=(const Zombie &other);

	// Destructor
	~Zombie();

	void announce(void);
};

Zombie *newZombie(std::string name);

void randomChump(std::string name);

#endif