#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

const int maxCandidates = 10;

string candidates[maxCandidates];
int votes[maxCandidates];

int validVotes = 0;
int invalidVotes = 0;
int CandidateNumber = 0;

bool hasNumber(string str) {
	return (string::npos != str.find_first_of("0123456789"));
};

void readVotes() {
	string str;
	while (getline(cin, str)) {
		if (hasNumber(str)) {
			stringstream ss(str);

			int vote;

			while(ss >> vote) {
				if (vote-1 < CandidateNumber && vote > 0) {
					votes[vote-1] += 1;
					validVotes++;
				} else {
					invalidVotes++;
				}
			}
		} else {
			candidates[CandidateNumber] = str;
			CandidateNumber++;
		}
	}
};

void printResults() {

	int voters = 0;

	cout << "Number of voters: " << invalidVotes+validVotes << endl;
	cout << "Number of valid votes: " << validVotes << endl;
	cout << "Number of spoilt votes: " << invalidVotes << endl;
	cout << left << setw(15) << "Candidate" << "Score" << endl;
	for (int i = 0; i < CandidateNumber; i++) {
		cout << left << setw(15) << candidates[i];
		cout << right << setw(3) << votes[i] << endl;
	}
};

int main() {
  readVotes();
  printResults();
}
