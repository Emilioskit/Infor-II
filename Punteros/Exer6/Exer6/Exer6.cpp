#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;



struct Date {
	int day;
	int month;
	int year;
};


struct Movie {
	char* Title;
	char* Topic;
	Date premiere; //estructura
};

int main() {
	Movie* list_Movies; //POINTER TO MOVIES STRUCT

	int num_movies;
	cout << "How many movies?";
	cin >> num_movies;

	list_Movies = new Movie[num_movies];

	int opcion;
	int index_movies = 0;//keep track of how many movies we have
	do {
		cout << "\n=== VIDEOCLUB ===\n";
		cout << "1. Add movie\n";
		cout << "2. Show movies\n";
		cout << "3. Erase movie\n";
		cout << "4. Exit\n";
		cout << "    Your Option?";
		cin >> opcion;

		switch (opcion) {
		case 1: //ADD MOVIE
			cout << "Movie Title?";
			char buffer[100]; //REMEBER TO MAKE IT AN ARRAY!!
			cin >> buffer;

			list_Movies[index_movies].Title = new char[strlen(buffer) + 1];
			//makes so that list[i].tittle can hold a char array of length(buffer +1)
			strcpy(list_Movies[index_movies].Title, buffer); //(Location to copy to, string)

			cin.ignore();   // Ignore the newline character left after reading Title
			char buffer2[100]; //REMEBER TO MAKE IT AN ARRAY!!
			cout << "Movie Topic?";
			cin >> buffer2;
			list_Movies[index_movies].Topic = new char[strlen(buffer2) + 1];
			strcpy(list_Movies[index_movies].Topic, buffer2);


			cout << "Release Date?:" << endl;
			cout << "Day?: "; cin >> list_Movies[index_movies].premiere.day;
			cout << "Month?: "; cin >> list_Movies[index_movies].premiere.month;
			cout << "Year?: "; cin >> list_Movies[index_movies].premiere.year;

			index_movies++;
			break;

		case 2: // Show movies
			for (int i = 0; i < index_movies; i++) {
				cout << "\nMovie " << (i + 1) << ":\n";
				cout << "Title: " << list_Movies[i].Title << endl;
				cout << "Topic: " << list_Movies[i].Topic << endl;
				cout << "Release Date: " 
					<< list_Movies[i].premiere.day << "/" 
					<< list_Movies[i].premiere.month << "/" 
					<< list_Movies[i].premiere.year << endl;
			}
			break; // Make sure to add a break here as well

		}

	} while (opcion != 4);


	//free space

	for (int i = 0; i < index_movies;i++) {
		delete[] list_Movies[i].Title;
		delete[] list_Movies[i].Topic;
	}
	delete[] list_Movies;

	return 0;
}