class Item {
public :
    Item (std::string);
    
    std::string getItem() { return item;}
    void printItem();

    ~Item();
private :
    std::string item;
};
