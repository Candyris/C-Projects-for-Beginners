#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define FILE_PATH Book_libray.info

typedef unsigned int UINT;
typedef std::string STR;


class Book{
public:
    UINT bookID;
    STR title;
    STR author;
    STR genre;
    UINT quantity;
};

class BookShop{
public:
    // constructor and destructor functions
    BookShop();
    ~BookShop();

    //Book operation function
    void addBook();
    void modifyBook();

    // Loading and Saving file from memory
    void loadDataFromFile();
    void saveDataToFile();
    
    // printing data
    void displayBOOKs();
private:
    std::vector<Book> books;
};


int main()
{

    return 0;
}
