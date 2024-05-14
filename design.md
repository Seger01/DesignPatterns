Gates
•	And
•	Or
•	Nand
•	Nor
•	Xor
•	Not
Propagation delay toevoegen (10 ns)
Geen graphical interface
Meerdere probes (op bepaald punt in schakeling waarde kunnen meten)
Meerdere inputs
Child class gaat limieten instellen van inputs 
Singel output
Check dat er geen terugkoppeling in zit

Ingang en uitgang worden een int. Initialize op -1. Waarde wordt 0/1 bij setten.

applicatie krijgt argumenten voor input file
inputfile heeft inputs die gedefineerd kunnen worden als "INPUT_HIGH", "INPUT_LOW" of "INPUT". Als er een input waarde "INPUT" is wordt de sim meerdere keren gerund



De volgende design patterns zijn er gebruikt:
- Template method: TextFileToGraph implementeert stappen die gedefnieerd zijn in FileToGraph
- Singleton: de Circuit klasse is een singleton
- Factory method: De vertex factory en bijbehorende child classes