#include <iostream>
#include <string>

class IPrinter
{
public:
    virtual void print(const std::string &document) = 0;
    virtual ~IPrinter() = default;
};

class IScanner
{
public:
    virtual void scan(const std::string &document) = 0;
    virtual ~IScanner() = default;
};

class IFax
{
public:
    virtual void fax(const std::string &document) = 0;
    virtual ~IFax() = default;
};

// Multi-function device implementing printing, scanning, and faxing
class MultiFunctionPrinter : public IPrinter, public IScanner, public IFax
{
public:
    void print(const std::string &document) override
    {
        std::cout << "MultiFunctionPrinter Printing: " << document << std::endl;
    }
    void scan(const std::string &document) override
    {
        std::cout << "MultiFunctionPrinter Scanning: " << document << std::endl;
    }
    void fax(const std::string &document) override
    {
        std::cout << "MultiFunctionPrinter Faxing: " << document << std::endl;
    }
};

// Simple printer that only implements printing
class SimplePrinter : public IPrinter
{
public:
    void print(const std::string &document) override
    {
        std::cout << "SimplePrinter Printing: " << document << std::endl;
    }
};

int main()
{
    MultiFunctionPrinter mfp;
    SimplePrinter sp;

    // MultiFunctionPrinter can print, scan, and fax documents
    mfp.print("Document 1");
    mfp.scan("Document 1");
    mfp.fax("Document 1");

    // SimplePrinter only implements the IPrinter interface
    sp.print("Document 2");

    return 0;
}