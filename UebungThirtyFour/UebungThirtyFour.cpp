01   #ifdef __EMPLOYEE_H__ //Fehler, endif fehlt und eventuell weiter bedingungen

02   #define __EMPLOYEE_H__ 

03
	//public unnötig, aber kein Fehler
04   public class Employee {
	//Aufgrund des Datenkapselungskonzepts müssten diese hier privat sein, + wir haben getter -> private:
	05   int salary = 20000; //Vorgabeparameter in Methodendeklaration

	06   char* name;

	07

		08   public; //Statt Semikolon ein Doppelpunkt

	09   void Employee(int newSalary) { // void weglassen bei Konstruktor, Konstruktoren sind keine Funktionen

		10     salary = newSalary;

		11     name = new char[80];

		12
	} 

	Employee(const Employee& emp) : salary(emp.salary), name(new char* [sizeof(emp.name) / sizeof(*emp.name)]) {
		std::copy(emp.name, emp.name + sizeof(emp.name) / sizeof(*emp.name), name);
	}

	void swap(Employee& anderer)
	{
		using std::swap;
		swap(salary, anderer.salary);
		swap(name, anderer.name);
	}

	Employee& operator=(Employee _emp)
	{
		swap(_emp);
		return *this;
	}

	13	
		// Müssen innerhalb der Klasse stehen
		14   int getSalary() { return salary; }
		//Rückgabewert falsch, müsste Kopie (oder mindestens Zeiger von Name) zurückgeben
		//es muss Name heißen
	15   int getName() { return nane; }

	16
		~Employee() {
		delete[] name;
	}
} // Nach Klassenende Semikolon

17

18   #endif __EMPLOYEE_H__ // müsste unterhalb von #define __EMPLOYEE_H__ stehen, __EMPLOYEE_H__ ('Bezeichner') hier weggelassen