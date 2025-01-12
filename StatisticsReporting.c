// Addition of the necessary packages / libraries to the program.
#include "func.h"

// The code for the function that sends the statistics for the shop's operations in the end.
void StatisticsReporting(product catalog[]) {
  int i, orderCnt = 0, successfulPurchaseCnt = 0, failedPurchaseCnt = 0, totalRevenue = 0;
  // Printing of the product report.
  printf("--------------------------------\nProduct report:\n\n");
  for (i = 0; i < CATALOG_SIZE; i++) {
    printf("Price: %d\nAvailable Items: %d\nDescription: %s\nTotal amount of purchase requests: %d\nSuccessful purchases for this product: %d\nFailed purchases for this product: %d\n\n", catalog[i].price, catalog[i].item_count, catalog[i].description, catalog[i].successfulPurchases + catalog[i].failedPurchases, catalog[i].successfulPurchases, catalog[i].failedPurchases);

    // Calculation of the values for the store report in the side of printing the product report.
    totalRevenue = totalRevenue + catalog[i].successfulPurchases * catalog[i].price;
    successfulPurchaseCnt = successfulPurchaseCnt + catalog[i].successfulPurchases;
    failedPurchaseCnt = failedPurchaseCnt + catalog[i].failedPurchases;
  }

  orderCnt = successfulPurchaseCnt + failedPurchaseCnt;
  printf("--------------------------------\nStore report:\n\n");
  printf("Total amount of orders: %d\nTotal number of successful orders: %d\nTotal number of failed orders: %d\nTotal earnings: %d€\n", orderCnt, successfulPurchaseCnt, failedPurchaseCnt, totalRevenue);
}

