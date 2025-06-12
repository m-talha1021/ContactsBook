#include<iostream>
#include "Address.h"
using namespace std;
// Constructor implementation
Address::Address(string house, string street, string city, string country) :
	house(house), street(street), city(city), country(country) {}

// Getter and setter implementations
string Address::get_house() const 
{
	return house;
}

void Address::set_house(const string& house)
{
	this->house = house;
}

string Address::get_street() const
{
	return street;
}

void Address::set_street(const string& street)
{
	this->street = street;
}

string Address::get_city() const
{
	return city;
}

void Address::set_city(const string& city)
{
	this->city = city;
}

string Address::get_country() const
{
	return country;
}

void Address::set_country(const string& country)
{
	this->country = country;
}

// Other member function implementations
bool Address::equals(const Address& address)
{
	return (house == address.house && street == address.street && city == address.city && country == address.country);
}

void Address::print_address()
{
	cout << house << " " << street << " " << city << " " << country << endl;
}
Address Address::copy_address() 
{
	return Address(house, street, city, country);
}
