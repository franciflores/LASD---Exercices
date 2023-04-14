
#ifndef CONTAINER_HPP
#define CONTAINER_HPP
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

private:

  // ...

protected:

  ulong size = 0;

public:

  // Destructor
  virtual ~Container() = default; //Suppongo basti un distruttore di default soprattutto considerando che la classe è una pure virtual.

  /* ************************************************************************ */
  //Usiamo Riferimenti (type&) poichè dobbiamo utilizzare la variabile (?)

  // Copy assignment
  Container& operator=(const Container&) = delete; // Non possiamo copiare classi virtual tra di loro (non possiamo nemmeno instanziarle se non come variabili da specializzare)

  // Move assignment (&& mantiene il fattore rvalue-lvalue quando usiamo il metodo move [motivo per cui non dobbiamo usarlo in copy, poichè non ci importa del rvalue ma di
  // modificare solo l'lvalue])
  Container& operator=(Container&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  //Ovviamente qui stiamo usando bool poichè abbiamo bisogno
  bool operator==(const Container&) const noexcept; // Comparison of abstract types might not be possible.
  bool operator!=(const Container&) const noexcept; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual bool Empty(){
    return (size==0);
  } // (concrete function should not throw exceptions)

  virtual bool Size(){
    return size;
  } // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

class ClearableContainer : virtual public Container {
                            // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~ClearableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  ClearableContainer& operator=(const ClearableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  ClearableContainer& operator=(ClearableContainer&&) noexcept  = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const ClearableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const ClearableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  virtual void Clear() = 0;

};

/* ************************************************************************** */

class ResizableContainer : virtual public ClearableContainer {
                            // Must extend ClearableContainer

private:

  // ...

protected:

  // ...

public:

  // Destructor
   virtual ~ResizableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  ResizableContainer& operator=(const ResizableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  ResizableContainer& operator=(ResizableContainer&&) = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(ResizableContainer&) = delete; // Comparison of abstract types might not be possible.
  bool operator!=(ResizableContainer&) = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  virtual void Resize(ulong) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  virtual void Clear() override {
    Resize(0);
  }

};

/* ************************************************************************** */

}

#endif
