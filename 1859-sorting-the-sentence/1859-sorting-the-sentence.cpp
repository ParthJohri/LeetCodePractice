class Solution {
public:
    string sortSentence(string s) {

	stringstream str(s);
	// Creating a string stream object
	// Now this object can read the string
	// as if it were a stream

	vector<string> v(201);
	// vector to store the words of the string 
	// or the token of the string

	string temp="";

	while(getline(str,temp,' '))
	{
		v[temp[temp.length()-1]]=temp.substr(0,temp.length()-1);
	}

    string newstr="";
	for(auto i:v)
	{
		if(i!="")
		newstr+=i+" ";
	}
	return newstr.substr(0,newstr.length()-1);
    }
};