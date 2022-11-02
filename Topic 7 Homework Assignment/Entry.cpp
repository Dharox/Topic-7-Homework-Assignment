#include "Entry.h"
#include <string>

using namespace std;

void Entry::setKey(const int& searchKey)
{
	key = searchKey;
}

Entry::Entry()
{
	key = 0;
	value = "";
}

Entry::Entry(const int& searchKey, const string& newValue)
{
	key = searchKey;
	value = newValue;
}

std::string Entry::getValue() const
{
	return value;
}

int Entry::getKey() const
{
	return key;
}

void Entry::setValue(const string& newValue)
{
	this->value = newValue;
}

bool Entry::operator==(const Entry& rightHandEntry) const
{
	return  (key == rightHandEntry.getKey());
}

bool Entry::operator>(const Entry& rightHandEntry) const
{
	return  (key > rightHandEntry.getKey());
}