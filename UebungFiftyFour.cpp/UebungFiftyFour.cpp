#include <iostream>
#include <vector>
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

class MessageSorter {
private:
    const string& zeichenfolge;

public:
    MessageSorter(const string& zeichen) : zeichenfolge(zeichen) {}
    bool operator()(const Message& message) {
        return strstr(message.getSubject().c_str(), zeichenfolge.c_str());
       
    }

};
bool operator< (const string& m1, const string& m2) {
    return m1.compare(m2);
}
class Mailbox
{
private:
    vector<Message>    messages;
    // ... weitere Elemente
public:
    Mailbox() {}
    Mailbox(vector<Message> temp) : messages(temp){}
    vector<Message>  searchMessageSubjects(const string& subj) {
        vector<Message> resultVec(messages.size());
        
        auto iter  = copy_if(messages.begin(), messages.end(), resultVec.begin(), MessageSorter(subj));
        resultVec.resize(std::distance(resultVec.begin(), iter));
        sort(resultVec.begin(), resultVec.end(), [](Message m1, Message m2) {
            return m1.getSubject() < m2.getSubject().c_str();
            });
        return resultVec;
    }
    // ... weitere Elemente
    vector<Message> getMessages() {
        return messages;
    }
};



int main() {
    Message one("a", "Hochschule Coburg", vector<string>{"Markus"});
    Message three("ab", "Hallo Pizza-Service", vector<string>{"Anna"});
    Message two("abcd", "Hallo123", vector<string>{"Konstantin"});

    Mailbox test(vector<Message>{ one, two, three });
   vector<Message> output =  test.searchMessageSubjects("a");
   for (auto k : output)
       cout << k.getSubject()<<endl;
}