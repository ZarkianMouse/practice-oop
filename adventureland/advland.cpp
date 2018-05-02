/* file to hold initial adventureland function definitions */

#include <iostream>
#include "advland.h"

/* C0%(151), C1%(151), C2%(151), C3%(151),
   C4%(151), C5%(151), C6%(151), C7%(151) action */
const unsigned int C[CL][8] =
{
  75,161,386,160,200,0,17612,0,
  10,401,420,400,146,0,1852,8850,
  8,421,0,0,0,0,2011,0,
  8,521,520,260,0,0,2609,7800,
  100,108,760,820,420,100,8312,9064,
  100,484,0,0,0,0,5613,0,
  5,141,140,20,246,0,6062,0,
  5,406,426,400,442,146,7845,0,
  8,482,152,0,0,0,2311,0,
  100,104,0,0,0,0,8550,0,
  50,161,246,160,1100,0,7259,7800,
  100,148,140,940,500,0,9062,9900,
  30,841,426,406,400,0,7845,0,
  50,542,141,0,0,0,10504,9150,
  100,248,642,720,640,700,8005,7950,
  100,248,542,1040,540,0,8005,0,
  100,28,49,20,40,0,6360,8700,
  100,288,260,280,0,0,7860,9150,
  100,248,240,0,0,0,9660,0,
  100,269,260,0,0,0,16558,17357,
  100,28,48,20,40,0,4110,9000,
  4366,22,0,0,0,0,6900,0,
  4374,0,0,0,0,0,9750,0,
  4404,682,0,0,0,0,6900,0,
  4407,82,0,0,0,0,6900,0,
  1521,142,421,420,140,0,8902,450,
  1542,462,146,482,0,0,2311,0,
  1521,142,401,400,140,0,8902,450,
  2742,461,460,502,780,500,8864,8005,
  2742,461,460,0,0,0,7950,0,
  1523,482,146,0,0,0,2311,0,
  1523,482,141,266,0,0,2400,0,
  1523,482,141,261,260,520,8902,0,
  1533,0,0,0,0,0,9900,0,
  4350,0,0,0,0,0,10564,0,
  5100,0,0,0,0,0,9900,0,
  3450,581,344,460,0,0,8118,8614,
  2125,623,566,0,0,0,2850,0,
  2125,621,561,620,0,0,3021,9209,
  6794,0,0,0,0,0,17100,0,
  2125,622,561,620,240,0,10555,8720,
  184,404,702,380,0,0,8170,9600,
  1525,24,806,0,0,0,2400,0,
  1525,24,801,800,620,0,8902,0,
  2725,621,620,800,0,0,8902,3450,
  2125,362,561,0,0,0,3300,0,
  6803,0,0,0,0,0,17100,0,
  185,384,0,0,0,0,3750,0,
  1510,762,760,505,0,0,7800,0,
  2710,761,760,582,20,0,7986,8700,
  6343,921,920,0,0,0,509,0,
  1513,122,261,260,240,0,8902,0,
  900,384,420,726,0,0,8164,0,
  900,424,380,0,0,0,8164,0,
  185,424,502,0,0,0,3900,0,
  185,424,505,440,0,0,8170,9600,
  5265,0,0,0,0,0,10650,0,
  204,682,0,0,0,0,7650,0,
  2723,521,502,520,480,280,4259,8008,
  1513,122,266,0,0,0,2400,0,
  5751,62,0,0,0,0,300,0,
  207,40,102,0,0,0,8170,9600,
  2713,241,240,260,0,0,8902,4350,
  1528,442,440,200,0,0,8319,8294,
  1257,100,102,292,80,221,8303,1050,
  5870,104,322,286,0,0,900,0,
  5570,104,322,286,0,0,900,0,
  3611,221,60,220,0,0,4558,7950,
  5870,322,281,320,340,0,8303,9600,
  2737,721,685,720,0,0,7950,0,
  900,384,721,0,0,0,5011,0,
  2737,721,1120,900,680,720,8003,8309,
  1537,722,720,0,0,0,4852,0,
  3300,0,0,0,0,0,5100,0,
  3900,0,0,0,0,0,9813,0,
  1510,762,502,0,0,0,3900,0,
  2710,761,585,820,760,0,5303,8850,
  1050,68,765,60,0,0,16710,0,
  4800,68,60,542,0,0,5910,0,
  4950,0,0,0,0,0,9750,0,
  7050,401,0,0,0,0,16613,15750,
  7050,421,0,0,0,0,16613,15750,
  184,364,0,0,0,0,15300,0,
  1554,682,0,0,0,0,7650,0,
  7650,502,860,360,500,0,6212,8250,
  2723,521,542,480,880,540,8003,8293,
  7350,68,60,0,0,0,9001,16607,
  5870,342,0,0,0,0,9600,0,
  166,702,380,0,0,0,10554,9600,
  1050,68,760,100,80,502,8308,4710,
  6761,0,0,0,0,0,16614,0,
  5400,0,0,0,0,0,197,0,
  207,82,60,0,0,0,8170,9600,
  1257,102,221,100,80,281,8303,1200,
  6038,502,0,0,0,0,3947,0,
  6039,542,0,0,0,0,5897,0,
  6313,241,240,260,0,0,509,7800,
  6313,122,0,0,0,0,450,0,
  6342,461,460,0,0,0,509,0,
  7500,322,68,320,340,60,8303,810,
  4050,524,10,0,0,0,4950,0,
  4050,524,11,200,0,0,8170,9600,
  1200,226,0,0,0,0,5700,0,
  6600,943,221,220,500,140,2762,8700,
  6600,221,527,220,500,0,2762,9900,
  4217,183,0,0,0,0,7650,0,
  1521,142,140,0,0,0,7800,0,
  4217,203,169,960,160,0,7403,8700,
  4217,203,228,0,0,0,150,0,
  4217,203,208,220,660,960,7558,8159,
  4217,203,188,200,660,980,7558,8159,
  4217,203,168,980,180,0,7403,8700,
  7650,401,400,420,0,0,462,8902,
  7650,421,0,0,0,0,463,9150,
  4050,527,0,0,0,0,15300,0,
  3450,586,0,0,0,0,150,0,
  6600,0,0,0,0,0,150,0,
  2117,183,0,0,0,0,1500,0,
  6807,0,0,0,0,0,15450,0,
  2723,521,480,520,260,0,8009,7800,
  6780,0,0,0,0,0,15450,0,
  6771,0,0,0,0,0,15450,0,
  7200,0,0,0,0,0,15600,0,
  207,224,560,0,0,0,8170,9600,
  7050,524,0,0,0,0,16605,16350,
  7050,224,0,0,0,0,16605,0,
  7050,384,0,0,0,0,16605,0,
  7050,464,0,0,0,0,16606,0,
  7050,264,0,0,0,0,16609,0,
  7050,344,0,0,0,0,16609,0,
  7050,304,0,0,0,0,16609,0,
  7050,424,0,0,0,0,16605,0,
  7050,164,0,0,0,0,16608,0,
  5570,281,322,340,320,0,8005,0,
  206,342,120,0,0,0,8156,10564,
  2117,201,200,180,0,0,8902,1500,
  2119,181,180,200,0,0,8902,1350,
  1551,62,0,0,0,0,1711,0,
  166,1042,480,0,0,0,8170,9600,
  1549,0,0,0,0,0,16611,0,
  2100,561,365,0,0,0,3600,0,
  7650,0,0,0,0,0,150,0,
  3450,581,347,340,0,0,8118,8464,
  7050,24,0,0,0,0,16605,0,
  3611,226,0,0,0,0,5700,0,
  7050,404,0,0,0,0,16616,15450,
  6774,0,0,0,0,0,9750,0,
  166,84,100,0,0,0,8170,9600,
  1542,462,460,0,0,0,7800,0,
  7050,0,0,0,0,0,150,0,
  1200,0,0,0,0,0,197,0,
  3600,0,0,0,0,0,16800,0
};

// NV$(59,1) commands
const char *NVS[2][NL] =
{
  "AUT","GO","*ENT","*RUN","*WAL","*CLI","JUM","BEA","CHO","*CUT",
  "TAK","*GET","*PIC","*CAT","LIG","*TUR","*LAM","*BUR","DRO","*REL",
  "*SPI","*LEA","STO","AWA","THR","TOS","QUI","SWI","RUB","LOO",
  "*SHO","*SEE","DRA","SCO","INV","SAV","WAK","UNL","REA","OPE",
  "ATT","*KIL","DRI","*GAT","BUN","FIN","*LOC","HEL","SAY","WIN",
  "DOO","SCR","*YEL","*HOL"," "," "," "," "," "," ",
  "ANY","NORTH","SOUTH","EAST","WEST","UP","DOWN","NET","FIS","AWA",
  "MIR","AXE","AXE","WAT","BOT","GAM","HOL","LAM","*ON","OFF",
  "DOO","MUD","*MED","BEE","SCO","GAS","FLI","EGG","OIL","*SLI",
  "KEY","HEL","BUN","INV","LED","THR","CRO","BRI","BEA","DRA",
  "RUG","RUB","HON","FRU","OX","RIN","CHI","*BIT","BRA","SIG",
  "BLA","WEB","*WRI","SWA","LAV","ARO","HAL","TRE","*STU","FIR"
};



// Room Locations
const Location RM[RL][6] =
{
  // Unassigned
  Unassigned,Unassigned,Unassigned,Unassigned,Unassigned,Unassigned,
  // Swamp
  Meadow,Unassigned,Unassigned,Grove,Tree,Unassigned,
  // Tree
  Unassigned,Unassigned,Unassigned,Unassigned,Unassigned,Swamp,
  // Stump
  Unassigned,Unassigned,Unassigned,Unassigned,Swamp,Root,
  // Root
  Unassigned,Unassigned,Unassigned,Unassigned,Stump,Hole,
  // Hole
  Unassigned,Unassigned,Unassigned,Unassigned,Root,Hall,
  // Hall
  Unassigned,Unassigned,Unassigned,Unassigned,Hole,Cavern,
  // Cavern
  EightRoom,Anteroom,Unassigned,PC,Hall,Maze,
  // EightRoom
  Unassigned,Cavern,Unassigned,Unassigned,Unassigned,Unassigned,
  // Anteroom
  Cavern,Unassigned,Unassigned,Unassigned,RoyalChamber,Unassigned,
  // Shore
  Bog,Swamp,Unassigned,Meadow,Unassigned,Unassigned,
  // Forest
  Forest,Forest,Meadow,Forest,Branch,Unassigned,
  // Maze
  Unassigned,Maze2,Maze4,Maze4,Unassigned,Unassigned,
  // Maze2
  Maze2,Unassigned,Unassigned,Unassigned,Maze3,Maze,
  // Maze3
  Unassigned,Maze6,Maze,Maze2,Maze5,Maze5,
  // Maze4
  Maze6,Maze,Unassigned,Maze2,Maze,Maze2,
  // Maze5
  Unassigned,Unassigned,Maze6,Unassigned,Unassigned,Maze3,
  // Maze6
  Maze6,Maze6,Maze,Maze,Maze4,Maze3,
  // Chasm
  Unassigned,Unassigned,Unassigned,Unassigned,Maze6,Unassigned,
  // Ledge
  Unassigned,Unassigned,Unassigned,Unassigned,RoyalChamber,Unassigned,
  // RoyalChamber
  Unassigned,Unassigned,Unassigned,Unassigned,Unassigned,Anteroom,
  // LedgeThrone
  Unassigned,Unassigned,Unassigned,Unassigned,Unassigned,Unassigned,
  // ThroneRoom
  Unassigned,Unassigned,Unassigned,LedgeThrone,Unassigned,Unassigned,
  // Meadow
  Unassigned,Swamp,Shore,Forest,Unassigned,Unassigned,
  // Trouble
  Unassigned,Unassigned,Unassigned,Unassigned,Unassigned,Unassigned,
  // Grove
  Forest,Unassigned,Swamp,Unassigned,Unassigned,Unassigned,
  // Bog
  Unassigned,Unassigned,Unassigned,Unassigned,Unassigned,Unassigned,
  // PC
  Unassigned,Unassigned,Cavern,Unassigned,Unassigned,Unassigned,
  // Branch
  Unassigned,Unassigned,Unassigned,Unassigned,Unassigned,Forest,
  // Empty1
  Unassigned,Unassigned,Unassigned,Unassigned,Unassigned,Unassigned,
  // Empty2
  Unassigned,Unassigned,Unassigned,Unassigned,Unassigned,Unassigned,
  // Empty3
  Unassigned,Unassigned,Unassigned,Unassigned,Unassigned,Unassigned,
  // Empty4
  Unassigned,Unassigned,Unassigned,Unassigned,Unassigned,Unassigned,
  // MistRoom
  Unassigned,Trouble,Forest,Trouble,Branch,Trouble,
};

// Room descriptions
const char *RSS[RL] = {
  " ",
  "dismal swamp.",
  "*I'm in the top of a tall cypress tree.",
  "large hollow damp stump in the swamp.",
  "root chamber under the stump.",
  "semi-dark hole by the root chamber.",
  "long down-sloping hall.",
  "large cavern.",
  "large 8-sided room.",
  "royal anteroom.",
  "*I'm on the shore of a lake.",
  "forest.",
  "maze of pits.",
  "maze of pits.",
  "maze of pits.",
  "maze of pits.",
  "maze of pits.",
  "maze of pits.",
  "bottom of a chasm.  Above 2 ledges.  One has a bricked up window.",
  "*I'm on a narrow ledge by a chasm.  Across the chasm is a throne room.",
  "royal chamber.",
  "*I'm on a narrow ledge by the throne room-across chasm-ledge.",
  "throne room.",
  "sunny meadow.",
  "*I think I'm in real trouble.  Here's a guy with a pitchfork!",
  "hidden grove.",
  "quick-sand bog.",
  "memory RAM of an IBM-PC.  I took a wrong turn!",
  "branch on the top of an old oak tree.\nTo the east I see a meadow beyond a lake.",
  " ",
  " ",
  " ",
  " ",
  "large misty room with strange letters over the exits."
};

Item items[IL] =
{
   Item(Unassigned, " "),
   Item(Root, "dark hole"),
   Item(Root, "*POT OF RUBIES*/RUB/"),
   Item(Tree, "spider web with writing on it."),
   Item(Unassigned, "Hollow stump and remains of a felled tree."),
   Item(Swamp, "cypress tree"),
   Item(Shore, "water"),
   Item(Swamp, "evil smelling mud/MUD/"),
   Item(Shore, "*GOLDEN FISH*/FIS/"),
   Item(Unassigned, "lit brass lamp/LAM/"),
   Item(Stump, "old fashioned brass lamp/LAM/"),
   Item(Shore, "rusty axe (magic word- BUNYON -on it)/AXE/"),
   Item(Stump, "bottle of water/BOT/"),
   Item(Unassigned, "empty bottle/BOT/"),
   Item(Tree, "ring of skeleton keys/KEY/"),
   Item(Stump, "sign- LEAVE TREASURE HERE - (say 'SCORE')"),
   Item(Hole, "locked door"),
   Item(Unassigned, "open door with a hallway beyond"),
   Item(Swamp, "swamp gas"),
   Item(Chasm, "*GOLDEN NET*/NET/"),
   Item(Unassigned, "chigger bites"),
   Item(Unassigned, "infected chigger bites"),
   Item(Swamp, "floating patch of oily slime"),
   Item(EightRoom, "*ROYAL HONEY*/HON/"),
   Item(EightRoom, "large african bees"),
   Item(LedgeThrone, "thin black bear"),
   Item(Unassigned, "bees in a bottle/BOT/"),
   Item(Meadow, "large sleeping dragon"),
   Item(Maze2, "flint and steel/FLI/"),
   Item(Maze6, "*THICK PERSIAN RUG*/RUG/"),
   Item(Chasm, 
     "sign- MAGIC WORD IS AWAY. LOOK LA -(rest of sign is missing)"),
   Item(Unassigned, "distended gas bladder/BLA/"),
   Item(RoyalChamber, "bricked up window"),
   Item(Meadow, 
      "sign here says- IN SOME CASES MUD IS GOOD, IN OTHERS..."),
   Item(Chasm, "stream of lava"),
   Item(Unassigned, 
     "bricked up window with a hole in it.  Beyond is a ledge."),
   Item(Unassigned, "loose fire bricks"),
   Item(ThroneRoom, "*GOLD CROWN*/CRO/"),
   Item(LedgeThrone, "*MAGIC MIRROR*"),
   Item(Unassigned, "sleeping bear"),
   Item(Anteroom, "empty wine bladder/BLA/"),
   Item(Unassigned, "broken glass"),
   Item(Swamp, "chiggers/CHI/"),
   Item(Unassigned, "dead bear"),
   Item(Unassigned, "*DRAGON EGGS* (very rare)/EGG/"),
   Item(Unassigned, "lava stream with a brick dam"),
   Item(Grove, "*JEWELED FRUIT*/FRU/"),
   Item(Bog, "*SMALL STATUE OF A BLUE OX*/OX/"),
   Item(Unassigned, "*DIAMOND RING*/RIN/"),
   Item(Unassigned, "*DIAMOND BRACELET*/BRA/"),
   Item(Maze3, 
     "strange scratchings on rock reveals- ALADDIN WAS HERE -"),
   Item(MistRoom, "sign says- LIMBO.  FIND RIGHT EXIT AND LIVE AGAIN!"),
   Item(Unassigned, "smoking hole.  Pieces of dragon and gore."),
   Item(Shore, "sign says- NO SWIMMING ALLOWED -"),
   Item(Maze6, "arrow pointing down"),
   Item(Unassigned, "dead fish/FIS/"),
   Item(Unassigned, "*FIRESTONE* (cold now)/FIR/"),
   Item(Grove, "sign says- PAUL'S PLACE -"),
   Item(Forest, "trees"),
   Item(Unassigned, " "),
   Item(Unassigned, " "),
};

// Messages
const char *MSS[ML] =
{
  " ",
  "Nothing happens",
  "CHOP IT DOWN!",
  "Boy that really hit the spot!",
  "Dragon smells something - awakens - attacks me!",
  "Lock shatters.",
  "I can't.  It's locked.",
  "TIMBER...  Something fell from the treetop and vanished!",
  "TIMBER...",
  "Lamp is off",
  "Flameless lamp is on.",
  "I'm bit by a spider.",
  "My chigger bites are now infected.",
  "The bites have rotted my whole body.",
  "The bear eats the honey and falls asleep.",
  "Bees sting me",
  "I've no container.",
  "The bees all suffocated.",
  "Something I'm holding vibrated and...",
  "Nothing to light it with.",
  "Gas bladder blew up.",
  "in my hands!",
  "Gas needs to be contained before it will burn.",
  "Gas dissipates.",
  "That won't ignite.",
  "How?  Jump?",
  "The bear won't let me.",
  "Don't waste *HONEY*.  Get mad instead.  Dam lava!",
  "Bees madden the bear.  Bear then attacks me!",
  "It soaks into the ground.",
  "In one word tell me what.",
  "Oh no...Bear dodges...CRASH!",
  "It's heavy!",
  "Something's too heavy.  I fall.",
  "To stop game say -QUIT-",
  "The mirror hits the floor and shatters into a million pieces.",
  "Mirror lands softly on the rug - lights up and says:",
  "You lost *ALL* treasures.",
  "Not carrying the axe.  TAKE INVENTORY!",
  "It doesn't bother him at all.",
  "The mud dried up and fell off.",
  "The bear got startled and fell off the ledge!",
  "*DRAGON STINGS* and fades.  I don't get it - hope you do.",
  "The bees attack the dragon which gets up and flies away...",
  "Magic oil attracts magic lamp.  Lamp is now full.",
  "I'm bit by chiggers.",
  "There's something there all right!  Maybe I should go there?",
  "Maybe if I threw something?...",
  "Too dry.  Fish die.",
  "A glowing genie appears - drops something - then vanishes.",
  "A genie appears - says 'boy you're selfish' - takes something - then vanishes!",
  "NO!  It's too hot.",
  "Not here.",
  "Try the swamp",
  "Use one word.",
  "Try:  LOOK,JUMP,SWIM,CLIMB,THROW,FIND,GO,TAKE,INVENTORY,SCORE.",
  "Only 3 things will wake the dragon.  One of them is dangerous!",
  "If you need a hint on something, try 'HELP'.",
  "Read the sign in the meadow!",
  "You may need magic words here.",
  "A voice booms out ...",
  "PLEASE LEAVE IT ALONE!",
  "Can only throw axe.",
  "Medicine is good for bites.",
  "I don't know where it is.",
  "Treasures have an * in their name.  Say 'SCORE'",
  "Blow it up.",
  "Fish escape back to the lake.",
  " ",
  " ",
  " ",
  " "
};

// print locations
std::string print(Location l)
{
   switch(l) {
   case Inventory :
      return "Inventory";
   case Unassigned :
      return "Unassigned";
   case Swamp :
      return "Swamp";
   case Tree :
      return "Tree";
   case Stump :
      return "Stump";
   case Root :
      return "Root";
   case Hole :
      return "Hole";
   case Hall :
      return "Hall";
   case Cavern :
      return "Cavern";
   case EightRoom :
      return "EightRoom";
   case Anteroom :
      return "Anteroom";
   case Shore :
      return "Shore";
   case Forest :
      return "Forest";
   case Maze :
      return "Maze";
   case Maze2 :
      return "Maze";
   case Maze3 :
      return "Maze";
   case Maze4 :
      return "Maze";
   case Maze5 :
      return "Maze";
   case Maze6 :
      return "Maze";
   case Chasm :
      return "Chasm";
   case Ledge :
      return "Ledge";
   case RoyalChamber :
      return "RoyalChamber";
   case LedgeThrone :
      return "LedgeThrone";
   case ThroneRoom :
      return "ThroneRoom";
   case Meadow :
      return "Meadow";
   case Trouble :
      return "Trouble";
   case Grove :
      return "Grove";
   case Bog :
      return "Bog";
   case PC :
      return "PC";
   case Branch :
      return "Branch";
   case Empty1 :
      return "Empty";
   case Empty2 :
      return "Empty";
   case Empty3 :
      return "Empty";
   case Empty4 :
      return "Empty";
   case MistRoom :
      return "MistRoom";
   default :
      return "";
   }
}
