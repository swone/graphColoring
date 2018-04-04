#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<int> reduce(vector<vector<int> > adjacency, int n){
	int i = 0;
	while(i < n){
		int j = i;
		while(j < n){
			if(adjacency[i][j] == 0 && i != j){
				vector<vector<int> >completer = adjacency;
				completer[i][j] = 1;
				vector<vector<int> >smaller (n-1, vector<int>(n-1, 0));
				for(int p = 0; p < n-1; p++){
					for(int q = p; q < n-1; q++){
						if(p >= j){
							if(q >= j){
								smaller[p][q] = adjacency[p+1][q+1];
							}else{
								smaller[p][q] = adjacency[p+1][q];
							}
						}else{
							if(q >= j){
								smaller[p][q] = adjacency[p][q+1];
							}else{
								smaller[p][q] = adjacency[p][q];
							}
						}
					}
				}
				vector<int> smallScore = reduce(smaller, n-1);
				vector<int> compScore = reduce(completer, n);
				vector<int> thisScore = compScore;
				for(int k = 0; k < n-1; k++){
					thisScore[k]+=smallScore[k];
				}
				return thisScore;	
			}
			j++;
		}	
		i++;
	}
	vector<int> thisScore(n);
	for(int j = 0; j < n; j++){
		if(j == n-1){
			thisScore[j] = 1;
		}else{
			thisScore[j] = 0;
		}
	}
	return thisScore;
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
	vector<int> factCoef = reduce(adjacency, n);
	for(int i = 0; i < n; i++){
		fout << factCoef[i] << "\n";
	}
	return 0;
}
