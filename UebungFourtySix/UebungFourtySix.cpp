template<typename T, int n>
class Stapel
{
public:
	Stapel();
	T pop();
	void push(T);
	bool istLeer();
private:

	int hoehe;
	T speicher[n];
};


Stapel<int, 50> S1, S2;
Stapel<bool, 30> S3;
Stapel<int, 100> S4;
int main() {
	int i = 20.0;
}
/*a) S1.push(20.0); //Korrekt: Der Typ Wert, der gepushed wird ist ein int und typename ist auch int
push(int) -> push(20.0) stimmt überein
b) S2.push(S1.pop()); //Korrekt, s1.pop() returned int Wert, dieser wrid in s2 anschließend gepushed

c) S3.push(S2.istLeer()); // istLeer() liefert bool zurück, s3 akzeptiert bools zum Pushen -> stimmt überein

d) S4 = S1 + S2; //Fehler, Additionsoperator wurde nicht für dieses Objekt definiert // nicht überladen
//Unklar was addiert werden soll

e) S4.push(S1.hoehe); //Fehler, hoehe ist private, darauf kann außerhalb der Klasse/Memberfunktionen nicht zugegriffen werden

*/