#include "hashtable.h"
#include <stdlib.h>
#include <memory.h>

hashtable *	ht_init(int capacity) {
	int i;
	
	hashtable * ht = (hashtable *)malloc(sizeof(hashtable));
	ht->capacity = capacity;
	ht->buckets = (list **)malloc(capacity * sizeof(list *));
	for (i = 0; i < capacity; i++) {
		ht->buckets[i] = l_init();
	}
	return ht;
}

int ht_hash(hashtable * ht, char * key) {
	/* TODO: implement hash function */
	return 0;
}

void ht_put(hashtable * ht, char * key, char * value) {
	/* TODO: implement insertion into hash table */
}

char * ht_get(hashtable * ht, char * key) {
	/* TODO: implement retrieval of data */
	return NULL;
}

void ht_print_bucket_sizes(hashtable * ht) {
	/* TODO: implement printing of bucket sizes */
}
