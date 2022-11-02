/** An array-based implementation of the ADT dictionary
 that organizes its entries in sorted search-key order.
 Search keys in the dictionary are unique.
 @file ArrayDictionary.h */
#ifndef ARRAY_DICTIONARY_
#define ARRAY_DICTIONARY_

#include "DictionaryInterface.h"
#include "Entry.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcept.h"

class ArrayDictionary : public DictionaryInterface
{
private:
    static const int DEFAULT_CAPACITY = 21;               // Small capacity to test for a full dictionary
    Entry entries[DEFAULT_CAPACITY];                      // Array of dictionary entries
    int entryCount;                                       // Current count of dictionary entries
    int maxEntries;                                       // Maximum capacity of the dictionary

    void destroyDictionary();
    int findEntryIndex(int firstIndex, int lastIndex, const int& searchKey) const;

public:
    ArrayDictionary();
    ArrayDictionary(int maxNumberOfEntries);
    // ArrayDictionary(const ArrayDictionary& dictionary);
    virtual ~ArrayDictionary();

    bool isEmpty() const;
    int getNumberOfEntries() const;

    bool add(const int& searchKey, const std::string& newValue) throw(PrecondViolatedExcept);
    bool remove(const int& searchKey);
    void clear();

    std::string getValue(const int& searchKey) const throw(NotFoundException);
    bool contains(const int& searchKey) const;

    /** Traverses the entries in this dictionary in sorted search-key order
     and calls a given client function once for the value in each entry. */
    void traverse(void visit(std::string& searchValue)) const;

}; // end ArrayDictionary
#endif