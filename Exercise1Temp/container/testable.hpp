
#ifndef TESTABLE_HPP
#define TESTABLE_HPP
#define ulong unsigned long

/* ************************************************************************** */

#include "container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class TestableContainer  : virtual public Container{
                          // Must extend Container

private:

  // ...

protected:

  using Container::size;

public:

  // Destructor
  virtual ~TestableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  TestableContainer& operator = (const TestableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  TestableContainer& operator=(TestableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(TestableContainer&) = delete; // Comparison of abstract types might not be possible.
  bool operator!=(TestableContainer&) = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  virtual bool Exists(const Data&) const noexcept = 0; // (concrete function should not throw exceptions) --> const alla fine? 

};

/* ************************************************************************** */

}

#endif
