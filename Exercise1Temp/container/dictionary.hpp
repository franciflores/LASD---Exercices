
#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/* ************************************************************************** */

#include "testable.hpp"
#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class DictionaryContainer : virtual public TestableContainer<Data> {
                            // Must extend TestableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~DictionaryContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  DictionaryContainer& operator=(const DictionaryContainer&) =  delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  DictionaryContainer& operator=(DictionaryContainer&&) = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const DictionaryContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const DictionaryContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  bool Insert(Data& copy); // Copy of the value
  bool Insert(Data&& move); // Move of the value
  bool Remove(Data& remove);

  bool InsertAll() ; // Copy of the value; From MappableContainer; True if all are inserted
  bool InsertAll() ; // Move of the value; From MutableMappableContainer; True if all are inserted
  bool RemoveAll() ; // From MappableContainer; True if all are removed

  bool InsertSome() ; // Copy of the value; From MappableContainer; True if some is inserted
  bool InsertSome() ; // Move of the value; From MutableMappableContainer; True if some is inserted
  bool RemoveSome() ; // From MappableContainer; True if some is bool
};

/* ************************************************************************** */

}

#include "dictionary.cpp"

#endif
