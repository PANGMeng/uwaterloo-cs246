#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

const int maxCandidates = 10;

string candidates[maxCandidates];
int votes[maxCandidates];

bool voteMode = false;
int X = 0;

int validVotes = 0;
int invalidVotes = 0;
int CandidateNumber = 0;

bool hasNumber(string str) {
	return (string::npos != str.find_first_of("0123456789"));
};

void readVotes() {
	string str;
	while (getline(cin, str)) {
		if (str == "") {
			continue;
		}
		if (voteMode || hasNumber(str)) { // If the line is votes
			stringstream ss(str);

			if (false == voteMode) { // If this is the first vote line
				for (int i = 0; i < maxCandidates; ++i) { // Initialize votes for all candidates to 0
					votes[i] = 0;
				}
				voteMode = true;
				if (X == 0) {
					X = CandidateNumber;
				}
			}

			int vote; // Each number - temporarily stores output from string stream
			int lineVotes[CandidateNumber]; // keep track of votes to be added 
			int total = 0;
			int cand = 0;

			while(ss >> vote) { // Collect vote data from tokenized input
				if (vote > 0) {
					lineVotes[cand] = vote;
					total += vote;
				}
				else {
					lineVotes[cand] = 0;
				}
				cand++;
			}

			#ifdef DEBUG
				cerr << "number of Votes = " << total << endl;
				cerr << "X = " << X << endl;
			#endif

			if (total <= X && total > 0 && cand == CandidateNumber) { // Make sure vote is valid
				validVotes++;
				while (cand >= 0) { // Add the stored votes to the tally
					votes[cand] += lineVotes[cand];
					cand--;
				}
				#ifdef DEBUG
					cerr << "Vote: VALID" << endl;
				#endif
			} else {
				invalidVotes++;
				#ifdef DEBUG
					cerr << "Vote: INVALID" << endl;
				#endif
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
	cout << "Number of valid ballots: " << validVotes << endl;
	cout << "Number of spoilt ballots: " << invalidVotes << endl;
	cout << endl;
	cout << left << setw(16) << "Candidate" << "Score" << endl;
	cout << endl;
	for (int i = 0; i < CandidateNumber; i++) {
		cout << left << setw(16) << candidates[i];
		cout << right << setw(3) << votes[i] << endl;
	}
};

int atoi(char* s) {
	int ret = 0;
	if (*s >= '0' && *s <= '9') {
		ret = *s - '0';
		s++;
	}
	else {
		return 0;
	}
	if (*s >= '0' && *s <= '9') {
		ret = 10 * (ret) + (*s - '0');
	}
	return ret;
}

int main(int argc, char* argv[]) {
	if (argc > 1) {
		X = atoi(argv[1]);
	}
	#ifdef DEBUG
		cout << "argc = " << argc << endl;
		cout << "X = " << X << endl;
	#endif
	readVotes();
	printResults();
}
