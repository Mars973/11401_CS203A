# Hash 與 Hash Table（雜湊與雜湊表）

---

## Hash（雜湊）

### 定義
Hash 是一種 **將資料轉換為固定範圍整數值的運算方式**。  
透過 **雜湊函數（Hash Function）**，將輸入資料（Key）映射成一個 **雜湊值（Hash Value）**，通常作為索引使用。

### 特點
- 相同的輸入（Key）一定會得到相同的雜湊值
- 不同的輸入**可能**得到相同的雜湊值（稱為碰撞，Collision）
- 計算速度快，通常為 O(1)
- 雜湊值範圍有限

### 簡單例子
```c
hash(key) = key % table_size;
```

## Hash Table（雜湊表）

---

### 定義

Hash Table 是一種 **使用雜湊函數（Hash Function）來實作的資料結構**，  
透過雜湊函數將 **Key 映射到陣列中的某個位置（Bucket）**，  
以達到 **快速插入、刪除與查詢** 的目的。

---

### 結構概念

```c
index = hash(key);
table[index] = value;
```
- **key**：用來查找資料的鍵
- **value**：實際儲存的資料
- **index**：雜湊函數計算後的陣列位置

## 碰撞（Collision）

### 定義

當 **不同的 Key 經過雜湊函數（Hash Function）後，得到相同的索引位置（Bucket）**，  
就稱為 **碰撞（Collision）**。

---

### 常見解決方法

#### 1. 鏈結法（Chaining）
- 每個 Bucket 存放一條 **Linked List**
- 發生碰撞時，將資料加入對應 Bucket 的串列中

#### 2. 開放定址法（Open Addressing）
- 所有資料都存放在陣列中
- 發生碰撞時，依照規則尋找下一個可用位置

**常見方式：**
- **Linear Probing**：依序往後尋找
- **Quadratic Probing**：以平方間隔跳躍尋找
- **Double Hashing**：使用第二個雜湊函數計算間隔

---

## Collision 解法比較表

| 解法 | 說明 | 優點 | 缺點 | 適合情境 |
|------|------|------|------|----------|
| **Chaining（鏈結法）** | 每個 Bucket 存一條 Linked List，碰撞的元素依序串接 | 實作簡單<br>不易發生滿表問題 | 額外指標空間<br>碰撞多時搜尋退化為 O(n) | 資料量不確定<br>記憶體較充足 |
| **Linear Probing** | 發生碰撞時，往後一格一格找空位 | 實作最簡單<br>快取友好 | 容易產生 Primary Clustering | 資料量小、碰撞少 |
| **Quadratic Probing** | 以平方距離跳躍尋找空位 | 降低 Primary Clustering | 仍可能 Secondary Clustering<br>實作較複雜 | 中等負載因子 |
| **Double Hashing** | 使用第二個雜湊函數決定探測間距 | 碰撞分散效果最好<br>Clustering 最少 | 實作最複雜<br>計算成本較高 | 高效能需求<br>高負載因子 |

---

### 補充重點（考試重點提醒）

- **Primary Clustering**：Linear Probing 易發生  
- **Secondary Clustering**：Quadratic Probing 可能發生  
- **Double Hashing**：最不容易產生 Clustering  
- 當負載因子過高時，應進行 **Rehash**

---

### 補充說明

- 碰撞是 **無法完全避免** 的
- 良好的雜湊函數可 **降低碰撞發生率**
- 碰撞過多會使 Hash Table 效能退化，最壞情況可達 **O(n)(時間複雜度是重點)**


