#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool path_finder(string maze) {

	vector<vector<int>> arr;
	vector<int> curLine;
	maze += "\n";
	for(int i = 0; i < maze.length(); i++){
		if(maze[i] == '.') curLine.push_back(0);
		if(maze[i] == 'W') curLine.push_back(-1);
		if(maze[i] == '\n'){
			arr.push_back(curLine);
			curLine.clear();
		}
	}
		
	int size = arr.size()-1;	
	stack<pair<int,int>> st;
	st.push({0,0});
	while(!st.empty()){
		auto cur = st.top();
		st.pop();
		int i = cur.first;
		int j = cur.second;
		if(i == size && j == size) return true;
		// R
		if(size >= i && size >= j+1 && arr[i][j+1] == 0) st.push({i,j+1});
		// D
		if(size >= i+1 && size >= j && arr[i+1][j] == 0) st.push({i+1,j});
		// U
		if(i-1 >= 0 && j >= 0 && arr[i-1][j] == 0) st.push({i-1,j});
		// L
		if(i >= 0 && j-1 >= 0 && arr[i][j-1] == 0) st.push({i,j-1});
		
		arr[i][j] = 6;
		
	}
	
	if(arr[arr.size()-1][arr.size()-1] == 6)
		return true;
	return false;
}

int main(){
	cout << path_finder(".W.\n.W.\n...") << endl;
	cout << path_finder(".W.\n.W.\nW..") << endl;
	cout << path_finder("......\n......\n......\n......\n......\n......") << endl;
	cout << path_finder("......\n......\n......\n......\n.....W\n....W.") << endl;
	cout << path_finder(".W.\n.W.\nW..") << endl;	
	cout << path_finder("...\nWWW\n...") << endl;
	
	return 0;
}

