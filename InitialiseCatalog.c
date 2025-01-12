// Addition of the necessary packages / libraries to the program.
#include "func.h"
#include <time.h>
#include <stdlib.h>

// The function that populates the product catalog with values.
void InitialiseCatalog(product catalog[]) {
  int i, maxPrice = 1200, minPrice = 200, RAMSize[5] = {4, 8, 16, 32, 64}, storageSize[5] = {128, 256, 512, 1000, 2000};
  char * brand[5] = {"Asus", "HP", "Dell", "Lenovo", "Apple"};
  srand(time(NULL));

  for (i = 0; i < CATALOG_SIZE; i++) {
    catalog[i].price = rand() % (maxPrice - minPrice + 1) + minPrice;
    catalog[i].item_count = PRODUCT_CNT;
    snprintf(catalog[i].description, 256, "A laptop from %s with %dGB of storage, and %dGB of RAM.", brand[rand() % 5], storageSize[rand() % 5], RAMSize[rand() % 5]);
    catalog[i].failedPurchases = 0;
    catalog[i].successfulPurchases = 0;
  }
}

