## How to Install MSYS2 on Windows

MSYS2 is a software distribution and development platform that provides a Unix-like environment on Windows. It includes a package manager (pacman) and popular development tools such as GCC and Make. Follow the steps below to install and set up MSYS2 properly.

1. Download MSYS2

Visit the official website:
https://www.msys2.org

Download the latest installer named msys2-x86_64-xxxxxx.exe.

2. Install MSYS2

Run the installer.

Choose an installation directory (the default C:\msys64 is recommended).

Proceed with the installation by clicking Next until it finishes.

Launch MSYS2 when prompted.

3. Update the System

After the first launch, update the base system.
In the MSYS2 MSYS terminal, run:

pacman -Syu


If MSYS2 asks you to close the window after updating, reopen it and continue with:

pacman -Su


This ensures that all packages are up to date.

4. Install the GCC Compiler

To compile C and C++ programs, install the following package:

pacman -S mingw-w64-ucrt-x86_64-gcc


If you also need Make:

pacman -S mingw-w64-ucrt-x86_64-make

5. Choose the Correct Terminal

MSYS2 provides several terminals. Each has its own purpose:

Terminal	Usage
MSYS	System utilities (not recommended for compiling).
MINGW64	64-bit compiler environment.
UCRT64	Modern runtime and the recommended environment.

To compile programs, open:

MSYS2 UCRT64


Compile C or C++ code:

gcc file.c -o file.exe
g++ file.cpp -o file.exe

6. (Optional) Add MSYS2 to PATH

If you want to use GCC from Windows Command Prompt or PowerShell, add this directory to the system PATH:

C:\msys64\ucrt64\bin


However, this step is optional because it may conflict with other compilers.

7. Verify the Installation

Check whether GCC is working:

gcc --version


If the version information appears, MSYS2 is installed correctly. 
## The problem I encountered
- the main issue I encountered was my limited understanding of hash functions. Because of this, the hash function I initially designed produced outputs that were clustered around certain table sizes, instead of being evenly distributed. This uneven distribution caused frequent collisions, making the hash table less efficient. After reviewing the concept more carefully and analyzing the outputs, I understood the importance of using a well-designed hash function together with an appropriate table size, especially a prime number, to achieve better uniformity.
- Another challenge I faced was my lack of familiarity with GitHub, especially with its Markdown formatting syntax. Because I wasn’t used to writing documents in GitHub’s format, I had difficulty adjusting the layout and organizing the content properly. This led to several formatting issues, such as misaligned tables, inconsistent spacing, and incorrect code block usage. Through practice, I gradually learned how to use Markdown more effectively to create clearer and more readable documentation.  
- The final issue I encountered was that I couldn’t properly edit or run my C and C++ programs in VS Code. After investigating the problem, I realized that my compiler environment had not been set up correctly. Because the necessary tools were missing or misconfigured, my code could not compile or execute as expected. Once I installed and configured the correct toolchain, the programs were able to run normally. 
