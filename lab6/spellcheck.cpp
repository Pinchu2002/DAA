#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main(){
	int count = 0;
	string s;
	vector<string> v;
	ifstream file("dictionary.txt");
	if(file.is_open()){
		while(getline(file,s)){
			transform(s.begin(),s.end(), s.begin(), ::tolower);
			v.push_back(s);
			//cout << s << "\n";
			count++;
		}
		cout << count << "\n";
		sort(v.begin(),v.end());
		//for(int i = 0; i < count; i++){
		//	cout << v[i] << " ";
		//}
		file.close();
	}
	else{
		cout << "Can't open the file!";
	}
	fstream myfile;
	string word, filename;
	filename = "document.txt";
	myfile.open(filename.c_str());
	set<string> mis_spelled;
	while(myfile >> word){
		word.erase(remove_if(word.begin(), word.end(), [](char c)
				{return !isalpha(c);}),word.end());
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		if(!binary_search(v.begin(),v.end(), word)){
			mis_spelled.insert(word);	
		}
		//cout << word << "\n";		
	}
	cout << "No. of Mis-Spelled Word: "<< mis_spelled.size() << "\n";
	for(auto &i:mis_spelled){
		cout << i << "\n";
	}
	cout << "\n";
	return 0;
}
