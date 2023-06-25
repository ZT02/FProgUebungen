class Basis {
	/*
	Sie wollen eine Klasse Basis schreiben, die im Konstruktor dynamisch Speicher anfordert.

	1)Welche Methoden oder Operatoren m�ssen Sie auf jeden Fall implementieren? Begr�nden Sie Ihre Angaben.

		Es sollte ebenfalls ein Kopierkonstruktor und Zuweisungoperator angelegt werden, damit tiefe Kopien erzeugt werden.
		Ein Konstruktor muss ebenfalls implementiert werden, um die Attribute zu implementieren
		Es k�nenn ebenfalls noch die Standardoperatoren �berschrieben werden, damit diese f�r die Objekte der Basis genutzt werden k�nnen
	
	2) Ihre neue Klasse soll als Basisklasse f�r andere Klassen dienen, die ebenfalls Speicher dynamisch anfordern. M�ssen Sie dieses beim Entwurf der Klasse Basis beachten?
		Wenn ja, was m�ssen Sie dazu machen? Begr�nden Sie Ihre Aussagen.

		Destruktor, evtl. Konstruktor, und methoden mit dem keyword "virtual" versehen, da sonst in Methoden/Konstruktoren die Methoden der Basisklasse verwendet werden in Funktionen und bei der Speicherbereinigung nur
		die Gr��e der Basisklasse beseitigt wird.
		Methoden, die immer nur in der abgeleiteten Klasse Implementiert werden sollen, m�ssen als rein virtuell deklariert werden.

	3) Sie wollen Objekte der Klasse Basis auch direkt in einem Array ablegen. Wie werden die Objekte im Array erzeugt, wenn das Array erzeugt wird?

	Beispiel: Basis array[ 1000 ];
	Basis(...) : array{new Basis()}
				

	4) Wie k�nnen Sie erreichen, dass die Objekte der Klasse Basis in einem Array mit einem allgemeinen Konstruktor initialisiert werden?
		Indem  die entsprechenden Parameter des allgeminen konstruktors hinzugef�gt werden.
		Eventuell standardkonstruktor l�schen
		Expliziter aufruf �ber Bereichsoperator
	*/

};