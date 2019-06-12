#include "hashtable.h"
#include <stdlib.h>
#include <memory.h>

hashtable *ht_init(int capacity) {
    int i;

    hashtable *ht = (hashtable *) malloc(sizeof(hashtable));
    ht->capacity = capacity;
    //sizeof List pointer, denn wir speichern ja ein Array von Pointern, daher 8bytes(64bit) * capacity, dies wir nun zu einem list** element gecastet -> pointer auf eine Liste von Pointer
    ht->buckets = (list **) malloc(capacity * sizeof(list *));
    for (i = 0; i < capacity; i++) {
        ht->buckets[i] = l_init();
    }
    return ht;
}

//zum Einordnen in das Array (jeweiliges Bucket/Liste) verwendet man eine Hashfunktion, in diesem Fall capacity mod realkey;
//Realkey wird aus dem jeweiligen char[5] ASCII code erstellt in der Schleife
int ht_hash(hashtable *ht, char *key) {
    int realkey = 0;
    for (int i = 0; i < 4; ++i) {
        //realkey += key[i];
        realkey += key[i];
    }
    //capacity mod keyvalue -> damit ist garantiert das in diesem Fall 0-99 ausgefüllt ist, denn mod 100 wäre 0 rest und wäre somit in array[0] bis may array[99] -> gscheit
    return realkey % ht->capacity;
}

//key = icao code value = station_name
void ht_put(hashtable *ht, char *key, char *value) {

    int arrayindex = ht_hash(ht, key);
    //list_insert an der richtigen Stelle in dem array aus Pointer die auf Listen zeigen
    l_insert(ht->buckets[arrayindex], key, value);

}

char *ht_get(hashtable *ht, char *key) {
    int arrayindex = ht_hash(ht, key); // hashen für richtigen index im Array (modulo)


    return l_find(ht->buckets[arrayindex], key)->station_name;
}

void ht_print_bucket_sizes(hashtable *ht) {
    for (int i = 0; ht->buckets[i] != 0 ; ++i) {
        printf("size of bucket[%d] = ",i);
        printf("%d \n",ht->buckets[i]->count);

    }


}
