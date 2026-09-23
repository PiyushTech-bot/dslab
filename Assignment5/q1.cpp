#include <iostream>
#include <string>

using namespace std;

struct Node {
    string songTitle;
    Node* next;

    Node(string title) {
        songTitle = title;
        next = nullptr;
    }
};

class CircularPlaylist {
private:
    Node* tail;
    Node* current;

public:
    CircularPlaylist() {
        tail = nullptr;
        current = nullptr;
    }

    // Adds a song to the tail of the circular list in O(1) time
    void addSong(string songTitle) {
        Node* newNode = new Node(songTitle);
        if (tail == nullptr) {
            tail = newNode;
            tail->next = tail; // Points to itself to form a loop
            current = tail;   // Initialize current to the first song
        } else {
            newNode->next = tail->next; // New node points to head
            tail->next = newNode;      // Old tail points to new node
            tail = newNode;           // Update tail reference
        }
    }

    // Moves current pointer to the next song in O(1) time and plays it
    void playNext() {
        if (tail == nullptr) {
            cout << "Playlist is empty." << endl;
            return;
        }
        current = current->next;
        cout << "Playing: " << current->songTitle << endl;
    }

    ~CircularPlaylist() {
        if (tail == nullptr) return;
        Node* head = tail->next;
        tail->next = nullptr; // Break the circle to safely delete nodes
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main(){
    CircularPlaylist playlist;

    // Simulating sample input execution
    playlist.addSong("Song A");
    playlist.addSong("Song B");
    playlist.addSong("Song C");

    // playNext()
    playlist.playNext();
    playlist.playNext();
    playlist.playNext();
    playlist.playNext(); // Loops back to Song A

    return 0;
}