#include<bits/stdc++.h>
using namespace std;

class Book
{
    private:  //access modifier to keep the data members private 
    //Here data members writen are pointer  
    char *bookauthor,*booktitle,*publisher;
    float *price;
    int *stockvalue;


    public : //Access modifier used,this section is public to all

    Book() //constructor is used for allocation of data using new keyword

    {
      bookauthor= new char[50]; //author is the pointer variable to which the memory address is returned
      //Similarly Memory allocated and address is returned to the respective pointer_variables

      booktitle = new char[50];
	  publisher = new char[20];
	  price = new float;
	  stockvalue = new int; 
    
    }  
//function declaration.........

    void Entrydata(); //Function used for Feeding the data 
    void bookdataedit(); //Function used for Editing the data for a book
    void showbookdata(); //Function used for showing the data to the user

    int booksearch(char[],char[]); //Function used for searching for a book ,
    //arguments have been passed as title and author details will be required
     
     void bookbuy();//Function used to buy the book


};

void Book::Entrydata() //This is Scope resolution operator (::) used to  define a function outside a class

{
  cin.ignore();

  cout<<"\nPlease Enter The Author Name :";
  cin.getline(bookauthor,50); //geline is used when we want to give space separated input

  cout<<"\nPlease Enter The Title of The book :";
  cin.getline(booktitle,50);

  cout<<"\nPlease Enter The Publisher Name: ";   
  cin.getline(publisher,50);
  cout<<"\n";

  cout<<"Enter Price: ";           
  cin>>*price;
  cout<<"\n";

  cout<<"Enter Stock Position: ";   
  cin>>*stockvalue;
  cout<<"\n";
  
  cout<<"Your Entry has been saved"<<endl;
  cout<<"\n";


}


void Book::bookdataedit()	
{
	cout<<"\nPlease Enter The Author Name :";
    cin.getline(bookauthor,50); 

    cout<<"\nPlease Enter The Title of The book :";
    cin.getline(booktitle,50);

    cout<<"Please Enter The Publisher Name: ";   
    cin.getline(publisher,50);

    cout<<"Enter Price: ";           
    cin>>*price;

    cout<<"Enter Stock Position: ";   
    cin>>*stockvalue; 
    cout<<"\n";

	
}
  
  void Book::showbookdata()
  {
      cout<<"\nThe Author Name is : "<<bookauthor;
      cout<<"\nThe Title of The Book is : "<<booktitle;
      cout<<"\nThe Publisher Name is : "<<publisher;
      cout<<"\nThe Price is :"<<*price;
      cout<<"\nStock Position :"<<*stockvalue<<endl;

  }


  int Book::booksearch(char tbuy[50],char abuy[50] )
  {  
      //Use of strcmp which compares the two strings lexicographically means it 
    //starts comparison character by character starting from the first character until the characters 
    //in both strings are equal or a NULL character is encountered.
      
      
      if(strcmp(tbuy,booktitle)==0 && strcmp(abuy,bookauthor)==0)
		return 1;
	  else 
        return 0;
        cout<<"\n";
  }

  
void Book::bookbuy()	{
	int count;
	cout<<"\nPlease Enter The Number Of Books to buy: ";
	cin>>count;
	cout<<"\n";
	


	if(count<=*stockvalue)	{
		*stockvalue=*stockvalue-count;  //This will maintain current stock record
	    
	
		cout<<"\n Amount Price to pay is : Rs. "<<(*price)*count<<endl;
		cout<<"\n";
	
		
		
	}
	else
	    cout<<"\nThe Required Copies are not in Stock"<<endl;
}



//Main Function.......

int main()
{    
    Book *Data[50];
	int d=0,s;
	char titlebuy[50],authorbuy[50];
	

    int choice; // this for choice selection in the Menu
    cout<<"*********Welcome to the Book Inventory System ********"<<endl;
    cout<<"\n";
    cout<<"\n";

    /*Starting of the Menu for the user .......*/
    
    while(1)
    {

    cout<<"....Here is the Menu ...."
       //The salesman can access this menu to go forward to do the following options told in the list
  
	    <<"\n1.Press 1 for the Entry of a New Book"
		<<"\n2.Press 2 for  Buying a Book"
		<<"\n3.Press 3 for  Searching a Book"
		<<"\n4.Press 4 for  Editing the Details Of  a Book"
		<<"\n5.Press 5 If You Wish to Exit"
		<<"\n\nPlease Enter your Choice: ";
		cin>>choice;

        /* Use of the Switch Case to represent the options specifically in Menu ...*/

        switch(choice)
    
     {  //****code for the entry of data memory allocated using new keyword and Entrydata() function is used to enter the data for new book****"
     
         case  1:
         Data[d]=new Book;
         Data[d]->Entrydata();  //This is Arrow operator used to access the members of the using pointers.
         
         d++;
         break;

        //**** Now this case is for Buying a book ,where booksearch() function is used to check for the stock of the book to buy****"

         case 2:
         cin.ignore(); //used here to clear characters from the input buffer
          
         cout<<"\nPlease Enter the Title of The Book :";
         cin.getline(titlebuy,50);
         cout<<"\n";
         cout<<"Please Enter the Author for the Respective Book:";
         cin.getline(authorbuy,50);
         cout<<"\n";
         
         for(s=0;s<d;s++)
         
         {
              
             if(Data[s]->booksearch(titlebuy,authorbuy))
             { 
                
                 
                 Data[s]->bookbuy();
                 cout<<"See the details about respective book...please wait..."<<endl;
                 
                 break;
             }
         }
        

         if(s==1)
         {
             cout<<"\nSorry,This Book is out of Stock you can look for other book if you want"<<endl;
             cout<<"\n";
             break;
         }

        //****This case will also be using the booksearch() function to search for a specific book****

         case 3:
         cin.ignore();
         cout<<"\nPlease Enter the Title of The Book You are Searching for:";
         cin.getline(titlebuy,50);
         cout<<"\n";
         cout<<"Please Enter The Author for The Respective Tile:";
         cin.getline(authorbuy,50);
         cout<<"\n";

         for(s=0;s<d;s++)
         {
             if(Data[s]->booksearch(titlebuy,authorbuy))
             {
                 cout<<"\nYour Book Search is Successfull"<<endl;

                 cout<<"Here is What we have for you"<<endl;
                 Data[s]->showbookdata();
                 break;
             }
         }

         if(s==d)
         cout<<"\nSorry Your Searched Book is Out of Stock";
         cout<<"\n";
         break;


         case 4:
         cin.ignore();
          cout<<"\nPlease Enter the Title of The Book You are Searching for:";
         cin.getline(titlebuy,50);
         cout<<"\n";
         cout<<"Please Enter The Author for The Respective Tile:";
         cin.getline(authorbuy,50);
         cout<<"\n";

         for(s=0;s<d;s++)
         {
             if(Data[s]->booksearch(titlebuy,authorbuy))
             {
                 cout<<"\nYour Book Search is Successfull";
                 cout<<"\n";
                 cout<<"Now You Can Edit the Book Data";
                 cout<<"\n";

                 Data[s]->bookdataedit();
                 break;
             }

         }

         if(s==d)
         cout<<"\nSorry You Cannot Edit the Data as Book is out of stock";
         cout<<"\n";
         break;

         case 5:
         cout<<"This is the end of Book Inventory System"<<endl;
         exit(0); //This is exit statement it represents the exit status  ,the integer zero indicates exit success i.e; successful termination of the program 

         default:
         cout<<"\nLooks Like Your Choice doesnt matches our case"<<endl;
         
         cout<<"Invalid Choice Please Enter a Valid Number"<<endl;
         cout<<"\n";

     }
}

return 0;
}