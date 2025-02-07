#include <iostream>
#include <fstream>
using namespace std;

void read(char maze[100][100], int &n, int &m,int &start_x,int &start_y,int &end_x,int &end_y,int table[100][100]) {
	std::fstream in("maze.txt");
	in >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			table[i][j] = INT_MAX;
			in >> maze[i][j];	
			if (maze[i][j] == 'S')
			{
				start_x = i;
				start_y = j;
				
			}
			if (maze[i][j] == 'E')
			{
				end_x = i;
				end_y = j;
			}
		}
	}
}

void write(char maze[100][100],int n, int m){
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << maze[i][j] << " ";
		cout << "\n";

	}
}

void escape(char maze[100][100],int x,int y, int table[100][100],int n,int m,int step) {
	if (step > table[x][y])
		return;
	table[x][y] = step;
	if (x - 1 >= 0 && maze[x - 1][y] != '#')
		escape(maze, x - 1, y, table, n, m, step + 1);
	if (x + 1 < n && maze[x + 1][y] != '#')
		escape(maze, x + 1, y, table, n, m, step + 1);
	if (y - 1 >= 0 && maze[x][y-1] != '#')
		escape(maze, x, y-1, table, n, m, step + 1);
	if (y + 1 < m && maze[x][y+1] != '#')
		escape(maze, x, y+1, table, n, m, step + 1);
	if (x - 1 >= 0 && y - 1 >= 0 && maze[x - 1][y-1] != '#')
		escape(maze, x - 1, y-1, table, n, m, step + 1);
	if (x + 1 < n && y + 1 < m && maze[x + 1][y + 1] != '#')
		escape(maze, x + 1, y+1, table, n, m, step + 1);
	if (x - 1 >= 0 && y + 1 < m && maze[x - 1][y + 1] != '#')
		escape(maze, x - 1, y + 1, table, n, m, step + 1);
	if (x + 1 < n && y - 1 >= 0 && maze[x + 1][y - 1] != '#')
		escape(maze, x - 1, y + 1, table, n, m, step + 1);
	
}

int main(){
	char maze[100][100];
	int table[100][100];
	int n, m,start_x, start_y,end_x,end_y;
	read(maze, n, m, start_x, start_y,end_x,end_y,table);
	table[start_x][start_y] = 0;
	write(maze, n, m);
	escape(maze, start_x, start_y, table, n, m, 0);	
	cout << table[end_x][end_y];
	
	return 0;
}