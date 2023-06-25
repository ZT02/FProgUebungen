//a) In welchen Fällen benötigt eine Klasse einen Kopierkonstruktor ?
// Sobald Objekte mit dynamischer Speicherverwaltung, z.B. Referenzen kopiert werden müssen

// When an object of the class is returned by value.
// When an object of the class is passed(to a function) by value as an argument.
// When an object is constructed based on another object of the same class.
// When the compiler generates a temporary object.
// (own)When an Object with a reference as attribute needs to be copied
// Whenever a copy of the object is needed

//Warum gehört die Klasse Employee aus Aufgabe 34 dazu ?
// char* name; Da Employee eine Referenz beinhaltet -> Tiefe Kopie ist notwendig

// Erweitern Sie die Klasse Employee und geben Sie eine Implementierung für den Kopierkonstruktor von Employee an.
// 
//b) Erweitern Sie die Klasse Employee um einen Zuweisungsoperator nach dem Copy& Swap - Idiom.

//b) In welchen Fällen benötigt eine Klasse einen Destruktor ?
// Wenn Objekte im Heap / dynamischen Speicherbereich erstellt werden, um diese wieder zu entfernen. bzw. Elemente/Attribute im Heap hat.
//When is destructor called ?
//A destructor function is called automatically when the object goes out of scope :
//(1) the function ends
//(2) the program ends
//(3) a block containing local variables ends
//(4) a delete operator is called
// The default destructor works fine unless we have dynamically allocated memory or pointer in class. When a class contains a pointer to memory allocated in class, we should write a destructor to release memory before the class instance is destroyed.
// This must be done to avoid memory leak.
//Warum gehört die Klasse Employee aus Aufgabe 34 dazu ?
// Weil diese eine Referenz als Attribut hat
//Geben Sie eine Implementierung für den Destruktor von Employee an.