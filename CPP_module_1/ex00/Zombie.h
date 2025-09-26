#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
private:
	std::string name;

public:
	// Default constructor
	Zombie(std::string name);

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