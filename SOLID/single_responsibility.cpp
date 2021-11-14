#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Journal {
    string title;
    vector<string> entries;

    Journal(const string &title) : title(title) {}

    void add_entry(const string &entry) {
        static int count = 1;
        entries.push_back(std::to_string(count++) + ": " + entry);
    }

//    void save(const string &filename) {
//        ofstream ofs(filename);
//        ofs << title << endl;
//        for (auto &e: entries)
//            ofs << e << endl;
//    }
};

struct PersistenceManager {
    static void save(const Journal &j, const string &filename) {
        ofstream ofs(filename);
        ofs << j.title << endl;
        for (auto &e: j.entries)
            ofs << e << endl;
    }
};

int main() {

    Journal journal{"Dear Diary"};
    journal.add_entry("I ate a bugger");
    journal.add_entry("I cried");
    journal.add_entry("I slept");

//    journal.save("diary.txt");
    PersistenceManager::save(journal, "diary.txt");

    return 0;
}