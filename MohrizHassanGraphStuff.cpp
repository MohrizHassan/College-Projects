/* MOHRIZ HASSAN
   12301385
   LAB 4
   GRAPHS */


#include <iostream>
using namespace std;

//----------------------------------------------------------------------------------------------
            //DECLARATIONS
//----------------------------------------------------------------------------------------------
#define MAX 12

int Graph[MAX][MAX];

int Graph2[MAX][MAX];

int weighting[MAX][MAX];

int HowManyNodes = MAX; //there are 12 nodes in the hard coded graph

bool BeenThere[MAX];

bool flag = false;

//----------------------------------------------------------------------------------------------
            //Here are all the funtions I intend on using :)
//----------------------------------------------------------------------------------------------
void LetsMakeAGraph();

void DijkstraGraphStuff();

bool DFS(int first, int last);

void dijkstra(int first, int last);

//-------------------------------------------------------------------------------------------------
//               MAIN OF CODE
//-------------------------------------------------------------------------------------------------

#define INFINITY 9999 //when my nodesdont have a path between them im going to set their distance to be infinty

int main()

{
// I was having issues with the output being in ints so I used your advice from the blackboard discussion forum in my own way

// your advice:
// I know the character 'A' has an ASCII value 65 and 'B' is 66 etc
// then you can say
// int node_index = graph[start_at_at - 65];
// or the same:
// int node_index = graph[start_at_at - 'A'];


//my reasoning:
// all myfunctions takes in the int ASCII values of the alphabet,
//I had many issues when i used chars in my code, but i made it so my outputs are in letters

//-------------------------------------------------------------------------------------------------------------------
//       A 	B 	C 	D 	E 	F 	G 	H 	I 	J 	K 	L 	M 	N 	O 	P 	Q 	R 	S 	T 	U 	V 	W 	X 	Y 	Z
//       0  1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25
//-------------------------------------------------------------------------------------------------------------------

    cout << endl;
    cout << "-----------------------------------------------------------"<<endl;
    cout << "    MOHRIZ'S GRAPH MAKER (NOW WITH DFS & DIJKSTRA!!!!)"     <<endl;
    cout << "-----------------------------------------------------------"<<endl;

//                                                                                               ^
    char primary = 'A'; //intial node A for purpose of showing DFS from A to L works             |
    char lastly = 'L';  // end node                                                              |
 //     |                                                                                        |
 //     |   I'm changing my chars into ints using simple ASCII maths.                            |
//      |  to do this I convert the chars into ints and then subtract 65 from ASCII table above  |
//      V
    int first = primary - 65;
    int last = lastly - 65;


//-------------------------------------------------------------------------------------------------
//               MY OUTPUTS
//-------------------------------------------------------------------------------------------------

//         DFS OUTPUT
//--------------------------

    cout << endl;
    cout << "*--- THE DFS "; //simply cosmetic so the output looks better (alot of this section is mainly cosmetic)
    LetsMakeAGraph();
    cout << "     DFS to get to " << lastly<< " from " << primary  << endl; //shows A to L DFS works I hope
    DFS(first, last);
    cout << endl;

    //THIS IS WHERE YOU CAN TEST ANY NODES OF YOUR CHOOSING :D

    primary = 'L'; //CHANGE INITIAL NODE HERE
    lastly = 'J'; // CHANGE END NODE HERE (WHATEVER YOU'RE SEARCHING FOR)
    first = primary - 65;
    last = lastly - 65;

    //After it was last used i need to reset the DFS graph and bool flags by using my LetsMakeAGraph Function
    cout << "*--- THE DFS ";
    LetsMakeAGraph();
    cout << "     DFS to get to " << lastly<< " from " << primary  << endl;
    DFS(first, last);
    cout << endl;


//   Dijkstra Output
//-------------------------

    primary = 'A'; // STARTING POINT, ANY NODE
    lastly = 'J'; //FINAL NODE YOU ARE GETTING TO WITH SHORTEST PATH
    first = primary - 65;
    last = lastly - 65;
    cout << "*--- THE Dijkstra ";

    //now because Dijkstra is associated with cost i create the graph but including these cost with the below function
    DijkstraGraphStuff();

    cout << "Dijkstra path to get to " << lastly << " from " << primary << endl;
    dijkstra(first, last);
    cout << endl << endl;

    primary = 'A';
    lastly = 'X';

    first = primary - 65;
    last = lastly - 65;

    cout << "*--- THE Dijkstra ";
    DijkstraGraphStuff();
    cout << "Dijkstra path from " << primary << " to " << lastly << endl;
    dijkstra(first, last);
    cout << endl;

    return 0;
}


//-------------------------------------------------------------------------------------------------
//               GRAPH HARCODING AND FUNCTIONS
//-------------------------------------------------------------------------------------------------

//          DFS
//--------------------------

// this function simply creates a adjacency matrix. I chose
// to use this method because when i tried with pointers I
// nearly lost my mind and this resonates more with me than using linked lists

void LetsMakeAGraph(){
    flag = false;
    for (int i = 0; i < HowManyNodes; i++){
        for (int j = 0; j < HowManyNodes; j++){
            Graph[i][j] = 0; // sets matrix to 0
        }
    }

//I hardcode my graph in below. It creates the links between the nodes of the assignment graph and puts them into a matrix
// I made sure it is a undirected graph
// I made sure that if a path already existed between some nodes it would be set to 1


    Graph[0][1] = 1;
    Graph[1][0] = 1;

    Graph[1][2] = 1;
    Graph[2][1] = 1;

    Graph[1][3] = 1;
    Graph[3][1] = 1;

    Graph[2][4] = 1;
    Graph[4][2] = 1;

    Graph[2][5] = 1;
    Graph[5][2] = 1;

    Graph[3][6] = 1;
    Graph[6][3] = 1;

    Graph[5][7] = 1;
    Graph[7][5] = 1;

    Graph[7][8] = 1;
    Graph[8][7] = 1;

    Graph[5][9] = 1;
    Graph[9][5] = 1;

    Graph[6][9] = 1;
    Graph[9][6] = 1;

    Graph[6][10] = 1;
    Graph[10][6] = 1;

    Graph[6][11] = 1;
    Graph[11][6] = 1;

    Graph[8][5] = 1;
    Graph[5][8] = 1;

    Graph[8][10] = 1;
    Graph[10][8] = 1;

    Graph2[9][11] = 1;
    Graph2[11][9] = 1;


    for(int h = 0; h < HowManyNodes; h++)   // BeenThere is set to false as no nodes are visted at this point
        BeenThere[h]= false;


    cout << "GRAPH WAS MADE---*" << endl;
}

//   Dijkstra
//-------------------------

// I hardcode my graph in below. It creates the links between the nodes of the assignment graph and puts them into a matrix
// This time the graph is WEIGHTED and assigns the weight to the path
// I made sure that if a path already existed between some nodes it would be set to 1
void DijkstraGraphStuff(){
    for (int i = 0; i < HowManyNodes; i++){
        for (int j = 0; j < HowManyNodes; j++){
            Graph2[i][j] = 0; // sets matrix to zero
        }
    }

    Graph2[0][1] = 1;
    Graph2[1][0] = 1;

    Graph2[1][2] = 2;
    Graph2[2][1] = 2;

    Graph2[1][3] = 2;
    Graph2[3][1] = 2;

    Graph2[2][4] = 3;
    Graph2[4][2] = 3;

    Graph2[2][5] = 2;
    Graph2[5][2] = 2;

    Graph2[3][6] = 2;
    Graph2[6][3] = 2;

    Graph2[5][7] = 1;
    Graph2[7][5] = 1;

    Graph2[5][9] = 4;
    Graph2[9][5] = 4;

    Graph2[6][9] = 1;
    Graph2[9][6] = 1;

    Graph2[6][10] = 2;
    Graph2[10][6] = 2;

    Graph2[6][11] = 3;
    Graph2[11][6] = 3;

    Graph2[8][5] = 2;
    Graph2[5][8] = 2;

    Graph2[7][10] = 11;
    Graph2[10][7] = 11;

    Graph2[9][11] = 5;
    Graph2[11][9] = 5;


    for(int h = 0; h < HowManyNodes; h++)
        BeenThere[h]= false; // same case as in DFS, BeenThere is set to false

    cout << "GRAPH WAS MADE---*" << endl;
}



//             FUNCTIONS


//-------------------------------------------------------------------------------------------------
//               DFS
//-------------------------------------------------------------------------------------------------

// DFS, is a way to traverse the graph. it is RECURSIVE
// it is given it's intial node and keeps recursing till it finds the node is is searching for
// mine sets the flag to true when node is found and returns true when the node is found
// Ihad issues with it continuelly recursing until i tried using a flag seen in my second if statemnet
// It will stop my DFS recursing once the node is found

bool DFS(int first, int last)
{
    if (first == last)
        {
        cout << (char)(first+65) << " ";
        cout << "target found - Halt\n";
        flag = true;
        return true;
    }

    else{
        cout << (char)(first+65) << "->";
        BeenThere[first] = true;
        for(int j = 0; j < HowManyNodes; j++)
            {
            if(!BeenThere[j] && Graph[first][j]==1){
                DFS(j, last);
            }

            if (flag){
                return false;
            }
        }
    }
    return false;
}


//-------------------------------------------------------------------------------------------------
//               DIJKSTRA
//-------------------------------------------------------------------------------------------------

void dijkstra(int first, int last)
{

        //WEIGHTS

    int minHowFar;


    for(int i = 0; i < HowManyNodes; i++)       //adds weight to matrix thereby making a weighted graph
        for(int j = 0; j < HowManyNodes; j++)

            if(Graph2[i][j] == 0)

                weighting[i][j] = INFINITY; // had to come up with somehing to denote no path so weight is set to infinty when this is the case
            else
                weighting[i][j] = Graph2[i][j]; // if theres a path it correspomds with the weights in the weighted matrix


    int PREDECESSOR[MAX]; // <---- parent of node in array
    int HowFar[MAX]; // <----length/distance (probably shouldve given simpler names

    for(int k = 0; k < HowManyNodes; k++)

        {
        HowFar[k] = weighting[first][k];
        PREDECESSOR[k] = first;
    }

            HowFar[first] = 0; // when the length to the first node turns out to be zero
            BeenThere[first] = true; // BeenThere is to true
            int NumberOfNodesSeen = 0; //setting number of ndes visited to 0
            int following = 0;


    while(NumberOfNodesSeen < HowManyNodes-1)

    {
        minHowFar = INFINITY;

        for(int x = 0; x < HowManyNodes; x++)
            if(HowFar[x] < minHowFar && !BeenThere[x])
            {
                minHowFar = HowFar[x];
                following = x; // this gives the following node that is closest to the node beforehand
            }

        // but if a better path exists check
        BeenThere[following] = true;

        for(int i = 0; i < HowManyNodes; i++)

            if(!BeenThere[i])

                if(minHowFar + weighting[following][i] < HowFar[i])
                {
                    HowFar[i] = minHowFar + weighting[following][i];
                    PREDECESSOR[i] = following;
                }

        NumberOfNodesSeen++;
    }//endwhile


    // SHORTEST PATH//
    // This prints the quickest way and overall cost from the every node
    // fto first node.
   // i struggled a bit here being honest. I couldnt get the desired print but
   // i do have the path shown from the intial node to the desired node
   // and you can see which is the previous node and therefore the predecessor

    if (last > HowManyNodes){

        for(int i = 0; i < HowManyNodes; i++){
            int j = i;
            if(i != first){
                cout << endl;
                cout << "Overall cost going from " << (char)(first+65) << " to " << (char)(i+65) << " = " << HowFar[i] << endl;
                cout << "You get from " << (char)(first+65) << " to " << (char)(i+65) << " by going this way " <<  "(node to the right of "<< (char)(i+65)<< " is it's parent)"<<endl  << (char)(i+65);

                while(j != first){
                    j = PREDECESSOR[j];
                    cout <<"<-" << (char)(j+65);
                }
                cout << endl;
            }
        }
    }

    else { // when finding a node that is in the graph, it only prints from the first node to the last node and the total distance between the nodes
        for(int i = 0; i < HowManyNodes; i++){
            int j = i;

            if(i != first){

                if (i == last){
                cout << endl;
                cout << "Overall cost going from " << (char)(first+65) << " to " << (char)(i+65) << " = " << HowFar[i] << endl;
                cout << "You get from " << (char)(first+65) << " to " << (char)(i+65) << " by going this way " <<  "(node to the right of "<< (char)(i+65)<< " is it's parent)"<<endl  << (char)(i+65);

                    while(j != first){
                        j = PREDECESSOR[j];
                        cout <<"<-" << (char)(j+65);
                    }
                }
            }
        }
        cout << endl << "Target found - Halt!";
    }
}




