//Implementation file for PrimaryColors class
#include "PrimaryColors.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//The constructor initializes the head pointer to be nullptr

PrimaryColors::PrimaryColors()
{
    headPtr=nullptr;   //Set the head to null automatically
}

//The singleNode struct holds the value and a pointer to the next singleNode

struct PrimaryColors::singleNode
{
    string color;  //The color of the node
    struct singleNode *nextPtr;  //The pointer to the next node
};

//The destructor destroys all of hte nodes and confirms this with a message

PrimaryColors::~PrimaryColors()
{
    //If there are no nodes, nothing needs to be done
    if (!headPtr)
    {
        cout<<"There are no nodes to delete.\n";
    }
    else
    {
        //Create a temporary node and set it to the first node
        singleNode *tempNode;
        tempNode = headPtr
        //Make a designating node for deletion
        singleNode *delThis;
        
        //While there is another node, load the next one and delete current one
        while (tempNode->nextPtr)
        {
            delThis=tempNode;
            tempNode=tempNode->nextPtr;
            delete delThis;
        
        //Delete current (last) node and notify the user
        delete tempNode;
        cout<<"All of your nodes have been deleted.\n";
        
    }
}

void PrimaryColors::appendNode(string col)
{
    //Limit the input to the three primary colors 
    if ((col=="red")||(col=="blue")||(col=="yellow"))
    {
        //Create a node to hold the user input and set its next to null
        singleNode *entryNode;
        entryNode = new singleNode;
        entryNode->color=col;
        entryNode->nextPtr = nullptr;
        
        //If the head pointer is null, make the user input the first node
        if(!headPtr)
        {
            headPtr=entryNode;
        }
        else 
        {
            //Otherwise, create a temporary node and set it to the first node
            singleNode *tempNode;
            tempNode=headPtr;
            
            //While there is another node, load it into the temporary node
            while(tempNode->nextPtr)
               { tempNode=tempNode->nextPtr;}
            
            //When the last node is reached, make the next one the user input
            tempNode->nextPtr=entryNode;
        }
    }
    //If the input is invalid, invoke an exit failure (low-level validation)
    else
    {
        cout<<"An invalid color was entered.\n";
        exit(EXIT_FAILURE);
    }
}

//insertNode adds a user-mase node to a user-sepcified spot in the linked list 

int PrimaryColors::insertNode(string col, int index)
{
    //Limit the input to the three primary colors
    if ((col=="red")||(col=="blue")||(col=="yellow"))
    {
        //Create a node to hold the user input
        singleNode *entryNode;
        entryNode = new singleNode;
        entryNode-> color=col;
        
        //If the user wants to put it at the beginning, do one of two things
        if (index==0)
        {
            //If there are no nodes, make the user input's next pointer null
            if (!headPtr)
            {entryNode->nextPtr=nullptr;}
            
            //If node(s) exist, make the user input's next pointer the 1st node
            else
            {
                entryNode->nextPtr=headPtr;
                
            }
            //Make the head node the user entry
            headPtr=entryNode;
            return 0;
        }
        else
        {
            //Disallow the user add a node at higher than 0 to an empty list
            //or add a value at a negative node value
            if ((!headPtr)|| (index<0))
            {
                return -1;
            }
            else 
            {
                //Create a temporary node and assign it to the first node
                singleNode *tempNode;
                tempNode=headPtr;
                int i=1;
                //While there is another node and the desired spot has not yet been reached
                //load the next node and increment the counter
                while ((tempNode->nextPtr)&&(i<index))
                {
                    tempNode=tempNode->nextPtr;
                    ++i;
                }
                //If desired spot has not been reached and there are no more nodes,
                //the insertion is impossible
                if (i<index)
                {
                    return -1;
                }
                //Otherwise, make the user entry point to the node it should precede,
                //then make the node preceding it point to it
                else
                {
                    entryNode->nextPtr=tempNode->nextPtr;
                    tempNode->nextPtr=entryNode;
                    return 0;
                }
            }
        }
    }
    //If the input if invalid, invoke an exit failure (low-level validation)
    else
    {
        cout <<"An invalid color was entered.\n";
        exit(EXIT_FAILURE);
    }
}

//deleteNode deletes a user-specified node in the linked list

int PrimaryColors::deleteNode(int index)
{
    //If there are no nodes to delete or if the user enters a negative value, return failure flag
    if ((!headPtr)||(index<0))
    {
        return -1;
    }
    
    //Create a node to hold what will be deleted
    singleNode *delThis;
    
    //If the first node is to be deleted, make the head point to the second, 
    //Then delete the first
    if (index ==0)
    {
        delThis = headPtr;
        headPtr=headPtr->nextPtr;
        delete delThis;
        return 0;
    }
    else
    {
        //Otherwise, create a temporary node and set it to the first node
        singleNode *tempNode;
        tempNode = headPtr;
        int i=1;
        //While there is another node and the desired spot has not yet been rached,
        //load the next node and increment the counter
        while ((tempNode->nextPtr)&&(i<index))
        {
            tempNode = tempNode->nextPtr;
            ++i;
        }
        //If the desired spot has not been reached or there are no more nodes,
        //the deletion is impossible
        if ((i<index)||(!(tempNode->nextPtr)))
        {
            return -1;
        }
        //Otherwise, load the node to be deleted then make the preceding node point 
        //to the following node, then delete the marked node
        else
        {
            delThis=tempNode->nextPtr;
            tempNode->nextPtr=delThis->nextPtr;
            delete delThis;
            return 0; 
        }
    }
}


//reverseList reverses the order of the nodes in the linked list

void PrimaryColors::reverseList()
{
    //If there are no nodes, nothing needs to be done
    if (!headPtr)
    {
        cout<< "Your list is empty and cannot be reversed. \n";
        
    }
    //If there is only one node, nothing needs to be done
    else if (!headPtr->nextPtr)
    {
        cout <<"Your list only has one entry and cannot be reversed.\n";
        
    }
    //Otherwise, start the process of reversing the linked list
    else
    {
        //Create a temporary node and set it to the first node
        singleNode *tempNode;
        tempNode=headPtr;
        int total=0;
        //While there are more nodes, add to the total of nodes
        while (tempNode->nextPtr)
        {
            tempNode=tempNode->nextPtr;
            ++total;
        }
        //Make the last node point to the first node, then move the last node to the 
        //first position
        tempNode->nextPtr=headPtr;
        headPtr=tempNode;
        
        //The process must be repeated for the remaining nodes (total-1)
        for (int i=0; i<total-1; ++i)
        {
            //Start over at the first position each loop 
            tempNode=headPtr;
            //Navigate to the last position in each loop
            for (int j=0; j<total; ++j)
            {
                tempNode=tempNode->nextPtr;
            }
            
            //Assign another node to the first node
            singleNode *currNode;
            currNode=headPtr;
            //Navigate to the node that was previously moved to its new spot
            for (int j=0; j<i; ++j)
            {
                currNode=currNode->nextPtr;
            }
            //Make the last node point to th node that the previously moved node
            //points to
            tempNode->nextPtr=currNode->nextPtr;
            //Mske the previously moved node point to the newly-moved node
            currNode->nextPtr=tempNode;
        }
        //Go to th last (what used to be first) node and cut it off from 
        //the infinite loop by making it point to null
        tempNode=headPtr;
        for (int i=0; i<total; ++i)
        {
            tempNode=tempNode->nextPtr;
        }
        tempNode->nextPtr=nullptr;
        //Display the success message to the user
        cout <<"Your list has been reversed.\n";
    }
    
    
}

void PrimaryColors::displayList(bool mono) const
{
    singleNode *nodePtr; //To move through list
    
    //Position nodePtr at the head of the list
    nodePtr=headPtr;
    
    //While nodePtr points to node, traverse the list
    while (nodePtr)
    {
        //Display the value in the node 
        cout <<nodePtr->color<<endl;
        
        //Move to next node
        nodePtr = nodePtr->nextPtr;
    }
    
}

int PrimaryColors::searchList(string input)
{
    int index=0;
    singleNode *nodePtr; //To move through list
    
    //Position nodePtr at the head of the list
    nodePtr=headPtr;
    
    //while nodePtr at the head of the list
    while(nodePtr)
    {
      if (nodePtr->color==input)
        {
        return index;
         }
         
         nodePtr=nodePtr->nextPtr;
         index++;
    
            
        }
        
        //If element not found
        return -1;
    }
    
