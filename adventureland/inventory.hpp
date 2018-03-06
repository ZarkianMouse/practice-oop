class Inventory {
public :
   Inventory();
   ~Inventory();
   
   void addItem(Item);
   void removeItem();
private :
   std::vector<Item> inven;    

};
