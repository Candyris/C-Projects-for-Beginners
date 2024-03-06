#include <iostream>
#include <fstream>
#include <vector>
#include <string>


#define FILE_PATH "Book_libray.info"

typedef unsigned int UINT;
typedef std::string STR;

void clearScreen();
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
  //  BookShop();
   // ~BookShop();

    //Book operation function
    void addBook();
    void modifyBook();

    // Loading  file From memory
    void loadDataFromFile();

    
    // printing data
  //  void displayBOOKs();
private:
    std::vector<Book> books;
    //Saving file to memory
    void saveDataToFile();
};
void clearScreen()
{
#if _WIN32
    system("cls");
#elif __linux__
    system("clear");
#endif
}

void BookShop::saveDataToFile()
{
    std::ofstream FILE(FILE_PATH, std::ios::binary);
    if (FILE.is_open())
    {
        for (Book &book : books)
        {
            FILE << book.bookID << " " << book.title << " "
                 << book.author << " " << book.genre << " "
                 << book.quantity;
            FILE << std::endl;
        }
    }
    else
    {
        std::cout << "FILE is not haev problem !";
    }
}
void BookShop::loadDataFromFile(){
   // std::ifstream FILE(FILE_PATH , std::ios::in){
        
   // }
}


    void BookShop::addBook()
    {

        clearScreen();
        class Book book;
        std::cout << "Enter the BookID : ";
        std::cin >> book.bookID;
        std::cin.ignore();
        std::cout << "Enter the Title : ";
        getline(std::cin, book.title);
        std::cout << "Enter the Author : ";
        getline(std::cin, book.author);
        std::cout << "Enter the Genre: ";
        getline(std::cin, book.genre);
        std::cout << "Enter the Quantity : ";
        std::cin >> book.quantity;

        books.push_back(book);
        saveDataToFile();

        std::cout << "Successful to add this book" << std::endl;
    }

    void BookShop::modifyBook()
    {
        int BookID;
        std::cout << "Enter the BookID : ";
        std::cin >> BookID;
        for (Book &book : books)
        {
            if (book.bookID == BookID)
            {
                class Book book;
                std::cout << "Enter the new BookID : ";
                std::cin >> book.bookID;
                std::cin.ignore();
                std::cout << "Enter the new Title : ";
                getline(std::cin, book.title);
                std::cout << "Enter the new Author : ";
                getline(std::cin, book.author);
                std::cout << "Enter the new Genre: ";
                getline(std::cin, book.genre);
                std::cout << "Enter the new Quantity : ";
                std::cin >> book.quantity;
                return;
            }
        }
        std::cout << " BookID [" << BookID << "] is not found !!" << std::endl;
    }
int main(){

    BookShop books;
    books.addBook();
    return 0;
}
