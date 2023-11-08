#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class BookShop //a class showing details of bookshop inventory system
{
public: //methods to perform operations 
    void control_panel(); //main menu 
    void add_book(); //adding a book
    void display_book(); //displaying all details of books user entered 
    void check_book(); //checking an individual book 
    void update_book(); //updating any book using its id
    void delete_book(); //deleting a book 
};

void BookShop::control_panel() //main menu to perform any task 
{
    system("cls");
    cout << "Welcome to Book Shop!" << endl;
    cout << endl;
    cout << "\t 1. Add Book" << endl;
    cout << "\t 2. Display Book" << endl;
    cout << "\t 3. Check Individual Book" << endl;
    cout << "\t 4. Update Book" << endl;
    cout << "\t 5. Delete Book" << endl;
    cout << "\t 6. Exit" << endl;
}

void BookShop::add_book() //adding details of a book 
{
    system("cls");
    //variables used for adding a book 
    fstream f1;
    int no_of_copy;
    string book_name, author_name, book_id;
    cout << "\t Add Book" << endl;
    cout << "Enter Book ID: ";
    cin >> book_id;
    cout << "Enter Book Name: ";
    cin >> book_name;
    cout << "Enter Author Name: ";
    cin >> author_name;
    cout << "Enter No. of Copy: ";
    cin >> no_of_copy;

    f1.open("Book.txt", ios::out | ios::app); //writing & appending details in a file 
    f1 << book_id << " " << book_name << " " << author_name << " " << no_of_copy << endl; //write into the file 
    f1.close(); 
}

void BookShop::display_book() //list to show all books in this system
{
    system("cls");
    //variables used for displaying all information of all books 
    fstream f2;
    int no_of_copy;
    string book_id, book_name, author_name;
    cout << "\t All Books" << endl;

    f2.open("Book.txt", ios::in);
    if (!f2)
    {
        cout << "File not found" << endl; //check whether file is present or not 
        return;
    }
    else
    {
        cout << "\t Book ID \t Book Name \t Author Name \t No. of Copy" << endl; //read from the file 
        f2 >> book_id >> book_name >> author_name >> no_of_copy;

        while (!f2.eof()) //get the data from file until it reaches its end 
        {
            cout << "\t" << book_id << "\t" << book_name << "\t" << author_name << "\t" << no_of_copy << endl;
            f2 >> book_id >> book_name >> author_name >> no_of_copy; //read data from file 
        }
        system("pause");
        f2.close();
    }
}

void BookShop::check_book() //check an individual book based on its id
{
    system("cls");
    fstream file;
    int no_of_copy, count = 0; //count is a boolean flag to check if id of book entered by user matches with id present already into file 

    string book_id, book_name, author_name; //local variables 
    cout << "\t Check Book" << endl;

    file.open("Book.txt", ios::in);
    if (!file)
    {
        cout << "File Not Found!" << endl; //if file doesn't exist 
        return;
    }
    else
    {
        cout << "Enter Book ID: ";
        cin >> book_id;
        file >> book_id >> book_name >> author_name >> no_of_copy; //read data from file 

        while (!file.eof())
        {
            if (book_id == book_id) //check till end of file & both id's match then display book details and increase counter to return true 
            {
                cout << "Book ID: " << book_id << endl;
                cout << "Book Name: " << book_name << endl;
                cout << "Author Name: " << author_name << endl;
                cout << "No. of Copy: " << no_of_copy << endl;
                count++;
                break;
            }
            file >> book_id >> book_name >> author_name >> no_of_copy; 
        }
        if (count == 0) //if counter remains 0 only then no book is available into the file 
        {
            cout << "Book not found" << endl;
        }
    }
}

void BookShop::update_book() //update book based on its id provided by user 
{
    system("cls");
    //variables for updating a book 
    fstream file, file1;
    int no_of_copy, count = 0;
    //local variables 
    string book_id, book_name, author_name;
    string book_id1, book_name1, author_name1;

    cout << "\t Update Book" << endl;
    file1.open("Book1.txt", ios::app | ios::out); //writing & appending new information into temporary file 
    file.open("Book.txt", ios::in); //original file

    if (!file)
    {
        cout << "File not found" << endl; //file doesn't exist before 
        return;
    }
    else
    {
        cout << "Enter Book ID: ";
        cin >> book_id;
        file >> book_id >> book_name >> author_name >> no_of_copy; //read data from file after entering its id 

        while (!file.eof())
        {
            if (book_id == book_id) //both id i.e. entered one & already present in file then update book details 
            {
                system("cls");
                cout << "Update Book" << endl;
                cout << "Enter New Book Name: ";
                cin >> book_name;
                cout << "Enter New Author Name: ";
                cin >> author_name;
                cout << "Enter New No. of Copy: ";
                cin >> no_of_copy;

                file1 << book_id << " " << book_name << " " << author_name << " " << no_of_copy << endl; //write data into temporary file 
                count++; //increase count by 1 
            }
            else
            {
                file1 << book_id << " " << book_name << " " << author_name << " " << no_of_copy << endl; //write data into temporary file
                file >> book_id >> book_name >> author_name >> no_of_copy; //read data from original file 
            }
        }
        if (count == 0) //if count remains 0 then no such book with that id is present into file 
        {
            cout << "Book not found...." << endl;
        }
        cout << endl;
        system("pause");
        file.close();
        file1.close();

        remove("Book.txt"); //remove original 
        rename("Book1.txt", "Book.txt"); //rename temporary into original one 
    }
}

void BookShop::delete_book() //delete a book through its id 
{
    system("cls");
    //variables for deleting a book record 
    fstream f, f1;
    int no_of_copy, count = 0;
    //local variables 
    string book_id, book_name, author_name;

    cout << "\t Delete Book" << endl;
    f1.open("Book1.txt", ios::app | ios::out); //temporary file 
    f.open("Book.txt", ios::in); //original file 

    if (!f)
    {
        cout << "File not found" << endl;  //if there is no such file 
        return;
    }
    else
    {
        cout << "Enter Book ID: ";
        cin >> book_id;
        f >> book_id >> book_name >> author_name >> no_of_copy; //read data from original file 

        while (!f.eof())
        {
            if (book_id == book_id) //check till end & its id's match then print a message for successful deletion & increment the count by 1
            {
                system("cls");
                cout << "Deleted Book Successfully!!!" << endl;
                count++;
            }
            else
            {
                f1 << book_id << " " << book_name << " " << author_name << " " << no_of_copy << endl; // write data to file
            }
        }
        if (count == 0) //if count is 0 then no file is available 
        {
            cout << "Book not found...." << endl;
        }
    }
    system("pause");
    f.close();
    f1.close();

    remove("Book.txt"); //remove original 
    rename("Book1.txt", "Book.txt"); //rename temporary into original 
}

void BookShopRecord()
{
    int option; //selecting any option from the menu 
    char x;
    BookShop bookshop; //class bookshop object 

    while (1) //until user ends 
    {
        bookshop.control_panel(); //display menu 
        cout << "\t Enter your choice: ";
        cin >> option;

        switch (option)
        {
        case 1:
            do
            {
                bookshop.add_book(); // add the book until user wish
                cout << "Do you want to add more book? (y/n): ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            break;
        case 2:
            bookshop.display_book(); //display all books in this system 
            break;
        case 3:
            bookshop.check_book(); //check an individual book from its id 
            break;
        case 4:
            bookshop.update_book(); //update an existing book with its id 
            break;
        case 5:
            bookshop.delete_book(); //delete a specific book 
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Invalid option!" << endl;
        }
    }
}

int main()
{
    BookShopRecord(); //call the main menu function 
    return 0;
}