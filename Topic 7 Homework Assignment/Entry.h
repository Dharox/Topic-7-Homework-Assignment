#ifndef ENTRY_
#define ENTRY_

class Entry
{
private:
	int key;
	std::string value;

protected:
	void setKey(const int& searchKey);

public:
	Entry();
	Entry(const int& searchKey, const std::string& newValue);
	std::string getValue() const;
	int getKey() const;
	void setValue(const std::string& newValue);
	bool operator==(const Entry& rightHandValue) const;
	bool operator>(const Entry& rightHandValue) const;
}; // end Entry
#endif
