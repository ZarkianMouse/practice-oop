#include <iostream>
#include <string>
#include "advland.h"
#include "room.hpp"

Room::Room()
  : rd(" ")
{
   direct = {Unassigned, Unassigned, Unassigned,
             Unassigned, Unassigned, Unassigned};
}

Room::Room(std::string d, std::vector<Location> dir)
  : rd(d), direct(dir)
{}


void Room::operator=(const Room& r)
{
  rd = r.rd;
  direct = r.direct;
}

bool operator==(Room a, Room b)
{
  return a.rd == b.rd && a.direct == b.direct;
}

bool operator!=(Room a, Room b)
{
  return !(a == b);
}

Room::~Room()
{}
