#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

enum class Relationship {
    parent, child
};

struct Person {
    string name;
};

struct RelationshipBrowser {
    virtual vector<Person> find_all_children_of(const string &name) = 0;
};

struct Relationships : RelationshipBrowser {
    vector<tuple<Person, Relationship, Person>> relations;

    vector<Person> find_all_children_of(const string &name) override {
        vector<Person> result;
        for (auto&&[first, rel, second]: relations)
            if (first.name == name && rel == Relationship::parent)
                result.push_back(second);
        return result;
    }

    void add_parent_and_child(const Person &parent, const Person &child) {
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::parent, parent});
    }
};

struct Research {
//    Research(Relationships &relationships) {
//        auto &relations = relationships.relations;
//        for (auto&&[first, rel, second]: relations)
//            if (first.name == "John" && rel == Relationship::parent)
//                cout << "John has a child called " << second.name << endl;
//    }

    Research(RelationshipBrowser &browser) {
        for (auto &child: browser.find_all_children_of("John"))
            cout << "John has a child called " << child.name << endl;
    }
};

int main() {

    Person parent{"John"};
    Person child1{"Bob"}, child2{"Alice"};

    Relationships relationships;
    relationships.add_parent_and_child(parent, child1);
    relationships.add_parent_and_child(parent, child2);

    Research _(relationships);

    return 0;
}