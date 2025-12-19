A programot linux-on a mellékelt makefile segítségével lehet fordítani.

A keretrendszer használatában az első lépés a projektmappa létrehozása, ez a következő paranccsal
tehető meg: bin/spark-build generate <projekt-neve>

A test mappa a zip archívumban egy elkészített példa projektet tartalmaz 2 forrás- és 1 fejlécfájllal.
A test mappába navigálva, a build-keretrendszer fordítása után a következő paranccsal lehet lefordítani 
a példaprojektet: ../bin/spark-build compile
