#include <iostream>
#include <memory>
#include <string>

// Define individual interfaces for each responsibility
class IPrinter
{
public:
    virtual void print(const std::string &doc) = 0;
    virtual ~IPrinter() = default;
};

class IScanner
{
public:
    virtual void scan(const std::string &doc) = 0;
    virtual ~IScanner() = default;
};

class IFax
{
public:
    virtual void fax(const std::string &doc) = 0;
    virtual ~IFax() = default;
};

// Implementations with a single responsibility
class Printer : public IPrinter
{
public:
    void print(const std::string &doc) override
    {
        std::cout << "Printing: " << doc << std::endl;
    }
};

class Scanner : public IScanner
{
public:
    void scan(const std::string &doc) override
    {
        std::cout << "Scanning: " << doc << std::endl;
    }
};

class Fax : public IFax
{
public:
    void fax(const std::string &doc) override
    {
        std::cout << "Faxing: " << doc << std::endl;
    }
};

// Composite class that combines the separate responsibilities
// This class adheres to the Single Responsibility Principle by delegating
// each function (print, scan, fax) to its dedicated component.
class MultifunctionDevice
{
public:
    MultifunctionDevice(std::unique_ptr<IPrinter> printer, std::unique_ptr<IScanner> scanner, std::unique_ptr<IFax> fax)
        : printer_(std::move(printer)), scanner_(std::move(scanner)), fax_(std::move(fax)) {}

    void print(const std::string &document)
    {
        printer_->print(document);
    }
    void scan(const std::string &document)
    {
        scanner_->scan(document);
    }
    void fax(const std::string &document)
    {
        fax_->fax(document);
    }

private:
    std::unique_ptr<IPrinter> printer_;
    std::unique_ptr<IScanner> scanner_;
    std::unique_ptr<IFax> fax_;
};

int main()
{
    // Create basic components with single responsibilities:
    auto printer = std::make_unique<Printer>();
    auto scanner = std::make_unique<Scanner>();
    auto fax = std::make_unique<Fax>();

    // Compose a multifunction device from the individual components.
    MultifunctionDevice device(std::move(printer), std::move(scanner), std::move(fax));

    // Each operation is delegated to the component that has the related responsibility.
    device.print("Document A");
    device.scan("Document A");
    device.fax("Document A");

    return 0;
}