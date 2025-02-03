#include <iostream>
#include <fstream>
using namespace std;

void read(char maze[100][100], int &n, int &m,int &start_x,int &start_y) {
	std::fstream in("maze.txt");
	in >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			in >> maze[i][j];
			if (maze[i][j] == 'S')
			{
				start_x = i;
				start_y = j;
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

void escape(char maze[100][100],int x,int y, int table[100][100],int n,int m) {
	
}

int main(){
	char maze[100][100];
	int table[100][100];
	int n, m,start_x, start_y;
	read(maze, n, m, start_x, start_y);
	write(maze, n, m);
	cout << start_x << " " << start_y;
}