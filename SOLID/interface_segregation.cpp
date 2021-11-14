using namespace std;

struct Document;

struct IPrinter {
    virtual void print(Document &doc) = 0;
};

struct IScanner {
    virtual void scan(Document &doc) = 0;
};

struct IMachine : IPrinter, IScanner {
};

struct Machine : IMachine {
    IPrinter &printer;
    IScanner &scanner;

    Machine(IPrinter &printer, IScanner &scanner) : printer(printer), scanner(scanner) {}

    void print(Document &doc) override {
        printer.print(doc);
    }

    void scan(Document &doc) override {
        scanner.scan(doc);
    }
};

int main() {
    return 0;
}