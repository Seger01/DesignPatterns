Gates
    De volgende gates kunnen gesimuleerd worden:
    •	And
    •	Or
    •	Nand
    •	Nor
    •	Xor
    •	Not
    Al deze gates hebben een eigen minimum en maximaal inputs, en specifiek een output.
    Ook zijn er inputs en probes in te stellen om respectieveliek waarden in het circuit 'in te voegen', en waardes uit te lezen. Er is geen theoretisch maximum voor het aantal gates, probes en inputs, maar het is uiteraard wel beperkt door de hoeveelheid geheugen beschikbaar op de uitvoerende computer.

Interface
    De applicatie heeft geen grafische interface. De applicatie kan zonder argumenten aangeroepen worden, waarbij er een default input bestand "inputfile.txt" gebruikt. Er kan ook een argument meegegeven worden, waarbij dat bestand als input wordt gebruikt. Mocht er een fout in het input bestand zitten, zoals bijvoorbeeld een syntax fout of een lus in het opgegeven circuit zal de applicatie dit aangeven.

Propagation delay toevoegen (10 ns)

Ingang en uitgang worden een int. Initialize op -1. Waarde wordt 0/1 bij setten.

inputfile heeft inputs die gedefineerd kunnen worden als "INPUT_HIGH", "INPUT_LOW" of "INPUT". Als er een input waarde "INPUT" is wordt de sim meerdere keren gerund


Design Patterns
    De volgende design patterns zijn er gebruikt:
    - Template method: TextFileToGraph implementeert stappen die gedefnieerd zijn in FileToGraph
    - Strategy: meerdere implementaties onder de FileStrategy interface
    - Singleton: de Circuit klasse is een singleton
    - Factory method: De vertex factory en bijbehorende child classes
    - Observer: de vertex subscribet bij de andere vertices waaraan die verbonden is