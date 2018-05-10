#include <iostream>
#include <string>
#include "advland.h"
#include "room.hpp"

Room::Room()
  : rl(Unassigned), rd(" ")
{
   direct = {Unassigned, Unassigned, Unassigned,
             Unassigned, Unassigned, Unassigned};
}

Room::Room(Location l, std::string d, std::vector<Location> dir)
  : rl(l), rd(d), direct(dir)
{}


void Room::operator=(const Room& r)
{
  rl = r.rl;
  rd = r.rd;
  direct = r.direct;
}

bool operator==(Room a, Room b)
{
  return a.rl == a.rl && a.rd == b.rd && a.direct == b.direct;
}

bool operator!=(Room a, Room b)
{
  return !(a == b);
}

Room::~Room()
{}
