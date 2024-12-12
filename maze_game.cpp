#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>

using namespace std;

const int WALL = 1;
const int PATH = 0;

class MazeGenerator {
private:
    int height, width;
    
    // Maze representation (2D grid)
    vector<vector<int>> maze;  
    
    
    // Directions: up, left, down, right
    const int dx[4] = {0, -1, 0, 1};  
    
    
    // Directions: up, left, down, right
    const int dy[4] = {1, 0, -1, 0};  

    // Recursive function to generate maze
    void generate(int x, int y) {
    
    
    // Directions to shuffles
        vector<int> direction = {0, 1, 2, 3};  
        random_device rd;
        mt19937 g(rd());
        shuffle(direction.begin(), direction.end(), g);  // Randomize direction) {


        // Explore direction) { and break walls to create paths
        for (int i : direction) {
            
            int nx = x + dx[i] * 2;  
            
            // Move 2 steps (to break wall and create path)
            int ny = y + dy[i] * 2;

            // Check if new position is within bounds and is a wall
            if (ny > 0 && ny < height - 1 && nx > 0 && nx < width - 1 && maze[ny][nx] == WALL) {
            
             // Break the wall and create a path
                maze[ny][nx] = PATH; 
            
            // Break the wall between current and new position
                maze[y + dy[i]][x + dx[i]] = PATH;  
            
            // Recurse to continue generating the maze
                generate(nx, ny);  
            }
        }
    }

public:
    // Constructor to initialize maze and start generation
    MazeGenerator(int w, int h) : width(w), height(h) {
        
        // Initialize maze with walls
        maze = vector<vector<int>>(height, vector<int>(width, WALL));  
        
        // Entrance
        maze[1][1] = PATH;  

        // Exit
        maze[width - 2][height - 2] = PATH;  

        // Start generating maze from (1, 1)
        generate(1, 1);  
        
    }

    // Getter for the generated maze
    const vector<vector<int>>& getMaze() const {
        return maze;
    }

    // Function to print the maze
    void PrintMaze() const {
    
        for (const auto& row : maze) {
    
            for (int cell : row) {
    
                if (cell == WALL)
    
                    cout << "# ";  // Wall
    
                else
    
                    cout << ". ";  // Path
    
            }
    
            cout << endl;
    
        }
    
    }

};

int main() {

    // Create a 15x15 maze
    
    MazeGenerator generator(15, 15);
    
    // Print the generated maze
    
    generator.PrintMaze();  
    
    return 0;
}
