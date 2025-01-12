// All the contents of this header file, will be copied over to the main and the sub-functions during the compilation. Due to this, all constants, structs and shared libraries are declared here.
// Addition of the necessary packages / libraries to all functions used by this program.
#include <stdio.h>

// Definition of the constant that dictates the amount of pieces of 
// each product the shop has at the beginning.
#define PRODUCT_CNT 2
// Definition of the catalog's size.
#define CATALOG_SIZE 20

// Definition of the struct that defines the shop's products in the server. 
typedef struct product {
  int price;
  int item_count;
  char description[256];
  int failedPurchases;
  int successfulPurchases;
} product;

// The declarations of the two sub-functions the e-shop uses.
void InitialiseCatalog(product catalog[]);
void StatisticsReporting(product catalog[]);
