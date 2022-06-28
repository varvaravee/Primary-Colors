//Specification file for PrimaryColors class
#ifndef PRIMARYCOLORS_H
#define PRIMARYCOLORS_H
#include <string>
using namespace std;

class PrimaryColors 
{
    private:
        //The structure for the linked list 
        struct singleNode;  //Holds value and pointer to next node
        singleNode *headPtr;  //The head pointer
    
    public:
        PrimaryColors();   //Constructor
        ~PrimaryColors();  //Destructor
        void appendNode(string);  //Add node at end of list 
        int insertNode(string, int); //Add node anywhere in the list
        int deleteNode(int);  //Delete any node in the list
        void reverseList();  //Reverse the order of the list nodes
        void displayList(bool) const;  //Display the colors
        int searchList(string); //Search for the first node of a color 
        
    
    
};

#endif