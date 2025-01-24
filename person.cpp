
#include "person.h"

istream &getAPersonFromStream(istream &in, Person *person){
	string line;
	if(getline(in, line)) {
		size_t commaPos = line,find(',');
		if (commaPos != string::npos){
			person->name = line.substr(0, commaPos);
			person->age = stoi(line.substr(commaPos + 1));
			return in;
		}
	}
	return in; 
	
}

void sortPersonArrayByAge(Person **arr, int size){
	for (int i = 0; i < size - 1; ++i){
		int minIndex = i;
		for(int j = i + 1; j < size; ++j){
			if(arr[j]->age < arr[minIndex]->age){
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
	}
}
void sortPersonArrayByName(Person **, int);
Person * findAPerson(Person **, int, string); 
void displayAPerson(ostream &, const Person *); 
