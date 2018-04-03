#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<int> reduce(vector<vector<int> > adjacency, int n){
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			if(adjacency[i][j] == 0 && i != j){
				vector<vector<int> >completer = adjacency;
				completer[i][j] = 1;
				completer[j][i] = 1;
				vector<vector<int> >smaller (n-1, vector<int> (n-1));
				for(int p = 0; p < n-1; p++){
					for(int q = p; q < n-1; q++){
						if(p == i){
							if(adjacency[j][q] == 1){
								smaller[p][q] = 1;
							}else{
								smaller[p][q] = 0;
							}
						}else if(q == i){
							if(adjacency[p][j] == 1){
								smaller[p][q] = 1;
							}else{
								smaller[p][q] = 0;
							}
						}else{
							smaller[p][q] = adjacency[p][q];
						}
					}
				}
			}
		}
	}
	vector<int> coeff(n);
	return coeff;	
}

int main(){
	ifstream fin ("adjacency.in");
	ofstream fout ("adjacency.out");
	int n;
	fin >> n;
	vector<vector<int> > adjacency (n, vector<int>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			fin >> adjacency[i][j];
		}
	}
	reduce(adjacency, n);
	return 0;
}
