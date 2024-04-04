extern "C" {
    // Define the dimensions of the screen
    void floodFill(int **myScreen, int M, int x, int y, int currColor, int newColor, int max_depth) 
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
      
        // Recursively call for north, east, south, and west 
        floodFill(myScreen, M, x+1, y, currColor, newColor, max_depth - 1); 
        floodFill(myScreen, M, x-1, y, currColor, newColor, max_depth - 1); 
        floodFill(myScreen, M, x, y+1, currColor, newColor, max_depth - 1); 
        floodFill(myScreen, M, x, y-1, currColor, newColor, max_depth - 1); 
    }  
}
