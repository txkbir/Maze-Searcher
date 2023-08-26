//
//  mazequeue.cpp
//

#include <queue>
using namespace std;

class Coord {
  public:
     // parametrized constructor
    Coord(int rr, int cc)
      : m_r(rr), m_c(cc) {}
    
     // accessors
    int r() const { return m_r; }
    int c() const { return m_c; }
    
  private:
     // this Coord object's row and column member
    int m_r;
    int m_c;
};

 // return true if a path exists from (sr,sc) -> (er,ec)
bool pathExists(char maze[][10], int sr, int sc, int er, int ec) {
    queue<Coord> coordQueue;
    Coord start(sr,sc), end(er,ec);
    coordQueue.push(start);
    maze[sr][sc] = '#';
    
    const int END_ROW = er, END_COL = ec;
    int row, col;
    
    while (!coordQueue.empty()) {
        Coord front = coordQueue.front();
        row = front.r();
        col = front.c();
        coordQueue.pop();

        if (row == END_ROW  &&  col == END_COL) return true;
                 // SOUTH
        if (maze[row + 1][col] == '.') {
            coordQueue.push(Coord(row+1,col));
            maze[row + 1][col] = '#';
        }             // EAST
        if (maze[row][col + 1] == '.') {
            coordQueue.push(Coord(row,col+1));
            maze[row][col + 1] = '#';
        }        // NORTH
        if (maze[row - 1][col] == '.') {
            coordQueue.push(Coord(row-1,col));
            maze[row - 1][col] = '#';
        }
        if (maze[row][col - 1] == '.') {
            coordQueue.push(Coord(row,col-1));
            maze[row][col - 1] = '#';
        }
    }
    return false;
}
