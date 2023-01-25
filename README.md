# Memory-Game
<b>Mein Projekt für das Modul 242</b></br>

<h2><b>DOKUMENTATION</b></h2>

<h3><b>Beschreibung</b></h3>
Dieses Projekt ist ein Spiel, bei welchem man sich Zahlen merken und danach eingeben muss. Das Spiel enthält 20 Level, 
was die Anzahl der zu merkenden Zahlen bestimmt. Beim ersten Level müssen drei Zahlen gemerkt werden und jedes weiteres Level eine Zahl mehr.

<h3><b>Voraussetzungen</b></h3>
Die Hardware, die man für dieses Programm braucht, ist ein Keypad 3x4, das an einen LCD 2x16 keypad Shield angeschlossen ist.
Beides muss an einen Arduino UNO angeschlossen sein. Die Library Liquidcrystal wird benutzt und folgendermassen eingebunden:

`
#include <LiquidCrystal.h>
`

<h3><b>Ablauf</b></h3>

Da das Keypad 3x4 variierende Werte zurückgibt, habe ich zwei Arrays initialisiert, welche pro Button ein min und max Value enthält.
Der erste Zustand GENERATING ist das Generieren und nacheinander Darstellen der ersten zu merkenden Zahlenfolge. Danach geht das Programm in den 
Zustand EXPECTING, wo es die Eingabe des Benutzers erwartet. Die Eingaben werden nach jeder einzeln eingegebenen im Zustand CHECK überprüft.
Bei richtiger Eingabe, wird einfach wieder der Zustand EXPECTING gewählt, wobei bei falscher Eingabe direkt ausgegeben wird, dass die Eingabe
falsch war und der Zustand LOSS aufgerufen wird. Der Zustand LOSS displayt das Level, bei welchem man gescheitert ist und den Score. Anschliessend
wird der Zustand NEWGAME aufgerufen, wo man das Spiel neustarten kann und alle Variabeln zurückgesetzt wird. Wenn man das 20igste Level geschafft
hat (was sehr unwahrscheinlich ist), wird gratuliert und man kann das Spiel neustarten.
