#pragma once
#include <iostream>
#include <string>

class Address {
private:
	std::string house;
	std::string street;
	std::string city;
	std::string country;

public:
	// Constructor
	Address(std::string house, std::string street, std::string city, std::string country);
	Address() {}

	// Getter and setter functions
	std::string get_house() const;
	void set_house(const std::string& house);

	std::string get_street() const;
	void set_street(const std::string& street);

	std::string get_city() const;
	void set_city(const std::string& city);

	std::string get_country() const;
	void set_country(const std::string& country);

	// Other member functions
	bool equals(const Address& address);
	void print_address();
	Address copy_address();
};
