# SOLID Principles

SOLID is an acronym for five basic principles of object-oriented design, formulated by Robert C. Martin (Uncle Bob). Adhering to these principles aims to create code that is readable, maintainable, flexible, and resistant to errors. Below are the individual principles along with brief explanations and examples.

## S – Single Responsibility Principle (SRP)
**Single Responsibility Principle**

Each class should have only one responsibility – meaning one reason to change. A class’s responsibility should focus on one, well-defined functionality.

**Example:**
- A `UserManager` class may be solely responsible for managing users (adding, editing, deleting). In contrast, tasks like authorization or authentication should be handled by separate classes (e.g., an `Authenticator`).

## O – Open/Closed Principle (OCP)
**Open/Closed Principle**

Modules (classes, functions) should be open for extension but closed for modification. This means that new functionalities should be added by extending existing modules without altering their code.

**Example:**
- Rather than modifying an existing class that implements data processing logic, it is better to create a new class that extends or implements an interface, so the core code remains unchanged.

## L – Liskov Substitution Principle (LSP)
**Liskov Substitution Principle**

Objects of derived classes should be able to replace objects of the base class without affecting the correctness of the program. In other words, every subclass must adhere to the contract defined by the base class.

**Example:**
- If a `Shape` class defines an `area()` method, both `Rectangle` and `Circle` should implement this method correctly. Functions operating on objects of type `Shape` (e.g., a function `printArea(const Shape&)`) should work correctly regardless of the specific type of object passed.

## I – Interface Segregation Principle (ISP)
**Interface Segregation Principle**

A client should not be forced to depend on interfaces it does not use. It is preferable to use several specialized interfaces instead of one large, general-purpose interface.

**Example:**
- Instead of defining one large interface `IMultiFunctionDevice` that includes methods for `print()`, `scan()`, and `fax()`, it is better to split it into three smaller interfaces: `IPrinter`, `IScanner`, and `IFax`. This way, a device that only implements printing does not need to provide implementations for scanning and faxing methods.

## D – Dependency Inversion Principle (DIP)
**Dependency Inversion Principle**

High-level modules should not depend on low-level modules. Both should depend on abstractions rather than on concrete implementations.

**Example:**
- Instead of directly using a concrete database class, it is better to introduce an interface (e.g., `IDatabase`) and inject the dependency into higher-level modules. This way, changing the database implementation (e.g., from MySQL to SQLite) does not require modifications in the business logic that uses this abstraction.

## Summary

Adhering to SOLID principles contributes to:
- **Better code organization:** Classes are divided according to functionality, making them easier to understand and manage.
- **Easier maintenance:** Modifications in one area do not affect others, reducing the risk of errors.
- **Extensibility:** New features can be added by extending existing interfaces and classes without modifying already working code.
- **Testability:** Improved modularity of code allows for more independent testing of individual components.

SOLID forms the foundation of good object-oriented system design, enabling the creation of flexible, scalable, and easy-to-maintain applications.
