# Trie

A **Trie** is a tree-based data structure used to store a dynamic set of strings, where keys are usually strings over an alphabet.

---

## Operations

- **Insert(string)** – Inserts a word into the Trie.
- **Search(string)** – Returns `true` if the word exists in the Trie.
- **StartsWith(prefix)** – Returns `true` if any word in the Trie starts with the given prefix.

---

## Time Complexity

Let **L** be the length of the word/prefix:
- Insert: `O(L)`
- Search: `O(L)`
- Prefix check: `O(L)`

---

## Usage Example

```cpp
Trie trie;
trie.insert("apple");
trie.search("apple");   // true
trie.search("app");     // false
trie.startsWith("app"); // true
trie.insert("app");
trie.search("app");     // true
