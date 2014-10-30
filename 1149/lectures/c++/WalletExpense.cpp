struct Node {
	void swap(Node &t) {
		int tdata = data;
		Node *tnext = next;
		data = t.data;
		next = t.next;
		t.data = tdata;
		t.next = tnext;
	}

	Node & operator=(const Node & o) {
		Node tmp = 0; // copy constructor
		swap(tmp);
		return *this;
	} // tmp is deallocated
};

class Wallet {
	Wallet();
	static Wallet* instance;
	static void cleanup;
public:
	int balance;
	static Wallet* getInstace();
	void addMoney();
};

void Wallet::cleanup() {
	cout << "Cleaning up..." << endl;
	delete instance;
}

Wallet* Wallet::instance = 0; // must initialize
Wallet* Wallet::getInstace() {
	if (!instance) {
		instance = new Wallet;
		atexit(cleanup); // only register cleanup if an instance has been created
	}
	return instance;
}

struct Expense {
	const std::string desc;
	const int amt
	Wallet * wallet;
	Expense(std::string desc, int amt);
	void pay();
};

Expense::Expense(string desc, int amt): desc(desc), amt(amt){
	wallet = Wallet::getInstace();
}

void Expense::pay() {
	cout << "Paying: " << desc << ":" << amt << endl;
	wallet->addMoney(-amt);
}

int main() {
	Expense rent("rent", 1000);
	Expense car("car", 150);
	Expense ins("insurance", 300);
	Wallet* wallet = Wallet::getInstace();
	Expense payCheque("pay", -2000);
	cout << "Initial: " << wallet->balance << endl;
	payCheque.pay();
	car.pay();
	rent.pay();
	car.pay();
	ins.pay();
	...
	cout << "Final: " << wallet->balance << endl;
	return 0;
}
