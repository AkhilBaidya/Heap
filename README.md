# Heap
Making a max heap! (a binary tree where every child node is smaller than its parent node)

This program creates a max heap that can store a max of 100 integers. The user can ADD to the heap, DELETE from it, DELETE_ALL, PRINT the heap, and QUIT the program.

1. ADD: After inputting this command, the user will be prompted to manually input values or input values into the heap from a file. In the manual input, the user can input up to 100 integers (must be non-negative, ideally a range between 1 and 1000 inclusive for each number) into the heap. In the file input, the user inputs the name of a file whose numbers (same criteria, up to 100 of such numbers) are put into the heap.

-> Note: Please input commands capitalized (exactly as the computer directs) in order for them to be recognized. Additionally, use the full name of files (for "num.txt" use "num.txt" not "num")

3. DELETE: After inputting this command, the root (largest element of the heap) will be deleted from the heap and printed out.

4. DELETE_ALL: In this command, delete is called repeatedly until the heap is empty (a value of -5 for a spot in the heap represents emptiness).

5. PRINT: After inputting this command, the heap is printed out in the form of a binary tree (with parents larger than their children), which is sideways.

6. QUIT: After inputting this command, the program will end.
