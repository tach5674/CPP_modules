#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string name_;

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

	void set_name(std::string name);
};

Zombie *zombieHorde(int N, std::string name);

#endif