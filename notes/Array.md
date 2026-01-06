# Study Note: Array

## 定義 

陣列 是一種基本的資料結構，用於在記憶體中連續儲存相同型別的元素。每個元素都可以透過索引（Index）直接存取。陣列提供 $O(1)$ 的隨機存取效率，但在中間進行插入或刪除操作的成本較高，為 $O(n)$，因為需要移動後續元素。

## Visualization  



## Abstract Data Type

- **Access**: 取得指定索引處元素的值。
- **Update**: 修改指定索引處元素的值。 
- **Insert**: 在指定位置新增一個元素，並將後續元素向左移動。 
- **Delete**: 移除指定位置的元素，並將後續元素向左移動。
- **Traversal**: 依序存取陣列中的每個元素。


## Array Declaration

### Static Array

#### Declaration
```c
// 1D array with five elements
int array[5];
```

#### Initialization
```c
// Initialize the integer array with 10, 20, 30, 40, 50
int array[5] = {10, 20, 30, 40, 50};

// Initialize by for loop
for (int i = 0; i < 5; i++) {
    array[i] = i + 1;
}
```

#### Access
```c
// Retrieve the third element from array
printf("%d", array[2]);
```

#### Traverse
```c
// Traverse the entire array and print
for (int i = 0; i < 5; i++) {
    printf("%d", array[i]);
}
```

### Resize

Static arrays are allocated at **compile time**, so their size is fixed and **cannot be resized** during runtime; to change the size, you must declare a new array (or use a dynamic array instead).

### Dynamic Array

#### Declaration
```c
// Dynamic array initialization by malloc()
int *array;
int n = 10;
array = (int *) malloc(n * sizeof(int));
```

#### Initialization
```c
// Initialize by for loop
for (int i = 0; i < n; i++) {
    array[i] = i + 1;
}
```

#### Access
```c
// Access the element by index
for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
}
```

#### Traverse
```c
// Traverse the entire array and print
for (int i = 0; i < 5; i++) {
    printf("%d", array[i]);
}
```

### Resize

To resize a dynamic array, you can use the `realloc` function to allocate more memory. Below is an example:

```c
int *array;
int n = 10;
array = (int *) malloc(n * sizeof(int));

// Initialize the array
for (int i = 0; i < n; i++) {
    array[i] = i + 1;
}

// Double the size of the array
n = n * 2;
int *temp = (int *) realloc(array, n * sizeof(int));

if (temp == NULL) {
    free(array);
    return -1; // Handle memory allocation failure
}

array = temp;

// Initialize the new elements
for (int i = n / 2; i < n; i++) {
    array[i] = i + 1;
}
```

This code demonstrates how to resize a dynamic array, ensuring that the new memory is properly initialized and handling potential memory allocation failures.

## 陣列（Array）時間與空間複雜度

假設陣列中有 `n` 個元素：

---

### 一、時間複雜度（Time Complexity）

| 操作 | 複雜度 | 說明 |
|------|--------|------|
| **存取（透過索引讀取）** | O(1) | 直接訪問特定索引的元素 |
| **更新（透過索引寫入）** | O(1) | 直接修改特定索引的元素 |
| **遍歷（訪問所有元素）** | O(n) | 逐一訪問每個元素 |

#### 搜尋（Search）
- 無序陣列（線性搜尋）：O(n)  
- 有序陣列（二分搜尋）：O(log n)  

#### 插入（Insert）
- 尾端插入（容量足夠，例如動態陣列）：攤還 O(1)  
- 尾端插入（需重新配置空間）：O(n)  
- 開頭或中間插入：O(n)（需要移動元素）  

#### 刪除（Delete）
- 尾端刪除：O(1)  
- 開頭或中間刪除：O(n)（需要移動元素）  

---

### 二、空間複雜度（Space Complexity）

| 類別 | 複雜度 | 說明 |
|------|--------|------|
| **元素存儲** | O(n) | 陣列本身所需空間 |
| **操作輔助空間** | O(1) | 常見操作（如存取、更新）所需額外空間 |
| **動態陣列額外容量** | O(n) | 根據增長策略，未使用的容量最多可達 O(n) |
| **重新分配（realloc）** | O(1)（若在原地增長）<br>上限 O(n)（若需分配新空間並複製元素） | 重新配置空間時的額外需求 |

## 優點與缺點

### 優點（Pros）

- **透過索引可 O(1) 隨機存取**：讀取與寫入速度快。
- **快取友好（Cache-friendly）**：連續記憶體配置使遍歷效率高。
- **低額外開銷**：相比鏈結結構，每個元素只需極少的額外資料。
- **簡單且可預測**：索引存取和迭代操作直觀易懂。
- **動態陣列可自動擴展**：透過 `realloc` 可在需要時增加容量。

### 缺點（Cons）

- **靜態陣列大小固定**：編譯時決定，若需改變大小必須建立新陣列。
- **中間插入或刪除代價高**：需移動元素，時間複雜度為 O(n)。
- **動態陣列重新配置可能昂貴**：`realloc` 可能分配新區塊並複製元素，O(n)，且原有指標可能失效。
- **仍受記憶體限制**：動態陣列受實體記憶體、作業系統堆區與碎片化影響。
- **使用方式影響效能**：頻繁小幅增減容量可能降低效能；合理的擴容策略（如倍增）很重要。
- **手動記憶體管理（C 語言）**：必須手動 `free`，否則可能造成記憶體洩漏或使用已釋放的記憶體。
## 基本排序法整理（Basic Sorting Algorithms）

### 1. Bubble Sort（氣泡排序）
- **原理**：反覆比較相鄰元素，若順序錯誤就交換  
- **特性**：較大的元素會逐步移動到陣列尾端  
- **穩定性**：穩定（Stable）  
- **時間複雜度**：  
  - 最佳情況：O(n)  
  - 平均 / 最差情況：O(n²)  
- **適合情況**：資料量小、教學與概念示範用途  

---

### 2. Selection Sort（選擇排序）
- **原理**：每回合從未排序區中找出最小值，放到正確位置  
- **特性**：比較次數固定、交換次數少  
- **穩定性**：不穩定（Unstable）  
- **時間複雜度**：  
  - 最佳 / 平均 / 最差情況：O(n²)  
- **適合情況**：交換成本較高的情境  

---

### 3. Insertion Sort（插入排序）
- **原理**：將未排序元素插入已排序區的正確位置  
- **特性**：類似整理撲克牌  
- **穩定性**：穩定（Stable）  
- **時間複雜度**：  
  - 最佳情況：O(n)  
  - 平均 / 最差情況：O(n²)  
- **適合情況**：資料接近已排序、小型資料集  
