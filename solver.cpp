#include <bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> answer;

int smallest_clause(vector<vector<int> > v){
    int n = v.size();
    int ans=10000000,index;
    for(int i=0;i<n;i++){
        int x = v[i].size();
        if(x<ans) {
            ans=x;
            index = i;
        }
    }
    return index;
}

vector< vector<int> > unit_literal(vector<vector<int> > v){
    int n=v.size();
    vector<int> remove_clause;
    for(int i=0;i<n;i++){
        if(v[i].size()==1){
            remove_clause.push_back(i);   
        }
    }
    for(int i=0;i<remove_clause.size();i++){
        int k = remove_clause[i];
        v.erase(v.begin()+k-i);
    }
    return v;
}

vector<vector<int> > Simplify(vector< vector<int> > v, int a){
    // v=unit_literal(v);
    int n=v.size();
    vector<int> remove_clause;
    for(int i=0;i<n;i++){
        int m = v[i].size();
        //vector<int> remove_literal;
        int count=0;
        for(int j=0;j<m;j++){
            if(v[i][j]==(-1)*a){
                //remove_literal.push_back(j);
                v[i].erase(v[i].begin()+j);
            }
            if(v[i][j]==a) {
                remove_clause.push_back(i);
                break;
            }
        }
        // for(int l=0;l<remove_literal.size();l++){
        //     int k = remove_literal[l];
        //     // v[i].erase(v[i].begin()+k-l);
        //     v[i].erase(v[i].begin()+k);
        // } 
        // remove_literal.clear();
    }
    for(int i=0;i<remove_clause.size();i++){
        int k = remove_clause[i];
        v.erase(v.begin()+k-i);
    }
    //remove_clause.clear();


    return v;
}

int DPLL(vector<vector<int> > v){
    if(v.size()==0){
        return 1;
    }
    int ind = smallest_clause(v);
    if(v[ind].size() == 0) {
        return 0;
    }
    int literal = v[ind][0];
    answer.push_back(literal);  //Assumed the literal to be true
    if(DPLL(Simplify(v,literal))==1){
        return 1;
    }
    else{
        answer.pop_back();
        answer.push_back(-literal);
        if(DPLL(Simplify(v,-literal))==1){
           return 1;
        }
        else {
            answer.pop_back();
            return 0;
        }
    }
}

int main(){
    //start time
    clock_t tStart = clock();
	//reading the input file and storing the encoding in vector of vectors
	int props,clauses;//number of literals and clauses
	string data;
	ifstream f;
	f.open("input.cnf");
	while(1){
		getline(f,data);
		if(data[0]=='p'){
			istringstream iss(data);
			vector<string> results((istream_iterator<string>(iss)),istream_iterator<string>());
			props=stoi(results[2]);
			clauses=stoi(results[3]);
			break;
		}
	}
    //vector of vectors to store the encoding
    vector< vector<int> > encoding(clauses);
	for(int i=0;i<clauses;i++){
		getline(f,data);
		istringstream iss(data);
		vector<string> results((istream_iterator<string>(iss)),istream_iterator<string>());
		int l=results.size();
		for(int j=0;j<l-1;j++){
			encoding[i].push_back(stoi(results[j]));
		}
	}
	f.close();
    int ans = DPLL(encoding);
    if(ans==1){
        int n=answer.size();
        vector<int> soln(props+1);
        for(int i=0;i<answer.size();i++){
            if(answer[i]>0) soln[answer[i]]=1;
            else soln[-answer[i]]=-1;
        }
        for(int i=1;i<=props;i++){
            if(soln[i]>0) cout<<i<<" ";
            else cout<<-i<<" ";
        }
        cout<<"\nSAT";
    }
    else {
        cout<<"UNSAT";
    }
    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}