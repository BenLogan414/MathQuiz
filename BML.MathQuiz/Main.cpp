
// Assignment 5 - Math Quiz
// Benjamin Logan

#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	// Define file paths
	string questionsPath = "C:\\temp\\Questions.txt";
	string resultsPath = "C:\\temp\\QuizResults.txt";

	// Open the input and output streams, passing in their respective file paths
	ifstream ifs(questionsPath);
	ofstream ofs(resultsPath);

	// Create an array to hold the questions
	string questions[10];
	int idx = 0;

	// Store questions into an array
	while (getline(ifs, questions[idx]) && idx < 10)
	{
		idx++;
	}

	// All the questions have been read, we are done with the input stream
	ifs.close();

	srand(time(NULL)); // initialize the random number generator

	cout << "Welcome to the Math Quiz!" << "\n" << " \n";
	
	// i < 3 - Only iterating through the loop 3 times to ask 3 questions
	for (int i = 0; i < 3; i++)
	{
		// Create a variable to store the answer
		int answer;

		// Generate a random number
		int randomNumber = rand() % 10;
		
		// Ask the question, read in from the array with index of randomNumber
		// The array has already read in all of the questions!
		cout << "Question " << i + 1 << ": " << questions[randomNumber] << " = ";
		cout << "\nEnter your answer: ";
		// Store the answer
		cin >> answer;

		// Output the answers to output stream - going into QuizResults.txt file
		ofs << questions[randomNumber] << " = " << answer << " \n";
		cout << " \n";
	}

	// All questions have been asked and all answers have been recorded into output file
	// We are done with the output stream
	ofs.close();

	// Confirm with user that the results have been saved to the output file
	cout << "Results saved to QuizResults.txt";

	(void)_getch();
	return 0;
}