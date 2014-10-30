#include <iostream>
using namespace std;

struct Rational{
    int numer, denom;
    double toDouble(){
        return (double)numer/denom;
    }

	 Rational operator+(Rational &r){
	 	  Rational temp;
		  temp.numer = this->numer * r.denom + this->denom * r.numer;
		  temp.denom = this->denom * r.denom;
		  return temp;
	 }
	 
	Rational operator-(Rational &r){
	 	  Rational temp;
		  temp.numer = this->numer * r.denom - this->denom * r.numer;
		  temp.denom = this->denom * r.denom;
		  return temp;
	 }

	Rational operator*(Rational &r){
	 	  Rational temp;
		  temp.numer = this->numer * r.numer;
		  temp.denom = this->denom * r.denom;
		  return temp;
	 }
};

ostream& operator<<(ostream& out, const Rational &r){
	out << r.numer << "/" << r.denom;
}

int main(){
  Rational r = {1,2}; // This is an object
  Rational s = {1,3};
  Rational t = r + s;
  cout << r.toDouble() << endl;
  cout << r << endl;
  cout << t << endl;
}
