bin/testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	g++ -o bin/testTableEntry testTableEntry.cpp


bin/testHashTable: testHashTable.cpp Dict.h HashTable.h TableEntry.h
	mkdir -p bin
	g++ -o bin/testHashTable testHashTable.cpp Dict.h HashTable.h TableEntry.h


bin/testBSTree: testBSTree.cpp BSTree.h BSNode.h	
	mkdir -p bin
	g++ -o bin/testBSTree testBSTree.cpp BSTree.h BSNode.h


bin/testBSTreeDict: testBSTreeDict.cpp TableEntry.h BSNode.h BSTreeDict.h  Dict.h	
	mkdir -p bin
	g++ -o bin/testBSTreeDict testBSTreeDict.cpp TableEntry.h BSNode.h BSTreeDict.h  Dict.h


clean:
	rm -rf *.o *.gch bin
