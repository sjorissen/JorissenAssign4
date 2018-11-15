// Sarah Jorissen
// CSCI 3250
// Assignment 4
// Class definition for a Set ADT

#ifndef SET_HPP
#define SET_HPP

template <typename Item>
class Set {
public:
  virtual bool isEmpty() const = 0;
  virtual void clear() = 0;
  virtual void copyTo(Set &set) const = 0;
  virtual bool contains(const Item& item) const = 0;
  virtual void insert(const Item& item) = 0;
  virtual void remove(const Item& item) = 0;
  virtual void display() const = 0;
  virtual void setUnion(const Set& set2, Set& result) const = 0;
  virtual void setIntersection(const Set& set2, Set& result) const = 0;
  virtual void setDifference(const Set& set2, Set& result) const = 0;
};

#endif
