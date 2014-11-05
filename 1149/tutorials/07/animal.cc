#include <iostream>
#include <string>

using namespace std;

struct Animal{
   void Noise(){
      cout << "Animal Noise" << endl;
   }
   virtual void virtualNoise(){
      cout << "Generic Animal Noise" << endl;
   }
};

struct Dog: public Animal{
   void Noise(){
     cout << "Woof" << endl;
   }
};

struct Cat: public Animal{
   virtual void virtualNoise(){
      cout << "Purr" << endl;
   }
};

struct Lion: public Cat{
   void Noise(){
		cout << "ROAR" << endl;
	}
};

struct Fish: public Animal{
	void Noise(){
		cout << "Glub glub" << endl;
	}
};

struct Whale: public Fish{
	virtual void virtualNoise(){
		cout << "WWWWWWWAAAAAALLLLLLLLLLLOOOOOOOOOOOOO" << endl;
	}
};

struct Fox: public Animal{
	virtual void virtualNoise(){
		cout << "egrep \"^A([RD]ING)+$\"" << endl;
	}
};

struct Shark: public Fish{
	virtual void virtualNoise(){
		cout << "Fish are friends not food" << endl;
	}
	void Noise(){
		cout << "DaaaaaaaaaaaNum" << endl;
		cout << "DaaaaaaaaaaaNum" << endl;
		cout << "DaaaaNum" << endl;
		cout << "DaaaaNum" << endl;
		cout << "DaNum DaNum" << endl;
	}
};

int main(){
	Animal A;
	cout << "Animal" << endl;
	A.Noise();				// calls Animal Noise()
	A.virtualNoise();    // calls Animal virtualNoise()
	cout << endl << "Dog" << endl;
   Dog D;
	D.Noise();				// calls Dog Noise()
	D.virtualNoise();		// calls Dog virtualNoise()

	cout << endl << "Cat" << endl;
	Cat C;
	C.Noise();				// calls Cat Noise()
	C.virtualNoise();		// calls Cat virtualNoise()

	cout << endl << "Lion" << endl;
	Lion L;
	L.Noise();				// calls Lion Noise()
	L.virtualNoise();		// calls Lion virtualNoise()

	cout << endl << "Fish" << endl;
	Fish F;
	F.Noise();				// calls Fish Noise()
	F.virtualNoise();		// calls Fish virtualNoise()
	
	cout << endl << "Whale" << endl;
	Whale W;
	W.Noise();				// calls Whale Noise()
	W.virtualNoise();		// calls Whale virtualNoise()

	cout << endl << "Shark" << endl;
	Shark S;
	S.Noise();				// calls Shark Noise()
	S.virtualNoise();		// calls Shark virtualNoise()
	
	cout << endl << "Fox" << endl;
	Fox Fo;
	Fo.Noise();				// calls Fox Noise()
	Fo.virtualNoise();		// calls Fox virtualNoise()
	#ifdef POINTERS
	// Fill in which noises are which
	Animal * pA = &D;

	cout << endl << "Animal Pointer to Dog" << endl;
	pA->Noise();			// calls Animal Noise()
	pA->virtualNoise();

	cout << endl << "Animal Pointer to Cat" << endl;
	pA = &C;
	pA->Noise();
	pA->virtualNoise();

	cout << endl << "Animal Pointer to Lion" << endl;
	pA = &L;
	pA->Noise();
	pA->virtualNoise();

	cout << endl << "Animal Pointer to Fish" << endl;
	pA = &F;
	pA->Noise();
	pA->virtualNoise();

	cout << endl << "Animal Pointer to Whale" << endl;
	pA = &W;
	pA->Noise();
	pA->virtualNoise();
	
	cout << endl << "Animal Pointer to Shark" << endl;
	pA = &S;
	pA->Noise();
	pA->virtualNoise();

	cout << endl << "Animal Pointer to Fox" << endl;
	pA = &Fo;
	pA->Noise();
	pA->virtualNoise();

	cout << endl << "Cat Pointer to Lion" << endl;
	Cat * pC = &L;
	pC->Noise();
	pC->virtualNoise();
	
	cout << endl << "Fish Pointer to Whale" << endl;
	Fish * pF = &W;
	pF->Noise();
	pF->virtualNoise();
	#endif
}	
