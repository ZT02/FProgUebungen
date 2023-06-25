class Basis {
	/*
	Sie wollen eine Klasse Basis schreiben, die im Konstruktor dynamisch Speicher anfordert.

	1)Welche Methoden oder Operatoren müssen Sie auf jeden Fall implementieren? Begründen Sie Ihre Angaben.

		Es sollte ebenfalls ein Kopierkonstruktor und Zuweisungoperator angelegt werden, damit tiefe Kopien erzeugt werden.
		Ein Konstruktor muss ebenfalls implementiert werden, um die Attribute zu implementieren
		Es könenn ebenfalls noch die Standardoperatoren überschrieben werden, damit diese für die Objekte der Basis genutzt werden können
	
	2) Ihre neue Klasse soll als Basisklasse für andere Klassen dienen, die ebenfalls Speicher dynamisch anfordern. Müssen Sie dieses beim Entwurf der Klasse Basis beachten?
		Wenn ja, was müssen Sie dazu machen? Begründen Sie Ihre Aussagen.

		Destruktor, evtl. Konstruktor, und methoden mit dem keyword "virtual" versehen, da sonst in Methoden/Konstruktoren die Methoden der Basisklasse verwendet werden in Funktionen und bei der Speicherbereinigung nur
		die Größe der Basisklasse beseitigt wird.
		Methoden, die immer nur in der abgeleiteten Klasse Implementiert werden sollen, müssen als rein virtuell deklariert werden.

	3) Sie wollen Objekte der Klasse Basis auch direkt in einem Array ablegen. Wie werden die Objekte im Array erzeugt, wenn das Array erzeugt wird?

	Beispiel: Basis array[ 1000 ];
	Basis(...) : array{new Basis()}
				

	4) Wie können Sie erreichen, dass die Objekte der Klasse Basis in einem Array mit einem allgemeinen Konstruktor initialisiert werden?
		Indem  die entsprechenden Parameter des allgeminen konstruktors hinzugefügt werden.
		Eventuell standardkonstruktor löschen
		Expliziter aufruf über Bereichsoperator
	*/

};