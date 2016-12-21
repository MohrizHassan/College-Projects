
            /* MOHRIZ HASSAN
               12301385
               3D5A LAB 3
               BINARY SEARCH TRESS
               */



            #include <iostream>
            using namespace std;

            #define SIZE 7 // here im setting a constant value of 7, this can be changed and fiddled with.This is the number of letters i'm hardcoding in
                            //using 7 lets me show my balancing of my tree


            char initialArray[SIZE] = {'X', 'Z', 'C', 'B', 'A', 'Y', 'J' }; //here im setting up my array. I figured Id use my name as an example. I decided just to  hardcode this in for ease to be honest

            char TreeBalancingArray[SIZE] = { NULL }; // come back and check


            typedef struct Tree_Node Tree_Node; // here im just creating my basic structure for a tree node (leaf)

            struct Tree_Node
            {
                char data;

                Tree_Node *left;    // leaf to left of parent
                Tree_Node *right;   // leaf to right of parent
            };


//--------------------------------------------------------------------------------------------------------------
            //Here are all the funtions I intend on using :)
//--------------------------------------------------------------------------------------------------------------

            void print(char AnyArray[]);

            void tree_insert(Tree_Node *root, char data);
                                                                                // I explain these all in more detail later in the code
            Tree_Node* tree_search(Tree_Node *root, char data);

            void tree_delete( Tree_Node* root );

            void QUICK(char initialArray[], int first, int last);

            int partition(char initialArray[], int pivot, int first, int last);

            void print_transverse(Tree_Node *root);

            void balance_tree(char TreeBalancingArray[], int first, int last);

            void balance_recurse(Tree_Node *root, char TreeBalancingArray[], int first, int last);

//--------------------------------------------------------------------------------------------------------------
//
//               MAIN OF CODE
//---------------------------------------------------------------------------------------------------------------

            int main()

            {

                int x = 0;
                int y = 0;

                char* TreeBalancingArray = NULL;


                TreeBalancingArray = new char [SIZE];


                for (int k = 0; k < SIZE; k++)

                    {

                    TreeBalancingArray[k] = initialArray[k];
                }


                Tree_Node *root = new Tree_Node;        // sets up a new root node for the tree
                root->left = NULL;
                root->right = NULL;






//-------------------------------------------------------------------------------------------------------------------
//                                         MY TABLE OUPUT
//                                    1. OUTPUT ORIGINAL LETTERS
//------------------------------------------------------------------------------------------------------------------
                cout << endl <<endl ;
                cout << "" << endl;
                cout << "    MOHRIZ'S BINARY SEARCH TREE (NOW WITH DELETION!!!!)"<<endl;
                cout << "-----------------------------------------------------------"<<endl;
                cout << "                      LETTERS";
                cout << endl <<endl ;
                print(initialArray);
                cout << "" << endl;
                cout << "-----------------------------------------------------------";


//-------------------------------------------------------------------------------------------------------------------
//                               2.STEP BY STEP PLACEMENT OF LETTERS INTO THE TREE (INSERTION)
//-------------------------------------------------------------------------------------------------------------------


                cout <<endl << "         LETTERS ARE PLACED IN THE TREE (INSERTION) " << endl<<endl;
                root->data = initialArray[x]; // sets the first character in the array to be the root of the tree

                // builds the tree round the root
                cout << "        *** The Root(starting letter) is " << root->data << " ***"<<endl<<endl;

                initialArray[y] = initialArray[x+1];

                for(int y = 1; y < SIZE; y++)

                    {
                    tree_insert(root, initialArray[y]); //Im making it go to every index and putting a letter into the indexs each time
                }



//-------------------------------------------------------------------------------------------------------------------
//                                         3.GIVES THE TRANVERSE ORDER OF TREE (ASCENDING)
//-------------------------------------------------------------------------------------------------------------------

                // prints the binary search tree in traversal small to high

                cout << "-----------------------------------------------------------";
                cout << endl << "         TRANVERSE OF TREE, SMALLEST TO GREATEST" << endl<<endl;


                print_transverse(root);
                cout << endl;
                cout << "-----------------------------------------------------------"<<endl<<endl;


//-------------------------------------------------------------------------------------------------------------------
//                                         4. SEARCH MY TREE FOR ENTERED CHARACTER
//-------------------------------------------------------------------------------------------------------------------


                // checks to see if the input character from the user is prsent in the binary tree
                char search;
                cout << "WHAT LETTER ARE YOU SEARCHING FOR? (DON'T FORGET ABOUT CASE SENSITIVITY): ";
                cin >> search;
                tree_search(root, search);


//-------------------------------------------------------------------------------------------------------------------
//                                         5. DELETE TREE ONE LETTER AT A TIME
//-------------------------------------------------------------------------------------------------------------------

                // terminates and deletes the tree from the bottom leaves all the way to the root
                cout << "            LET'S START TO DELETE THE TREE"<<endl;
                tree_delete(root);
                cout << endl;
                cout << endl << "            I'VE DELETED THE TREE, BYE BYE TREE" << endl;


//-------------------------------------------------------------------------------------------------------------------
//                                         6. MAKING A BALANCED TREE
//-------------------------------------------------------------------------------------------------------------------


                // here im outputting the balanced tree for the hardcoded letters at the start
                 cout << "-----------------------------------------------------------"<<endl;
                cout << "           TIME TO BALANCE THE TREE WITH QUICKSORT" << endl << endl;
                 cout << "                  STARTING LETTERS" << endl<<endl;

                print(TreeBalancingArray);
                QUICK(TreeBalancingArray,0,SIZE - 1);


                cout << endl << endl;

                balance_tree(TreeBalancingArray, 0, SIZE-1);

                cout << endl << "            TREE IS NOW BALANCED!!! :D :D :D" << endl;
                cout << "-----------------------------------------------------------"<<endl<<endl;


                return 0;
}





                            //FUNCTIONS



//-------------------------------------------------------------------------------------------------------------------
//                                         PRINT FUNCTION
//-------------------------------------------------------------------------------------------------------------------


void print(char initialArray[]) //simple funtion to print the intitial letters
{
    for (int i = 0; i < SIZE; i++) {

        cout << initialArray[i] << '\t';
    }
}



 // Tree_Node* tree_search( Tree_Node* root, char data );
 //If a value exists in the tree, return a pointer to that node, otherwise return NULL.*/
//-------------------------------------------------------------------------------------------------------------------
//                                         SEARCH FUNCTION  //search through tree for inputted letter repeatidly until it's established that it is or isnt there
//-------------------------------------------------------------------------------------------------------------------

Tree_Node* tree_search(Tree_Node* root, char data)
{
    if (root == NULL) {                 // If a value exists in the tree, return a pointer to that node, otherwise return NULL
                                        // when a binary tree is NULL is its empty meaning the root must be zero
        cout << "UH OH THE TREE SEEMS TO BE EMPTY :O" << endl;
        return 0;
    }

    else if (data == root->data) // whenever the letter being looked for happens to be the same as the root
        {

        cout << endl  ;
        cout << data << " JUST HAPPENS TO BE IN THE TREE :D" << endl; // the letter is found do ouput this to screen :)
        cout << "-----------------------------------------------------------"<<endl;

        return root;
    }

    else if (data < root->data) // the letter is smaller than the root so it will instantly look at the left of the search tree
        {

        if (root->left == NULL) // if it isnt in the left hand side it's not in the tree
            {
            cout << endl ;
            cout << data << " UNFORTUNATLEY ISN'T IN THE TREE :(" << endl; //  output telling user its not in tree
            cout << "-----------------------------------------------------------"<<endl;

            return root;
        }

        return tree_search(root->left, data); // this is where my search goes through the left side repeatedly looking for the letter
    }

    else if (data > root->data) { // similar to above when the letter is bigger than null we check the right side of the tree

        if (root->right == NULL) // if the right branch is empty
            {
            cout << endl ;
            cout << data << " UNFORTUNATLEY ISN'T IN THE TREE :(" << endl;
            cout << "-----------------------------------------------------------"<<endl;

            return root;
        }

        return tree_search(root->right, data);
    }

    else // when the letter is found in the tree simply let the user know
        {
        cout << data << " JUST HAPPENS TO BE IN THE TREE :D" << endl;
        cout << "-----------------------------------------------------------"<<endl;
        return root;
    }

    return 0;
}


//-------------------------------------------------------------------------------------------------------------------
//                                         TRANVERSE FUNCTION  //prints from smallest to greatest
//-------------------------------------------------------------------------------------------------------------------

// goes to the most left node of the tree i.e to the most left subtree
// and checks the left node of that subtree then checks the subtree root
// and checks (transverses) to the right brnch (transverses)of the subtree
// then recurses and prints the value there

void print_transverse(Tree_Node *root) {

    if (root != NULL) {

        print_transverse(root->left);

        cout << root->data << '\t';

        print_transverse(root->right);

    }
}


//-------------------------------------------------------------------------------------------------------------------
//                                         BALANCE FUNCTION
//-------------------------------------------------------------------------------------------------------------------
void balance_tree(char TreeBalancingArray[], int first, int last) {

    int midpoint;

    midpoint = (first + last) / 2;                                                  // borrowed this from my quicksort in the last lab to find middle index of the array of letters
                                                                                    // sets the letter in the midpoints index to be the root of the tree
                                                                                    // then it balances and inserts the first half of the array and the second half of the array into the tree

    Tree_Node *root = new Tree_Node;

    root->data = TreeBalancingArray[midpoint];

    cout << "       *** The Root(starting letter) is " << TreeBalancingArray[midpoint]<< "***" << endl<<endl;

    balance_recurse(root, TreeBalancingArray, first, midpoint-1);

    balance_recurse(root, TreeBalancingArray, midpoint+1, last);
}




void balance_recurse(Tree_Node *root, char TreeBalancingArray[], int first, int last)
{
    // creates the index of the middle value of the array like in my balance function above, thne i get it to output the middle index value
    // the my function inserts the root of the tree
    // then it resurvivly balances and inserts into the left side of the tree and inserts into the right side of the tree

    int midpoint;

    midpoint = (first + last) / 2;

    if (first <= last) {
        cout << "           The midpoint is " << TreeBalancingArray[midpoint] <<endl;

        tree_insert(root, TreeBalancingArray[midpoint]);

        balance_recurse(root, TreeBalancingArray, midpoint+1, last);

        balance_recurse(root, TreeBalancingArray, first, midpoint-1);
    }
}


//-------------------------------------------------------------------------------------------------------------------
//                                         INSERT FUNCTION //creates new nodes to left or right of parent and inserts the letters into tree
//-------------------------------------------------------------------------------------------------------------------


// This is my void tree_insert( Tree_Node* root, char data );
 //Creates a new node in the tree in the appropriate position for a binary search tree.


void tree_insert(Tree_Node *root, char data)
{
    if (data < root->data) { // first i see if the enetred letter is smaller than my root, in this case M

        // like all binary search trees i'm placing the letter to the left hand side of the root i.e left branch when it is less than the root (M)


        if (root->left != NULL) {           // just a condition for when there is already a branch on the left tht already contains a leaf

            tree_insert(root->left, data);
        }
                                               //then move onto else statement
        else {
            root->left = new Tree_Node;                        //  make a new leaf on the left branch

            root->left->data = data;                          // then the new letter being inserted is set to the new node

            root->left->left = root->left->right = NULL;      // then ensure both branches of the new node are set to nothing incase branching occurs from the node

            cout << "           Place " <<  data << " to the left of           "<< root->data << endl;
        }
    }


       else {                             // if this else is hit it shows that the letter is > M, and needs to be put on the right side of the tree

        if (root->right != NULL)

            {
            tree_insert(root->right, data); // just a condition for when there is already a branch on the right tht already contains a leaf
        }

        else {

            root->right = new Tree_Node;    // same procedure as setting new left node but for right

            root->right->data = data;

            root->right->left = root->right->right = NULL;
            cout <<  "           Place " <<  data << " to the right of          "<< root->data << endl;
        }
    }
}


//-------------------------------------------------------------------------------------------------------------------
//                                         DELETE FUNCTION
//-------------------------------------------------------------------------------------------------------------------


//keeps calling the delete function until the entire tree is deleted one by one until the root is zero

void tree_delete(Tree_Node* root)
{
    if (root != NULL)
    {
        tree_delete(root->left);
        tree_delete(root->right);

        cout << endl << "                 " << root->data << " JUST GOT DELETED!";

        delete root;
    }
}

//-------------------------------------------------------------------------------------------------------------------
//                                         QUICKSORT FUNCTION
//-------------------------------------------------------------------------------------------------------------------

void QUICK(char initialArray[], int first, int last)
{
      int x = first, y = last; //FIRST =left side, LAST = right side
      int tmp; // setting up a temporary value

      int pivot = initialArray[(first + last) / 2]; //initialise the pivot pointing it at the middle index of the array

      // creating my partition
      while (x <= y) //while the left side of the array is smaller or equal to the right
        {

            while (initialArray[x] < pivot) //while left side contains values smaller than pivot index's value

                  x++;      //move forward through left side of array

            while (initialArray[y] > pivot) //while right side contains values greater than pivot index's value

                  y--; //move backwards through right side of array

            if (x <= y) //if left side is smaller then the right side of the array
            {
                  tmp = initialArray[x]; // tmp is set to the quicksort of the left hand side
                  initialArray[x] = initialArray[y]; //swap
                  initialArray[y] = tmp;

                  x++; //increment left hand side
                  y--; //decrease left hand side
            }// end fi
      }
 //end of 1st while

              /* recursion */
               //it recursively calls itself to sort the two partitions, but only does it if it is necessary (hence the ifs before the recursive calls).
              if (first < y)
                {
                QUICK(initialArray, first, y);
              }

              if (x < last){
                    QUICK(initialArray, x, last);

              }






}
