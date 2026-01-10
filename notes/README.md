# 公告

課程資料：資料結構講義。

AI輔助：本內容由ChatGPT和Gemini AI協助進行綜合和整理。

製作方式:我將講義讀過一遍後先把不會的概念詢問AI，完全理解後把用自己的話給AI進行整理，分成不同的資料結構類型將筆記分別放入，最後再藉由小考和作業找出錯誤的地方，把錯題的概念作入筆記中。

# Data Structures notes
這個資料夾包含了這堂課所學習的所有資料學習筆記，裡面包括:
- **Array**
- **Linklist**
- **Stacks & Queues**
- **Hashing**
- **Trees**
- **Heap**
- **Graph**
筆記涵蓋**定義、核心操作、C 語言範例、比較分析，以及時間複雜度**。
## Contents
### Introduction.md
#### 基本介紹
- 是用來組織與儲存資料的方法，讓電腦可以更有效率地存取、修改與管理資料，也是各種演算法的基礎。
#### 分類
- **ic Data Structures（靜態資料結構）**
- **Dynamic Data Structures（動態資料結構）**
#### 操作
- **核心操作（CRUD）**
- **基本操作**
- **靜態結構常見操作**

### ADT.md
#### 基本介紹
  - 一組可使用的 操作（Operations）
  - 資料的 抽象數學模型
#### 實際應用
  - STL 提供多種 ADT，如：
    - vector
    - list
    - stack
    - queue
  -使用者只需知道操作方式與行為不需要了解內部實作
### Array.md
#### 定義
  - 線性資料結構
  - 相同型態元素
  - **連續記憶體**
  - 以 **索引（index）** 存取
#### ADT
  - access
  - update
  - insert
  - delete
  - traverse
#### 時間複雜度
  - 存取 / 修改：O(1)
  - 走訪：O(n)
  - 搜尋
    - 未排序：O(n)已排序
    - 已排序（二分）：O(log n)
  - 插入 / 刪除（非尾端）：O(n)
#### 空間複雜度
  - 儲存空間：O(n)
  - 儲存空間：O(n)
  - 大小通常固定（可能浪費或不足）
#### 排序法
  - Bubble Sort：O(n²)
  - Selection Sort：O(n²)
  - Insertion Sort：O(n²)（近乎排序時快）
### LinkedList.md
#### 定義
- 線性資料結構  
- 由多個 **節點（Node）** 組成  
- 每個節點包含：
  - **Data**（資料）
  - **Pointer / Next**（指向下一個節點）
- **非連續記憶體**
- 透過指標將節點串接起來

#### 特點
- 大小可 **動態調整**
- 插入、刪除效率高（不需搬移其他資料）
- **無法用索引直接存取**
- 每個節點需額外儲存指標（記憶體成本較高）

#### 時間複雜度
- 存取（Access）：**O(n)**
- 走訪（Traverse）：**O(n)**
- 搜尋（Search）：**O(n)**
- 插入（Insert）：
  - 已知位置：**O(1)**
  - 需先搜尋：**O(n)**
- 刪除（Delete）：
  - 已知位置：**O(1)**
  - 需先搜尋：**O(n)**
### Stack & Queue.md
#### Stack

#### 定義
- 遵循 **LIFO（Last In, First Out）**
- 只能在 **同一端（Top）** 進行操作


#### 特點
- 後進先出
- 操作位置固定（Top）
- 常用於遞迴、函式呼叫、運算式處理


#### 基本操作
- `push`：加入元素到頂端
- `pop`：移除頂端元素
- `peek / top`：查看頂端元素
- `isEmpty`：判斷是否為空
- `isFull`（陣列實作時）


#### 時間複雜度
- push:O(1)
- pop:O(1)
- peek:O(1)
- Search:O(n)

### Queue（佇列）

#### 定義
- 遵循 **FIFO（First In, First Out）**
- 從 **尾端加入（Rear）**，**前端移除（Front）**


#### 特點
- 先進先出
- 兩個操作端點（Front / Rear）
- 常用於排程、BFS、等待隊列


### 基本操作
- `enqueue`：加入元素到尾端
- `dequeue`：移除前端元素
- `front`：查看前端元素
- `isEmpty`
- `isFull`（陣列實作時）


### 時間複雜度
- enqueue:O(1)
- dequeue:O(1)
- front:O(1)
- search:O(n)

### HashTable.md
### 定義
- 一種資料結構，用 **Hash Function（雜湊函數）** 將 **Key** 映射到陣列的索引位置（Bucket）
- 目標：快速 **插入、搜尋、刪除**
- 支援動態資料存取，效能取決於 **雜湊函數設計與碰撞處理方式**


### 碰撞（Collision）
- 定義：不同的 Key 經過 Hash Function 得到相同索引
- 解法：
  1. **鏈結法（Chaining）**
  2. **開放定址法（Open Addressing）**：
     - Linear Probing（線性探測）
     - Quadratic Probing（二次探測）
     - Double Hashing（雙重雜湊）


### 時間複雜度（平均情況）
- Insert（插入）:O(1) 
- Search（搜尋）:O(1)
- Delete（刪除）:O(1)

### Tree.md
### 定義
- 一種 **非線性資料結構**
- 由 **節點（Node）** 與 **邊（Edge）** 組成
- **根節點（Root）** 為頂端節點
- 每個節點可有 **零或多個子節點**
- **沒有循環（Cycle）**（樹本身是無環的）


### 特性
- **層級結構**：父子關係清楚
- **非線性**：不像陣列或鏈結串列
- **每個節點只有一個父節點**（除根節點）
- **子節點數可變**：依樹種類而定


### 類型
| 類型 | 特點 | 範例簡圖 |
|----|----|----|
| Binary Tree | 每個節點最多兩個子節點 | A<br>├─B<br>└─C |
| Binary Search Tree (BST) | 左子小於根，右子大於根 | 10<br>├─5<br>└─15 |
| Complete Binary Tree | 所有層滿或左對齊 | 1<br>├─2<br>└─3 |
| AVL Tree | 自平衡 BST，左右子樹高度差 ≤1 | 10<br>├─5<br>└─15 |
| Red-Black Tree | 自平衡 BST，顏色規則保持高度平衡 | 10(B)<br>├─5(R)<br>└─15(R) |
| Heap | 完全二元樹，父節點大小規則 | Max Heap: 10<br>├─9<br>└─8 |
| General Tree | 每個節點可有多個子節點 | A<br>├─B<br>├─C<br>└─D |


### 操作時間複雜度（以 n 節點計）
| 操作 | Binary Tree | BST（平均） | BST（最壞） | AVL / Red-Black |
|----|----|----|----|----|
| Search | O(n) | O(log n) | O(n) | O(log n) |
| Insert | O(n) | O(log n) | O(n) | O(log n) |
| Delete | O(n) | O(log n) | O(n) | O(log n) |
| Traversal | O(n) | O(n) | O(n) | O(n) |

### Heap.md
#### 定義
- 一種 **完全二元樹（Complete Binary Tree）**
- 節點遵循 **堆性質（Heap Property）**
  - **Max Heap**：父節點 ≥ 子節點  
  - **Min Heap**：父節點 ≤ 子節點
- 常用於**優先隊列**、排序演算法（如 Heap Sort）

---

#### 特性
- **完全二元樹**：每層節點都填滿，最底層從左開始填
- **父子大小規則**：
  - Max Heap：父大於子  
  - Min Heap：父小於子
- 可以用 **陣列實作**：
  - 父節點 index = i  
  - 左子 = 2i + 1  
  - 右子 = 2i + 2

---

#### 基本操作
| 操作 | 說明 |
|----|----|
| Insert | 將新元素加入最後，向上調整（sift-up） |
| Delete / Extract | 移除根節點（最大或最小），最後元素補上，向下調整（sift-down） |
| Peek / Top | 查看根節點（最大或最小） |
| Heapify | 將任意陣列整理成 Heap |

---

#### 時間複雜度
| 操作 | 時間複雜度 |
|----|----|
| Insert | O(log n) |
| Delete / Extract | O(log n) |
| Peek / Top | O(1) |
| Heapify（整個陣列建堆） | O(n) |

### Graph.md
### 定義
- 一種 **非線性資料結構**
- 由 **頂點（Vertices, V）** 與 **邊（Edges, E）** 組成
- 用來表示**元素間的關係**


### 特點
- 可以是 **有向（Directed）** 或 **無向（Undirected）**
- 可以包含 **權重（Weighted）** 或 **無權重（Unweighted）**
- 可連通或不連通
- 可能有環（Cycle）或無環

### 種類
| 類型 | 特點 |
|----|----|
| Directed Graph | 邊有方向 |
| Undirected Graph | 邊無方向 |
| Weighted Graph | 邊有權重 |
| Unweighted Graph | 邊無權重 |
| Cyclic Graph | 有環 |
| Acyclic Graph | 無環 |


### 表示法
| 方法 | 特點 | 時間 / 空間優缺點 |
|----|----|----|
| Adjacency Matrix（鄰接矩陣） | 二維陣列，matrix[i][j]=1 表示有邊 | 查邊 O(1)，空間 O(V²) |
| Adjacency List（鄰接表） | 每個頂點存鄰居列表 | 查邊 O(V)，空間 O(V+E) |


### 基本操作
| 操作 | 資料結構 / 方法 | 時間複雜度 |
|----|----|----|
| Traversal（走訪） | BFS（Queue） | O(V + E) |
| Traversal（走訪） | DFS（Stack / Recursion） | O(V + E) |
| Path / Connectivity | BFS / DFS | O(V + E) |
| Cycle Detection | DFS | O(V + E) |
| Shortest Path | BFS / Dijkstra / Bellman-Ford | 視演算法而定 |

