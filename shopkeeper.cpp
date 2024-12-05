#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

class shopdetails {
   public:
      string title;
      string author;
      string publisher;
      int stock;
      int cost;

      // Constructor
      shopdetails() {
         // No dynamic allocation is needed here
      }

      // Function to accept details of a book
      void accept() {
         cout << "\nEnter the name of book author:\t";
         cin.ignore(); // Ignore newline characters before taking string input
         getline(cin, author);

         cout << "\nEnter the title of book:\t";
         getline(cin, title);

         cout << "\nEnter the cost of the book:\t";
         cin >> cost;

         cout << "\nEnter the name of publisher:\t";
         cin.ignore(); // Ignore newline characters before taking string input
         getline(cin, publisher);

         cout << "\nEnter the stock:\t";
         cin >> stock;
      }

      // Function to display book details
      void display() {
         cout << setw(20) << left << author
              << setw(20) << left << title
              << setw(20) << left << publisher
              << setw(10) << right << cost
              << setw(10) << right << stock << endl;
      }

      // Static function to search and update stock
      static void search(int n, shopdetails obj[]) {
         int flag = 0, s_stock; 
         string s_title, s_author;
         
         cout << "\nEnter the title of the book:\t";
         cin.ignore();
         getline(cin, s_title);
         
         cout << "\nEnter the author of the book:\t";
         getline(cin, s_author);

         for (int i = 0; i < n; i++) {
            if (obj[i].title == s_title && obj[i].author == s_author) {
               cout << setw(20) << left << "Author"
                    << setw(20) << left << "Title"
                    << setw(20) << left << "Publisher"
                    << setw(10) << right << "Cost"
                    << setw(10) << right << "Stock" << endl;
               cout << setfill('-') << setw(80) << "" << setfill(' ') << endl;
               
               obj[i].display();

               cout << "\nEnter the quantity of books you want to buy:\t";
               cin >> s_stock;

               if (obj[i].stock >= s_stock) {
                  cout << "\nBooks are available for price: " << s_stock * obj[i].cost << ".\n";
                  obj[i].stock -= s_stock;
               } else {
                  cout << "\nInsufficient stock. Available stock is: " << obj[i].stock;
               }

               flag = 1;
               break;
            }
         }

         if (flag == 0) {
            cout << "\nBook is not available.";
         }
      }
};

int main() {
   shopdetails obj[10];
   int i, n = 0, n1, choice;

   do {
      cout << "\n1. Store Data";
      cout << "\n2. Display Data";
      cout << "\n3. Search";
      cout << "\n4. Exit";
      cout << "\nEnter your choice from above:\t";
      cin >> choice;

      switch (choice) {
         case 1:
            cout << "Enter the number of books you want to enter:\t";
            cin >> n1;
            for (i = n; i < n + n1; i++) {
               cout << "\nBook " << i + 1 << ":\n";
               obj[i].accept();
            }
            n += n1;
            break;

         case 2:
            cout << setw(20) << left << "Author"
                 << setw(20) << left << "Title"
                 << setw(20) << left << "Publisher"
                 << setw(10) << right << "Cost"
                 << setw(10) << right << "Stock" << endl;
            cout << setfill('-') << setw(80) << "" << setfill(' ') << endl;
            for (i = 0; i < n; i++) {
               obj[i].display();
            }
            break;

         case 3:
            shopdetails::search(n, obj);
            break;

         case 4:
            cout << "\nExiting...";
            break;

         default:
            cout << "\nInvalid choice";
      }
   } while (choice != 4);

   return 0;
}
