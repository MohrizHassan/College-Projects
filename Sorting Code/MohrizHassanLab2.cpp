


/* MOHRIZ HASSAN
   12301385
   3D5A DATA STRUCTURES LAB 2
   12/11/16
*/

#include <iostream>
#include<iomanip>


using namespace std;

#define SIZE 7    //size of array to be tested, change to desired size (7 looks best on screen in my opinion :)  but any value should work )

//intialising arrays
int StartingArray[SIZE];
int SelectionSortArray[SIZE] = { 0 };  //array for selection sort  |
int BubbleSortArray[SIZE] = { 0 };    // array for bubble sort      |------ all 3 set to 0 to begin with so theres no junk inside them. All set to overall array size of SIZE
int QuickSortArray[SIZE] = { 0 };     //array for quicksort       |

//function declarations
void print(int array[]);                                   //function to print array
void selectionSort(int arraySelection[]);                //function for selection sort
void bubbleSort(int bubbleSortArray[]);                   //function for bubble sort
void QuickSortFnct(int QuickSortArray[], int L, int R);  //function for quick sort


//counter declarations
int selectioncount;
int bubblecount;
int quickcount;


int main()

{
    srand(time(NULL)); // creates random numbers to fill into arrays

   for (int x = 0; x < SIZE; x++)
    {

       StartingArray[x] = rand() % 100;    //here we fill the array with random variables created until it is full with SiZE amount of integers

   } //first for loop end

   for (int y = 0; y < SIZE; y++)

    {
       BubbleSortArray[y] = StartingArray[y];
       SelectionSortArray[y] = StartingArray[y]; //here we fill each sorting array with the integers put into StartingArray above
       QuickSortArray[y] = StartingArray[y];
    } // 2nd for loop end


   /* SELECTION SORT OUTPUT */

   cout << "" << endl;
   cout << "----------------------------------------------------------------------------" << endl; //just to look good
   cout << "1. SELECTION SORT"<< endl<<endl;
   cout << "Array before SELECTION SORT:" << endl;
   print(SelectionSortArray);     //print out array before it has been sorted by select sort function
   cout << endl<<endl;

   clock_t tStart_selection = clock();  // start to clock
   selectionSort(SelectionSortArray);   // time taken for selection sort to work on given array
   clock_t tEnd_selection = clock();   // end clock

   cout << "Array post SELECTION SORT:" << endl;
   print(SelectionSortArray);                   //print out sorted array
   cout << endl;
   cout << "\nTime taken for function to run: " << (double)(tEnd_selection - tStart_selection) / CLOCKS_PER_SEC << " seconds" << endl; //print time taken to run
   cout << "Counter of array elements looked at for swap to happen: " << selectioncount << endl; //print slection count value
   cout << "----------------------------------------------------------------------------" << endl; //end section

    /*BUBBLE SORT OUTPUT */

   cout << "2. BUBBLE SORT"<< endl<<endl;

   cout << "Array before BUBBLE SORT:" << endl;
   print(BubbleSortArray); //print initial array before sorting
   cout << endl<< endl;

   clock_t tStart_bubble = clock(); //start clock etc as in slection sort output above
   bubbleSort(BubbleSortArray);
   clock_t tEnd_bubble = clock();

   cout << "Array post BUBBLE SORT:" << endl;
   print(BubbleSortArray) ;     //print array sorted via bubblesort
   cout << endl<<endl;

   cout << "Time taken for function to run: " << (double)(tEnd_bubble - tStart_bubble)/ CLOCKS_PER_SEC << " seconds" << endl; //print time taken tor run
   cout << "Counter of array elements looked at for swap to happen:" << bubblecount << endl; //print bubble count value

    cout << "----------------------------------------------------------------------------" << endl;


   /* QUICKSORT OUTPUT */

   cout << "3. QUICK SORT"<< endl<<endl;
   cout << "Array before QUICK SORT: " << endl;
   print(QuickSortArray);                   //output array before being sorted
   cout << endl;

   clock_t tStart_quick = clock(); //start clock etc.
   QuickSortFnct(QuickSortArray,0,SIZE - 1);
   clock_t tEnd_quick = clock();

   cout << endl << "Array post QUICK SORT: " << endl;
   print(QuickSortArray); //print array sorted via quick sort
   cout << endl;
   cout << "\nTime: " << (double)(tEnd_quick - tStart_quick) / CLOCKS_PER_SEC << " seconds" << endl;        //print time taken to run
   cout << "Counter of array elements looked at for swap to happen: " << quickcount << endl;        //print quick count value
   cout << "----------------------------------------------------------------------------" << endl;


    /* RESULTS TABLE OUTPUT */

    cout << "                               RESULTS    ";
    cout << endl<<endl;

    cout << "Array before sorting:    ";
    print(StartingArray);  //output original array so you can it before it has been sorted
    cout << endl;

    // in this part i output the value of each array post sorting to show the all work and that im not just outputting one sorted version of the array

    cout << endl;
    cout << "Sorted via Bubble Sort:  ";
    print(BubbleSortArray) ;
    cout << endl;

    cout << "Sorted via Select Sort:  ";
    print(SelectionSortArray);
    cout << endl;

    cout << "Sorted via Quick Sort:   ";
    print(QuickSortArray);
    cout << endl<<endl;


    cout << "Counter for BubbleSort:    " << bubblecount << endl;  //printing the counters for each function so you can see them side by side and compare them
    cout << "Counter for SelectionSort: " << selectioncount << endl;
    cout << "Counter for QuickSort:     " << quickcount << endl;

    cout << "----------------------------------------------------------------------------" << endl;
    cout << endl<<endl;



    return 0;
}

    /* FUNCTIONS */

    void print(int array[]) {
       for (int i = 0; i < SIZE; i++) {   //function to simply print any array of size SIZE
           cout << array[i] << '\t';
       }
    }


    void bubbleSort(int bubbleSortArray[])
    {
        int x=1, y=0; //initialise variables outside main loop to keep loop going until fully sorted array is aquired

        while (x==1) //while our value of x is equal to 1 my loop will continue to run
            {
                x=0;    //initialise x to zero
                y++;   //increment y each time the while loop runs this allows my for loop to go through every element in the array
                for (int i=1;i<=SIZE-y;i++)
                {
                    if (bubbleSortArray[i]<=bubbleSortArray[i-1]) //if current index value is smaller than the previous index value
                    {
                        int temp=bubbleSortArray[i];
                        bubbleSortArray[i]=bubbleSortArray[i-1];        // swap the numbers
                        bubbleSortArray[i-1]=temp;
                        x=1;
                        bubblecount++; //counts how many times if statement runs
                    }
                    bubblecount++; //counts how many times the loop runs
                }
            }
    }

void selectionSort(int arraySelection[])
{
   for (int x = 0; x < SIZE; x++)
    {
       int minimumInd = x;  //assign x the smallest index in the array i.e minimum index

       for (int y = x + 1;y < SIZE;y++)     // for loop goes though the given array one index ahead of x (y)
        {
           if (arraySelection[y] < arraySelection[minimumInd]) //if  number stored in y(next index) is less than the number in the smallest index
           {
               minimumInd = y;      //  assign y to be the smallest index
               selectioncount++;
           } //end if statement
           selectioncount++;        //increment counter each if statement runs
        } //end nested for loop

       swap(arraySelection[x], arraySelection[minimumInd]); //swaps x with the smallest index
       selectioncount++;    //increment counter each time loop runs
   } //end main for loop
}


void QuickSortFnct(int QuickSortArray[], int L, int R)//explained alot clearer in report!!!
{
      int x = L, y = R; //L =left side, R = right side
      int tmp; // setting up a temporary value

      int pivot = QuickSortArray[(L + R) / 2]; //initialise the pivot pointing it at the middle index of the array

      // creating my partition
      while (x <= y) //while the left side of the array is smaller or equal to the right
        {

            while (QuickSortArray[x] < pivot) //while left side contains values smaller than pivot index's value

                  x++;      //move forward through left side of array

            while (QuickSortArray[y] > pivot) //while right side contains values greater than pivot index's value

                  y--; //move backwards through right side of array

            if (x <= y) //if left side is smaller then the right side of the array
            {
                  tmp = QuickSortArray[x]; // tmp is set to the quicksort of the left hand side
                  QuickSortArray[x] = QuickSortArray[y]; //swap
                  QuickSortArray[y] = tmp;
                  quickcount++;
                  x++; //incrment left hand side
                  y--; //decrease left hand side
            }// end fi
      }
 //end of 1st while

              /* recursion */
               //it recursively calls itself to sort the two partitions, but only does it if it is necessary (hence the ifs before the recursive calls).
              if (L < y)
                {
                QuickSortFnct(QuickSortArray, L, y);
              }

              if (x < R){
                    QuickSortFnct(QuickSortArray, x, R);
                    quickcount++;
              }

   }



