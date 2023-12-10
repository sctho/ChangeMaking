*README*

This folder has a ps1 file in it. To run it, navigate to the folder in a powershell terminal, then run:
set-executionpolicy -scope process remotesigned

Then, after you accept, run:

powershell "./ChangeMaking.ps1"

It will run recursive tests 11,23,31,51 for the U.S. system, all tests for the greedy algorithm and dynamic solution for the U.S. system, 
and will run 69 for the weird system on all algorithms. 

To run these files separately, they take 3 arguments. The number you want to test, the size of the coin array, and the coin array, with the format:
d[1,5,...,x]
