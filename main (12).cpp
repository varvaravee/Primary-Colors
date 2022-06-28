/* Varvara Vorobieva
* Chapter 18 Assignment
*CISC 187
* 4/7/2022
*/
 
#include <iostream>
#include <iomanip>
#include <string>
#include "PrimaryColors.h"
using namespace std;


//Function prototypes
void displayMenu(PrimaryColors &, bool &);
void appendColor(PrimaryColors &);
void insertColor(PrimaryColors &);
void deleteColor(PrimaryColors &);
void reverseColors(PrimaryColors &);
void displayColors(PrimaryColors &, bool);
void searchColor(PrimaryColors &);
void changeMono(bool &);
void displayQuit();

int main()
{
    //Declare PrimaryColors obj and boolean for monochhrom control
    PrimaryColors primCo;
    bool monochrome=false;
    
    //Call menu function, passing PrimaryColors object and boolean
    displayMenu(primCo, monochrome);
    
    //End program
    return 0;
}


/*
 * name: displayMenu
 * called by: main
 * passed: PrimaryColors &pC, bool &mono
 * returns: nothing
 * calls:appendColor, countVowels, displayArray, countChar, displayQuit;
 */
 
 void displayMenu(PrimaryColors &pC, bool &mono)
 {
     //Initialize user choice integer and the row input string
     int choice=0;
     string input;
     
     //While loop displays menu until user enters number 8 
     while(choice!=8)
     {
         //Display menu options
         cout<<"1. Append a Color\n";
         cout<<"2. Insert a Color\n";
         cout<<"3. Delete a Color\n";
         cout<<"4. Print the Colors\n";
         cout<<"5. Reverse the Colors\n";
         cout<<"6. Search for a Color\n";
         cout<<"7. Activate/Deactivate Monochrome Display\n";
         cout<<"8. Exit\n";
         cout<<"Please choose a menu option: ";
         
         //Get user's menu choice
         cin.ignore();
         getline(cin, input);
         choice=stoi(input);
         
         switch (choice)
         {
             case 1:
                //Run the Append Color function
                appendColor(pC);
                break;
             case 2:
                //Run Insert Color function
                insertColor(pC);
                break;
             case 3:
                //Run Delete Color function
                deleteColor(pC);
                break;
             case 4:
                //Run Display Colors function
                displayColors(pC,mono);
                break;
             case 5:
                //Run Reverse colors function
                reverseColors(pC);
                break;
             case 6:
                //Run the Search Color function
                searchColor(pC);
                break;
             case 7:
                //Run the Change Monochrome function
                changeMono(mono);
                break;
             case 8:
                //Run the Display Quit function
                displayQuit();
                break;
            default:
                //Display an error message if an invalid number is entered
                cout<<"Error, that number is not on the menu.\n";
                cout<<"Please enter a valid number (1-7 or 8 to quit)./n/n";
                break;
                
             
         }
     }
 }
 
 /*
 *Name: appendColor
 *called by: displayMenu
 *passed:PrimaryColors &pC 
 *returns: nothing
 *calls: nothing
 */
 
 void appendColor(PrimaryColors &pC)
 {
     //Prompt user for color of their new node
     string input;
     cout<<"Enter the colors of the new node (in lowercase):";
     getline(cin, input);
     
     //If input is not primary color, prompt user for another input
     while((input !="red")&&(input != "yellow")&& (input != "blue"))
     {
         cout << "Error: " << input << " is not a primary color.\n";
         cout << "Please enter a different color to append (in lowercase): ";
         getline(cin, input);
         
     }
    
    //Append the new node to the list by calling the member function
    pC.appendNode(input);
    
    //Tell user that their new node has been successfully appended
    cout<<"A " << input << " node has been appended to your list.\n\n";
 }
 
 /*
 *name: insertColor
 *called by: displayMenu
 *passed: PrimaryColors &pC
 *returns: nothing
 *calls: nothing
 */
 
 void insertColor(PrimaryColors &pC)
 {
     //Prompt the user for the color of their new node 
     string input;
     cout <<"Enter the color of the new node (in lowercase): ";
     getline(cin, input);
     
     //If the input is not a primary color, prompt the user for another input
     while((input!="red") && (input!="yellow") && (input!= "blue"))
     {
         cout<<"Error: " << input << " is not a primary color.\n";
         cout<<"Please enter a different color to add (in lowercase): ";
         getline(cin, input);
         
     }
     
     //Prompt the user for the position of hteir new node
     string place;
     cout<< "Enter the position of the new node: ";
     getline(cin, place);
     int pos= stoi(place);
     
     //Attempt to add the specified node by calling member function
     int done=pC.insertNode(input, pos);
     if (done==-1)
     {
         //If the node could not be inserted, tell the user
         cout <<"Sorry, but a node could not be added at position (" <<pos<<").\n\n";
     }
     else
     {
         //Otherwise tell the user that the node was successfully added
         cout<<"A "<< input << "node has been added at position ("<<pos<< ").\n\n";
         
     }
 }
 
 /*
 *name:deleteColor
 *called by: displayMenu
 *passed: PrimaryColors &pC
 *returns: nothing
 *calls:nothing
 */
 
 void deleteColor(PrimaryColors &pC)
 {
     //Prompt user to enter position to delete
     string input;
     cout<<"Enter the node position you want to delete: ";
     getline(cin, input);
     int pos=stoi(input);
     
     //Attempt to delete the specified position by calling the member function 
     int done=pC.deleteNode(pos);
     
     if (done==-1)
     {
         //If the node could not be deleted, tell the user
         cout << "Sorry, but there is no node at position ("<<pos<<").\n\n";
         
     }
     else
     {
         //Otherwise tell the user that the node was successfully removed
         cout<<"Node ("<< pos << ") has been deleted from your list.\n\n";
         
     }
 }
 
 /*
 *name:reverseColors
 *called by:displayMenu
 *passed: PrimaryColors &pC
 *returns: nothing
 *calls:nothing
 */
 
 void reverseColors(PrimaryColors &pC)
 {
     //Call the member function to reverse the order of the list
     pC.reverseList();
     cout<<endl;
     
 }
 
 /*
 *name: displayColors
 *called by: displayMenu
 *passed: PrimaryColors &pC, bool mono
 *returns: nothing
 *calls: nothing
 */
 
 void displayColors(PrimaryColors &pC, bool mono)
 {
     //Call the member function to display the colors in the color or Monochrome
     pC.displayList(mono);
     cout<<endl;
     
 }
 
 /*
 *name:searchColor
 *called by: displayMenu
 *passed: PrimaryColors &pC
 *returns: nothing
 *calls: nothing
 */
 
 void searchColor(PrimaryColors &pC)
 {
     //Prompt user to search for color
     string input;
     cout<<"Please enter a color to search for (in lowercase):";
     getline(cin, input);
     
     //If input is not primary color, prompt user for another input
     while((input!="red")&&(input!="yellow")&& (input!="blue"))
     {
         cout<<"Error: "<<input<< " is not a primary color.\n";
         cout<<"Please enter a different color to search for (in lowercase): ";
         getline(cin, input);
     }
     
     //Search for the color's first instance using the member function
     int pos=pC.searchList(input);
     
     if(pos==-1)
     {
         //If the color is not found, tell this to the user.
         cout<<"A "<<input<< " node is not present in your list.\n\n";
         
     }
     else
     {
         //Otherwise display the position to the user
         cout<< "The first "<< input << " node is at position (" << pos<< ").\n\n";
         
     }
 }
 
 /*
 *name:changeMono
 *called by: displayMenu
 *passed: bool &mono
 *returns: nothing
 *calls: nothing
 */
 
 void changeMono(bool &mono)
 {
     //Change boolean value to opposite value and display message
     if (mono)
     {
         mono=false;
         cout<<"Your list will now be displayed in color.\n\n";
     }
     else
     {
         mono=true;
         cout<<"Your list will now be displayed in monochrome.\n";
         cout<<"(NOTE: All other operations still requite/specify colors.)\n\n";
         
     }
    }
    
    /*
    *name: displayQuit
    *called by: displayMenu
    *passed: nothing
    *returns: nothing
    *calls: nothing
    */
    
    void displayQuit()
    {
        //Display the quitting message
        cout<<"Goodby, and thanks for using the Primary List Color Program.\n";
    }
 

 