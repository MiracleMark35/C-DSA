
# Insert
Why TRUE?
```c
bool insert_cache(HashTable *table, const char *key) {
    unsigned int hashKey = hash(key);

    // Check if key already exists
    CacheEntry* trav = table->buckets[hashKey];
    while(trav != NULL) {
        if(strcmp(trav->key, key) == 0){
            // Key already exists, skip insertion
            return true; // or false, depending on how you want to signal "skipped"
        }
        trav = trav->next;
    }

    // Key is new, fetch results
    char **results = simulate_database_fetch(key);
    if(results == NULL) return false;

    // Allocate new node
    CacheEntry* newNode = malloc(sizeof(CacheEntry));
    newNode->key = malloc(strlen(key)+1);
    strcpy(newNode->key, key);
    newNode->results = results;
    newNode->next = table->buckets[hashKey];
    table->buckets[hashKey] = newNode;

    return true; // insertion successful
}

``` 
# Return Statements HASH
Follow return statements

If the unsigned int value fits within the range of int, it works fine
```c
unsigned int hash(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % HASH_BUCKETS;
}
```
So, it’s safer to do:
```c
unsigned int hashKey = hash(key);

```
# ERROR
Error: Segmentation fault (core dumped) Possible issues: - Stack Overflow - Due to an array out of bounds - Memory access violation. - Using void main() instead of int main().

💥 What “Segmentation fault (core dumped)” means

A segmentation fault (or segfault) happens when your program tries to access memory that it’s not allowed to use.

“Segmentation fault (core dumped)” = you accessed invalid memory (out of bounds, null, or freed pointer).

# Char To Const Char

| Method             | Code                         | Safe?                     | Can Modify? | Allocates Memory? |
| ------------------ | ---------------------------- | ------------------------- | ----------- | ----------------- |
| **Copy manually**  | `malloc + strcpy`            | ✅ Yes                     | ✅ Yes       | ✅ Yes             |
| **Use `strdup()`** | `newNode->key = strdup(key)` | ✅ Yes                     | ✅ Yes       | ✅ Yes             |
| **Direct pointer** | `newNode->key = (char *)key` | ⚠️ Only safe for literals | ❌ No        | ❌ No              |

That line writes characters to wherever newNode->key is pointing — which is undefined memory.
```c
strcpy(newNode->key, key);

```
your pointer newNode->key points nowhere valid, so strcpy() causes a segmentation fault.
