### Gates


De volgende gates kunnen gesimuleerd worden:

•	And

•	Or

•	Nand

•	Nor

•	Xor

•	Not

Al deze gates hebben een eigen minimum en maximum inputs, en specifiek een output.
Ook zijn er inputs en probes in te stellen om respectievelijk waarden in het circuit als input te geven, en waardes uit te lezen. Er is geen theoretisch maximum voor het aantal gates, probes en inputs, maar het is uiteraard wel beperkt door de hoeveelheid geheugen beschikbaar op de uitvoerende computer.

### Interface


De applicatie heeft geen grafische interface. De applicatie kan zonder argumenten aangeroepen worden, waarbij er een default input bestand "inputfile.txt" gebruikt. Er kan ook een argument meegegeven worden, waarbij dat bestand als input wordt gebruikt. Mocht er een fout in het input bestand zitten, zoals bijvoorbeeld een syntax fout of een lus in het opgegeven circuit zal de applicatie dit aangeven.

Gebruik bijvoordbeeld "./executable circuit2.txt" om de simulatie te starten met het circuit gedefinieerd in circuit2.txt

Voor elke probe word het maximale propagation delay berekent, waarbij elke gate in de weg van input naar probe 10us
Propagation delay toevoegen (10us)


In de inputfile kunnen inputs gedefineerd worden als "INPUT_HIGH", "INPUT_LOW" of "INPUT". Als de input gedefinieerd is als "INPUT" wordt de sim meerdere keren gerund met een 1 en een 0 als input waarde. 
de uitkomsten van de verschillende input waardes worden apart opgeslagen in het ouput bestand in dit format:


Sim 1

Input:

A: 	0

B: 	0

Output:

S: 	0



### Design Patterns


De volgende design patterns zijn er gebruikt:

- Template method: TextFileToGraph implementeert stappen die gedefnieerd zijn in FileToGraph

- Strategy: meerdere implementaties onder de FileStrategy interface

- Singleton: de Circuit klasse is een singleton

- Factory method: De vertex factory en bijbehorende child klassen

- Observer: de vertex subscribet bij de andere vertices waaraan die verbonden is

- Visitor: de visitor zorgt voor unieke functionaliteit onder de child klassen van de vertices met een universeel interface




### Verkooppunten

- Applicatie werkt(circuit1.txt)

- Applicatie checkt voor loops in circuit definitie(circuit2.txt)

- File parsing heeft robuuste fout detectie(circuit3.txt)
    - Geeft aan welke line de fout bevat(circuit6-10.txt)


- Applicatie checkt voor onverbonden outputs(circuit4.txt)

- Applicatie checkt voor inputs zonder vaste waarde(circuit5.txt)
    - bij een input zonder vaste waarde wordt het circuit gesimuleerd met 1 en 0 als inputwaarde

- Applicatie checkt genoeg inputs per type Gate

- Applicatie berekent de maximale propagationdelay per probe

- Template method: TextFileToGraph implementeert stappen die gedefnieerd zijn in FileToGraph

- Strategy: meerdere implementaties onder de FileStrategy interface

- Singleton: de Circuit klasse is een singleton

- Factory method: De vertex factory en bijbehorende child klassen

- Observer: de vertex subscribet bij de andere vertices waaraan die verbonden is

- Visitor: de visitor zorgt voor unieke functionaliteit onder de child klassen van de vertices met een universeel interface

- Cppcheck en valgrind memcheck uitgevoerd

- Doxygen comments toegevoegd

- Klassen diagram gemaakt

- Sequence diagram gemaakt


