#include <iostream>
#include <map>
#include <string>
using namespace std;

class Dictionary {
private:
    map<string, string> words;

    void preloadWords() {
        words = {
            {"apple"," 	  A fruit that keeps the doctor away."},
            {"banana","   A long, curved fruit with a yellow skin."},
            {"cat"," 	  A small domesticated carnivorous mammal."},
            {"dog","	  A domesticated carnivorous mammal often kept as a pet."},
            {"elephant"," The largest land animal with a trunk."},
            {"flower","   The reproductive structure in flowering plants."},
            {"grape","    A small, round fruit used to make wine."},
            {"house","    A building for human habitation."},
            {"india","    A country in South Asia."},
            {"joy","      A feeling of great happiness."},
            {"kite","     A toy flown in the air at the end of a string."},
            {"love","     An intense feeling of deep affection."},
            {"music","    Vocal or instrumental sounds combined in harmony."},
            {"night","    The period of darkness in each 24 hours."},
            {"orange","   A citrus fruit with a tough orange skin."},
            {"peace","    Freedom from disturbance; tranquility."},
            {"queen","    The female ruler of an independent state."},
            {"river","    A large, flowing body of water."},
            {"school","   An institution for educating children."},
            {"tea","      A hot drink made by infusing tea leaves in water."},
            {"umbrella"," A device used for protection against rain."},
            {"victory","  An act of defeating an opponent."},
            {"water","    A transparent, tasteless liquid essential for life."},
            {"yoga","     A spiritual and physical discipline for health."},
            {"zebra","    An African wild animal with black-and-white stripes."},
            {"air","      The invisible mixture of gases we breathe."},
            {"book","     A set of written or printed pages bound together."},
            {"car","      A road vehicle with an engine and four wheels."},
            {"door","     A movable barrier used to open or close an entrance."},
            {"earth","    The planet we live on."},
            {"fire","     The heat and light produced by combustion."},
            {"glass","    A hard, brittle substance typically transparent."},
            {"heart","    The organ that pumps blood in the body."},
            
            // Add more words as needed 
        };
    }

public:
    Dictionary() {
        preloadWords();
    }

    void addWord() {
        string word, meaning;
        cout << "Enter the word: ";
        cin.ignore();
        getline(cin, word);
        cout << "Enter the meaning: ";
        getline(cin, meaning);
        words[word] = meaning;
        cout << "Word added successfully.\n";
    }

    void displayAllWords() {
        if (words.empty()) {
            cout << "The dictionary is empty.\n";
            return;
        }
        cout << "\n=== Dictionary Words ===\n";
        for (const auto& entry : words) {
            cout << entry.first << ": " << entry.second << endl;
        }
    }

    void searchWord() {
        string word;
        cout << "Enter the word to search: ";
        cin.ignore();
        getline(cin, word);
        auto it = words.find(word);
        if (it != words.end()) {
            cout << "Meaning of '" << word << "': " << it->second << endl;
        } else {
            cout << "Word not found in the dictionary.\n";
        }
    }

    void removeWord() {
        string word;
        cout << "Enter the word to remove: ";
        cin.ignore();
        getline(cin, word);
        if (words.erase(word)) {
            cout << "Word removed successfully.\n";
        } else {
            cout << "Word not found in the dictionary.\n";
        }
    }
};

int main() {
    Dictionary dict;
    int choice;

    do {
        cout << "\n=== Dictionary App ===\n";
        cout << "1. Add Word\n";
        cout << "2. View All Words\n";
        cout << "3. Search for a Word\n";
        cout << "4. Remove Word\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                dict.addWord();
                break;
            case 2:
                dict.displayAllWords();
                break;
            case 3:
                dict.searchWord();
                break;
            case 4:
                dict.removeWord();
                break;
            case 5:
                cout << "Thank you for using the Dictionary App. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

