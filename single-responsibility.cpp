#include <iostream>
#include <memory>

// Interfaces
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

class IDevice
{
public:
  virtual std::string getInfo() const = 0;
  virtual ~IDevice() = default;
};

// Implementations
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

class PrintScanDevice : public Printer, public Scanner, public IDevice
{
public:
  std::string getInfo() const override { return "Print & Scan Device"; }
};

class PrintFaxDevice : public Printer, public Fax, public IDevice
{
public:
  std::string getInfo() const override { return "Print & Fax Device"; }
};

int main()
{
  std::unique_ptr<PrintScanDevice> classicPrinter =
      std::make_unique<PrintScanDevice>();
  std::cout << classicPrinter->getInfo() << std::endl;
  classicPrinter->print("Document A");
  classicPrinter->scan("Document A");

  std::unique_ptr<PrintFaxDevice> classicFax =
      std::make_unique<PrintFaxDevice>();
  std::cout << classicFax->getInfo() << std::endl;
  classicFax->print("Document B");
  classicFax->fax("Document B");

  return 0;
}