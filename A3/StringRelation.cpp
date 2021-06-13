#include "StringRelation.h"
#include <unistd.h>


//#include <iostream>
//
//using namespace std;
/*
 * Assign SetMembers.
 */
void StringRelation::setInput(SetOfStrings *s)
{
	SetMembers=s;
}

/*
 * It splits a pair "a,b" into a vector of strings "a", "b".
 * Returns the string vector.
 */
vector<string> StringRelation::makeTokens(string pair){
	vector<string> out;
	vector<string>::iterator p;
	char *a = new char [pair.length()+1];
	strcpy(a,pair.c_str());
	char* token = strtok(a,",");
			int index=0;
				while (token != NULL) {
					out.push_back(token);
					token = strtok(NULL, ",");
					index++;
				}
	return out;
}

/*
 * Returns the equivalence class as a set object.
 */
SetOfStrings *StringRelation::computeEquivalenceClass(string element){
	int size = this->size();
	SetOfStrings *out = new SetOfStrings();

	if (this-> isEquivalence() == true){
		for (int i = 0; i < size; i++){
			string a = this->returnElement(i);
			vector <string> tokens;
			tokens = makeTokens(a);
			if (tokens[0] == element){
				out->insertElement(tokens[1]);
			}
		}
	}
	return out;
}

/*
 * Returns true if the relation is reflexive.
 * Otherwise, returns false.
 */
bool StringRelation::isReflexive(){
	int x = 0;
	for (int i = 0; i< this->size(); i++){
		string a = this->returnElement(i);
		vector <string> tokens;
		tokens = makeTokens(a);
		if (tokens[0] == tokens[1]){
			x++;
		}
	}
	int b = SetMembers->size();

	if (x == b){
		return true;
	}

	return false;
}

/*
 * Returns true if the relation is symmetric.
 * Otherwise, returns false.
 */
bool StringRelation::isSymmetric(){
	int x = 0;
	int y = 0;
	int size = this->size();
	for (int i = 0; i < size; i++ ){
		string a = this->returnElement(i);
		vector <string> tokens;
		tokens = makeTokens(a);
		if (tokens[0] != tokens[1]){
			x++;

			for (int j = 0; j < size; j++ ){
				string b = this-> returnElement(j);
				vector <string> tokensTwo;
				tokensTwo = makeTokens(b);
				if (tokens[0] == tokensTwo[1] && tokens[1] == tokensTwo[0]){
					y++;
				}
			}
		}
	}
	if (y == x){
		return true;
	}
	return false;

//	int count = 0;
//	int size = this->size();
//	for (int i = 0; i < size; i++ ){
//		string a = this->returnElement(i);
//		vector <string> tokens;
//		tokens = makeTokens(a);
//		if (token[0]==token[1]){
//			count ++;
//		}
//		else {
//			for (int j = 0; j < size; j++ ){
//				string b = this-> returnElement(j);
//				vector <string> tokensTwo;
//				tokensTwo = makeTokens(b);
//
//				if (tokens[0] == tokensTwo[1] && tokens[1] == tokensTwo[0]){
//					count++;
//				}
//
//			}
//		}
//	}
//
//	if (count == this->size()){
//		return true;
//	}
//
//	return false;

}

/*
 * Returns true if the relation is transitive.
 * Otherwise, returns false.
 */
bool StringRelation::isTransitive(){

		int x = 0;
		int y = 0;
		int size = this->size();

			for (int i = 0; i < size; i++ ){
				string a = this->returnElement(i);
				vector <string> tokens;
				tokens = makeTokens(a);


				if (tokens[0] != tokens[1]){
						for (int j= 0; j < size; j++){
							string b = this-> returnElement(j);
							vector <string> tokensTwo;
							tokensTwo = makeTokens(b);

							if (tokens[1] == tokensTwo[0] && tokensTwo[0] != tokensTwo[1]){
								x= x+1;

								for (int k = 0; k < size; k++){
									string c = this-> returnElement(k);
									vector <string> tokensThree;
									tokensThree = makeTokens(c);

									if (tokens[0] == tokensThree[0] && tokensTwo[1] == tokensThree[1]){
										y= y+1;
									}
								}
							}

						}

				}

			}

		if (x==y){
			return true;
		}

		return false;
}

/*
 * Returns true if the relation is the equivalence relation.
 * Otherwise, returns false.
 */
bool StringRelation::isEquivalence(){
	if (isReflexive() == true && isSymmetric() == true && isTransitive() == true){
		return true;
	}
	return false;
}
