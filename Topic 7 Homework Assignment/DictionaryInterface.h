#ifndef DICTIONARY_INTERFACE_
#define DICTIONARY_INTERFACE_

#include "NotFoundException.h"

class DictionaryInterface
{
public:
    /** Sees whether this dictionary is empty.
     @return  True if the dictionary is empty;
        otherwise returns false. */
    virtual bool isEmpty() const = 0;

    /** Gets the number of entries in this dictionary.
     @return  The number of entries in the dictionary. */
    virtual int getNumberOfEntries() const = 0;

    /** Adds a new search key and associated value to this dictionary.
     @pre  The new search key differs from all search keys presently
        in the dictionary.
     @post  If the addition is successful, the new key-value pair
        proper position within the dictionary.
     @param searchKey  The search key associated with the value to
     @param newValue  The value to be added.
     @return  True if the entry was successfully added, or false if not. */
    virtual bool add(const int& searchKey, const std::string& newValue) = 0;

    /** Removes a key-value pair from this dictionary.
    @post  If the entry whose search key equals searchKey existed in the
       dictionary, the entry was removed.
    @param searchKey  The search key of the entry to be removed.
    @return  True if the entry was successfully removed, or false if not. */
    virtual bool remove(const int& searchKey) = 0;

    /** Removes all entries from this dictionary. */
    virtual void clear() = 0;

    /** Retrieves the value in this dictionary whose search key is given
     @post  If the retrieval is successful, the value is returned.
     @param searchKey  The search key of the value to be retrieved.
     @return  The value associated with the search key.
     @throw  NotFoundException if the key-value pair does not exist. */
    virtual std::string getValue(const int& searchKey) const
        throw (NotFoundException) = 0;
    /** Sees whether this dictionary contains an entry with a given search key.
    @post  The dictionary is unchanged.
    @param searchKey  The given search key.
    @return  True if an entry with the given search key exists in the dictionary. */
    virtual bool contains(const int& searchKey) const = 0;

    /** Traverses this dictionary and calls a given client function
        for each entry.
     @post  The given function's action occurs once for each entry in the
        dictionary and possibly alters the entry.
     @param visit  A client function. */
    virtual void traverse(void visit(std::string&)) const = 0;

    /** Destroys this dictionary and frees its assigned memory. */
    virtual ~DictionaryInterface() { }
}; // end DictionaryInterface

#endif
