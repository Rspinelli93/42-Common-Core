/*
Your subject: polyset
==================================================
Assigment name: Polyset
Expected File: searchable_array_bag.cpp, searchable_array_bag.hpp,
searchable_tree_bg.cpp, searchable_tree_bag.hpp, set.cpp, set.hpp

You will find in this directory some classes:
- bag: an abstract class representing a bag
- searchable_bag: an abstract class representing a bag with the ability to
	search in it.
- array_bag: an implementation of a bag with an array an underlying data
	structure.
- tree_bag: an implementation of a bag with a binary search tree as underlying
	data structure.

If you don't know what is a set or a bag (shame!) you can read the attached
file shame.en.txt

First Part:
Since a bag without a searching function isn't very useful, implement two
classes searchable_array_bag and searchable_tree_bag, that will inherit from
array_bag and tree_bag and implement the searchable bag abstract class.

Second Part:
Implement the class set that will wrap a searchable_bag and turn it into a set.
You will find in this dir a main that must compile with your code.
All classes should be under orthodox canonical form. Don't forget the const.

==================================================
*/

/*
*	DEFINITIONS
*	---------------------------------------------------------------------------------------
*	Attribute	|					BAG					|				SET
*	---------------------------------------------------------------------------------------
*	Definition	|	A collection of unordered elements	|	A collection of unique elements
				|	with possible duplicates	 		|	with no duplicates
*	---------------------------------------------------------------------------------------
*	Order		|	Does not maintain order of elements	|	Maintains order of elements
*	---------------------------------------------------------------------------------------
*	Duplicates	|	Allows duplicates					|	Does not allow duplicates
*	---------------------------------------------------------------------------------------
*	Operations	|	Supports operations like add,		|	Supports operations like add,
				|	remove, and contains				|	remove, and contains
*	---------------------------------------------------------------------------------------
*/

#include "searchable_bag.hpp"

#include <iostream>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc == 1)
    return 1;
  searchable_bag *t = new searchable_tree_bag;
  searchable_bag *a = new searchable_array_bag;

  for (int i = 1; i < argc; i++) {
    t->insert(atoi(argv[i]));
    a->insert(atoi(argv[i]));
  }
  t->print();
  a->print();

  for (int i = 1; i < argc; i++) {
    std::cout << t->has(atoi(argv[i])) << std::endl;
    std::cout << a->has(atoi(argv[i])) << std::endl;
    std::cout << t->has(atoi(argv[i]) - 1) << std::endl;
    std::cout << a->has(atoi(argv[i]) - 1) << std::endl;
  }

  t->clear();
  a->clear();

  const searchable_array_bag tmp(static_cast<searchable_array_bag &>(*a));
  tmp.print();
  tmp.has(1);

  set sa(*a);
  set st(*t);
  for (int i = 1; i < argc; i++) {
    st.insert(atoi(argv[i]));
    sa.insert(atoi(argv[i]));

    sa.has(atoi(argv[i]));
    sa.print();
    sa.get_bag().print();
    st.print();
    sa.clear();
    int values[] = {1, 2, 3, 4};
    sa.insert(values, 4);
    std::cout << std::endl;
  }
  delete a;
  delete t;
  return 0;
}

// Objective: practice OOP composition/inheritance and the difference between a 
// bag (multiset — duplicates allowed) and a set (no duplicates).

// Breakdown:

// searchable_array_bag / searchable_tree_bag: you're given array_bag/tree_
// bag (store elements, allow duplicates, no search). You inherit from them 
// AND implement searchable_bag's interface (probably a contains(T) method) — 
// so you're adding search capability on top of existing storage without rewriting 
// storage logic. This tests multiple inheritance (implementation inheritance
// from the concrete bag + interface inheritance from the abstract searchable_bag).

// set: not inheritance — composition. set has a searchable_bag* internally 
// (that's the point of making searchable_bag abstract — set doesn't care if 
// it wraps an array or tree implementation). set enforces the actual 
// set property: no duplicates. So set::insert must check contains() before adding.

// Real lesson here: program to an interface, not an implementation — 
// set only knows about searchable_bag, letting you swap array/tree backend 
// with zero changes to set's code.

// Also testing: orthodox canonical form (constructor, copy constructor, 
// 	operator=, destructor) on every class, and proper const usage on 
// 	read-only methods (contains, size, etc.)