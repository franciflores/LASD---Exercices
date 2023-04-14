
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector : virtual public ResizableContainer, virtual public SortableLinearContainer<Data> {
                // Must extend ResizableContainer,
                //             SortableLinearContainer<Data>

private:

  // ...

protected:

  using Container::size;
  ulong dimensione = 0;
  Data* VectorImplementato = nullptr;

  // ...

public:

  // Default constructor
   Vector() = default;

  /* ************************************************************************ */

  // Specific constructors
   Vector(ulong); // A vector with a given initial dimension FATTO
   Vector(MappableContainer<Data>&); // A vector obtained from a MappableContainer FATTO
   Vector(MutableMappableContainer<Data>&); // A vector obtained from a MutableMappableContainer FATTO

  /* ************************************************************************ */

  // Copy constructor
   Vector(const Vector<Data>&); //FATTO

  // Move constructor
   Vector(Vector<Data>&&) noexcept; //FATTO

  /* ************************************************************************ */

  // Destructor
  virtual ~Vector(); //FATTO

  /* ************************************************************************ */

  // Copy assignment
  Vector& operator=(const Vector<Data>&); //FATTO

  // Move assignment
  Vector& operator=(Vector<Data>&&) noexcept; //FATTO

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Vector<Data>&) const noexcept; //FATTO
  bool operator!=(const Vector<Data>&) const noexcept; //FATTO

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  virtual void Clear() override; // Override ClearableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ResizableContainer)

  virtual void Resize(ulong) override; // Override ResizableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  //FATTO
  Data& operator[](const ulong) const override; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
  Data& operator[](const ulong) override; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)

  Data& Front() const override ; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  Data& Front() override; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  Data& Back() const override; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  Data& Back() override; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from SortableLinearContainer)

  virtual void Sort() override; // Override SortableLinearContainer member

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
