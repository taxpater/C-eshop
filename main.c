// Addition of the necessary packages / libraries to the program.
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include "func.h"

// The main function that executes all the processes of the e-shop.
int main(void) {
  // Initialisation of the i, j and k counters along with the fd1 and fd2 tables that will be used for the two pipes connecting 
  // the clients and the server. fd1 is used for sending orders to the server and fd2 for the server's response to the client.
  int i = 1, j, k, fd1[2], fd2[2], response;
  char buffer[512];
  product catalog[CATALOG_SIZE];
  InitialiseCatalog(catalog);
  
  while(i <= CLIENT_AMOUNT) {
    // The seed for the rand() function is changed with every new client to decrease the chances of multiple duplicate requests of the same product.
    srand(time(NULL));
    
    // Creation of the two pipes using the two file descriptors (fd1, fd2).
    if (pipe(fd1) < 0) {
      printf("Error Number : %d\n", errno);
      perror("Error Description");
      return -1;
    }
    if (pipe(fd2) < 0) {
      printf("Error Number : %d\n", errno);
      perror("Error Description");
      return -1;
    }

    int customerTotal = 0;
    printf("--------------------------------\nClient No.%d: \n", i);
    pid_t clientPid = fork();
    
    // If fork() returns any negative integer, it meants that we have ecountered a fatal error and the program should quit.
    if (clientPid < 0) {
      printf("Error Number : %d\n", errno);
      perror("Error Description");
      return (-2); 
    }

    // Client Process.
    if (clientPid == 0) {
      close(fd1[0]);
      close(fd2[1]);
      int productNo;
      
      // The loop that allows the client to send the "ORDER_AMOUNT" orders to the server.
      for (j = 1; j <= ORDER_AMOUNT; j++) {
        productNo = rand() % CATALOG_SIZE;

        write(fd1[1], &productNo, sizeof(int));
        sleep(1); // Order processing time

        read(fd2[0], buffer, sizeof(buffer));

        printf("%s", buffer);
      }
      close(fd1[1]);
      close(fd2[0]);
      exit(0);
    }
    // Server Process
    else {
     // Closure of the appropriate file descriptors to ensure that the client-server communication is completed through the correct avenues.
      close(fd1[1]);
      close(fd2[0]);
      
      // The loop that allows the server to handle the 10 orders that each client sends to it.
      for (k = 1; k <= ORDER_AMOUNT; k++) {
        read(fd1[0], &response, sizeof(int));

        if (catalog[response].item_count >= 1) {
          customerTotal = customerTotal + catalog[i].price;
          catalog[response].item_count--;
          catalog[response].successfulPurchases++;
          snprintf(buffer, sizeof(buffer), "Purchase of item No.%d was successful! Your charge is: %d€.\n", response, catalog[response].price);
        } else {
          catalog[response].failedPurchases++;
          snprintf(buffer, sizeof(buffer), "There isn't enough stock of item No.%d! Your order has been canceled.\n", response);
        }

        write(fd2[1], buffer, sizeof(buffer));
        
        // Order cooldown
        sleep(1); 
      }
      printf("\nThe total for client No.%d is: %d\n", i, customerTotal);
      
      // "Freezing" the server to ensure that the client has exited before proceeding with handing the next client's orders. 
      waitpid(clientPid, NULL, 0);
    }
    // Closing the rest of the pipe's ends since they are no longer needed.
    close(fd1[0]);
    close(fd2[1]);
    i++;
  }
  // Calling the relevant function to display the final report for the e-shop.
  StatisticsReporting(catalog);
  return 0;
}
