#include<iostream>
#include "Contact.h"
using namespace std;
// Constructors implementation
Contact::Contact() {}

Contact::Contact(std::string first_name, string last_name, std::string mobile_number, std::string email_address, Address *address) :
	first_name(first_name), last_name(last_name), mobile_number(mobile_number), email_address(email_address), address(address) {}

// Getter and setter 
string Contact::get_first_name() const
{
	return first_name;
}

void Contact::set_first_name(const string& first_name)
{
	if (!first_name.empty())
	{
		this->first_name = first_name;
	}
}

string Contact::get_last_name() const
{
	return last_name;
}

void Contact::set_last_name(const string& last_name) 
{
	if (!last_name.empty()) {
		this->last_name = last_name;
	}
}

string Contact::get_mobile_number() const 
{
	return mobile_number;
}

void Contact::set_mobile_number(const string& mobile_number) {
	if (mobile_number.length() == 11) 
	{
		this->mobile_number = mobile_number;
	}
}

string Contact::get_email_address() const 
{
	return email_address;
}

void Contact::set_email_address(const string& email_address) {
	if (!email_address.empty())
	{
		this->email_address = email_address;
	}
}

Address* Contact::get_address() const
{
	return address;
}

void Contact::set_address(Address *address) {
	this->address = address;
}

// Other member function implementations
bool Contact::equals(const Contact& contact) 
{
	return (first_name == contact.first_name && last_name == contact.last_name &&
		mobile_number == contact.mobile_number && email_address == contact.email_address &&
		address->equals(*(contact.address)));
}

Contact* Contact::copy_contact() 
{
	Contact* copied_contact = new Contact(); // Create a new Contact object
   // Copy the attributes from the original contact to the new contact
	copied_contact->set_first_name(first_name);
	copied_contact->set_last_name(last_name);
	copied_contact->set_mobile_number(mobile_number);
	copied_contact->set_email_address(email_address);
	// new Address object & copy address details
	Address* copied_address = new Address(address->get_house(), address->get_street(), address->get_city(), address->get_country());
	copied_contact->set_address(copied_address);
	return copied_contact; 
}


