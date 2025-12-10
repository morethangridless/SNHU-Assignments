# SNHU-Assignments
SNHU Assignments
# Corner Grocer Item Frequency Tracker – CS210 Project Three

**Course:** CS 210 – Programming Languages  
**Language:** C++  
**IDE:** Microsoft Visual Studio 2022  

## Project Summary
This console application helps the Corner Grocer analyze daily sales by reading a list of purchased items from `CS210_Project_Three_Input_File.txt`.
It counts how often each item was bought, displays the data in three different ways, and automatically creates and updates a backup file called `frequency.dat`
every time the program runs.

Users get a clean menu with four options:
1. Search for how many times a specific item was purchased today  
2. See a numbered list of all items and their frequencies  
3. View a text-based histogram using asterisks  
4. Exit

## What I Did Particularly Well
- Strong object oriented design using a `GroceryTracker` class with full encapsulation  
- Automatic creation/overwriting of `frequency.dat` with zero user interaction  
- Professional user experience: screen clearing, input validation, “Press Enter to continue…” prompts, and consistent formatting  
- Cross platform compatibility (Windows, Mac, Linux) using preprocessor directives

## Possible Enhancements
- Add case insensitive search (e.g., “cranberries”  finds “Cranberries”)  
- Trim whitespace and handle common typos automatically   
These would improve usability in a real store environment without changing core functionality.

## Most Challenging Pieces & How I Overcame Them
- Getting `frequency.dat` to appear reliably. Learned that Visual Studio runs the .exe from `x64\Debug`, so the input file must be copied there  
- Robust menu input used `cin.fail()`, `cin.clear()`, and `numeric_limits` to handle letters/symbols gracefully  
- Clean screen between menus implemented cross-platform `clearScreen()` function  

Resources added to my toolkit: GitHub, Visual Studio, and the zyBooks C++ sections.

## Transferable Skills Gained
- Mastery of `std::map` for frequency counting and sorted output  
- File input/output in constructors  
- Separation of concerns (class does data, `main()` does UI)  
- Professional commenting and code organization  
- Defensive programming and input validation

## How I Made the Program Maintainable, Readable, and Adaptable
- Clear class structure with private data and public interface  
- Meaningful function and variable names  
- Section headers and inline comments explaining purpose  
- All magic strings and file names are `const` members easy to change  
- Code is modular: adding new menu options or output formats would be trivial
