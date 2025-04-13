# Zasady SOLID

SOLID to akronim opisujący pięć podstawowych zasad projektowania obiektowego, sformułowanych przez Roberta C. Martina (Uncle Bob). Stosowanie tych zasad ma na celu tworzenie kodu, który jest czytelny, łatwy do utrzymania, elastyczny i odporny na błędy. Poniżej przedstawiono poszczególne zasady wraz z krótkim wyjaśnieniem i przykładem.

## S – Single Responsibility Principle (SRP)
**Zasada jednej odpowiedzialności**

Każda klasa powinna mieć tylko jedną odpowiedzialność – czyli jeden powód do zmiany. Odpowiedzialność klasy powinna skupiać się na jednej, ściśle określonej funkcjonalności.

**Przykład:**
- Klasa `UserManager` może być odpowiedzialna wyłącznie za zarządzanie użytkownikami (dodawanie, edytowanie, usuwanie). Natomiast kwestie autoryzacji lub uwierzytelniania powinny być obsługiwane przez osobne klasy (np. `Authenticator`).

## O – Open/Closed Principle (OCP)
**Zasada otwarte/zamknięte**

Moduły (klasy, funkcje) powinny być otwarte na rozszerzenie, ale zamknięte na modyfikację. Oznacza to, że nowe funkcjonalności powinny być dodawane poprzez rozszerzanie istniejących modułów bez konieczności modyfikowania ich kodu.

**Przykład:**
- Zamiast modyfikować istniejącą klasę implementującą logikę przetwarzania danych, lepiej jest stworzyć nową klasę, która rozszerza lub implementuje interfejs, dzięki czemu główny kod nie ulega zmianie.

## L – Liskov Substitution Principle (LSP)
**Zasada podstawienia Liskov**

Obiekty klas pochodnych powinny być w stanie zastąpić obiekty klasy bazowej bez wpływu na poprawność działania programu. Innymi słowy, każda podklasa musi spełniać kontrakt określony przez klasę bazową.

**Przykład:**
- Jeśli klasa `Shape` definiuje metodę `area()`, to zarówno `Rectangle`, jak i `Circle` powinny poprawnie implementować tę metodę. Funkcje operujące na obiektach typu `Shape` (np. funkcja `printArea(const Shape&)`) powinny działać poprawnie, niezależnie od konkretnego typu przekazanego obiektu.

## I – Interface Segregation Principle (ISP)
**Zasada segregacji interfejsów**

Klient nie powinien być zmuszany do zależności od interfejsów, których nie używa. Lepiej jest stosować kilka wyspecjalizowanych interfejsów niż jeden duży, ogólny.

**Przykład:**
- Zamiast definiować jeden duży interfejs `IMultiFunctionDevice`, który zawiera metody `print()`, `scan()`, i `fax()`, lepiej podzielić go na trzy mniejsze interfejsy: `IPrinter`, `IScanner` i `IFax`. Dzięki temu urządzenie, które implementuje tylko funkcję drukowania, nie musi implementować metod skanowania i faksowania.

## D – Dependency Inversion Principle (DIP)
**Zasada odwrócenia zależności**

Moduły wysokiego poziomu nie powinny zależeć od modułów niskiego poziomu. Oba typy modułów powinny zależeć od abstrakcji, a nie od konkretnych implementacji.

**Przykład:**
- Zamiast bezpośrednio używać konkretnej klasy bazy danych, lepiej jest wprowadzić interfejs (np. `IDatabase`) i wstrzykiwać zależność do modułów wyższej warstwy. Dzięki temu, zmiana implementacji bazy danych (np. z MySQL na SQLite) nie wymaga modyfikacji modułu biznesowego, który korzysta z tej abstrakcji.

## Podsumowanie

Stosowanie zasad SOLID przyczynia się do:
- **Lepszej organizacji kodu:** Klasy są podzielone zgodnie z funkcjonalnością, co ułatwia ich zrozumienie i zarządzanie.
- **Łatwego utrzymania:** Modyfikacje w jednym obszarze nie wpływają na inne, co zmniejsza ryzyko błędów.
- **Rozszerzalności:** Nowe funkcje można dodawać poprzez rozszerzanie istniejących interfejsów i klas, bez konieczności modyfikacji już działającego kodu.
- **Testowalności:** Lepsza modularność kodu pozwala na bardziej niezależne testowanie poszczególnych komponentów.

SOLID stanowi fundament, na którym opiera się dobre projektowanie systemów obiektowych, umożliwiając tworzenie elastycznych, skalowalnych i łatwych do utrzymania aplikacji.

