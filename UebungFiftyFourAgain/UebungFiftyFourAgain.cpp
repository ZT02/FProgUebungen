#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Message
{
private:
    string   subject;
    string   body;
    vector<string>  recipients;
public:
    Message() {}
    Message(const string& s, const string& b, const vector<string>& r) :
        subject(s), body(b), recipients(r) {}
    const string& getSubject() const { return subject; }
    const string& getBody() const { return body; }
    // andere Methoden...
};

class Mailbox
{
private:
    vector<Message>    messages;
    // ... weitere Elemente
public:
    Mailbox() {}
    Mailbox(vector<Message> hier) : messages{Message(), Message()} {}
    vector<Message>  searchMessageSubjects(const string& subj);
    // ... weitere Elemente
};
class MessageSorter {
public:

    MessageSorter(const string& ref) : saveString(ref) {}
    bool operator()(const Message& input) {
        return input.getSubject().find(saveString) != string::npos;
    }

private:
    string saveString;

};
vector<Message> Mailbox::searchMessageSubjects(const string& subj) {
    vector<Message> results = vector<Message>(messages.size());
   
    auto retIter = std::copy_if(messages.begin(), messages.end(), results.begin(), MessageSorter(subj));
    
    results.resize(distance(results.begin(), retIter));

    sort(results.begin(), results.end(), [=](Message a, Message b) { return a.getSubject() < b.getSubject(); });

        return results;
}




int main() {
    Message one("a", "Hochschule Coburg", vector<string>{"Markus"});
    Message three("abz", "Hallo Pizza-Service", vector<string>{"Anna"});
    Message two("abcd", "Hallo123", vector<string>{"Konstantin"});

    Mailbox test(vector<Message>{ one, two, three });
    vector<Message> output = test.searchMessageSubjects("a");
    for (auto k : output)
        cout << k.getSubject() << endl;
}