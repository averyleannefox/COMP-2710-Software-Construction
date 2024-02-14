/* COMP 2710 project2FinalCode.cpp
* Avery Fox alf0075
* I refered to the skeleton pseudocode structure Dr. Li explained in lecutre on 9/21/23.
* I referenced @https://stackoverflow.com/ many times while debugging / verifying correct syntax for c++.
* FINAL!
*/

# include <iostream>
# include <stdlib.h>
# include <assert.h>
# include <ctime>


using namespace std;


// methods

bool at_least_two_alive(bool isAaronAlive, bool isBobAlive, bool isCharlieAlive);
void aaronShoots(bool isBobAlive, bool isCharlieAlive);
void aaronShoots2(bool isBobAlive, bool isCharlieAlive);
void bobShoots(bool isAaronAlive, bool isCharlieAlive);
void charlieShoots(bool isAaronAlive, bool isBobAlive);
void Press_any_key(void);

void test_at_least_two_alive(void);
void TestAaronShoots(bool isBobAlive, bool isCharlieAlive);
void TestAaronShoots2(bool isBobAlive, bool isCharlieAlive);
void TestBobShoots(bool isAaronAlive, bool isCharlieAlive);
void TestCharlieShoots(bool isAaronAlive, bool isBobAlive);

// initilizing variables

const int aaronAccuracy = 33;
const int bobAccuracy = 50;
const int charlieAccuracy = 100;

const int totalTimesRun = 10000;

bool isAaronAlive = true;
bool isBobAlive = true;
bool isCharlieAlive = true;

int aaronWins = 0;
int bobWins = 0;
int charlieWins = 0;
int aaronWins2 = 0;

// main function

int main()
{

    // print statments
    
    cout << "*** Welcome to Avery's Duel Simulator ***\n";

    cout << "Ready to test strategy 1 (run 10000 times):\n";
	Press_any_key();

    cout << "Aaron won " << aaronWins << "/10000 duels or " << static_cast<double>(aaronWins)/10000 * 100 << "%\n"
		 << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins)/10000 * 100 << "%\n"
		 << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins)/10000 * 100 << "%\n"
		 << endl;

        // comparison to Strategy 1 to Strategy 2

         if (aaronWins > aaronWins2) {
		    cout << "Strategy 1 is better than strategy 2.\n";
	    } 
        else {
		    cout << "Strategy 2 is better than strategy 1.\n";
	    }

	    return 0;



// for loop that iterates through the simulation 10000 times

    int i;
    for (i = 1; i <= 10000; i++) {

        //initizling the 'lives' to alive

        isAaronAlive = true;
        isBobAlive = true;
        charlieWins = true;

        // while loop that iterates only if at least two of the plyers are alive

        while (at_least_two_alive(isAaronAlive, isBobAlive, isCharlieAlive)) {
            if (isAaronAlive && at_least_two_alive) {
                aaronShoots(isBobAlive, isCharlieAlive);

                aaronWins++;
            }

            if (isBobAlive && at_least_two_alive) {
                bobShoots(isAaronAlive, isCharlieAlive);

                bobWins++;
            }

            if (isCharlieAlive && at_least_two_alive) {
                charlieShoots(isAaronAlive, isBobAlive);

                charlieWins++;
            }

            if (isAaronAlive && at_least_two_alive) {
                aaronShoots2(isBobAlive, isCharlieAlive);

                aaronWins2++;
            }

            return 0;
        }

    }
}

        // simulation of Aaron shooting with his specific shooting probability

    

        void aaronShoots(bool isBobAlive, bool isCharlieAlive) {


            assert(isBobAlive || isCharlieAlive);

            int shoot = rand() % 100;

            if (isCharlieAlive) {
                if (shoot <= aaronAccuracy) {
                    isCharlieAlive = false;
                }
            }

            if (isBobAlive) {
                if (shoot <= aaronAccuracy) {
                    isBobAlive = false;
                }
        }
        }

        // simulation of Bob shooting with his specific shooting probability

        void bobShoots(bool isAaronAlive, bool isCharlieAlive) {
            assert(isAaronAlive || isCharlieAlive);

            int shoot = rand() % 100;

            if (isAaronAlive) {
                if (shoot <= bobAccuracy) {
                    isAaronAlive = false;
                }
            }

            if (isCharlieAlive) {
                if (shoot <= bobAccuracy) {
                    isCharlieAlive = false;
                }
        }
        }

        // simulation of Charlie shooting with his specific shooting probability

        void charlieShoots(bool isAaronAlive, bool isBobAlive) {
            assert(isAaronAlive || isBobAlive);

            int shoot = rand() % 100;

            if (isAaronAlive) {
                if (shoot <= charlieAccuracy) {
                    isAaronAlive = false;
                }
            }

            if (isBobAlive) {
                if (shoot <= charlieAccuracy) {
                    isBobAlive = false;
                }
        }
        }

        bool at_least_two_alive(bool isAaronAlive, bool isBobAlive, bool isCharlieAlive){
        return false;
        }

        void Press_any_key(void){
        cout << "Press Enter to continue...";
        cin.ignore().get();
        }


        // test case for method 'at least two alive'


        void test_at_least_two_alive(void) {

            bool at_least_two_alive(bool isAaronAlive, bool isBobAlive, bool isCharlieAlive);

            

	cout << "Unit Testing 1: Function – at_least_two_alive()\n";
	// Case 1
	cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(true, true, true));
	cout << "\tCase passed ...\n";
	// Case 2
	cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(false, true, true));
	cout << "\tCase passed ...\n";
	// Case 3
	cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
	assert(true == at_least_two_alive(true, false, true));
	cout << "\tCase passed ...\n";
	// Case 4
	cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
	assert(true == at_least_two_alive(true, true, false));
	cout << "\tCase passed ...\n";
	// Case 5
	cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
	assert(false == at_least_two_alive(false, false, true));
	cout << "\tCase passed ...\n";
	// Case 6
	cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
	assert(false == at_least_two_alive(false, true, false));
	cout << "\tCase passed ...\n";
	// Case 7
	cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(true, false, false));
	cout << "\tCase passed ...\n";
	// Case 8
	cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(false, false, false));
	cout << "\tCase passed ...\n";
}
// test case for method 'arronShoots'

void TestAaronShoots() {

    void aaronShoots(bool isBobAlive, bool isCharlieAlive);

	cout << "Unit Testing 2: Function aaronShoots(isBobAlive, isCharlieAlive)\n";

	// Case 1
	bool isBobAlive = true, isCharlieAlive = true;
	cout << "\tCase 1: Bob alive, Charlie alive\n"
		 << "\t\tAaron is shooting at Charlie\n";
	aaronShoots(isBobAlive, isCharlieAlive);
	assert(true == isBobAlive);

	// Case 2
	isBobAlive = false, isCharlieAlive = true;
	cout << "\tCase 2: Bob dead, Charlie alive\n"
		 << "\t\tAaron is shooting at Charlie\n";
	aaronShoots(isBobAlive, isCharlieAlive);

	// Case 3
	isBobAlive = true, isCharlieAlive = false;
	cout << "\tCase 3: Bob alive, Charlie dead\n"
		 << "\t\tAaron is shooting at Bob\n";
	aaronShoots(isBobAlive, isCharlieAlive);
}

// test case for method 'bobshoots'

void TestBobShoots() {

    void bobShoots(bool isAaronAlive, bool isCharlieAlive);

	cout << "Unit Testing 3: Function bobShoots(isAaronAlive, isCharlieAlive)\n";

	// Case 1
	bool isAaronAlive = true, isCharlieAlive = true;
	cout << "\tCase 1: Aaron alive, Charlie alive\n"
		 << "\t\tBob is shooting at Charlie\n";
	bobShoots(isAaronAlive, isCharlieAlive);

	// Case 2
	isAaronAlive = false, isCharlieAlive = true;
	cout << "\tCase 1: Aaron dead, Charlie alive\n"
		 << "\t\tBob is shooting at Charlie\n";
	bobShoots(isAaronAlive, isCharlieAlive);

	// Case 3
	isAaronAlive = true, isCharlieAlive = false;
	cout << "\tCase 3: Aaron alive, Charlie dead\n"
		 << "\t\tBob is shooting at Aaron\n";
    bobShoots(isAaronAlive, isCharlieAlive);
}

// test case for method 'charlieShoots'

void TestCharlieShoots(){

    void charlieShoots(bool isAaronAlive, bool isBobAlive);

	cout << "Unit Testing 4: Function charlieShoots(isAaronAlive, isBobAlive)\n";

	// Case 1
	bool isAaronAlive = true, isBobAlive = true;
	cout << "\tCase 1: Aaron alive, Bob alive\n"
		 << "\t\tCharlie is shooting at Bob\n";
        charlieShoots(isAaronAlive, isBobAlive);
        assert(false == isBobAlive && true == isAaronAlive);

	// Case 2
	isAaronAlive = false, isBobAlive = true;
	cout << "\tCase 1: Aaron dead, Bob alive\n"
		 << "\t\tCharlie is shooting at Bob\n";
	charlieShoots(isAaronAlive, isBobAlive);
	assert(false == isBobAlive && false == isAaronAlive);

	// Case 3
	isAaronAlive = true, isBobAlive = false;
	cout << "\tCase 3: Aaron alive, Bob dead\n"
		 << "\t\tCharlie is shooting at Aaron\n";
	charlieShoots(isAaronAlive, isBobAlive);
	assert(false == isAaronAlive && false == isBobAlive);
}

// test case for method 'aaronShoots2'

void TestAaronShoots2(){

    void aaronShoots2(bool isBobAlive, bool isCharlieAlive);

	cout << "Unit Testing 5: Function aaronShoots2(isBobAlive, isCharlieAlive)\n";

	// Case 1
	bool isBobAlive = true, isCharlieAlive = true;
	cout << "\tCase 1: Bob alive, Charlie alive\n"
		 << "\t\tAaron intentionally misses his first shot\n"
		 << "\t\tBoth Bob and Charlie are alive.\n";
	aaronShoots2(isBobAlive, isCharlieAlive);
	assert(isBobAlive == true && isCharlieAlive == true);

	// Case 2
	isBobAlive = false, isCharlieAlive = true;
	cout << "\tCase 2: Bob dead, Charlie alive\n"
		 << "\t\tAaron is shooting at Charlie\n";
	aaronShoots2(isBobAlive, isCharlieAlive);

	// Case 3
	isBobAlive = true, isCharlieAlive = false;
	cout << "\tCase 3: Bob alive, Charlie dead\n"
		 << "\t\tAaron is shooting at Bob\n";
	aaronShoots2(isBobAlive, isCharlieAlive);


}

void TestAaronShoots(bool isBobAlive, bool isCharlieAlive)
{
}

void TestAaronShoots2(bool isBobAlive, bool isCharlieAlive)
{
}

void TestBobShoots(bool isAaronAlive, bool isCharlieAlive)
{
}

void TestCharlieShoots(bool isAaronAlive, bool isBobAlive)
{
}

