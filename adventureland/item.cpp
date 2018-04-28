#include <iostream>
#include <string>
#include "advland.h"
#include "item.hpp"



Item::Item()
  : il(Unassigned)
{}

Item::Item(Location l)
  : il(l)
{}

void Item::operator=(Location a)
{
  il = a;
}

bool Item::operator==(Location a)
{
  return il == a;
}

bool Item::operator!=(Location a)
{
  return il != a;
}
