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

void my_strcpy(char* destination, const char* source) { 

	// Arrays "decay" to pointers when passed to functions:
	// if we pass char buffer[100], it automatically becomes &buffer[0].
	// So this function accepts both char arrays and char* because
	// it only receives the address of the first character.

	int i = 0;
	while (*(source + i) != '\0') { //mientras no vea el null terminator
		*(destination + i) = *(source + i); //copiamos el dato
		i++;
	}
	*(destination + i) = '\0';
}

//void my_strcpy(char destination[], const char source[])
//{
//	int i = 0;
//	while (source[i] != '\0') {
//		destination[i] = source[i];
//		i++;
//	}
//	destination[i] = '\0';
//}

int main() {

	int num_movies;
	cout << "How many movies? ";
	cin >> num_movies;
	cin.ignore();

	Movie* list_Movies; 
	//list_Movies is a pointer to a movie (in stack). “This variable holds the address where a Movie lives.”

	list_Movies = new Movie[num_movies]; 
	// allocate an array of Movie structs in the heap and store the address of the first element in the pointer
	//list_Movies[index] == * (list_movies + index)

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
		cin.ignore();

		switch (opcion) {
		case 1: //ADD MOVIE
			cout << "Movie Title?: ";
			char buffer[100]; //REMEBER TO MAKE IT AN ARRAY!!
			
			cin.getline(buffer, 100);
	

			// allocate heap memory for the title string (exact length of buffer + 1 for the '\0')
			list_Movies[index_movies].Title = new char[strlen(buffer) + 1];
			//new returns address of first slot of heap memory

			my_strcpy(list_Movies[index_movies].Title, buffer); 
			//strcpy(list_Movies[index_movies].Title, buffer); //(Location to copy to (address), string)
			
			

			char buffer2[100]; //REMEBER TO MAKE IT AN ARRAY!!
			cout << "Movie Topic?: ";
			cin.getline(buffer2, 100);

			list_Movies[index_movies].Topic = new char[strlen(buffer2) + 1];
			my_strcpy(list_Movies[index_movies].Topic, buffer2);


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

		case 3:
			//1 -> delete movie in x index
			cout << "Number of movie you want to delete?";
			int index_to_delete;
			cin >> index_to_delete;
			index_to_delete = index_to_delete - 1; //???

			//free memory of heap that we are no longer using
			delete[] list_Movies[index_to_delete].Title;
			delete[] list_Movies[index_to_delete].Topic;
			//do I delete de date? is it necessary?
			

			//2 -> copy the last movie(index_movies) to where the other on was (index_to_delete)

			int last = index_movies - 1; // index of the last valid movie

			//reserver memory for the length that is the one that im copying
			if (index_to_delete != last) {
				// Copy last into the deleted slot
				list_Movies[index_to_delete].Title = new char[strlen(list_Movies[last].Title) + 1];
				list_Movies[index_to_delete].Topic = new char[strlen(list_Movies[last].Topic) + 1];
				my_strcpy(list_Movies[index_to_delete].Title, list_Movies[last].Title);
				my_strcpy(list_Movies[index_to_delete].Topic, list_Movies[last].Topic);
				list_Movies[index_to_delete].premiere = list_Movies[last].premiere;

				// Only now free the last slot (its data was copied)
				delete[] list_Movies[last].Title;
				delete[] list_Movies[last].Topic;
				list_Movies[last].Title = nullptr;
				list_Movies[last].Topic = nullptr;
			}
			// if index_to_delete == last, we already freed it above, nothing else to do
			
			

			//3 -> substract from index
			index_movies--;


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