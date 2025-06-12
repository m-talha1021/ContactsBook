#pragma once

#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB

#include "Address.h"

class Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string mobile_number;
	std::string email_address;
	Address *address;

public:
	// Constructors
	Contact();
	Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address, Address *address);

	// Getter and setter functions
	std::string get_first_name() const;
	void set_first_name(const std::string& first_name);

	std::string get_last_name() const;
	void set_last_name(const std::string& last_name);

	std::string get_mobile_number() const;
	void set_mobile_number(const std::string& mobile_number);

	std::string get_email_address() const;
	void set_email_address(const std::string& email_address);

	Address* get_address() const;
	void set_address(Address *address);

	// Other member functions
	bool equals(const Contact& contact);
	Contact* copy_contact();
};
