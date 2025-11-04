## Data structure
- Data structures are ways of organizing and storing data to enable efficient access and manipulation by computers.
- They form the foundation of algorithms, as different data structures are suited for solving different types of problems.
## Classification
### Static Data Structures
- It is a data structure with a fixed memory size and is easier to access.
- The size is determined before the program executes.
- Once established, the capacity cannot be changed (the space for elements cannot be increased or decreased).
- This may result in **wasted memory** or **insufficient capacity**.
- Example:**Array**
### Dynamic Data Structures
- The size of memory is not fixed.
- It can be randomly updated while the program is running, which is efficient given how memory-intensive the code is.
- Memory can be dynamically configured and released during execution.
- Nodes can be added or deleted, and capacity can be adjusted as needed.
- Operations (such as insertion and deletion) require additional metrics and memory management.
- Access speed is usually slower than static structures.
- Example:**Link List**
## Operation
### Core CRUD
- **Insert (Create)**:Add a new data element into the structure.
- **Read (Retrieve)**:Read an existing data element.
- **Update**:Modify or replace an existing data element.
- **Delete**:Remove a specific data element from the structure.
### Basic Operations
- **Access**:Retrieve,read,and write an element at a given index or node position.
- **Traverse**:Visit each element in the data structure sequentially to perform an operation or gather information.
- **Search**:Find the location of a specific element within the data structure.
- **Copy**:Create a duplicate of the data structure, preserving its elements and structure.
- **Swap**:Exchange the positions of two elements within the data structure.
- **Resize**:Adjust the size of the data structure to accommodate more or fewer elements.
- **Initialize**:Set up the data structure with default values or an initial state.
- **Compare**:Evaluate two data structures to determine if they are equal or satisfy specific criteria.
### Static Operations
- **isEmpty**:Check if the structure has no elements.
- **isFull**:Check if the structure has reached its maximum capacity.
- **count / size**:Return the number of elements stored.
- **capacity**:Return the maximum capacity (for fixed-size structures).
- **clear**:Remove all elements but keep the structure allocated.
