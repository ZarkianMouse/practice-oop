#include <iostream>
#include <string>
#include "advland.h"
#include "item.hpp"



Item::Item()
  : il(Unassigned), id(" ")
{}

Item::Item(Location l, std::string d)
  : il(l), id(d)
{}

void Item::setLocate(Location l)
{
  il = l;
}
void Item::operator=(const Item& i)
{
  il = i.il;
  id = i.id;
}

bool operator==(Item a, Item b)
{
  return a.il == b.il && a.id == b.id;
}

bool operator!=(Item a, Item b)
{
  return !(a == b);
}

Item::~Item()
{}
