#include "ArrayDictionary.h"
#include <iostream>
using namespace std;

ArrayDictionary::ArrayDictionary()
{
    entryCount = 0;
    maxEntries = DEFAULT_CAPACITY;
}

ArrayDictionary::ArrayDictionary(int maxNumberOfEntries)
{
    entryCount = 0;
    maxEntries = maxNumberOfEntries;
}

ArrayDictionary::~ArrayDictionary()
{
    destroyDictionary();
}

void ArrayDictionary::destroyDictionary()
{
    clear();
}

int ArrayDictionary::findEntryIndex(int firstIndex, int lastIndex, const int& searchKey) const
{
    int index = entryCount;

    while ((index >= 0) && (searchKey != entries[index].getKey()))
    {
        if (searchKey == entries[index].getKey())
        {
            // return index if searchKey is found
            return index;
        }
        else
        {
            index--;
        }
    }

    return index;
}

bool ArrayDictionary::isEmpty() const
{
    return (entryCount == 0);
}

int ArrayDictionary::getNumberOfEntries() const
{
    return entryCount;
}

bool ArrayDictionary::add(const int& searchKey, const std::string& newValue)
throw(PrecondViolatedExcept)
{
    bool ableToInsert = (entryCount < maxEntries);
    if (ableToInsert)
    {
        // Make room for new entry by shifting all entries at
        // positions >= newPosition toward the end of the array
        // (no shift if newPosition == itemCount + 1). Performing
        // a binary search doesn't help here, because we need to
        // shift the entries while looking for the location of the addition.
        int index = entryCount;

        // Short-circuit evaluation is important
        while ((index > 0) && (searchKey < entries[index - 1].getKey()))
        {
            entries[index] = entries[index - 1];
            index--;
        }

        // Enforce precondition: Ensure distinct search keys
        if (searchKey != entries[index - 1].getKey())
        {
            // Insert new entry
            entries[index] = Entry(searchKey, newValue);
            entryCount++; // Increase count of entries
        }
        else
        {
            auto message = "Attempt to add an entry whose search key exists in dictionary.";
            throw(PrecondViolatedExcept(message));
        }
    }

    return ableToInsert;
}

bool ArrayDictionary::remove(const int& searchKey)
{
    bool found = false;

    for (int i = 0; i < entryCount; i++)
    {
        if (searchKey == entries[i].getKey() || found == true)
        {
            found = true;
            entries[i] = entries[i + 1];
        }
    }
    entryCount--;

    return found;
}

void ArrayDictionary::clear()
{
    bool noError = true;
    while (entryCount > 0 && noError)
    {
        noError = remove(entryCount);
    }

    if (!noError && entryCount > 0)
    {
        cout << "\nError with clearing dictionary." << endl;
    }
}

void ArrayDictionary::traverse(void visit(std::string& searchValue)) const
{

}
