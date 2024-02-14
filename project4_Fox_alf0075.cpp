/* COMP 2710 project4_Fox_alf0075.cpp
* Avery Fox alf0075@auburn.edu
* I refered to the skeleton pseudocode structure Dr. Li explained in lecutre on 10/27/23.
* I referenced @https://stackoverflow.com/ many times while debugging / verifying correct syntax for c++.
* FINAL!
*/

#include <iostream>
#include <string>
using namespace std;

// decalring functions + initizlizing varaibles

int questionNum = 0;

struct TriviaNode {

    string question;
    string answer;
    int points;
    TriviaNode *next;
};

typedef TriviaNode* pointerNode;

// prototypes 

void initialQuestionList(pointerNode& questionList);
void questionAdder(pointerNode& questionList);
int questionAsker(pointerNode questionList, int numAsk);
void Unit_Test();

// debug / release version 

#define TRIVIA_QUIZ 

int main() {

    #ifdef TRIVIA_QUIZ
        
         pointerNode nodeList = new TriviaNode;
         initialQuestionList(nodeList);
    

        cout << "*** Welcome to Avery's trivia quiz game ***\n";
        string input;

        // my program will accept "Yes", "yes", "YES", "Y" and "y"

        do {

            questionAdder(nodeList);
            cout << "Continue? (Yes/No): ";

            getline (cin, input);

        } while (input.compare("Yes") == 0 || input.compare("yes") == 0 || input.compare("YES") == 0 || input.compare("Y") == 0 || input.compare("y") == 0);
        cout << endl;


        questionAsker(nodeList, questionNum);
        cout << "*** Thank you for playing the trivia quiz game. Goodbye! ***";
        return 0;
    
}

 
#endif

void initialQuestionList(pointerNode& questionList) {
    pointerNode currentPointer = new TriviaNode;

    // Question 1

	currentPointer->question = "How long was the shortest war on record? (Hint: how many minutes)";
	currentPointer->answer = "38";
	currentPointer->points = 100;
	currentPointer->next = new TriviaNode;

    questionList = currentPointer;
    currentPointer = questionList->next;

    // Question 2

	currentPointer->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
	currentPointer->answer = "Bank of Italy";
	currentPointer->points = 50;
	currentPointer->next = new TriviaNode;
	currentPointer = currentPointer->next;

	// Question 3

	currentPointer->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
	currentPointer->answer = "Wii Sports";
	currentPointer->points = 20;
	currentPointer->next = NULL;

	questionNum += 3;
}

void questionAdder(pointerNode& questionList) {
    pointerNode newPointer = new TriviaNode;

    cout << "Enter a question: ";
    getline(cin, newPointer->question);

    cout << "Enter an answer: ";
    getline(cin, newPointer->answer);

    cout << "Enter award points: ";
    cin >> newPointer->points;

    cin.ignore();
    newPointer->next = NULL;

    TriviaNode* last = questionList;

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newPointer;

    questionNum++;
}

int questionAsker(pointerNode questionList, int numAsk) {

    pointerNode currentPointer = questionList;
    string userAnswer;
    int totalPoints = 0;

    if (questionList == NULL) {
        return 0;
    }

    if (numAsk <= 0) {
        cout << "Warning - the number of trivia to be asked must equal to or be larger then 1." << endl;
        return 1;

    } else if(questionNum < numAsk) {
        cout << "Warning - there is only " << questionNum << " trivia in the list." << endl;
        return 1;

    } else {
        for (int i = 0; i < numAsk; i++) {
            cout << "Question: " << currentPointer->question << endl;
            cout << "Answer: ";

            getline(cin, userAnswer);

            if (userAnswer.compare(currentPointer->answer) == 0) {
                cout << "Your answer is correct. You recieve " << currentPointer->points << " points." << endl;
                totalPoints += currentPointer->points;

            } else {
                cout << "Your answer is wrong. The correct answer is: " << currentPointer->answer << endl;
            }
            cout << "Your total points: " << totalPoints << endl << endl;

            currentPointer = currentPointer->next;
        }
    }

    return 0;
}

#ifdef UNIT_TESTING
    Unit_Test(){
        return 0;
    }

#endif

void Unit_Test() {
    cout << "*** This is a debugging version ***\n";

	// Initialize trivia question 
    
	pointerNode nodeList = new TriviaNode;
	initialQuestionList(nodeList);

	cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
	questionAsker(nodeList, 0);
	cout << "Case 1 passed\n\n";

	cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer." << endl;
	questionAsker(nodeList,1);
	cout << "Case 2.1 passed\n\n";

	cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer." << endl;
	questionAsker(nodeList,1);
	cout << "Case 2.2 passed\n\n";

	cout << "Unit Test Case 3: Ask all the questions of the last trivia in the linked list." << endl;
	questionAsker(nodeList,3);
	cout << "Case 3 passed\n\n";

	cout << "Unit Test Case 4: Ask 5 questions in the linked list." << endl;
	questionAsker(nodeList,5);
	cout << "Case 4 passed\n\n";

	cout << "*** End of the Debugging Version ***";
}


