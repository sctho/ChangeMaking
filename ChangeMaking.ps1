g++ ./GreedyChangeAlgorithm.cpp -o GreedyChangeAlgorithm.exe
g++ ./RecursiveChangeMaking.cpp -o RecursiveChangeMaking.exe
g++ ./DynamicChangeMaking.cpp -o DynamicChangeMaking.exe

Write-Host "U.S. Recursive Change Making: "
./RecursiveChangeMaking.exe 11 4 d[1,5,10,25]
./RecursiveChangeMaking.exe 23 4 d[1,5,10,25]
./RecursiveChangeMaking.exe 31 4 d[1,5,10,25]
./RecursiveChangeMaking.exe 51 4 d[1,5,10,25]

Write-Host "`nU.S. Greedy Change Making: "
./GreedyChangeAlgorithm.exe 11 4 d[1,5,10,25]
./GreedyChangeAlgorithm.exe 23 4 d[1,5,10,25]
./GreedyChangeAlgorithm.exe 31 4 d[1,5,10,25]
./GreedyChangeAlgorithm.exe 51 4 d[1,5,10,25]
./GreedyChangeAlgorithm.exe 73 4 d[1,5,10,25]
./GreedyChangeAlgorithm.exe 83 4 d[1,5,10,25]
./GreedyChangeAlgorithm.exe 91 4 d[1,5,10,25]
./GreedyChangeAlgorithm.exe 99 4 d[1,5,10,25]

Write-Host "`nU.S. Dynamic Change Making: "
./DynamicChangeMaking.exe 11 4 d[1,5,10,25]
./DynamicChangeMaking.exe 23 4 d[1,5,10,25]
./DynamicChangeMaking.exe 31 4 d[1,5,10,25]
./DynamicChangeMaking.exe 51 4 d[1,5,10,25]
./DynamicChangeMaking.exe 73 4 d[1,5,10,25]
./DynamicChangeMaking.exe 83 4 d[1,5,10,25]
./DynamicChangeMaking.exe 91 4 d[1,5,10,25]
./DynamicChangeMaking.exe 99 4 d[1,5,10,25]

Write-Host "`nWeird Recursive Change Making: "

./RecursiveChangeMaking.exe 69 5 d[1,5,10,23,25]

Write-Host "`nWeird Greedy Change Making: "
./GreedyChangeAlgorithm.exe 69 5 d[1,5,10,23,25]

Write-Host "`nWeird Dynamic Change Making: "
./DynamicChangeMaking.exe 69 5 d[1,5,10,23,25]

