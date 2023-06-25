#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;
class Stoppuhr {
private:
	time_point<system_clock> startVal = system_clock::time_point();
	time_point<system_clock> stopVal = system_clock::time_point();
	time_point<system_clock> temp = system_clock::time_point() = system_clock::now();

public:
	void Start();
	void Stopp();
	void Zurücksetzen();
	void Zwischenzeit();

};

void Stoppuhr::Start() {
	cout << "Gestartet" << endl;
	startVal = time_point<system_clock>(temp);
	
	
}

void Stoppuhr::Stopp() {
	cout << "Angehalten" <<endl;
	temp = time_point<system_clock>(startVal);
	stopVal = system_clock::now();
	
}

void Stoppuhr::Zurücksetzen() {
	cout << "Zurücksetzen" << endl;
	startVal = system_clock::time_point();
	stopVal = system_clock::time_point();
	
}

void Stoppuhr::Zwischenzeit() {
	
	 stopVal = system_clock::now();
	duration<double, milli> elapsed_time = stopVal - startVal;
	
	int format[4] = {};
	int inInt = (int)elapsed_time.count();
	
	format[0] = ((inInt / (1000*60*60)));
	format[1] = ((inInt / (1000 * 60)));
	format[2] = ((inInt / (1000)));
	format[3] = inInt;
	cout << format[0]<< ":" << format[1]  << ":" << format[2] << ":" << format[3] << endl;
	
}

int main() {
	Stoppuhr uhr;
	bool run = true;
	bool start = false;
	bool stopp = false;
	int choose;
	
	
	
	uhr.Zwischenzeit();
	cout << "[0] Starten" << endl;
	cin >> choose;
	if(choose == 0) {
		stopp = true;
		while (run) {
			if (start) {
				cout << "Funktion:" << endl;
				cout << "[0] Stopp\n[1] Zwischenzeit" << endl;
				cin >> choose;
				switch (choose) {
				case 0:
					uhr.Stopp();
					start = false;
					stopp = true;
					break;
				case 1:
					uhr.Zwischenzeit();
					break;
				default:;
				}
				
			}
			else if (stopp) {
				cout << "Funktion:" << endl;
				cout << "[0] Start\n[1] Zuruecksetzen" << endl;
				cin >> choose;
				switch (choose) {
				case 0:
					uhr.Start();
					start = true;
					stopp = false;
					break;
				case 1:
					uhr.Zurücksetzen();
					break;
				default:;
				}
				

			}
		}



	}
}

//genauigkeit: tausendstelsekunde
//nach 24h neu anfangen
//Ausgabeformat: hh:mm:ss:ttt

/*
die Stoppuhr nur im gestoppten Zustand gestartet oder zurückgesetzt werden kann,
die Uhr nur im gestarteten Zustand gestoppt werden kann,
die Zwischenzeit nur im gestarteten und nicht gestoppten Zustand abgelesen werden kann.
*/