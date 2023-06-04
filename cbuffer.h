#ifndef _CBUFFER_LIB_
#define _CBUFFER_LIB_

#include <stdbool.h>
#include <inttypes.h>

#define NVS_BUFF_LEN_DATA   100


typedef struct data_storage_nvs{
    float* temp;        // Pointer to the buffer
    float* humy;        // Pointer to the buffer
    uint8_t* batt;      // Pointer to the buffer
    int capacity;       // Maximum number of elements in the buffer
    int ptr_read;       // Index to read from
    int ptr_write;      // Index to write to
    int size;           // Current number of elements in the buffer
} data_storage_nvs_t;


typedef struct data_payload {
    float temp;
    float humy;
    uint8_t batt;
} data_payload_t;


// Function to initialize the circular buffer
void cbuffer_init(data_storage_nvs_t * cb, int capacity);


// Function to check if the circular buffer is empty
bool cbuffer_is_empty(data_storage_nvs_t * cb);


// Function to check if the circular buffer is full
bool cbuffer_is_full(data_storage_nvs_t * cb);


// Function to add an element to the circular buffer
void cbuffer_enqueue(data_storage_nvs_t * cb, data_payload_t data);


// Function to remove and return the oldest element from the circular buffer
int cbuffer_dequeue(data_storage_nvs_t * cb, data_payload_t * data);


// Function to get the current number of elements in the circular buffer
int cbuffer_size(data_storage_nvs_t * cb);



#endif