#include <iostream>
#include <string>
#include "item.hpp"

Item::Item()
  : location(0)
{}

Item::Item(signed char l)
  : location(l)
{}

void Item::operator=(int a)
{
  location = a;
}

bool Item::operator==(int a)
{
  return location == a;
}

bool Item::operator!=(int a)
{
  return location != a;
}
