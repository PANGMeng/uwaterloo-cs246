#include <iostream>
#include <string>
using namespace std;

const int maxFriends = 20;

struct Person{
		string name;
		int numStatus;
		int maxStatus;
		string * status;
		int NumFriends;
		Person * friends[maxFriends];

		Person(std::string name): name(name),numStatus(0),maxStatus(10),
			status(new string[maxStatus]), NumFriends(0){
			for (int i = 0; i < maxFriends; ++i){
				friends[i] = 0;
			}//for
		}

		void increaseStatus(){
			maxStatus *= 2;
			string * temp = new string[maxStatus];
			for(int i = 0; i < numStatus; ++i){
				temp[i] = status[i];
			}
			delete[] status;
			status = temp;
		}

		void notify(Person * p){
			cout << "Notification to " << name << endl;
			cout << p->name << " posted the status: " << p->status[p->numStatus-1] << endl;
		}

		void notifyFriends(){
			for ( int i = 0; i < NumFriends; ++i){
				friends[i]->notify(this);
			}			
		}

		void postStatus(const string & message){
			if ( numStatus == maxStatus ){
				increaseStatus();
			}
			status[numStatus++] = message;
			notifyFriends();
		}

		bool addFriend(Person *p){
			if ( NumFriends < maxFriends){
				friends[NumFriends++] = p;
				p->friends[p->NumFriends++] = this;
				return true;
			}
			return false;
		}

		~Person(){
			delete[] status;
		}
};

int main(){
	Person Alice("Alice");
	Person Bob("Bob");
	Person Charlie("Charlie");
	
	Alice.addFriend(&Bob);
	Alice.postStatus("Hello world");
	Bob.postStatus("ALL THE THINGS");
	Bob.addFriend(&Charlie);
	Bob.postStatus("HAPPY NATIONAL PIZZA WITH EVERYTHING (except anchovies) DAY!");
}
