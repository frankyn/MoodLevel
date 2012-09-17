#include <iostream>
#include <map>
#include <list>
#include <string>

using namespace std;

map<string, int> words;
map<string, int>::iterator i;
list<string> split;
list<string>::iterator sI;

void splitString(string in, string delim){
	string word;
	size_t startPos = 0, endPos = 0;
	split.clear();

	while(startPos < in.length()){
		endPos = in.find(delim, startPos);
		
		if(endPos == string::npos){
			endPos = in.length();
		}

		word = in.substr(startPos, endPos);
		split.push_back(word);

		startPos = endPos + delim.length();
	}
}

int calculateMood(string in){
	int phraseMood = 0;
	size_t endPos;
	
	splitString(in, " ");
	
	for(sI = split.begin(); sI != split.end(); sI++){	
		//for( i = words.begin(); i != words.end(); i++){
			//size_t t = sI->find(i->first);			
			//if(t != string::npos){	
			//	cout<<"Word: "<<i->first;
			//	phraseMood += i->second;
			//	i = words.end();
			//}
		//}
		phraseMood += words[(*sI)];
	}
		
	return phraseMood;
}
//i have love the star too fondly to be fear of the night 
int main(){
	words["everything"] = 0;
	words["positive"] = 1;
	words["negative"] = -1;
	words["neutral"] = 0;
	words["better"] = 1;
	words["fondly"] = 1;
	words["night"] = 0;
	words["think"] = 0;
	words["love"] = 1;
	words["have"] = 0;
	words["fear"] = -1;
	words["star"] = 1;
	words["than"] = 0;
	words["will"] = 0;
	words["too"] = 0;
	words["the"] = 0;
	words["let"] = 0;
	words["you"] = 0;
	words["do"] = 0;
	words["to"] = 0;
	words["be"] = 0;	
	words["i"] = 0;

	int mood = 0;
	string in;

	while(in.compare("exit")!=0){
		//cout<<"Current mood: "
		  //  << ( mood >= 0 ? "Happy" : "Mad" ) 
                  //  << " ( " << mood << " ) "
                  //  << endl;
		//cout<<"Enter a phrase:"<<endl;
		cin>>in;
		mood += calculateMood(in);
	}
	cout<<"Current mood: "
	    << ( mood >= 0 ? "Happy" : "Mad" )
	    << " ( " << mood << " ) "
	    << endl;
       
	return 0;
}
