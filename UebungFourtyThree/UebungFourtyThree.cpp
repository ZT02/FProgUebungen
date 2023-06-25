class Soundcard
{
private:
    // verschiedene Attribute
    static Soundcard* soundpointer;
    Soundcard();
    Soundcard(const Soundcard& sou) = delete;
public:
    void loadSoundFile(const char* filename);
    void play();
    static Soundcard* instance() {
        if (soundpointer == nullptr) {
            soundpointer = new Soundcard();
            return soundpointer;
        }
        return soundpointer;
    }
    static void del() {
        if (soundpointer)
            delete soundpointer;
        soundpointer = nullptr;
    }
};
/* Standard - und Kopierkonstruktor müssen private sein,
damit 1. Kein Objekt erzeugt werden kann und
2. Damit vom dem Objekt auf den der Pointer zeigt keine Kopie angelegt werden kann*/

int main() {
    Soundcard* a = Soundcard::instance();
    a->del;
}