#include<iostream> 
using namespace std; 
// Dimentions of myScreen. You may change
#define M 8
  
// A recursive function to replace 
// previous color 'currColor' at  '(x, y)'  
// and all surrounding pixels of (x, y) 
// with new color 'newColor'
void floodFill(int myScreen[][M], int x, int y, int currColor, int newColor, int max_depth) 
{ 
    // Base cases 
    if (x < 0 || x >= M || y < 0 || y >= M) 
        return; 
    if (myScreen[x][y] != currColor) 
        return; 
    if (myScreen[x][y] == newColor) 
        return;
	if (!max_depth)
		return;
  
    // Replace the color at cell (x, y) 
    myScreen[x][y] = newColor; 
  
    // Recursively call for north, east, south and west 
    floodFill(myScreen, x+1, y, currColor, newColor, max_depth - 1); 
    floodFill(myScreen, x-1, y, currColor, newColor, max_depth - 1); 
    floodFill(myScreen, x, y+1, currColor, newColor, max_depth - 1); 
    floodFill(myScreen, x, y-1, currColor, newColor, max_depth - 1); 
} 
  
// It mainly finds the previous color on (x, y) and 
// calls floodFill() 
void findColor(int myScreen[][M], int x, int y, int newColor, int max_depth) 
{ 
    int currColor = myScreen[x][y]; 
    floodFill(myScreen, x, y, currColor, newColor, max_depth); 
} 
  
// Driver program to test above function 
int main() 
{ 
    int myScreen[M][M] = 
                    {
                      {3, 2, 1, 1, 1, 1, 1, 1}, 
                      {1, 1, 1, 1, 1, 1, 0, 0}, 
                      {1, 0, 0, 1, 1, 0, 1, 1}, 
                      {1, 2, 2, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 2, 2, 0}, 
                      {1, 1, 1, 1, 1, 2, 1, 1}, 
                      {1, 1, 1, 1, 1, 2, 2, 1}, 
                     }; 
	//printing screen before
    for (int i=0; i<M; i++) 
    { 
        for (int j=0; j<M; j++) 
           cout << myScreen[i][j] << " "; 
        cout << endl; 
    } 
	
    int x = 4, y = 4, newColor = 3, max_depth = 2; 
    findColor(myScreen, x, y, newColor, max_depth); 
  
    cout << "Updated myScreen : \n"; 
    
    //printing screen after
    for (int i=0; i<M; i++) 
    { 
        for (int j=0; j<M; j++) 
           cout << myScreen[i][j] << " "; 
        cout << endl; 
    } 
    return 0;
}