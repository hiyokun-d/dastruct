# 🧾 Boogle: Slang Dictionary Using Trie in C (Full Documentation)

---

## 📘 Program Overview

This program implements a **slang dictionary** using a **Trie (prefix tree)** in C. Users can:

- Add slang terms and descriptions
- Search for slang
- View all slang starting with a prefix
- View all slang in alphabetical order
- Clean up all memory on exit

The Trie structure makes these operations fast and efficient.

---

## 🧠 Why We Use Trie

A Trie is a specialized tree structure ideal for word-based data:

- Fast O(L) search time (L = length of word)
- Perfect for prefix lookups
- Sorted traversal is natural (a–z)

It’s better than:

- Arrays/linked lists (slow, unsorted)
- Hash maps (no prefix support)
- Binary search trees (less efficient for prefix)

---

## 🔧 Function-by-Function Breakdown

---

### 🧩 `createNode`

**Purpose**: Create a new Trie node  
**Logic**:

- Allocates memory for one node
- Sets all children to NULL
- Sets description to NULL

```c
TrieNode *createNode() {
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    node->description = NULL;
    return node;
}
```

**Limitations**: Doesn’t check for malloc failure.

---

### 🧩 `insert`

**Purpose**: Insert a slang word and its description  
**Logic**:

- Follows or creates a path for each character
- At the end, stores (or replaces) the description

```c
void insert(TrieNode* root, const char* word, const char* description) {
    TrieNode* curr = root;
    for (int i = 0; word[i] != '\0'; i++) {
        char ch = tolower(word[i]);
        if (ch < 'a' || ch > 'z') continue;
        int index = ch - 'a';
        if (curr->children[index] == NULL)
            curr->children[index] = createNode();
        curr = curr->children[index];
    }
    if (curr->description != NULL) free(curr->description);
    curr->description = malloc(strlen(description) + 1);
    strcpy(curr->description, description);
}
```

**Limitations**: Ignores non-alphabet characters, silently overwrites descriptions.

---

### 🧩 `search`

**Purpose**: Search for a slang word  
**Logic**:

- Follows the trie path character-by-character
- Prints the description if it exists at the end node

```c
void search(TrieNode *root, const char *word) {
    TrieNode *curr = root;
    for (int i = 0; word[i] != '\0'; i++) {
        char ch = tolower(word[i]);
        if (ch < 'a' || ch > 'z') continue;
        int index = ch - 'a';
        if (curr->children[index] == NULL) {
            printf("Not found\\n");
            return;
        }
        curr = curr->children[index];
    }
    if (curr->description)
        printf("%s\\n", curr->description);
    else
        printf("Not found\\n");
}
```

**Limitations**: No fuzzy matches or suggestion logic.

---

### 🧩 `searchByPrefix`

**Purpose**: List all slang words that start with a prefix  
**Logic**:

- Navigate to the end node of the prefix
- Recursively print all words starting from that node

```c
void searchByPrefix(TrieNode *root, const char *prefix) {
    TrieNode *curr = root;
    for (int i = 0; prefix[i] != '\0'; i++) {
        char ch = tolower(prefix[i]);
        if (ch < 'a' || ch > 'z') continue;
        int index = ch - 'a';
        if (curr->children[index] == NULL) {
            printf("No match\\n");
            return;
        }
        curr = curr->children[index];
    }
    char buffer[100];
    strcpy(buffer, prefix);
    listAllFromNode(curr, buffer, strlen(prefix));
}
```

**Limitations**: Fixed buffer size; input must be valid a–z characters.

---

### 🧩 `printAllWords`

**Purpose**: Print all slang words alphabetically  
**Logic**:

- DFS traversal across trie
- When a node has a description, print the word + meaning

```c
void printAllWords(TrieNode *root, char *buffer, int depth) {
    if (!root) return;
    if (root->description) {
        buffer[depth] = '\0';
        printf("%s: %s\\n", buffer, root->description);
    }
    for (int i = 0; i < 26; i++) {
        if (root->children[i]) {
            buffer[depth] = 'a' + i;
            printAllWords(root->children[i], buffer, depth + 1);
        }
    }
}
```

**Limitations**: Not UTF-8 friendly; assumes ASCII only.

---

### 🧩 `freeTrie`

**Purpose**: Deallocate all dynamic memory  
**Logic**:

- Post-order traversal
- Frees children first, then description, then the node

```c
void freeTrie(TrieNode *root) {
    if (!root) return;
    for (int i = 0; i < 26; i++) {
        if (root->children[i]) {
            freeTrie(root->children[i]);
        }
    }
    if (root->description) free(root->description);
    free(root);
}
```

**Limitations**: Does not track how much memory was freed.

---

## ✅ Sample Test Cases

```c
insert("sus", "suspicious behavior");
insert("yeet", "to throw something forcefully");
insert("simp", "someone who does too much for someone they like");
insert("sus", "updated: still suspicious");
insert("savage", "cool or bold in a crazy way");
insert("ship", "to support a romantic relationship");

search("sus");     // ➜ "updated: still suspicious"
search("yeet");    // ➜ "to throw something forcefully"
search("unknown"); // ➜ Not found

searchByPrefix("s");  // ➜ Lists: savage, ship, simp, sus
searchByPrefix("z");  // ➜ "No match"

printAllWords();      // ➜ Prints all in order
```

---

## 🧼 Limitations Summary

- Only supports ASCII lowercase letters `a-z`
- No persistent file saving (data lost on exit)
- No GUI or interactive input validation
- Description assumes single-line strings
- Buffer sizes (like 100 chars) are hardcoded

---

## 🧾 Conclusion

This project uses a **Trie** to manage slang words efficiently and cleanly. It allows fast searches, intuitive prefix handling, and alphabetical output — all while reinforcing dynamic memory, recursion, and string handling skills in C.

It's an ideal demonstration of applying a data structure to solve a practical dictionary-like problem.
