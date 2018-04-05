#define IL      60+1
#define MX      5       /* max number of items allowed to carry */


// IA$(60) item descriptions
const char *IAS[IL] =
{
  " ",
  "dark hole",
  "*POT OF RUBIES*/RUB/",
  "spider web with writing on it.",
  "Hollow stump and remains of a felled tree.",
  "cypress tree",
  "water",
 "evil smelling mud/MUD/",
  "*GOLDEN FISH*/FIS/",
  "lit brass lamp/LAM/",
  "old fashoned brass lamp/LAM/",
  "rusty axe (magic word- BUNYON -on it)/AXE/",
  "bottle of water/BOT/",
  "empty bottle/BOT/",
  "ring of skeleton keys/KEY/",
  "sign- LEAVE TREASURE HERE - (say 'SCORE')",
  "locked door",
  "open door with a hallway beyond",
  "swamp gas",
  "*GOLDEN NET*/NET/",
  "chigger bites",
  "infected chigger bites",
  "floating patch of oily slime",
  "*ROYAL HONEY*/HON/",
  "large african bees",
  "thin black bear",
  "bees in a bottle/BOT/",
  "large sleeping dragon",
  "flint and steel/FLI/",
  "*THICK PERSIAN RUG*/RUG/",
  "sign- MAGIC WORD IS AWAY. LOOK LA -(rest of sign is missing)",
  "distended gas bladder/BLA/",
  "bricked up window",
  "sign here says- IN SOME CASES MUD IS GOOD, IN OTHERS...",
  "stream of lava",
  "bricked up window with a hole in it.  Beyond is a ledge.",
  "loose fire bricks",
  "*GOLD CROWN*/CRO/",
  "*MAGIC MIRROR*",
  "sleeping bear",
  "empty wine bladder/BLA/",
  "broken glass",
  "chiggers/CHI/",
  "dead bear",
  "*DRAGON EGGS* (very rare)/EGG/",
  "lava stream with a brick dam",
  "*JEWELED FRUIT*/FRU/",
  "*SMALL STATUE OF A BLUE OX*/OX/",
  "*DIAMOND RING*/RIN/",
  "*DIAMOND BRACELET*/BRA/",
  "strange scratchings on rock reveals- ALADDIN WAS HERE -",
  "sign says- LIMBO.  FIND RIGHT EXIT AND LIVE AGAIN!",
  "smoking hole.  Pieces of dragon and gore.",
  "sign says- NO SWIMMING ALLOWED -",
  "arrow pointing down",
  "dead fish/FIS/",
  "*FIRESTONE* (cold now)/FIR/",
  "sign says- PAUL'S PLACE -",
  "trees",
  " ",
  " "
};

/* I2(60) item locations */
const signed char I2[IL] =
{
  0,4,4,2,0,1,10,1,10,0,
  3,10,3,0,2,3,5,0,1,18,
  0,0,1,8,8,21,0,23,13,17,
  18,0,20,23,18,0,0,22,21,0,
  9,0,1,0,0,0,25,26,0,0,
  14,33,0,10,17,0,0,25,11,0,
  0
};