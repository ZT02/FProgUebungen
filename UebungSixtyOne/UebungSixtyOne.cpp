/*
1. Um eine abgeleitete Klasse definieren zu können, muss bekannt sein, wie die Methoden der Basisklasse implementiert sind.
	Falsch, es genügt, ": public OBERKLASSE" nach der Kindklassendeklaration zu schreiben


2. Eine abgeleitete Klasse erbt eine public-Methode der Basisklasse nicht, wenn sie selbst eine public -Methode mit dem gleichen Namen besitzt.
	Falsch, sie bekommt diese public Methode ebenfalls vererbt, außer beide Methoden haben diesselbe Signatur (Name + Parameterliste)

3. In einer abgeleiteten Klasse können nur die Methoden der Basisklasse redefiniert werden.
	(//Korrekt, alles andere wäre eine neue eigene Methode der Kindklasse (Neudefinition).)
	//Falsch, es können ebenfalls Methoden standardmäßiger übergeordneter Klassen redefiniert werden, sowie Operatoren
		Z.B. eine spezialisierte print funktion etc
	Ist ebenfalls abhängig von Zugriffsbeschränkung, private methoden können nicht redefiniert werden.


4. Bei der Definition eines Destruktors einer abgeleiteten Klasse muss der Destruktor der Basisklasse explizit aufgerufen werden.
	Falsch, der Destruktor der Basisklasse muss als "virtual" gekennzeichnet sein
	
5. Der Zugriff auf ein protected-Element einer Klasse X ist möglich innerhalb jeder Methode einer von X abgeleiteten Klasse.
	Korrekt. "Die nachfolgenden Elemente und Methoden sind
in der eigenen und allen public abgeleiteten Klassen
zugreifbar, aber nicht in anderen Klassen oder Funktionen "

*/