# slist. 

Grocery List Manager
Description
This C++ program reads a list of grocery items from a file (grocery.dat) and stores them in a linked list. It allows users to view the list, delete an item, and display the updated list. The program maintains the original order of items as they appear in the file.

Features
Reads grocery items from grocery.dat and stores them in a linked list.

Displays the list of items.

Allows the user to delete an item from the list.

Handles cases where the list is empty or the item is not found.

Releases allocated memory when the program exits.

File Format (grocery.dat)
The file should contain a list of grocery items, one per line, like this:

nginx
Copy
Edit
milk
egg
apple
banana
bread
pepper
chips
icecream
candy
onion
cake
How the Code Works
Reads the file: The program reads grocery.dat line by line and inserts each item into a linked list.

Displays the list: The items are printed in the same order they appear in the file.

User Input: The user is prompted to enter an item to delete.

Deletes the item (if found) and displays the updated list.

Handles edge cases: If the list is empty or the item is not found, it displays an appropriate message.

How to Compile and Run
Compile the program
bash
Copy
Edit
g++ grocery_list.cpp -o grocery_list
Run the program
bash
Copy
Edit
./grocery_list
Ensure grocery.dat is in the same directory as the executable.

Sample Output (Bash Terminal Run)
Given grocery.dat:
nginx
Copy
Edit
milk
egg
apple
banana
bread
pepper
chips
icecream
candy
onion
cake
Program Execution
bash
Copy
Edit
$ ./grocery_list
The list of items are:

milk
egg
apple
banana
bread
pepper
chips
icecream
candy
onion
cake

Enter an item to be deleted from the list: banana
banana deleted from the list.

The updated list is:

milk
egg
apple
bread
pepper
chips
icecream
candy
onion
cake
Edge Cases Handled
If the file is empty → "The list is empty."

If the item is not found → "Item is not in the list."

If the first item is deleted → The head of the list is updated.

If the last item is deleted → The previous item’s next pointer is updated to NULL.

Memory Management
Dynamically allocated nodes are properly deallocated using ReleaseList before the program exits.
