#include <cbuffer.h>
#include <stdbool.h>


// Function to initialize the circular buffer
void cbuffer_init(data_storage_nvs_t * cb, int capacity)
{
    cb->temp = malloc(capacity * sizeof(float));
    cb->humy = malloc(capacity * sizeof(float));
    cb->batt = malloc(capacity * sizeof(uint8_t));
    cb->capacity = capacity;
    cb->ptr_read = 0;
    cb->ptr_write = 0;
    cb->size = 0;
}


// Function to check if the circular buffer is empty
bool cbuffer_is_empty(data_storage_nvs_t * cb)
{
    return cb->size == 0;
}


// Function to check if the circular buffer is full
bool cbuffer_is_full(data_storage_nvs_t * cb)
{
    return cb->size == cb->capacity;
}


// Function to add an element to the circular buffer
void cbuffer_enqueue(data_storage_nvs_t * cb, data_payload_t data)
{
    if (cbuffer_is_full(cb)) {
        // Handle buffer overflow (optional)
        return;
    }

    cb->temp[cb->ptr_write] = data.temp;
    cb->humy[cb->ptr_write] = data.humy;
    cb->batt[cb->ptr_write] = data.batt;
    cb->ptr_write = (cb->ptr_write + 1) % cb->capacity;
    cb->size++;
}


// Function to remove and return the oldest element from the circular buffer
int cbuffer_dequeue(data_storage_nvs_t * cb, data_payload_t * data)
{
    if (cbuffer_is_empty(cb)) {
        // Handle buffer underflow (optional)
        return 0;
    }

    data->temp = cb->temp[cb->ptr_read];
    data->humy = cb->humy[cb->ptr_read];
    data->batt = cb->batt[cb->ptr_read];
    cb->ptr_read = (cb->ptr_read + 1) % cb->capacity;
    cb->size--;

    return 1;
}


// Function to get the current number of elements in the circular buffer
int cbuffer_size(data_storage_nvs_t * cb)
{
    return cb->size;
}
